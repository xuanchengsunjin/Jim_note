#### [linux-网络IO模型](https://blog.csdn.net/qq_31833457/article/details/78504002)
------------------------------------------------------------------------------------------------------------
##### 前言

> 一个输入操作通常包括两个阶段：<br>
- 等待数据准备好
- 从内核向进程复制数据

> 对于一个套接字上的输入操作，第一步通常涉及等待数据从网络中到达。当所等待数据到达时，它被复制到内核中的某个缓冲区。第二步就是把数据从内核缓冲区<br>
> 复制到应用进程缓冲区。

----------------------------------------------------------------------------------------------------------
##### Unix 有五种 I/O 模型：

- [ ] 阻塞I/O(Blocking I/O)
> 应用进程被阻塞，直到数据从内核缓冲区复制到应用进程缓冲区中才返回。<br><br>

> 应该注意到，在阻塞的过程中，其它应用进程还可以执行，因此阻塞不意味着整个操作系统都被阻塞。因为其它应用进程还可以执行，所以不消耗 CPU 时间，<br>
> 这种模型的 CPU 利用率会比较高。<br>
  - 下图中，recvfrom() 用于接收 Socket 传来的数据，并复制到应用进程的缓冲区 buf 中。这里把 recvfrom() 当成系统调用。
  ```C++
    ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);
  ```
  <div align="center">
    <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/net/block_io.png" width="650px">
  </div>
  
- [ ] 阻塞I/O (Non-Blocking I/O)
> 应用进程执行系统调用之后，内核返回一个错误码。应用进程可以继续执行，但是需要不断的执行系统调用来获知 I/O 是否完成，这种方式称为轮询（polling）。<br><br>
> 由于 CPU 要处理更多的系统调用，因此这种模型的 CPU 利用率比较低。
  <div align="center">
    <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/net/no_block_io.png" width="650px">
  </div>
  
- [ ] 信号驱动的I/O (Signal Driven I/O)
> 应用进程使用 sigaction 系统调用，内核立即返回，应用进程可以继续执行，也就是说等待数据阶段应用进程是非阻塞的。内核在数据到达时向应用进程发送<br>
> SIGIO 信号，应用进程收到之后在信号处理程序中调用 recvfrom 将数据从内核复制到应用进程中。<br><br>

> 相比于非阻塞式 I/O 的轮询方式，信号驱动 I/O 的 CPU 利用率更高。
  <div align="center">
    <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/net/signal_io.png" width="650px">
  </div>
  
- [ ] 异步I/O (Asynchrnous I/O)
> 应用进程执行 aio_read 系统调用会立即返回，应用进程可以继续执行，不会被阻塞，内核会在所有操作完成之后向应用进程发送信号。<br><br>

> 异步 I/O 与信号驱动 I/O 的区别在于，异步 I/O 的信号是通知应用进程 I/O 完成，而信号驱动 I/O 的信号是通知应用进程可以开始 I/O。
  <div align="center">
    <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/net/async_io.png" width="650px">
  </div>

- [ ] I/O复用（I/O Multiplexing)
> 使用 select 或者 poll 等待数据，并且可以等待多个套接字中的任何一个变为可读。这一过程会被阻塞，当某一个套接字可读时返回，之后再使用<br>
> recvfrom 把数据从内核复制到进程中。<br><br>

> 它可以让单个进程具有处理多个 I/O 事件的能力。又被称为 Event Driven I/O，即事件驱动 I/O。<br><br>

> 如果一个 Web 服务器没有 I/O 复用，那么每一个 Socket 连接都需要创建一个线程去处理。如果同时有几万个连接，那么就需要创建相同数量的线程。<br>
> 相比于多进程和多线程技术，I/O 复用不需要进程线程创建和切换的开销，系统开销更小。
  <div align="center">
    <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/net/poll_io.png" width="650px">
  </div>
#### [异步&同步 阻塞&非阻塞](https://www.cnblogs.com/Anker/p/5965654.html)
---------------------------------------------------------------------------------------------------------------
