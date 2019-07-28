#### 五种通信方式:
-----------------------------------------------------------------------------------------
- 1.管道：速度慢，容量有限，只有父子进程能通讯    

- 2.FIFO：任何进程间都能通讯，但速度慢    

- 3.消息队列：容量受到系统限制，且要注意第一次读的时候，要考虑上一次没有读完数据的问题    

- 4.信号量：不能传递复杂消息，只能用来同步    

- 5.共享内存区：能够很容易控制容量，速度快，但要保持同步，比如一个进程在写的时候，另一个进程要注意读写的问题，相当于线程中的线程安全，当然，共享内存区同样可以用作线程间通讯，不过没这个必要，线程间本来就已经共享了同一进程内的一块内存

#### 编程实践
---------------------------------------------------------------------------------------
- [ ] 管道
  > 管道，通常指无名管道，是 UNIX 系统IPC最古老的形式。<br>
  - 特点：
  > 它是半双工的（即数据只能在一个方向上流动），具有固定的读端和写端。<br>
  > 它只能用于具有亲缘关系的进程之间的通信（也是父子进程或者兄弟进程之间）。<br>
  > 它可以看成是一种特殊的文件，对于它的读写也可以使用普通的read、write 等函数。但是它不是普通的文件，并不属于其他任何文件系统，并且只存在于内存中。
  <div align="center">
    <img src="https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/resource/img/operating_system/pipe_linux.png" width="300px">
  </div>
  
  ```C++
    #include<stdio.h>
    #include<unistd.h>

    int main()
    {
        int fd[2];  // 两个文件描述符
        pid_t pid;
        char buff[20];

        if(pipe(fd) < 0)  // 创建管道
            printf("Create Pipe Error!\n");

        if((pid = fork()) < 0)  // 创建子进程
            printf("Fork Error!\n");
        else if(pid > 0)  // 父进程
        {
            close(fd[0]); // 关闭读端
            write(fd[1], "hello world\n", 12);
        }
        else
        {
            close(fd[1]); // 关闭写端
            read(fd[0], buff, 20);
            printf("%s", buff);
        }

        return 0;
    }
  ```
  
 - [ ] FIFO
 > FIFO，也称为命名管道，它是一种文件类型。<br>
 
 - 特点
 > FIFO可以在无关的进程之间交换数据，与无名管道不同。<br>
 > FIFO有路径名与之相关联，它以一种特殊设备文件形式存在于文件系统中。
 
 - 原型
 ```C++
  1 #include <sys/stat.h>
  2 // 返回值：成功返回0，出错返回-1
  3 int mkfifo(const char *pathname, mode_t mode);
 ```
 
