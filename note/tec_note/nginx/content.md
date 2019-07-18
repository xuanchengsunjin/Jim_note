### [源码分析](https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/note/C++/nginx_content/nginx_content.md)

### 配置解析

- 1. 二级域名配置:
- [ ] 实现功能:根据二级域名进行http请求的转发
```linux
server{
        listen 80;
        server_name kibana.yckz003.top;
        location / {
                more_clear_headers 'content-security-policy';
                proxy_pass http://127.0.0.1:5601;
        }
     }
```
### 模块解析

### 功能分析

- [1. 反向代理](http://wiki.jikexueyuan.com/project/openresty/ngx/reverse_proxy.html)
> 配置举例:
```linux
   ## 2.用户访问 http://ip:port/README.md，则反向代理到
   ##   https://github.com/.../README.md
   location /README.md {
       proxy_redirect     off;
       proxy_set_header   Host             $host;
       proxy_set_header   X-Real-IP        $remote_addr;
       proxy_set_header   X-Forwarded-For  $proxy_add_x_forwarded_for;
       proxy_set_header  X-Real-IP  $remote_addr;
       proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
       
       proxy_pass https://github.com/moonbingbing/openresty-best-practices/blob/master/README.md;
    }
```
- [2. 负载均衡](http://wiki.jikexueyuan.com/project/openresty/ngx/balancer.html)
- [3. 日志配置](http://wiki.jikexueyuan.com/project/openresty/ngx/nginx_log.html)
- [ ] 自定义日志格式:
```linux
log_format  main  escape=none '$remote_addr $time_iso8601 $msec $request_time_format $request_length '
            '$connection $connection_requests $uri "$request" $status_format '
            '$body_bytes_sent $sent_http_X_IS_Error_Code "$sent_http_X_IS_Error_Msg" "$http_referer" '
            '"$http_user_agent" "$http_x_forwarded_for" "$http_x_is_ip" $http_host ';
```
- [ ] 印日志到目录
```linux
worker_processes 1;

pid logs/nginx.pid;
### 错误日志打印
error_log logs/error.log warn;

events {
    worker_connections 3000;
}

http {
   access_log logs/access.log  main;
.....
}
```
- [ ] 打印日志到syslog日志服务器
```linux
## 误日志
error_log syslog:server=127.0.0.1:5204,tag=5001;
http{
...
    log_format  main  escape=none '$remote_addr $time_iso8601 $msec $request_time_format $request_length '
            '$connection $connection_requests $uri "$request" $status_format '
            '$body_bytes_sent $sent_http_X_IS_Error_Code "$sent_http_X_IS_Error_Msg" "$http_referer" '
            '"$http_user_agent" "$http_x_forwarded_for" "$http_x_is_ip" $http_host ';
    ## access日志
    access_log syslog:server=127.0.0.1:5204,facility=local7,tag=5002,severity=info main;
...
}
```
- [ ] 段及其作用：

字段	作用
remoteaddr与http_x_forwarded_for	记录客户端IP地址
$remote_user	记录客户端用户名称
$request	记录请求的URI和HTTP协议
$status	记录请求状态
$body_bytes_sent	发送给客户端的字节数，不包括响应头的大小
$bytes_sent	发送给客户端的总字节数
$connection	连接的序列号
$connection_requests	当前通过一个连接获得的请求数量
$msec	日志写入时间。单位为秒，精度是毫秒
$pipe	如果请求是通过HTTP流水线(pipelined)发送，pipe值为“p”，否则为“.”
$http_referer	记录从哪个页面链接访问过来的
$http_user_agent	记录客户端浏览器相关信息
$request_length	请求的长度（包括请求行，请求头和请求正文）
$request_time	请求处理时间，单位为秒，精度毫秒
$time_iso8601	ISO8601标准格式下的本地时间
$time_local	记录访问时间与时区

### nginx内置变量
