### 安装新的yum源
-------------------------------------------------------------------------------------------------------------------------------
- 首先备份/etc/yum.repos.d/CentOS-Base.repo:

```linux
  mv /etc/yum.repos.d/CentOS-Base.repo /etc/yum.repos.d/CentOS-Base.repo.backup
```

- 下载对应版本 repo 文件, 放入 /etc/yum.repos.d/ (操作前请做好相应备份)

- [ ] [CentOS5](http://mirrors.163.com/.help/CentOS5-Base-163.repo)
- [ ] [CentOS6](http://mirrors.163.com/.help/CentOS6-Base-163.repo)
- [ ] [CentOS7](http://mirrors.163.com/.help/CentOS7-Base-163.repo)

```linux
  wget http://mirrors.163.com/.help/CentOS6-Base-163.repo
  mv CentOS6-Base-163.repo CentOS-Base.repo
```

- 运行以下命令生成缓存:
```linux
  yum clean all
  yum makecache
```
- yum makecache失败解决办法:
- [ ] 就是把下载的CentOS7对应的repo文件中的$releasever全部改成对应版本7，并且把不存在的网址的子路径删去即可
- [ ] 修改好后CentOS6-Base-163.repo文件如下：
```linux
# CentOS-Base.repo
#
# The mirror system uses the connecting IP address of the client and the
# update status of each mirror to pick mirrors that are updated to and
# geographically close to the client.  You should use this for CentOS updates
# unless you are manually picking other mirrors.
#
# If the mirrorlist= does not work for you, as a fall back you can try the 
# remarked out baseurl= line instead.
#
#
[base]
name=CentOS-7 - Base - 163.com
#mirrorlist=http://mirrorlist.centos.org/?release=$releasever&arch=$basearch&repo=os
baseurl=http://mirrors.163.com/centos/7/os/$basearch/
gpgcheck=1
gpgkey=http://mirrors.163.com/centos/RPM-GPG-KEY-CentOS-7

#released updates
[updates]
name=CentOS-7 - Updates - 163.com
#mirrorlist=http://mirrorlist.centos.org/?release=$releasever&arch=$basearch&repo=updates
baseurl=http://mirrors.163.com/centos/7/updates/$basearch/
gpgcheck=1
gpgkey=http://mirrors.163.com/centos/RPM-GPG-KEY-CentOS-7

#additional packages that may be useful
[extras]
name=CentOS-7 - Extras - 163.com
#mirrorlist=http://mirrorlist.centos.org/?release=$releasever&arch=$basearch&repo=extras
baseurl=http://mirrors.163.com/centos/7/extras/$basearch/
gpgcheck=1
gpgkey=http://mirrors.163.com/centos/RPM-GPG-KEY-CentOS-7

#additional packages that extend functionality of existing packages
[centosplus]
name=CentOS-7 - Plus - 163.com
baseurl=http://mirrors.163.com/centos/7/centosplus/$basearch/
gpgcheck=1
enabled=0
gpgkey=http://mirrors.163.com/centos/RPM-GPG-KEY-CentOS-7
```
### yum相关指令
--------------------------------------------------------------------------------------------------------------------------------------
- yum 语法
```linux
  yum [options] [command] [package ...]
```
- [ ] options：可选，选项包括-h（帮助），-y（当安装过程提示选择全部为"yes"），-q（不显示安装的过程）等等。
- [ ] command：要进行的操作。
- [ ] package操作的对象。

- [ ] 1.列出所有可更新的软件清单命令：yum check-update
- [ ] 2.更新所有软件命令：yum update
- [ ] 3.仅安装指定的软件命令：yum install <package_name>
- [ ] 4.仅更新指定的软件命令：yum update <package_name>
- [ ] 5.列出所有可安裝的软件清单命令：yum list
- [ ] 6.删除软件包命令：yum remove <package_name>
- [ ] 7.查找软件包 命令：yum search <keyword>
- [ ] 8.清除缓存命令:
> yum clean packages: 清除缓存目录下的软件包
> yum clean headers: 清除缓存目录下的 headers
> yum clean oldheaders: 清除缓存目录下旧的 headers
> yum clean, yum clean all (= yum clean packages; yum clean oldheaders) :清除缓存目录下的软件包及旧的headers
