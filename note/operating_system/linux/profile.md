### /etc/profile

> 当一个用户登录Linux系统或使用su -命令切换到另一个用户时，也就是Login shell 启动时，首先要确保执行的启动脚本就是 /etc/profile 。

> 敲黑板：只有Login shell 启动时才会运行 /etc/profile 这个脚本，而Non-login shell 不会调用这个脚本。

> 一些重要的变量就是在这个脚本文件中设置的，含义如下：

> PATH： 预设可执行文件或命令的搜索路径。

> USER: 用户登录时使用的用户名。

> LOGNAME: 其值为$USER。

> HOSTNAME: 所使用的主机名。

> MAIL： 存放用户电子邮件的邮箱（实际上是一个ASCII码文件）。

> HISTSIZE： 历史记录的行数。

> INPUTRC: 存放的是针对键盘热键的信息（也是一个ASCII码文件）。

> 要注意的是在/etc/profile 文件中设置的变量是全局变量。

```linux

if [ "$PS1" ]; then
  if [ "$BASH" ] && [ "$BASH" != "/bin/sh" ]; then
    # The file bash.bashrc already sets the default PS1.
    # PS1='\h:\w\$ '
    if [ -f /etc/bash.bashrc ]; then
      . /etc/bash.bashrc
    fi
  else
    if [ "`id -u`" -eq 0 ]; then
      PS1='# '
    else
      PS1='$ '
    fi
  fi
fi

# The default umask is now handled by pam_umask.
# See pam_umask(8) and /etc/login.defs.

if [ -d /etc/profile.d ]; then
  for i in /etc/profile.d/*.sh; do
    if [ -r $i ]; then
      . $i
    fi
  done
  unset i
fi

```

### /etc/profile.d 目录中的脚本文件

> 在/etc/profile.d 目录中存放的是一些应用程序所需的启动脚本，其中包括了颜色、语言、less、vim及which等命令的一些附加设置。

> 这些脚本文件之所以能够 被自动执行，是因为在/etc/profile 中使用一个for循环语句来调用这些脚本。而这些脚本文件是用来设置一些变量和运行一些初始化过程的。

> 大致介绍一下/etc/profile.d 目录下一些脚本文件中的具体内容。首先，切换到/etc/profile.d 目录，之后使用ls命令列出/etc/profile.d 目录中的所有脚本文件（在这个目录中只有脚本文件）。

### 配置环境变量

```linux

vim /etc/profile.d/test.sh
# 举例：
JAVA_HOME=/usr/local/java/jdk1.8.0_161/
export JAVA_HOME
 
export PATH=$PATH:$JAVA_HOME/bin
# 生效变量
source /etc/profile.d/dev.sh

# 打印变量
echo $JAVA_HOME

```
