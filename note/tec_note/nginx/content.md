### [源码分析](https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/note/C++/nginx_content/nginx_content.md)
------------------------------------------------------------------------------------------------------
### 配置解析
---------------------------------------------------------------------------------------------------------------
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
-----------------------------------------------------------------------------------------------------
- [1. proxy_cache](http://nginx.org/en/docs/http/ngx_http_proxy_module.html#proxy_cache)
        - [ ] [应用:nginx构建静态文件服务](http://wiki.jikexueyuan.com/project/openresty/ngx/static_file.html)

### 基础功能分析
----------------------------------------------------------------------------------------------------
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

        ```linux
        ## 配置实例:
        upstream test.net{
            ip_hash;
            server 192.168.10.13:80;
            server 192.168.10.14:80  down;
            server 192.168.10.15:8009  max_fails=3  fail_timeout=20s;
            server 192.168.10.16:8080;
        }
        server {
            location / {
                proxy_pass  http://test.net;
            }
        }
        ```
<div align="center">
    <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/tec_note/nginx_fuzai.png" width="700px">
</div>

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
        - [ ] 字段及其作用：

   | 字段 | 作用  |
   | ---- | ---- |
   | remoteaddr与http_x_forwarded_for | 记录客户端IP地址   |
   | $remote_user | 记录客户端用户名称  |
   | $request |记录请求的URI和HTTP协议   | 
   | $status  |	记录请求状态   |
   | $body_bytes_sent  |	发送给客户端的字节数，不包括响应头的大小   |
   | $bytes_sent |	发送给客户端的总字节数   |
   | $connection |	连接的序列号   |
   | $connection_requests |	当前通过一个连接获得的请求数量   |
   | $msec | 日志写入时间。单位为秒，精度是毫秒   |
   | $pipe | 如果请求是通过HTTP流水线(pipelined)发送，pipe值为“p”，否则为“.”   |
   | $http_referer	| 记录从哪个页面链接访问过来的   |   
   | $http_user_agent | 记录客户端浏览器相关信息   |   
   | $request_length | 请求的长度（包括请求行，请求头和请求正文）   |
   | $request_time	| 请求处理时间，单位为秒，精度毫秒   |
   | $time_iso8601 | ISO8601标准格式下的本地时间   |
   | $time_local | 记录访问时间与时区   |

### [nginx内置变量](https://www.cnblogs.com/raichen/p/5121262.html)
-----------------------------------------------------------------------------------------------------
        > 内置变量存放在  ngx_http_core_module 模块中,变量的命名方式和apache 服务器变量是一致的。<br>
        > 总而言之，这些变量代表着客户端请求头的内容，例如$http_user_agent, $http_cookie...
| 字段 | 说明  |
        | ---- | ---- |
        |$arg_name|请求中的的参数名，即“?”后面的arg_name=arg_value形式的arg_name|
        |$args|请求中的参数值|
        |$binary_remote_addr|客户端地址的二进制形式, 固定长度为4个字节|
        |$body_bytes_sent|传输给客户端的字节数，响应头不计算在内；这个变量和Apache的mod_log_config模块中的“%B”参数保持兼容|
        |$bytes_sent|传输给客户端的字节数 (1.3.8, 1.2.5)|
        |$connection|TCP连接的序列号 (1.3.8, 1.2.5)|
        |$connection_requests|TCP连接当前的请求数量 (1.3.8, 1.2.5)|
        |$content_length|“Content-Length” 请求头字段|
        |$content_type|“Content-Type” 请求头字段|
        |$cookie_name|cookie名称|
        |$document_root|当前请求的文档根目录或别名|
        |$document_uri|同 $uri|
        |$host|优先级如下：HTTP请求行的主机名>”HOST”请求头字段>符合请求的服务器名|
        |$hostname|主机名|
        |$http_name|匹配任意请求头字段； 变量名中的后半部分“name”可以替换成任意请求头字段...|
        |$https|如果开启了SSL安全模式，值为“on”，否则为空字符串。|
        |$is_args|如果请求中有参数，值为“?”，否则为空字符串。|
        |$limit_rate|用于设置响应的速度限制，详见 limit_rate。|
        |$msec|当前的Unix时间戳 (1.3.9, 1.2.6)|
        |$nginx_version|nginx版本|
        |$pid|工作进程的PID|
        |$pipe|如果请求来自管道通信，值为“p”，否则为“.” (1.3.12, 1.2.7)|
        |$proxy_protocol_addr|获取代理访问服务器的客户端地址，如果是直接访问，该值为空字符串。(1.5.12)|
        |$query_string|同 $args|
        |$realpath_root|当前请求的文档根目录或别名的真实路径，会将所有符号连接转换为真实路径。|
        |$remote_addr|客户端地址|
        |$remote_port|客户端端口|
        |$remote_user|用于HTTP基础认证服务的用户名|
        |$request|代表客户端的请求地址|
        |$request_body|客户端的请求主体此变量可在location中使用，将请求主体通过proxy_pass, fastcgi_pass, uwsgi_pas...|
        |$request_body_file|将客户端请求主体保存在临时文件中。文件处理结束后，此文件需删除...|
        |$request_completion|如果请求成功，值为”OK”，如果请求未完成或者请求不是一个范围请求的最后一部分，则为空。|
        |$request_filename|当前连接请求的文件路径，由root或alias指令与URI请求生成。|
        |$request_length|请求的长度 (包括请求的地址, http请求头和请求主体) (1.3.12, 1.2.7)|
        |$request_method|HTTP请求方法，通常为“GET”或“POST”|
        |$request_time|处理客户端请求使用的时间 (1.3.9, 1.2.6); 从读取客户端的第一个字节开始计时。|
        |$request_uri|这个变量等于包含一些客户端请求参数的原始URI|
        |$scheme|请求使用的Web协议, “http” 或 “https”|
        |$sent_http_name|...|
        |$server_addr|服务器端地址，需要注意的是：为了避免访问linux系统内核，应将ip地址提前设置在配置文件中。|
        |$server_name|服务器名，www.cnphp.info|
        |$server_port|服务器端口|
        |$server_protocol|服务器的HTTP版本, 通常为 “HTTP/1.0” 或 “HTTP/1.1”|
        |$status|HTTP响应代码 (1.3.2, 1.2.2)|
        |$tcpinfo_rtt, $tcpinfo_rttvar, $tcpinfo_snd_cwnd, $tcpinfo_rcv_space|客户端TCP连接的具体信息|
        |$time_iso8601|服务器时间的ISO 8610格式 (1.3.12, 1.2.7)|
        |$time_local|服务器时间（LOG Format 格式） (1.3.12, 1.2.7)|
        |$uri|请求中的当前URI(不带请求参数，参数位于$args)|
        

### 场景应用
------------------------------------------------------------------------------------------------------
- [1. 解决cookie跨域](https://www.cnblogs.com/hujunzheng/p/5744755.html)
        ```linux
         location /web1 {
                    proxy_pass http://web1;
                    proxy_set_header Host  127.0.0.1;
                    proxy_set_header   X-Real-IP        $remote_addr;
                    proxy_set_header   X-Forwarded-For  $proxy_add_x_forwarded_for;

                    proxy_set_header Cookie $http_cookie;
                    log_subrequest on;
                }
        ```

- [2. 解决跨域](https://www.cnblogs.com/morethink/p/6628757.html)
        ```linux
        location / {
            root   html;
            index  index.html index.htm;
            # 配置html以文件方式打开
            if ($request_method = 'POST') {
                  add_header 'Access-Control-Allow-Origin' *;
                  add_header 'Access-Control-Allow-Credentials' 'true';
                  add_header 'Access-Control-Allow-Methods' 'GET, POST, OPTIONS';
                  add_header 'Access-Control-Allow-Headers' 'DNT,X-Mx-ReqToken,Keep-Alive,User-Agent,X-Requested-With,If-Modified-Since,Cache-Control,Content-Type';
              }
            if ($request_method = 'GET') {
                  add_header 'Access-Control-Allow-Origin' *;
                  add_header 'Access-Control-Allow-Credentials' 'true';
                  add_header 'Access-Control-Allow-Methods' 'GET, POST, OPTIONS';
                  add_header 'Access-Control-Allow-Headers' 'DNT,X-Mx-ReqToken,Keep-Alive,User-Agent,X-Requested-With,If-Modified-Since,Cache-Control,Content-Type';
            }
            # 代理到8080端口
            proxy_pass        http://127.0.0.1:8080;

        }
        ```

- [URL重写](http://www.360doc.com/content/13/1205/06/14234135_334577912.shtml)
