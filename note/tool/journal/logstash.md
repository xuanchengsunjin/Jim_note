### 下载安装

**1. elastic官网** 

[下载链接](https://www.elastic.co/cn/downloads/)

<div align="center"> <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/database/elastic_link.png" width="700px"> </div><br>

```linux

root@server:/opt/# mkdir /opt/ELK
root@server:/opt/# cd /opt/ELK/
root@server:/opt/ELK/# wget https://artifacts.elastic.co/downloads/logstash/logstash-7.2.0.tar.gz
root@server:/opt/ELK/ tar -xvf  logstash/logstash-7.2.0.tar.gz
root@server:/opt/ELK# cd logstash-7.2.0/
root@server:/opt/ELK/logstash-7.2.0# ls
root@server:/opt/ELK/logstash-7.2.0# ls
bin  config  CONTRIBUTORS  data  Gemfile  Gemfile.lock  lib  LICENSE.txt  logstash-core  logstash-core-plugin-api  modules  NOTICE.TXT  tools  vendor  x-pack

```

### 插件

- [logstash插件](https://blog.csdn.net/sinat_35930259/article/details/81052139)

### 配置

- /opt/ELK/logstash-7.2.0/config/logstash_xt.json

```javascript

input
{
    file {
        path => "/data/log/*"
    }
}

filter
{
    #grok正则表达式，匹配message中的字段内容,可使用https://grokdebug.herokuapp.com/在线工具先进行测试
    grok
    {
        match =>
        {
            "message" => "%{NOTSPACE:remote_addr} %{TIMESTAMP_ISO8601:time_iso8601} %{NUMBER:msec} [\S\[0-9a-z;]*%{NUMBER:request_time}(\S\[0m)? %{NUMBER:request_length} %{NUMBER:connection} %{NUMBER:connection_requests} (?:%{URIPATH:uri}|-) \"%{WORD:method} %{URIPATH}(?:%{URIPARAM:param}|-)? %{WORD:procotol}/%{NUMBER:http_version}\" [\S\[0-9a-z;]*%{NUMBER:status}(\S\[0m)? %{NUMBER:body_bytes_sent} (?:%{NUMBER:sent_http_X_IS_Error_Code}|-) %{QS:sent_http_X_IS_Error_Msg} %{QS:http_referer} %{QS:http_user_agent} \"(?:(?:%{IP}[ ]*,[ ]*|-)*%{IP:http_x_forwarded_for}|-)\" %{QS:http_x_is_ip} (?:%{URIHOST:http_host}|[\S\[0-9a-z;]*) (?:%{URIHOST:upstream_addr}|-) (?:%{NUMBER:upstream_response_time}|-) (?:%{NUMBER:upstream_status}|-) \"(?:%{IP:http_x_is_client_ip}|-)\""
        }
    }

    if "_grokparsefailure" not in [tags]
    {
        if [http_x_is_client_ip]{
            mutate{
                update => { "remote_addr" => "%{http_x_is_client_ip}" }
            }
        }


        #geoip配置主要是实现IP到地址的转换
        #geoip
        #{
        #    source => "remote_addr"
        #    target => "geoip1"
        #    database => "/opt/logstash-2.3.4/etc/GeoLiteCity.dat"
        #    add_field => ["[geoip][location]","%{[geoip1][longitude]}"]
        #    add_field => ["[geoip][location]","%{[geoip1][latitude]}"]
        #}

        #mutate可过滤相应的字段，对字段进行设置
        mutate
        {
            remove_field => ["message", "http_x_forwarded_for", "http_x_is_client_ip"]
            remove_field => ["path", "host", "msec", "request_length", "method", "procotol", "geoip1", "port"]
            remove_field => ["http_version", "sent_http_X_IS_Error_Msg", "http_referer", "http_x_is_ip"]
            remove_field => ["body_bytes_sent", "sent_http_X_IS_Error_Code", "upstream_addr", "upstream_response_time", "upstream_status"]
            convert => ["[geoip][location]","float"]
            convert => ["request_time","float"]
            convert => ["connection_requests","integer"]
            convert => ["connection","integer"]
            convert => ["status","integer"]
            gsub => ["uri", "/search/CCAppService/", "/CCAppService/"]
            gsub => ["http_user_agent", ".*[bB]aidu.*", "BaiduSpider"]
            gsub => ["http_user_agent", ".*PROJECT_UA.*", "BaiduSpider"]
            gsub => ["http_user_agent", ".*[aA]ndroid.*", "android"]
            gsub => ["http_user_agent", ".*iOS.*", "iOS"]
            gsub => ["http_user_agent", ".*iPhone.*", "iOS"]
            gsub => ["http_user_agent", ".*Darwin.*", "iOS"]
            gsub => ["http_user_agent", ".*okhttp.*", "okhttp"]
            gsub => ["http_user_agent", ".*mobile.*", "mobile"]
            gsub => ["http_user_agent", ".*PC.*", "PC"]
            gsub => ["http_user_agent", ".*[wW]indows.*", "windows"]
        }
    }
}

output
{
    if "_grokparsefailure" not in [tags]
    {
        elasticsearch  #输出到elasticsearch中，index为索引名称，在kibana界面settings时应与此对应。
        {
            hosts => "127.0.0.1:9200"
            index => "logstash-xt-%{+YYYY.MM.dd}"
        }
        #stdout
        #{
        #    codec=> rubydebug
        #}
    }

    if "_grokparsefailure" in [tags]
    {
        elasticsearch
        {
            hosts => "127.0.0.1:9200"
            index => "errorlog-search"
            #user => "elastic"
            #password => "123456"
        }
        stdout  #输出到命令行中
        {
           codec=> rubydebug
        }
    }
}

```