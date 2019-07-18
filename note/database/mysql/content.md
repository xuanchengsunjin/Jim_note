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
