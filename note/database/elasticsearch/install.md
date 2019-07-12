### 下载安装

**1. elastic官网** 

[下载链接](https://www.elastic.co/cn/downloads/)

<div align="center"> <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/database/elastic_link.png" width="700px"> </div><br>

```linux

root@server:/opt/# mkdir /opt/ELK
root@server:/opt/# cd /opt/ELK/
root@server:/opt/ELK/# wget https://artifacts.elastic.co/downloads/elasticsearch/elasticsearch-7.2.0-linux-x86_64.tar.gz
root@server:/opt/ELK/ tar -xvf  elasticsearch-7.2.0-linux-x86_64.tar.gz
root@server:/opt/ELK/elasticsearch-7.2.0# cd elasticsearch-7.2.0
root@server:/opt/ELK/elasticsearch-7.2.0# ls
bin  config  jdk  lib  LICENSE.txt  logs  modules  NOTICE.txt  plugins  README.textile

```
### 安装java

- 安装教程(https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/note/code/java/install.md)

### linux添加elk用户名&用户组

- root不允许直接启动，所以我们需要新建一个用户来启动es:

```linux

# 以root用户来创建新的用户，groupadd 添加一个用户组
root@server:/opt/ELK/elasticsearch-7.2.0#  groupadd elk
# 添加一个用户，-g是在用户组下 -p是密码
root@server:/opt/ELK/elasticsearch-7.2.0# useradd elk -g elk -p elk
# 进入es的安装目录
root@server:/opt/ELK/elasticsearch-7.2.0# cd ../
# 给用户elk授权
root@server:/opt/ELK# chown -R elk:elk elasticsearch-7.2.0/
# 切换到elk用户
root@server:/opt/ELK# su elk
elk@server:/opt/ELK$ cd elasticsearch-7.2.0

```
### 配置和启动

- 配置

```linux

elk@server:/opt/ELK/elasticsearch-7.2.0$ ls
bin  config  data  jdk  lib  LICENSE.txt  logs  modules  NOTICE.txt  plugins  README.textile
elk@server:/opt/ELK/elasticsearch-7.2.0$ cd config
elk@server:/opt/ELK/elasticsearch-7.2.0/config$ ls
elasticsearch.keystore  elasticsearch.yml  jvm.options  log4j2.properties  role_mapping.yml  roles.yml  users  users_roles
elk@server:/opt/ELK/elasticsearch-7.2.0/config$ vim elasticsearch.yml

```

- 修改配置
- network.host：0.0.0.0 (可以远程访问)
- network.host：指定IP (指定IP访问,可以设置为本地IP)

```linux
cluster.name: my-application
#
# ------------------------------------ Node ------------------------------------
#
# Use a descriptive name for the node:
#
node.name: log_node-1
#
# Add custom attributes to the node:
#
#node.attr.rack: r1
#
# ----------------------------------- Paths ------------------------------------
#
# Path to directory where to store the data (separate multiple locations by comma):
#
path.data: /data/elasticsearch/data
#
# Path to log files:
#
path.logs: /data/elasticsearch/logs
#
# ----------------------------------- Memory -----------------------------------
#
# Lock the memory on startup:
#
#bootstrap.memory_lock: true
#
# Make sure that the heap size is set to about half the memory available
# on the system and that the owner of the process is allowed to use this
# limit.
#
# Elasticsearch performs poorly when the system is swapping the memory.
#
# ---------------------------------- Network -----------------------------------
#
# Set the bind address to a specific IP (IPv4 or IPv6):
#
network.host: 0.0.0.0
#
# Set a custom port for HTTP:
#
http.port: 9200
#
# For more information, consult the network module documentation.
#
# --------------------------------- Discovery ----------------------------------
#
# Pass an initial list of hosts to perform discovery when this node is started:
# The default list of hosts is ["127.0.0.1", "[::1]"]
#
```

- 修改了path.data&path.logs,导致elk用户没有读写权限,启动出现异常

```linux

......
Caused by: java.nio.file.AccessDeniedException: /data
        at sun.nio.fs.UnixException.translateToIOException(UnixException.java:84) ~[?:1.8.0_161]
        at sun.nio.fs.UnixException.rethrowAsIOException(UnixException.java:102) ~[?:1.8.0_161]
        at sun.nio.fs.UnixException.rethrowAsIOException(UnixException.java:107) ~[?:1.8.0_161]
        at sun.nio.fs.UnixFileSystemProvider.createDirectory(UnixFileSystemProvider.java:384) ~[?:1.8.0_161]
        at java.nio.file.Files.createDirectory(Files.java:674) ~[?:1.8.0_161]
        at java.nio.file.Files.createAndCheckIsDirectory(Files.java:781) ~[?:1.8.0_161]
        at java.nio.file.Files.createDirectories(Files.java:767) ~[?:1.8.0_161]
        at org.elasticsearch.bootstrap.Security.ensureDirectoryExists(Security.java:401) ~[elasticsearch-7.2.0.jar:7.2.0]
        at org.elasticsearch.bootstrap.FilePermissionUtils.addDirectoryPath(FilePermissionUtils.java:68) ~[elasticsearch-7.2.0.jar:7.2.0]
        at org.elasticsearch.bootstrap.Security.addFilePermissions(Security.java:291) ~[elasticsearch-7.2.0.jar:7.2.0]
        at org.elasticsearch.bootstrap.Security.createPermissions(Security.java:253) ~[elasticsearch-7.2.0.jar:7.2.0]
        at org.elasticsearch.bootstrap.Security.configure(Security.java:122) ~[elasticsearch-7.2.0.jar:7.2.0]
        at org.elasticsearch.bootstrap.Bootstrap.setup(Bootstrap.java:216) ~[elasticsearch-7.2.0.jar:7.2.0]
        at org.elasticsearch.bootstrap.Bootstrap.init(Bootstrap.java:349) ~[elasticsearch-7.2.0.jar:7.2.0]
        at org.elasticsearch.bootstrap.Elasticsearch.init(Elasticsearch.java:159) ~[elasticsearch-7.2.0.jar:7.2.0]
......

```
- 修改/data/elasticsearch权限

```linux

root@server:/data/elasticsearch# cd ../
# -d参数表示后台运行
root@server:/data# chown -R elk:elk elasticsearch/ -d
root@server:/data# ls -ll
total 4
drwxr-xr-x 4 elk elk 4096 Jul 12 10:45 elasticsearch 

```
- 检查是否运行

```linux

root@server:/data# curl "http://127.0.0.1:9200"
{
  "name" : "log_node-1",
  "cluster_name" : "my-application",
  "cluster_uuid" : "3E21P3tETZeHnZdwAFvDpQ",
  "version" : {
    "number" : "7.2.0",
    "build_flavor" : "default",
    "build_type" : "tar",
    "build_hash" : "508c38a",
    "build_date" : "2019-06-20T15:54:18.811730Z",
    "build_snapshot" : false,
    "lucene_version" : "8.0.0",
    "minimum_wire_compatibility_version" : "6.8.0",
    "minimum_index_compatibility_version" : "6.0.0-beta1"
  },
  "tagline" : "You Know, for Search"
}

```
### 添加用户名和密码认证

- 未完待续
