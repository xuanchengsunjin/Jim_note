### 下载安装

**1. elastic官网** 

[下载链接](https://www.elastic.co/cn/downloads/)

<div align="center"> <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/database/elastic_link.png" width="700px"> </div><br>

```linux

root@server:/opt/# mkdir /opt/ELK
root@server:/opt/# cd /opt/ELK/
root@server:/opt/ELK/# wget https://artifacts.elastic.co/downloads/kibana/kibana-7.2.0-linux-x86_64.tar.gz
root@server:/opt/ELK/ tar -xvf  kibana-7.2.0-linux-x86_64.tar.gz
root@server:/opt/ELK# cd kibana-7.2.0-linux-x86_64/
root@server:/opt/ELK/kibana-7.2.0-linux-x86_64# ls
bin  built_assets  config  data  LICENSE.txt  node  node_modules  NOTICE.txt  optimize  package.json  plugins  README.txt  src  target  webpackShims  x-pack

```

### 配置&启动

> server.port: 5601
> kibana.index: ".kibana"
> server.host: 127.0.0.1
> elasticsearch.hosts: ["http://127.0.0.1:9200"]
> elasticsearch.pingTimeout: 1500
> elasticsearch.requestTimeout: 300000
> elasticsearch.username: "elastic"
> elasticsearch.password: "123456"

```linux

# 后台启动,root用户需要加--allow-root
nohup /opt/ELK/kibana-7.2.0-linux-x86_64/bin/kibana --allow-root &

```
### 访问(http://localhost:5601/)

<div align="center"> <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/tool/kibana_ui.png" width="700px"> </div><br>
