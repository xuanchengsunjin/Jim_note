#### 基础
-------------------------------------------------------------------------
   在Linux系统中,一切设备都看作文件。而每打开一个文件,就有一个代表该打开文件的文件描述符。程序启动时默认打开三个I/O设备文件:标准输入文件stdin,
标准输出文件stdout,标准错误输出文件stderr,分别得到文件描述符0,1,2。

- 文件描述符0：标准输入文件stdin

- 文件描述符1：标准输出文件stdout

- 文件描述符2：标准错误输出文件stderr

#### 编程
--------------------------------------------------------------------------

