### Linux指令

+ [文件&目录管理](https://www.runoob.com/linux/linux-file-content-manage.html)
   - ls(列出目录)
     - [ ] -a ：全部的文件，连同隐藏档( 开头为 . 的文件) 一起列出来
     - [ ] -d ：仅列出目录本身，而不是列出目录内的文件数据
     - [ ] -l ：长数据串列出，包含文件的属性与权限等等数据
   - mkdir(创建目录)
     - [ ] -m:指定目录权限(mkdir -m 711 /test1)
     - [ ] -p:递归创建(mkdir -p  /data/test1/test2)
   - rmkdir(删除目录)
     - [ ] -p:递归删除
   - rm(移除文件或目录)
     - [ ] -f ：就是 force 的意思，忽略不存在的文件，不会出现警告信息；
     - [ ] -i ：互动模式，在删除前会询问使用者是否动作
     - [ ] -r ：递归删除啊！最常用在目录的删除了！这是非常危险的选项！！！ 
   - mv(移动文件与目录，或修改名称)
     - [ ] -f ：force 强制的意思，如果目标文件已经存在，不会询问而直接覆盖；
     - [ ] -i ：若目标文件(destination)已经存在时，就会询问是否覆盖！
     - [ ] -u ：若目标文件已经存在，且 source 比较新，才会升级 (update)
   - cp(复制文件或目录)
     - [ ] -p：连同文件的属性一起复制过去，而非使用默认属性(备份常用)；
     - [ ] -r：递归持续复制，用於目录的复制行为；(常用)
     - [ ] i：若目标档(destination)已经存在时，在覆盖时会先询问动作的进行(常用)
   - cd(切换目录)
     - [ ] cd ~(切换当前用户home目录:/home/jim_sun)
     - [ ] cd ../(切换到上一级目录)
     - [ ] cd ../../(切换到上上级目录)
   - pwd(显示目前所在的目录) 
   
+ [用户&用户组管理](https://www.runoob.com/linux/linux-user-manage.html)
   - useradd(添加新的用户账号)
     - [ ] useradd 选项 用户名
     - [ ] -c comment 指定一段注释性描述。
     - [ ] -d 目录 指定用户主目录，如果此目录不存在，则同时使用-m选项，可以创建主目录。
     - [ ] -g 用户组 指定用户所属的用户组。
     - [ ] -G 用户组，用户组 指定用户所属的附加组。
     - [ ] -s Shell文件 指定用户的登录Shell。
     - [ ] -u 用户号 指定用户的用户号，如果同时有-o选项，则可以重复使用其他用户的标识号。
   - userdel(删除用户账号)
     - [ ] userdel 选项 用户名
     - [ ] -r 它的作用是把用户的主目录一起删除 
   - usermod(修改用户账号)
     - [ ] usermod 选项 用户名
   - passwd(用户口令密码管理)
     - [ ] passwd 选项 用户名
     - [ ] -l 锁定口令，即禁用账号。
     - [ ] -u 口令解锁。
     - [ ] -d 使账号无口令。
     - [ ] -f 强迫用户下次登录时修改口令

   - groupadd(增加一个新的用户组)
     - [ ] groupadd 选项 用户组
     - [ ] -g GID 指定新用户组的组标识号（GID）。
     - [ ] -o 一般与-g选项同时使用，表示新用户组的GID可以与系统已有用户组的GID相同。
   - groupdel(删除用户组)
     - [ ] groupdel 用户组
   - groupmod(修改用户组)

+ [磁盘管理](https://www.runoob.com/linux/linux-filesystem.html)

+ 文件编辑工具 
  - [vi/vim](https://www.runoob.com/linux/linux-vim.html)

+ [修改文件属性和属主](https://www.runoob.com/linux/linux-file-attr-permission.html)
  - chgrp(更改文件属组)
    - [ ] chgrp [-R] 属组名 文件名
    - [ ] -R：递归更改文件属组，就是在更改某个目录文件的属组时，如果加上-R的参数，那么该目录下的所有文件的属组都会更改。
  - chown(更改文件属主，也可以同时更改文件属组)
    - [ ] chown [–R] 属主名 文件名
    - [ ] chown [-R] 属主名：属组名 文件名
  - chmod(更改文件9个属性)
    - [ ] r:4
    - [ ] w:2
    - [ ] x:1
    - [ ] xyz : 就是刚刚提到的数字类型的权限属性，为 rwx 属性数值的相加。
    - [ ] -R : 进行递归(recursive)的持续变更，亦即连同次目录下的所有文件都会变更

+ [文件查看](https://www.runoob.com/linux/linux-file-content-manage.html)
  - tail(取出文件后面几行)
    - [ ] -n ：后面接数字，代表显示几行的意思
    - [ ] -f ：表示持续侦测后面所接的档名，要等到按下[ctrl]-c才会结束tail的侦测,实时查看文件内容
  - head(取出文件前面几行)
    - [ ] -n ：后面接数字，代表显示几行的意思
  - [wc(用于计算字数,例如日志文件统计:cat /jornal.txt | wc -l)](https://www.runoob.com/linux/linux-comm-wc.html)  
    - [ ] -c或--bytes或--chars 只显示Bytes数。
    - [ ] -l或--lines 只显示行数。
    - [ ] -w或--words 只显示字数
  - cat(由第一行开始显示文件内容)
  - tac(文件内容从最后一行开始显示)
  - nl(显示行号)
  - more(一页一页翻动)
    - [ ] 空白键 (space)：代表向下翻一页
    - [ ] Enter         ：代表向下翻『一行』
    - [ ] /字串         ：代表在这个显示的内容当中，向下搜寻『字串』这个关键字
    - [ ] :f            ：立刻显示出档名以及目前显示的行数
    - [ ] q             ：代表立刻离开 more ，不再显示该文件内容。
    - [ ] b 或 [ctrl]-b ：代表往回翻页，不过这动作只对文件有用，对管线无用。
  - less(一页一页翻动)
    - [ ] 空白键    ：向下翻动一页
    - [ ] [pagedown]：向下翻动一页
    - [ ] [pageup]  ：向上翻动一页
    - [ ] /字串     ：向下搜寻『字串』的功能
    - [ ] ?字串     ：向上搜寻『字串』的功能
    - [ ] n         ：重复前一个搜寻 (与 / 或 ? 有关！)
    - [ ] N         ：反向的重复前一个搜寻 (与 / 或 ? 有关！)
    - [ ] q         ：离开 less 这个程序

+ 文件查找&搜索工具
    - [grep](https://www.runoob.com/linux/linux-comm-grep.html)
    - [find:指定目录下查找文件](https://www.runoob.com/linux/linux-comm-find.html)
      - [ ] find   path   -option   [   -print ]   [ -exec   -ok   command ]   {} \;
    - [which:在环境变量$PATH设置的目录里查找符合条件的文件](https://www.runoob.com/linux/linux-comm-which.html)
    - [locate](https://www.runoob.com/linux/linux-comm-locate.html)
      - [ ] 查找符合条件的文档，他会去保存文档和目录名称的数据库内，查找合乎范本样式条件的文档或目录
    - locate&find不同:
      - [ ] find 是去硬盘找，locate 只在/var/lib/slocate资料库中找  
+ 进程管理
  - [ps:显示当前进程 (process) 的状态](https://www.runoob.com/linux/linux-comm-ps.html)
    - [ ] [ps -ef|grep](https://www.cnblogs.com/freinds/p/8074651.html)
    - [ ] UID      ：程序被该 UID 所拥有 
    - [ ] PID      ：就是这个程序的 ID 
    - [ ] PPID    ：则是其上级父程序的ID
    - [ ] C          ：CPU使用的资源百分比
    - [ ] STIME ：系统启动时间
    - [ ] TTY     ：登入者的终端机位置
    - [ ] TIME   ：使用掉的CPU时间。
    - [ ] CMD   ：所下达的是什么指令
  - [kill:删除执行中的程序或工作](https://www.runoob.com/linux/linux-comm-kill.html)
    - [ ] kill pid 杀死进程
    - [ ] kill -HUP pid 发送SIGHUP信号，可以使用一下信号
    - [ ] kill -9 pid 彻底杀死进程
    - [ ] kill -l 显示信号

+ 网络管理
    - [ip](https://www.cnblogs.com/diantong/p/9511072.html)
    - [ifconfig:显示或设置网络设备](https://www.runoob.com/linux/linux-comm-ifconfig.html)
    - [iptable:防火墙设置](https://linux.cn/article-10075-1.html)
    - [netstat:用于显示网络状态](https://www.runoob.com/linux/linux-comm-netstat.html)
      - [ ] -a (all)显示所有选项，netstat默认不显示LISTEN相关
      - [ ] -t (tcp)仅显示tcp相关选项
      - [ ] -u (udp)仅显示udp相关选项
      - [ ] 列出所有端口:     netstat -a
      - [ ] 列出所有tcp端口:  netstat -at
      - [ ] 列出所有udp端口:  netstat -au

+ 系统设置
    - [设置环境变量](https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/note/operating_system/linux/profile.md)
    - [export指令](https://www.runoob.com/linux/linux-comm-export.html)
      - [ ] -f 　代表[变量名称]中为函数名称。
      - [ ] -n 　删除指定的变量。变量实际上并未删除，只是不会输出到后续指令的执行环境中。
      - [ ] -p 　列出所有的shell赋予程序的环境变量。
    - [declare命令](https://www.runoob.com/linux/linux-comm-declare.html)
      - [ ] +/- 　"-"可用来指定变量的属性，"+"则是取消变量所设的属性。
      - [ ] -f 　仅显示函数。
      - [ ] r 　将变量设置为只读。
      - [ ] x 　指定的变量会成为环境变量，可供shell以外的程序来使用。
      - [ ] i 　[设置值]可以是数值，字符串或运算式。
