# 调试

## launch.json文件

```json
launch.json 是 ​​Visual Studio Code (VS Code)​​ 中用于配置调试行为的核心文件，它定义了如何启动和调试程序。

#launch.json 的主要功能是：

​​定义调试配置​​：指定调试器类型（如 GDB、LLDB、Python 等）。
​​控制调试环境​​：设置程序路径、命令行参数、工作目录、环境变量等。
​​自动化流程​​：通过 preLaunchTask 在调试前自动执行编译或构建任务。

```

## tasks.json

```json
tasks.json 是 ​​Visual Studio Code (VS Code)​​ 中用于定义 ​​自动化任务​​ 的配置文件，通常位于项目根目录的 .vscode 文件夹中。它主要用于执行编译、构建、测试、清理等操作，并可以与 launch.json 配合，实现 ​​“一键编译+调试”​​ 的工作流。

tasks.json 的核心作用​​
​​自动化执行命令​​（如编译、运行、测试、打包等）。
​​与 launch.json 联动​​，在调试前自动执行编译任务（preLaunchTask）。
​​支持多种任务类型​​（Shell 命令、npm 脚本、Makefile 等）。
​​提供问题匹配​​（自动解析错误信息并显示在 VS Code 的问题面板）。

```

## 一键编译+调试

tasks.json 负责构建​​（如 g++、npm run build）
​​launch.json 负责调试​​（如 GDB、Python）
用 preLaunchTask 串联两者​​，实现一键编译+调试

![launch.json和tasks.json区分](.//pictures/launch.json和tasks.json区分.jpg)
