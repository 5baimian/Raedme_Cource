# 为什么要使用CMake编译

```c
使用 CMake 编译的主要目的是为了简化和自动化项目的构建过程，尤其在涉及到多个文件、多个平台、第三方库和复杂的构建配置时，CMake 的优势更加明显。以下是使用 CMake 编译的几个主要原因：

# 跨平台支持
Linux 上的 Makefile

Windows 上的 Visual Studio 项目文件

macOS 上的 Xcode 项目

CMake 提供了一个统一的构建脚本，可以在不同的操作系统和编译器上运行，而不需要修改源代码或构建命令。它帮助开发者避免了不同平台之间的差异化配置问题。

# 自动化构建过程
CMake 允许你通过简单的配置文件（CMakeLists.txt）来自动化整个构建过程。你可以定义：

源文件、头文件

编译选项

需要链接的库

这使得每次构建都变得一致，避免了手动编译时可能出现的错误或遗漏。

# 管理复杂的依赖关系
对于一个大型项目，往往包含多个源文件和第三方库。CMake 可以自动管理这些依赖关系。你可以通过 target_link_libraries() 和 find_package() 等命令指定项目所依赖的库或工具。CMake 会根据配置自动查找并链接这些库。

# 支持不同的构建系统
CMake 支持多种构建系统。你可以选择以下构建系统：

Makefiles（用于类 Unix 系统）

Visual Studio（用于 Windows）

Ninja（更快速的构建工具）

Xcode（用于 macOS）

这意味着你可以在不同的 IDE 和构建系统中使用相同的 CMake 配置文件。


总结：
CMake 是一个强大的构建工具，适用于复杂的多文件项目，尤其是需要跨平台和多种构建系统的项目。

对于 小型单文件项目，确实不需要使用 CMake，直接使用 g++ 编译即可。

如果项目变得复杂，或者需要管理多个依赖、多个平台的构建配置、编译选项等，CMake 是一个非常有用的工具。

简而言之，CMake 的优势在于 自动化 和 跨平台支持，尤其对于复杂项目或多人协作的项目来说，能够显著简化构建过程。
```

## CMake编译

### 单文件和多文件的不同体现在CMakeLists.txt文件中

```c
#使用外部构建的方法：
在文件夹增加CMakeLists.txt文件并进行相关配置
在文件夹里面新建build文件夹
mkdir build
# 在build文件夹中执行以下命令
cd build

#生成Makefile文件
cmake -G "MinGW Makefiles" ..

#编译代码，生成可执行文件
mingw32-make

#执行代码
./hello_world.exe

```