### 下载安装

**1. ORACLE官网** 

[下载链接](http://jdk.java.net/12/)

<div align="center"> <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/code/jdk_link.png" width="700px"> </div><br>

- 下载解压
```linux

root@server:/opt# cd /opt
root@server:/opt# wget https://download.java.net/java/GA/jdk12.0.1/69cfe15208a647278a19ef0990eea691/12/GPL/openjdk-12.0.1_linux-x64_bin.tar.gz
root@server:/opt# tar -xvf openjdk-12.0.1_linux-x64_bin.tar.gz
root@server:/opt# cd jdk-12.0.1/
root@server:/opt/jdk-12.0.1# ls
bin  conf  include  jmods  legal  lib  release

```

- 配置环境

```linux

vim /etc/profile.d/dev.sh
# Set Dev Path
JAVA_HOME=/usr/local/java/jdk1.8.0_161/
export JAVA_HOME
 
export PATH=$PATH:$JAVA_HOME/bin
# 生效变量
source /etc/profile.d/dev.sh

```

- 查看jdk版本

```linux

root@server:/opt# java -version

```