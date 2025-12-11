# VSCode使用教程

## 1、开启自动保存

![在设置中开启自动保存](.//pictures/1.png)

## 基础快捷键操作

```c
#按住Alt双击另一个文件实现分屏显示

#F11实现全屏显示（隐藏掉windows状态栏）

```
## windows环境下输出乱码问题
```bash
//查看当前环境下的编码格式
$OutputEncoding.EncodingName
输出：Unicode (UTF-8)

//设置编码格式
$OutputEncoding = [Console]::OutputEncoding = [System.Text.Encoding]::UTF8
//使用UTF-8编码格式进行编译
g++ -finput-charset=UTF-8 -fexec-charset=UTF-8 -o main main.cpp

chcp 65001
输出：Activate code page: 65001
//查看当前编码格式
chcp
输出：Activate code page: 65001
//再运行

```
