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
- [2. 负载均衡]()
