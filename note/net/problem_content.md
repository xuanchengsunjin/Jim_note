### 问题总结
--------------------------------------------------------------------------------------

- 1.kibana
- [ ] 问题描述:
> 打开kibana界面一直在loading
- [ ] 解析:浏览器F12一探究竟
<div align="center"> 
    <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/net/kibana_edage.png" width="600px"> 
</div><br>

- [ ] 确认问题原因:
> CSP策略影响
- [ ] 进一步解析:查看头部信息
<div align="center"> 
    <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/net/kibana_chrome.png" width="600px"> 
</div><br>

- [ ] 初步解决方案:
> 利用nginx反向代理,删除content-security-policy头部信息

- [ ] 配置如下:
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