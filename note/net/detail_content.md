#### 1.获取客户端真实ip
```lua
_util.get_ip = function()
	local x_is_ip = ngx.req.get_headers()["X-IS-CLIENT-IP"]
	if x_is_ip then
		return x_is_ip
	end
    if ngx.var.http_x_forwarded_for then
        return string.match(ngx.var.http_x_forwarded_for..",", "[%d%.]+")
    end
    return ngx.req.get_headers()["X-Real-IP"] or ngx.var.remote_addr or ""
end
```
- [ ] 优先级最高的是X-IS-CLIENT-IP头部
- [ ] 其次是X-Forwarded-For头部,例如nginx的配置( proxy_set_header   X-Forwarded-For  $proxy_add_x_forwarded_for;)
- [ ] 最后是X-Real-IP头部,例如nginx的配置(proxy_set_header   X-Real-IP        $remote_addr;)

