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

#HTTPS和SSH的区别：
使用URL可以直接进行克隆
使用SSH协议进行克隆时，要生成SSH密钥，参照2.1
```
#### 现象:
![1.1、拉取整个仓库](.//pictures/1.1.png)
### 1.2、更新本地仓库
```
git pull 

```
### 1.3、拉取仓库特定分支文件
#### 现象：在克隆本地时，只会克隆默认分支，不会克隆其他分支，需要指定分支进行克隆
```
git clone -b 分支名 +仓库HTTPS/SSH网址

git clone -b master git@github.com:5baimian/Raedme_Cource.git

推荐：
git clone -b 分支名 --single-branch +仓库HTTPS/SSH网址

```
#### ![克隆指定分支](.//pictures/1.3.png)


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
![上传本地文件](.//pictures/2.1.1.png)
### 2.2、更改SSH协议
#### 现象：使用git push 上传时会报网络错误
![上传出错](.//pictures/2.1.2.png)
#### HTTPS 推送可能会被网络限制，而 SSH 更稳定
```
#步骤
​​1、生成 SSH 密钥​
ssh-keygen -t ed25519 -C "your_email@example.com"
2、添加 SSH 公钥到 GitHub​
cat ~/.ssh/id_ed25519.pub
3、修改远程仓库 URL 为 SSH​
git remote set-url origin git@github.com:5baimian/Raedme_Cource.git
4、重新推送​
git push origin master
```


### 2.2、git push 时出错
#### 现象：
![上传时出错](.//pictures/2.2.1.png)
#### 解决步骤
```
# 1、ping github.com

正在 Ping github.com [20.205.243.166] 具有 32 字节的数据:
来自 20.205.243.166 的回复: 字节=32 时间=338ms TTL=100
来自 20.205.243.166 的回复: 字节=32 时间=338ms TTL=100
来自 20.205.243.166 的回复: 字节=32 时间=337ms TTL=100
来自 20.205.243.166 的回复: 字节=32 时间=337ms TTL=100

20.205.243.166 的 Ping 统计信息:
    数据包: 已发送 = 4，已接收 = 4，丢失 = 0 (0% 丢失)，
往返行程的估计时间(以毫秒为单位):
    最短 = 337ms，最长 = 338ms，平均 = 337ms

#20.205.243.166 是 GitHub 的服务器 IP（动态变化，正常）
#​​延迟（Latency）​​：平均 ​​337ms​​，属于较高延迟（但能连通）
#​​丢包率​​：​​0% 丢失​​，说明网络连接稳定

#结论：1、​​网络基础连接正常​​：你能成功访问 GitHub 服务器。
       2、​​高延迟可能影响 Git 操作​​：HTTPS 协议对延迟敏感，可能导致 git push 超时或失败
#2、 git remote -v


origin  https://github.com/5baimian/C-CODE.git (fetch)
origin  https://github.com/5baimian/C-CODE.git (push)

#你的本地仓库关联了一个远程仓库，名字是 origin。
#它的 ​​拉取（fetch）​​ 和 ​​推送（push）​​ 地址都是 https://github.com/5baimian/C-CODE.git
#此时采用的是HTTPS,相比之下SSH协议更加稳定

#3、切换到 SSH 协议

git remote set-url origin git@github.com:5baimian/C-CODE.git

#再次push
git push origin master

```

### 3、删除文件
#### 上传时会因为不小心上传其余文件，想要删除掉
```
# 具体操作
  1、将github上文件拉取到本地
  git pull
  2、将不想要的文件在本地删除掉
  3、将更改添加到Git暂存区
     包括：新增的文件（untracked）

           修改过的文件（modified）

	    删除的文件（deleted）
    git add -A

       这是最全面的添加方式，等同于把当前工作区的所有改动都准备好提交。
    4、提交备注
    git commit -m "清理无用文件夹"
    5、推送
    git push origin +特定分支
    6、查看暂存区状态
    git status

  
```

