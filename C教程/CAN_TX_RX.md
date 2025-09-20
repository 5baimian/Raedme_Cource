# CAN_RX
#### 1.在对can接收的数据进行接收时要要首先区分ID格式，标准帧和拓展帧进行区分，标准ID为11位，拓展ID为29位。

#### 2.case+ID进行匹配，匹配到对应的ID后，再对数据进行解码。首先对接收到的数据进行CRC校验，校验通过后再进行解码。

# CAN_TX
#### 1.在一个整体的工程当中，首先应该对can函数的初始化进行检查，区分标准帧和拓展帧。
    filter_init(&hcan1);
    filter2_init(&hcan2);
    //拓展帧
    vApp_CAN_TxHeader_Init(&hCAN1_TxHeader, 0, 0x18C4D2D0, CAN_ID_EXT, CAN_RTR_DATA, 8);
    //标准帧
    vApp_CAN_TxHeader_Init(&hCAN2_TxHeader, 0x13, 0, CAN_ID_STD, CAN_RTR_DATA, 8);

#### 2.在通过can进行指令的发送过程中，并不是以二进制直接进行发送，我们发送的是指令，并不是二进制数据，所以我们要对目标数据进行处理，将其转化为二进制并且存在can发送缓冲区当中（就是那个八个字节组成的数组）。

#### 3.在传参的过程当中，要注意实参和形参在两个函数中的类型要保持一致，并且要保证形参与其函数中的参数名称保持一致。