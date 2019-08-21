#### 常见知识点
-----------------------------------------------------------------------------------------------------------
- [ ] [FROM_UNIXTIME()函数 & UNIX_TIMESTAMP()函数](https://www.cnblogs.com/haorenergou/p/7927591.html)
    ```sql
    SELECT
    username,
    FROM_UNIXTIME(create_time, "%Y-%m-%d") AS dat
    FROM
    `wp_user`
    GROUP BY 
    dat
    ```

- [ ] [datetime & timestamp](https://www.cnblogs.com/mxwz/p/7520309.html)

    > DEFAULT CURRENT_TIMESTAMP：在创建新记录的时候把这个字段设置为当前时间，但以后修改时，不再刷新它<br>
    > ON UPDATE CURRENT_TIMESTAMP：在创建新记录和修改现有记录的时候都对这个数据列刷新
    ```sql
    Create Table: CREATE TABLE `test` (
    `id` int(11) DEFAULT NULL,
    `hiredate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
    ) ENGINE=InnoDB DEFAULT CHARSET=latin1
    ```
- [ ] LENGTH(str)
    > 以字节为单位<br>
    判断字段是否是数字:
    > 特殊方式:
    ```sql
    select * from tt where length(0+name)=length(name);
    ```
    > 正则表达式方式:
    ```sql
    SELECT * FROM TEST WHERE RESULT REGEXP '(^[0-9].[0-9]$)|(^[0-9]$)';
    ```

- [ ] CHAR_LENGTH()
    > 以字符为单位

- [ ] [正则匹配](https://www.runoob.com/mysql/mysql-regexp.html)
    > 查找name字段中以'st'为开头的所有数据：
    ```sql
    mysql> SELECT name FROM person_tbl WHERE name REGEXP '^st';
    ```
- [ ] [基础题解](https://github.com/CyC2018/CS-Notes/blob/master/notes/Leetcode-Database%20题解.md)

#### 数据类型
-----------------------------------------------------------------

   - [ ] 时间类型
   ```
    MySQL 提供了两种相似的日期时间类型：DATETIME 和 TIMESTAMP。

    1. DATETIME
    能够保存从 1000 年到 9999 年的日期和时间，精度为秒，使用 8 字节的存储空间。

    它与时区无关。

    默认情况下，MySQL 以一种可排序的、无歧义的格式显示 DATETIME 值，例如“2008-01-16 22:37:08”，这是 ANSI 标准定义的日期和时间表示方法。

    2. TIMESTAMP
    和 UNIX 时间戳相同，保存从 1970 年 1 月 1 日午夜（格林威治时间）以来的秒数，使用 4 个字节，只能表示从 1970 年到 2038 年。

    它和时区有关，也就是说一个时间戳在不同的时区所代表的具体时间是不同的。

    MySQL 提供了 FROM_UNIXTIME() 函数把 UNIX 时间戳转换为日期，并提供了 UNIX_TIMESTAMP() 函数把日期转换为 UNIX 时间戳。

    默认情况下，如果插入时没有指定 TIMESTAMP 列的值，会将这个值设置为当前时间。

    应该尽量使用 TIMESTAMP，因为它比 DATETIME 空间效率更高。
   ```
   
   - [ ] [善用mysql中的FROM_UNIXTIME()函数和UNIX_TIMESTAMP()函数](https://www.cnblogs.com/haorenergou/p/7927591.html)
