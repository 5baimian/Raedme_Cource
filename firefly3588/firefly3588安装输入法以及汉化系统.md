# 汉化系统语言
```bash
# 查看当前系统语言
echo $LANG
#输出：en_US.UTF-8
# 安装语言包
sudo apt update
sudo apt install language-pack-zh-hans
# 更改系统语言设置
 sudo update-locale LANG=zh_CN.UTF-8
# 重启
reboot

#检查是否生效 
echo $LANG


```
# 安装中文输入法
```bash
#安装IBus和拼音输入法引擎
sudo apt update
sudo apt install ibus-pinyin
# 启用IBus输入法框架
ibus-daemon -drx

#在设置里面启用：IBus preference 点击启用
#重启检验生效与否，不重启可能打不出字，直接重启！！！


```

#更改用户登录密码
 ```bash
sudo passwd firefly


```
