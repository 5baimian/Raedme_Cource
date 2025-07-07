# 1、打开终端
```
ctrl+alt+T --打开终端

输入sudo apt-get update
初始密码：123456

会报错
test@linux:~$ sudo apt-get update
[sudo] password for test: 
test is not in the sudoers file.  This incident will be reported.

test 不在sudo组中，加入sudo组中

运行
su - root
usermod -aG sudo test 
exit

 su - root会报错

 root@linux:~# Can't open display 

解决方法：##允许 root 访问当前用户的显示（临时方案）

在普通用户（test）下运行：

xhost +SI:localuser:root  # 允许 root 访问当前显示

然后切换到 root 并手动设置 DISPLAY：

su - root
export DISPLAY=:0  # 通常 :0 是默认显示，可用 `echo $DISPLAY` 确认

##永久修复 sudo 权限问题

既然目标是让 test 用户能用 sudo，无需频繁切换 root。请确认：

    test 是否在 sudo 组（groups test 应包含 sudo）。---无需切换root

    /etc/sudoers 是否包含 %sudo ALL=(ALL:ALL) ALL（用 visudo 检查）。

如果已配置但仍无效，尝试：
bash

su - root
echo "test ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/test  # 免密码 sudo（测试用）
chmod 440 /etc/sudoers.d/test
exit

然后重新登录 test，运行 sudo apt-get update

```

# 2、下载VScode
## 注意选择arm64版本

# 3、设置输入法为中文
```
1、检查系统已安装的输入法
im-config -l  # 查看当前输入法框架（IBus/Fcitx）

2、启用 IBus 中文输入法（Ubuntu 默认）

（1）安装中文输入引擎
sudo apt install ibus-libpinyin  # 拼音输入法

(2) 设置 IBus
ibus-setup  # 打开 IBus 配置界面

#在 Input Method 选项卡中，点击 Add，选择 Chinese (LibPinyin) 或 Chinese (SunPinyin)。

#关闭配置窗口。

(3) 重启 IBus
ibus restart


验证：
检查是否安装了中文输入法引擎（如 ibus-libpinyin）：

apt list --installed | grep ibus

检查输入法引擎是否加载

ibus list-engine | grep -i pinyin

正常显示：
libpinyin - Intelligent Pinyin

设置中仍然不显示中文

1. 强制重启 IBus 服务
killall ibus-daemon
ibus-daemon -drx --panel=/usr/lib/ibus/ibus-ui-gtk3 &  # 显式指定面板程序

2. 检查输入法是否被正确激活
gsettings get org.gnome.desktop.input-sources sources

输出：test@linux:~$ gsettings get org.gnome.desktop.input-sources sources
[('xkb', 'us')]
[1]+  Done                    ibus-daemon -drx --panel=/usr/lib/ibus/ibus-ui-gtk3
tes

错误：不显示('ibus', 'libpinyin')

解决方法：
1. 手动添加 IBus 中文输入法到系统输入源
gsettings set org.gnome.desktop.input-sources sources "[('xkb', 'us'), ('ibus', 'libpinyin')]"

2. 立即生效配置
killall ibus-daemon
ibus-daemon -drx --panel=/usr/lib/ibus/ibus-ui-gtk3 &

3. 验证输入源是否添加成功
gsettings get org.gnome.desktop.input-sources sources

正常输出应包含 libpinyin：
[('xkb', 'us'), ('ibus', 'libpinyin')]

重启解决问题，设置中文完成！




```