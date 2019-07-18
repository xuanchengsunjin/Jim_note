#### 常用语法
----------------------------------------------------------------------------------------------------------------------
- [Shell变量](https://www.runoob.com/linux/linux-shell-variable.html)
```bash
your_name="qinjx"
echo $your_name
echo ${your_name}
```
- [Shell传递参数](https://www.runoob.com/linux/linux-shell-passing-arguments.html)
```bash
echo "Shell 传递参数实例！";
echo "执行的文件名：$0";
echo "第一个参数为：$1";
echo "第二个参数为：$2";
echo "第三个参数为：$3";

$ chmod +x test.sh 
$ ./test.sh 1 2 3
Shell 传递参数实例！
执行的文件名：./test.sh
第一个参数为：1
第二个参数为：2
第三个参数为：3
```

|参数处理 |	说明 |
| --- | --- |
|$#	| 传递到脚本的参数个数|
|$*	 | 以一个单字符串显示所有向脚本传递的参数。|
|$$|脚本运行的当前进程ID号|
|$!|后台运行的最后一个进程的ID号|
|$@|与$*相同，但是使用时加引号，并在引号中返回每个参数。如"$@"用「"」括起来的情况、以"$1" "$2" … "$n" 的形式输出所有参数。|
|$- | 显示Shell使用的当前选项，与set命令功能相同。|
|$?	 | 显示最后命令的退出状态。0表示没有错误，其他任何值表明有错误。|

- [shell数组](https://www.runoob.com/linux/linux-shell-array.html)

```bash
my_array=(A B "C" D)

echo "第一个元素为: ${my_array[0]}"
echo "第二个元素为: ${my_array[1]}"
echo "第三个元素为: ${my_array[2]}"
echo "第四个元素为: ${my_array[3]}"
```

```bash
# 使用@ 或 * 可以获取数组中的所有元素，例如：
my_array[0]=A
my_array[1]=B
my_array[2]=C
my_array[3]=D

echo "数组的元素为: ${my_array[*]}"
echo "数组的元素为: ${my_array[@]}"
```
- [Shell基本运算符](https://www.runoob.com/linux/linux-shell-basic-operators.html)
- [ ] 算术运算符
```bash
a=10
b=20

val=`expr $a + $b`
echo "a + b : $val"

val=`expr $a - $b`
echo "a - b : $val"

val=`expr $a \* $b`
echo "a * b : $val"

val=`expr $b / $a`
echo "b / a : $val"

val=`expr $b % $a`
echo "b % a : $val"

if [ $a == $b ]
then
   echo "a 等于 b"
fi
if [ $a != $b ]
then
   echo "a 不等于 b"
fi
```
- [ ] 关系运算符

|运算符	|说明	|举例|
| --- | --- | --- |
|-eq |	检测两个数是否相等，相等返回 true。|	[ $a -eq $b ] 返回 false。|
|-ne	|检测两个数是否不相等，不相等返回 true。	|[ $a -ne $b ] 返回 true。|
|-gt	|检测左边的数是否大于右边的，如果是，则返回 true。|	[ $a -gt $b ] 返回 false。|
|-lt	|检测左边的数是否小于右边的，如果是，则返回 true。	|[ $a -lt $b ] 返回 true。|
|-ge	|检测左边的数是否大于等于右边的，如果是，则返回 true。	|[ $a -ge $b ] 返回 false。|
|-le	|检测左边的数是否小于等于右边的，如果是，则返回 true。	|[ $a -le $b ] 返回 true。|

 ```bash
 if [ $a -eq $b ]
then
   echo "$a -eq $b : a 等于 b"
else
   echo "$a -eq $b: a 不等于 b"
fi
if [ $a -ne $b ]
then
   echo "$a -ne $b: a 不等于 b"
else
   echo "$a -ne $b : a 等于 b"
fi
 ```
 
 - [ ] 布尔运算符:
 
|运算符|	说明|	举例|
| --- | --- | --- |
|!	|非运算，表达式为 true 则返回 false，否则返回 true。|	[ ! false ] 返回 true。|
|-o	|或运算，有一个表达式为 true 则返回 true。|	[ $a -lt 20 -o $b -gt 100 ] 返回 true。||
|-a	|与运算，两个表达式都为 true 才返回 true。|	[ $a -lt 20 -a $b -gt 100 ] 返回 false。|
 
```bash
a=10
b=20

if [ $a != $b ]
then
   echo "$a != $b : a 不等于 b"
else
   echo "$a == $b: a 等于 b"
fi
```

- [ ] 逻辑运算符:

|运算符	|说明	|举例|
| --- | --- | --- |
|&&	|逻辑的 AND|	[[ $a -lt 100 && $b -gt 100 ]] 返回 false|
| &#124;&#124; |逻辑的 OR	|[[ $a -lt 100 &#124;&#124; $b -gt 100 ]] 返回 true|

- [ ] 文件测试运算符:

- [echo命令](https://www.runoob.com/linux/linux-shell-echo.html)
- [printf命令](https://www.runoob.com/linux/linux-shell-printf.html)
- [test命令](https://www.runoob.com/linux/linux-shell-test.html)

```bash
num1=100
num2=100
if test $[num1] -eq $[num2]
then
    echo '两个数相等！'
else
    echo '两个数不相等！'
fi
```
- [Shell流程控制](https://www.runoob.com/linux/linux-shell-process-control.html)

```bash
# if语句
if condition
then
    command1 
    command2
    ...
    commandN 
fi

# if-else语句
if condition
then
    command1 
    command2
    ...
    commandN
else
    command
fi

# if-elseif-else语句
if condition1
then
    command1
elif condition2 
then 
    command2
else
    commandN
fi

# for循环
for var in item1 item2 ... itemN
do
    command1
    command2
    ...
    commandN
done

# while循环
int=1
while(( $int<=5 ))
do
    echo $int
    let "int++"
done

while true
do
    command
done

# do-while循环
until [ ! $a -lt 10 ]
do
   echo $a
   a=`expr $a + 1`
done

# switch-case语句
case 值 in
模式1)
    command1
    command2
    ...
    commandN
    ;;
模式2）
    command1
    command2
    ...
    commandN
    ;;
esac
```

- [Shell函数](https://www.runoob.com/linux/linux-shell-func.html)
- [Shell输入/输出重定向](https://www.runoob.com/linux/linux-shell-io-redirections.html)
- [文件包含](https://www.runoob.com/linux/linux-shell-include-file.html)

#### 实践
------------------------------------------------------------------------------------------------------------

- [ ] 日志解析
>  取当前时间10分钟内的日志数据
```bash
# 生成当日日期格式字符串
datePath=`date +%Y/%m/%d`
# 生成时间格式字符串
HOURDB=`date +%Y-%m-%d" "%H:%M`
# 截取除分钟个位的字符串
HOURDB=${HOURDB:0:15}

error=`cat /data/backend/$datePath/127.0.0.1/5004/* | grep "$HOURDB" | grep "xxxxx" | wc -l`
```
> 取昨天的日志数据
```bash
# 生成昨日日期格式字符串
datePath=`date -d "yesterday" +%Y-%m-%d`

error=`cat /data/backend/$datePath/127.0.0.1/5002/* | grep "xxxxxx" | wc -l`
```

#### 详解
------------------------------------------------------------------------------------------------------------
- [ ] 字符串截取

|格式 |	说明|
| --- | --- |
|${string: start :length}|	从 string 字符串的左边第 start 个字符开始，向右截取 length 个字符。|
|${string: start}	|从 string 字符串的左边第 start 个字符开始截取，直到最后。|
|${string: 0-start :length}|	从 string 字符串的右边第 start 个字符开始，向右截取 length 个字符。|
|${string: 0-start}|	从 string 字符串的右边第 start 个字符开始截取，直到最后。|
|${string#*chars}	|从 string 字符串第一次出现 *chars 的位置开始，截取 *chars 右边的所有字符。|
|${string##*chars}	|从 string 字符串最后一次出现 *chars 的位置开始，截取 *chars 右边的所有字符。|
|${string%*chars}	|从 string 字符串第一次出现 *chars 的位置开始，截取 *chars 左边的所有字符。|
|${string%%*chars}|	从 string 字符串最后一次出现 *chars 的位置开始，截取 *chars 左边的所有字符。|
