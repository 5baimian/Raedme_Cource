# 安装 RKNN-Toolkit2 
```bash

# 环境是Ubuntu 22.04 LTS(x86_64) 

# 1）安装virtualenv 环境
sudo apt-get install virtualenv
# 2）安装相关依赖
sudo apt-get update
sudo apt-get install  python3.10 python3.10-dev python3.10-venv python3-pip -y
sudo apt-get install libxslt1-dev zlib1g zlib1g-dev libglib2.0-0 libsm6 libgl1-mesa-glx libprotobuf-dev gcc -y
# 3）创建虚拟环境(可以选定指定的文件夹)
virtualenv -p /usr/bin/python3 venv
source venv/bin/activate
# rknpu SDK 里面配置好了
cd rknn-toolkit2-v2.3.0-2024-11-08/rknn-toolkit2/packages/x86_64
# 安装 Python 3.10 对应的依赖包
pip3 install -r packages/x86_64/requirements_cp310-2.3.0.txt -i https://pypi.tuna.tsinghua.edu.cn/simple

# 安装 Python 3.10 对应的 Toolkit2 本体
pip3 install packages/x86_64/rknn_toolkit2-2.3.0-cp310-cp310-manylinux_2_17_x86_64.manylinux2014_x86_64.whl

# 验证安装

python3 -c "from rknn.api import RKNN; print('环境配置彻底成功！')"

# 执行 yolov8 模型转换
# rknn_model_zoo-v2.3.0-2024-11-08/examples/yolov8/python文件夹下执行

#配置好的虚拟环境在 yolov8 目录下
# 激活虚拟环境
source ~/Desktop/rknn_model_zoo-v2.3.0-2024-11-08/examples/yolov8/python/venv/bin/activate

python3 convert.py ../model/yolov8.onnx rk3588 i8

# 生成的rknn模型文件在 yolov8/model/yolov8.rknn
```

# 创建虚拟空间
```bash
# 在指定目录下创建干净的虚拟环境
python3 -m venv venv

# 激活虚拟环境
source venv/bin/activate

# 退出虚拟环境
deactivate  

# 安装转换工具以及ultraytics的文件都安装在虚拟环境中，这个虚拟环境的地址是:
# /home/duan/Desktop/rknn_model_zoo-v2.3.0-2024-11-08/examples/yolov8/python

```

# 在板端上运行CPP文件
```bash
# 进入到model_zoo目录下

# 将编译好的.rknn模型文件拷贝到指定的目录下
rknn_model_zoo-v2.3.0-2024-11-08/examples/yolov8/model

# 回到工程主目录下
firefly@firefly:~/Desktop/workspace/rknn_model_zoo-v2.3.0-2024-11-08$ ./build-linux.sh -t rk3588 -a aarch64 -d yolov8

#执行成功后会在install目录下生成可执行文件yolov8

# 运行yolov8可执行文件
firefly@firefly:~/Desktop/workspace/rknn_model_zoo-v2.3.0-2024-11-08/install/rk3588_linux_aarch64/rknn_yolov8_demo$ ./rknn_yolov8_demo model/yolov8.rknn model/bus.jpg

```


# 使用yolov8.py出现错误

```bash
# 原因：在ultraytics里面直接训练的模型，在这里面运行不通过，因为瑞芯微NPU里面的.onnx模型里面进行了剪裁，所以要再进行处理一下
# 所以在Windows环境下面的转化就不可用了，需要重新进行转化。

# 进入到model_zoo目录下
# 激活虚拟环境
source ~/Desktop/rknn_model_zoo-v2.3.0-2024-11-08/examples/yolov8/python/venv/bin/activate

# 在虚拟环境下安装
pip install --upgrade pip
pip install ultralytics onnx onnxsim -i https://pypi.tuna.tsinghua.edu.cn/simple

# 遇到版本冲突
# 强制安装 2.4.0 版本，这样既能满足瑞芯微，也能满足 Ultralytics
pip install torch==2.4.0 torchvision==0.19.0 --extra-index-url https://pypi.tuna.tsinghua.edu.cn/simple

# 创建转换脚本,将由官方生成的.pt转化为.onnx
# 绝对路径:~/Desktop/rknn_model_zoo-v2.3.0-2024-11-08/examples/yolov8/python$
touch export_for_rknn.py

import torch
from ultralytics import YOLO

model = YOLO("../model/test_best.pt") 

def forward_for_rknn(self, x):
    z = []
    for i in range(self.nl):
        # 1. 坐标分支：保持原样
        z.append(self.cv2[i](x[i])) 
        # 2. 分类分支：必须加上 .sigmoid() ！！！
        z.append(self.cv3[i](x[i]).sigmoid()) 
    return z

model.model.model[-1].forward = forward_for_rknn.__get__(model.model.model[-1])
model.export(format="onnx", opset=12, simplify=True)

# 更改要转化的.pt模型路径

# 运行
python export_for_rknn.py
# 在同级目录下可以看到同名的.onnx文件

# 运行测试
python yolov8.py --model_path ../model/test_yolov8s.onnx --img_show

# 正常的话结果会出现在终端中 ，在测试脚本里，标签会进行映射成对应的名称，在yolov8.py里面可以修改映射关系

# 将.onnx模型转化为.rknn模型
# 运行脚本
python convert.py ../model/test_yolov8s.onnx rk3588 i8 ../model/test_yolov8s.rknn

# 在model里面会出现.rknn模型


```