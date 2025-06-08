# GitHub教程
## 1、拉取仓库文件到本地
### 1.1、拉取整个仓库
```
#使用git进行拉取
1.进入特定的文件夹
2.打开git
3.初始化文件夹
4.进行拉取

#指令
git init
git clone +仓库HTTPS/SSH网址
```
#### 现象:
![1.1、拉取整个仓库](.//pictures/1.1.png)
## 2、上传本地文件到仓库
### 2.1、首次上传
```
#使用git进行上传
1、建立本地文件夹进行对目标仓库进行拉取
2、将要上传的文件复制到此目录下
3、输入指令进行上传

#指令操作
git remote add origin <远程仓库URL>//关联远程仓库
git add .//加载全部文件
git add +文件名/   //加载单个文件
git commit -m "(对文件进行的修改或者介绍)" 
git push origin master

git branch//查看分支情况，带*的为主分支
```
#### 现象：
![2.1、上传本地文件](.//pictures/2.1.png)

