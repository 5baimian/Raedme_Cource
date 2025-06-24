# 单文件g++编译

```cpp
single_cpp
文件夹中包含.cpp文件,不需要CMakeLists.txt配置文件

编译：g++ -g .\hello_world.cpp 
-o hello_world 
结果：生成hello_world.exe文件

解释：
-g：生成调试信息，用于调试程序
.\\hello_world.cpp：要编译的.cpp文件路径
-o hello_world：指定输出文件的名称为hello_world.exe

运行
./hello_world.exe

结果：打印helloworld

```

#多文件g++编译

## 文件结构：
![多文件g++编译文件结构](.//pictures/多文件g++编译文件结构.png)

```cpp
图片中展示的多文件编译方法完全正确且高效，不需要额外配置 CMakeLists.txt 文件。这种直接使用 g++ 编译的方式是 C++ 开发中最基础也最直接的多文件编译方法。

# 编译命令： g++ -g main.cpp src/Calculator.cpp -o calculator.exe

# 解释：
-g：生成调试信息，用于调试程序
main.cpp：要编译的主文件路径，包含main函数
src/Calculator.cpp：要编译的.cpp文件路径，包含Calculator类的实现
-o calculator.exe：指定输出文件的名称为calculator.exe

# 运行
./calculator.exe

# 结果：
打印加法、减法、乘法、除法的结果


```