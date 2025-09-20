struct _tx_data tx_data_test = {0};/* 底盘数据结构体变量定义 */
void send_to_ackermann_car(	uint8_t    ctrl_cmd_gear,
                            fp32       ctrl_cmd_velocity,
                            fp32      ctrl_cmd_steering,
                            uint8_t    ctrl_cmd_Brake)
{
	unsigned char SendData_to_vehicle[8] = {0};
  unsigned short vel = 0;
	short angular = tx_data_test.cmd_steering * 100;
	static unsigned char count = 0;
  uint32_t cel_ID=0x18C4D2D0;
	
//	tx_data.ctrl_cmd_velocity=0.5;
//  tx_data.ctrl_cmd_steering=0;
//	tx_data.ctrl_cmd_Brake=0;
//	tx_data.ctrl_cmd_gear=4;
	
	
	if(tx_data_test.cmd_velocity < 0) vel = 0;
	else
	{
		vel = tx_data_test.cmd_velocity * 1000;
	}

	SendData_to_vehicle[0] = SendData_to_vehicle[0] | (0x0f & tx_data_test.cmd_gear);
	
	SendData_to_vehicle[0] = SendData_to_vehicle[0] | (0xf0 & ((vel & 0x0f) << 4));

	SendData_to_vehicle[1] = (vel >> 4) & 0xff;

	SendData_to_vehicle[2] = SendData_to_vehicle[2] | (0x0f & (vel >> 12));

	SendData_to_vehicle[2] = SendData_to_vehicle[2] | (0xf0 & ((angular & 0x0f) << 4));

	SendData_to_vehicle[3] = (angular >> 4) & 0xff;

	SendData_to_vehicle[4] = SendData_to_vehicle[4] | (0xf0 & ((tx_data_test.cmd_Brake & 0x0f) << 4));

	SendData_to_vehicle[4] = SendData_to_vehicle[4] | (0x0f & (angular >> 12));

	SendData_to_vehicle[5] = 0;

	count ++;

	if(count == 16)	count = 0;

	SendData_to_vehicle[6] =  count << 4;
	

	SendData_to_vehicle[7] = SendData_to_vehicle[0] ^ SendData_to_vehicle[1] ^ SendData_to_vehicle[2] ^ SendData_to_vehicle[3] ^ SendData_to_vehicle[4] ^ SendData_to_vehicle[5] ^ SendData_to_vehicle[6];


	/* 通过CAN1发送信息 */
	vApp_User_CAN1_TxMessage(cel_ID,SendData_to_vehicle,8);
}
