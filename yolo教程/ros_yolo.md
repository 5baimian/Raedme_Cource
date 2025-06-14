# 1.安装摄像头驱动

    sudo apt-get install ros-noetic-usb-cam
 
 #测试摄像头
 
    （1） roslaunch usb_cam usb_cam-test.launch
  
    （2）rqt_image_view

# 2. OpenCV-ROS转换
    sudo apt-get install ros-<noetic>-cv-bridge
  #验证

    roscd cv_bridge 
  #此处不报错则安装成功
  
# 3.YOLOv8和OpenCV  
    pip install ultralytics opencv-python 


# 4.先创建工作空间
    
  #创建yolov8检测节点 yolov8_ros_node.py

  #修改CMakeLists.test

      catkin_install_python(PROGRAMS
      scripts/yolov8_ros_node.py
      DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION
      }

  #进到scripts给py文件配置权限
      
      /yolov8_ros/src/ros_yolo_cam/scripts$ chmod +x *.py
# 5.运行：
  #启动摄像头

    roslaunch usb_cam usb_cam-test.launch
  #启动检测节点

    rosrun your_package yolov8_ros_node.py


# 6.代码
  #创建yolov8检测节点 --yolov8_ros_node.py
        
        #!/usr/bin/env python3
        import rospy
        from sensor_msgs.msg import Image
        from cv_bridge import CvBridge
        import cv2
        from ultralytics import YOLO

        class YOLOv8Node:
        def __init__(self):
          rospy.init_node('yolov8_ros_node')
          
          # 加载YOLOv8模型
          self.model = YOLO("yolov8n.pt")  # 可替换为 yolov8s.pt, yolov8m.pt 等
          
          # 初始化 OpenCV-ROS 转换器
          self.bridge = CvBridge()
          
          # 订阅摄像头话题
          self.image_sub = rospy.Subscriber("/usb_cam/image_raw", Image, self.image_callback)
          
          # 发布检测结果（可选）
          self.detection_pub = rospy.Publisher("/yolov8/detections", Image, queue_size=10)
          
          # 实时显示检测结果
          self.window_name = "YOLOv8 ROS Detection"
          cv2.namedWindow(self.window_name, cv2.WINDOW_NORMAL)
          
        def image_callback(self, msg):
          try:
              # 转换ROS图像消息为OpenCV格式
              cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
              
              # 使用YOLOv8进行检测
              results = self.model(cv_image)
              
              # 绘制检测结果
              annotated_frame = results[0].plot()
              
              # 显示检测结果
              cv2.imshow(self.window_name, annotated_frame)
              cv2.waitKey(1)  # 必须调用，否则窗口不会更新
              
              # 可选：发布检测结果到ROS话题
              detection_msg = self.bridge.cv2_to_imgmsg(annotated_frame, "bgr8")
              self.detection_pub.publish(detection_msg)
              
          except Exception as e:
              rospy.logerr(f"Error processing image: {e}")

        def run(self):
          rospy.spin()
          cv2.destroyAllWindows()  # 关闭OpenCV窗口

        if __name__ == '__main__':
        node = YOLOv8Node()
        node.run()


# 7.Ubuntu配置Yolov8环境并训练自己的数据集 + ROS实时运行
    URL_ADDRESS  https://blog.csdn.net/zardforever123/article/details/134338193

# 8.超详细Ubuntu安装Anaconda步骤+Anconda常用命令
    URL_ADDRESS  https://blog.csdn.net/KRISNAT/article/details/124041869
 

