#### http头部解析
-----------------------------------------------------------------------------------------------------------------------------
- [content-security-policy](http://www.ruanyifeng.com/blog/2016/09/csp.html)

- [X-Forwarded-For](https://imququ.com/post/x-forwarded-for-header-in-http.html)

- Accept：
> 告诉WEB服务器自己接受什么介质类型，*/*表示任何类型，type/*<br> 
> 表示该类型下的所有子类型，type/sub-type。

- Accept-Charset：
> 浏览器申明自己接收的字符集<br> 

- Accept-Encoding： 
> 浏览器申明自己接收的编码方法，通常指定压缩方法，是否支持压缩，支持什么压缩方法(gzip，deflate)<br> 

- Accept-Language：
> 浏览器申明自己接收的语言<br> 
> 语言跟字符集的区别：中文是语言，中文有多种字符集，比如big5，gb2312，gbk等等。<br>

- Age：
> 当代理服务器用自己缓存的实体去响应请求时，用该头部表明该实体从产生到现在经过多长时间了。<br>

- Authorization：
> 当客户端接收到来自WEB服务器的 WWW-Authenticate 响应时，用该头部来回应自己的身份验证信息给WEB服务器。

- Cache-Control：
> 请求:
- [ ] no-cache(不要缓存的实体，要求现在从WEB服务器去取) 
- [ ] max-age：(只接受Age值小于 max-age 值，并且没有过期的对象)
- [ ] max-stale：(可以接受过去的对象，但是过期时间必须小于 max-stale 值) 
- [ ] min-fresh：(接受其新鲜生命期大于其当前 Age 跟 min-fresh 值之和的缓存对象) 
> 响应：
- [ ] public(可以用 Cached 内容回应任何用户)
- [ ] private(只能用缓存内容回应先前请求该内容的那个用户） 
- [ ] no-cache(可以缓存，但是只有在跟WEB服务器验证了其有效后，才能返回给客户端)
- [ ] max-age：(本响应包含的对象的过期时间) 
- [ ] ALL: no-store(不允许缓存)

- Connection：
> 请求：
- [ ] close(告诉WEB服务器或者代理服务器，在完成本次请求的响应后，断开连接，不要等待本次连接的后续请求了)。 
- [ ] keepalive(告诉WEB服务器或者代理服务器，在完成本次请求的响应后，保持连接，等待本次连接的后续请求)。 
> 响应：
- [ ] close(连接已经关闭）。 
- [ ] keepalive(连接保持着，在等待本次连接的后续请求)。 
- [ ] Keep-Alive：如果浏览器请求保持连接，则该头部表明希望 WEB 服务器保持连接多长时间(秒)。例如：Keep-Alive：300

- Content-Encoding：
> WEB服务器表明自己使用了什么压缩方法(gzip，deflate)压缩响应中的对象。例如：Content-Encoding：gzip<br>

- Content-Language：
> WEB 服务器告诉浏览器自己响应的对象的语言。<br>

- Content-Length： 
> WEB 服务器告诉浏览器自己响应的对象的长度。例如：Content-Length: 26012

- Content-Range： 
> WEB 服务器表明该响应包含的部分对象为整个对象的哪个部分。例如：Content-Range: bytes 21010-47021/47022

- Content-Type： 
> WEB服务器告诉浏览器自己响应的对象的类型。例如：Content-Type：application/xml

- ETag：
> 就是一个对象(比如URL)的标志值，就一个对象而言，比如一个 html 文件，如果被修改了，其 Etag 也会别修改，所以ETag<br> 
> 的作用跟 Last-Modified 的作用差不多，主要供 WEB 服务器判断一个对象是否改变了。比如前一次请求某个 html<br> 
> 文件时，获得了其 ETag，当这次又请求这个文件时，浏览器就会把先前获得的 ETag 值发送给WEB 服务器，然后 WEB 服务器会把这个<br> 
> ETag 跟该文件的当前 ETag 进行对比，然后就知道这个文件有没有改变了。

- Expired：
> WEB服务器表明该实体将在什么时候过期，对于过期了的对象，只有在跟WEB服务器验证了其有效性后，才能用来响应客户请求。是<br> 
> HTTP/1.0 的头部。例如：Expires：Sat, 23 May 2009 10:02:12 GMT

- Host：
> 客户端指定自己想访问的WEB服务器的域名/IP 地址和端口号。例如：Host：rss.sina.com.cn

- If-Match：
> 如果对象的 ETag 没有改变，其实也就意味著对象没有改变，才执行请求的动作。

- If-None-Match：
> 如果对象的 ETag 改变了，其实也就意味著对象也改变了，才执行请求的动作。

- If-Modified-Since：
> 如果请求的对象在该头部指定的时间之后修改了，才执行请求的动作(比如返回对象)，否则返回代码304，告诉浏览器该对象没有修改。<br>
> 例如：If-Modified-Since：Thu,10 Apr 2008 09:14:42 GMT

- If-Unmodified-Since：
> 如果请求的对象在该头部指定的时间之后没修改过，才执行请求的动作(比如返回对象)。

- If-Range：
> 浏览器告诉 WEB服务器，如果我请求的对象没有改变，就把我缺少的部分给我，如果对象改变了，就把整个对象给我。浏览器通过发送请求对象的 ETag 或者<br>
> 自己所知道的最后修改时间给 WEB 服务器，让其判断对象是否改变了。总是跟 Range 头部一起使用。

- Last-Modified：
> WEB服务器认为对象的最后修改时间，比如文件的最后修改时间，动态页面的最后产生时间等等。<br>
> 例如：Last-Modified：Tue, 06 May 2008 02:42:43 GMT

- Location：
> WEB服务器告诉浏览器，试图访问的对象已经被移到别的位置了，到该头部指定的位置去取。<br> 
> 例如：Location http://i0.sinaimg.cn/dy/deco/2008/0528/sina0.gif

- Pramga：
> 主要使用 Pramga: no-cache，相当于 Cache-Control： no-cache。例如：Pragma：no-cache

- Proxy-Authenticate： 
> 代理服务器响应浏览器，要求其提供代理身份验证信息。Proxy-Authorization：浏览器响应代理服务器的身份验证请求，提供自己的身份信息。

- Range：
> 浏览器(比如 Flashget 多线程下载时)告诉 WEB 服务器自己想取对象的哪部分。例如：Range:bytes=1173546-

- Referer：
> 浏览器向 WEB 服务器表明自己是从哪个 网页/URL 获得/点击 当前请求中的网址/URL。例如：Referer：http://www.sina.com/

- Server: 
> WEB服务器表明自己是什么软件及版本等信息。例如：Server：Apache/2.0.61 (Unix)

- User-Agent:
> 浏览器表明自己的身份(是哪种浏览器）。<br> 
> 例如：User-Agent：Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.8.1.14) Gecko/20080404 Firefox/2、0、0、14

- Transfer-Encoding: 
> WEB 服务器表明自己对本响应消息体(不是消息体里面的对象)作了怎样的编码，比如是否分块(chunked)。<br> 
> 例如：Transfer-Encoding:chunked

#### [http缓存机制](https://www.cnblogs.com/chenqf/p/6386163.html)
- 强制缓存规则:
- [ ] 第一次响应:
服务器响应头:
> Cache-Control:(max-age:xxxx,),max-age表示最大资源最大存活时间,单位秒br>
> Expires(http1.0，不建议考虑)

- [ ] 再次请求:
> 浏览器头部包含Last-Modified(表示资源上一次更改时间)<br>
> 服务器根据Last-Modified判断资源是否更改:<br>
> 是:返回200，并返回新的资源，否:返回304<br>

- 对比缓存流程解析
- [ ] 浏览器第一次请求：
<div align="center">
   <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/net/http_cache_request.png" width="500px">
</div><br>
- [ ] 浏览器再次请求：
<div align="center">
   <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/net/http_cache_requesta.png" width="500px">
</div><br>

#### http返回状态码
- 1XX：请求接收成功，需要继续处理

- 2XX：请求接收成功，并且服务端已经进行处理
- [ ] 200：请求已经成功，会返回响应的数据

- 3XX：重定向，即URL发生了改变
- [ ] 301：永久重定向，即URL已经发生了改变
- [ ] 302：临时重定向，即URL只是暂时发生改
- [ ] 304：请求的网页没有发生改变，可以直接从缓存服务器中取资源

- 4XX：请求发生了错误
- [ ] 401：请求需要进行验证
- [ ] 403：页面访问被禁止
- [ ] 404：请求的资源不存在

- 5XX：服务端发生了错误
