# Windows连接Ubuntu
## 1、将Windows文件通过SSH协议传输至Ubuntu
### 1.1、通过git软件实现
#### 1.1.1、目标是连接到服务器
```
ssh username@hostname

ssh duan@172.26.239.57

#安全退出
exit 
或者ctrl+D
```
##### 现象：
![连接到服务器](.//pictures/1.1.1.png)
#### 1.1.2、目标是传输文件
```
# 上传文件到服务器(此时的服务器就是我们的电脑)
scp nomachine_9.0.188_11_x64.zip duan@172.26.239.57:/home/duan/

```


