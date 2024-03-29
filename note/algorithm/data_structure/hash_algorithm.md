### 哈希算法
#### 常见哈希算法
----------------------------------------------------------------------------------------------------
- 1. 直接定址法
----------------------------------------------------------------------------------------------------
直接定址法是以数据元素关键字k本身或它的线性函数作为它的哈希地址，即：H（k）=k  或 H（k）=a×k+b ； (其中a,b为常数)

例1，有一个人口统计表，记录了从1岁到100岁的人口数目，其中年龄作为关键字，哈希函数取关键字本身，如下表：

| 地址 | A1   | A2   | ……   | A99  | A100 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 年龄 | 1    | 2    | ……   | 99   | 100  |
| 人数 | 980  | 800  | ……   | 495  | 107  |

可以看到，当需要查找某一年龄的人数时，直接查找相应的项即可。如查找99岁的老人数，则直接读出第99项即可。这种哈希函数简单，并且对于不同的关键字不会产生冲突，但可以看出这是一种较为特殊的哈希函数，实际生活中，关键字的元素很少是连续的。用该方法产生的哈希表会造成空间大量的浪费，因此这种方法适应性并不强。
- 2. 数字分析法
----------------------------------------------------------------------------------------------------
数字分析法是取数据元素关键字中某些取值较均匀的数字位作为哈希地址的方法。即当关键字的位数很多时，可以通过对关键字的各位进行分析，丢掉分布不均匀的位，作为哈希值。它只适合于所有关键字值已知的情况。通过分析分布情况把关键字取值区间转化为一个较小的关键字取值区间。

   例2，要构造一个数据元素个数n=80,哈希长度m=100的哈希表。不失一般性，我们这里只给出其中8个关键字进行分析，8个关键字如下所示：

K1=61317602      K2=61326875      K3=62739628      K4=61343634

K5=62706815      K6=62774638      K7=61381262      K8=61394220

分析上述8个关键字可知，关键字从左到右的第1、2、3、6位取值比较集中，不宜作为哈希地址，剩余的第4、5、7、8位取值较均匀，可选取其中的两位作为哈希地址。设选取最后两位作为哈希地址，则这8个关键字的哈希地址分别为：2，75，28，34，15，38，62，20。
- 3. 折叠法
----------------------------------------------------------------------------------------------------
 所谓折叠法是将关键字分割成位数相同的几部分（最后一部分的位数可以不同），然后取这几部分的叠加和（舍去进位），这方法称为折叠法。这种方法适用于关键字位数较多，而且关键字中每一位上数字分布大致均匀的情况。

  折叠法中数位折叠又分为移位叠加和边界叠加两种方法，移位叠加是将分割后是每一部分的最低位对齐，然后相加；边界叠加是从一端向另一端沿分割界来回折叠，然后对齐相加。

例4，当哈希表长为1000时，关键字key=110108331119891，允许的地址空间为三位十进制数，则这两种叠加情况如图（2）：

       移位叠加                                 边界叠加

       8 9 1                                     8 9 1

       1 1 9                                     9 1 1

       3 3 1                                     3 3 1

       1 0 8                                     8 0 1

    +  1 1 0                                   + 1 1 0              

   (1) 5 5 9                                  (3)0 4 4

                 图（2）由折叠法求哈希地址

     用移位叠加得到的哈希地址是559，而用边界叠加所得到的哈希地址是44。如果关键字不是数值而是字符串，则可先转化为数。转化的办法可以用ASCⅡ字符或字符的次序值
- 4. 平方取中法
----------------------------------------------------------------------------------------------------
这是一种常用的哈希函数构造方法。这个方法是先取关键字的平方，然后根据可使用空间的大小，选取平方数是中间几位为哈希地址。

哈希函数 H(key)=“key2的中间几位”因为这种方法的原理是通过取平方扩大差别，平方值的中间几位和这个数的每一位都相关，则对不同的关键字得到的哈希函数值不易产生冲突，由此产生的哈希地址也较为均匀。

例5，若设哈希表长为1000则可取关键字平方值的中间三位，如图（3）所示：

| 关键字 | 关键字的平方 | 哈希函数值 |
| ------ | ------------ | ---------- |
| 1234   | 1522756      | 227        |
| 2143   | 4592449      | 924        |
| 4132   | 17073424     | 734        |
| 3214   | 10329796     | 297        |
- 5. 字符串数值哈希法
----------------------------------------------------------------------------------------------------
在很都情况下关键字是字符串，因此这样对字符串设计Hash函数是一个需要讨论的问题。下列函数是取字符串前10个字符来设计的哈希函数

Int Hash _ char (char *X)

{

  int I ,sum 

  i=0;

  while (i 10 && X[i]) 

  Sum +=X[i++];

  sum%=N;      //N是记录的条数

  }

这种函数把字符串的前10个字符的ASCⅡ值之和对N取摸作为Hash地址，只要N较小，Hash地址将较均匀分布[0，N]区间内，因此这个函数还是可用的。
- 6. 减去法
----------------------------------------------------------------------------------------------------
减去法是数据的键值减去一个特定的数值以求得数据存储的位置。

例7，公司有一百个员工，而员工的编号介于1001到1100，减去法就是员工编号减去1000后即为数据的位置。编号1001员工的数据在数据中的第一笔。编号1002员工的数据在数据中的第二笔…依次类推。从而获得有关员工的所有信息，因为编号1000以前并没有数据，所有员工编号都从1001开始编号。
- 7. 基数转换法
----------------------------------------------------------------------------------------------------
  将十进制数X看作其他进制，比如十三进制，再按照十三进制数转换成十进制数，提取其中若干为作为X的哈希值。一般取大于原来基数的数作为转换的基数，并且两个基数应该是互素的。

例8，Hash(80127429)=(80127429)13=8*137+0*136+1*135+2*134+7*133+4*132+2*131+9=(502432641)10如果取中间三位作为哈希值，得Hash（80127429）=432

 为了获得良好的哈希函数，可以将几种方法联合起来使用，比如先变基，再折叠或平方取中等等，只要散列均匀，就可以随意拼凑。
- 8. 除留余数法
----------------------------------------------------------------------------------------------------
取关键字被某个不大于哈希表表长m的数p除后所得余数为哈希地址，即设定哈希函数为  Hash(key)=key mod p (p≤m)，其中，除数p称作模。

除留余数法不仅可以对关键字直接取模，也可以在折叠、平方取中等运算后取模。对于除留余数法求哈希地址，关键在于模p的选择。使得数据元素集合中每一个关键字通过该哈希函数映射到内存单元的任意地址上的概率相等，从而尽可能减少发生哈希冲突的可能性。

理论研究表明，除留余数法的模p取不大于表长且最接近表长m素数时效果最好，且p最好取1.1n～1.7n之间的一个素数（n为存在的数据元素个数）。例如：当n=7时，p最好取11、13等素数。 又例图(5)：

| 表长m | 8    | 16   | 32   | 64   | 128  | 256  | 512  | 1000 |
| ----- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 模p   | 7    | 13   | 31   | 61   | 127  | 251  | 503  | 997  |

由于除留余数法的地址计算方法简单，而且在许多情况下效果较好
- 9. 随机乘数法
----------------------------------------------------------------------------------------------------
亦称为“乘余取整法”。随机乘数法使用一个随机实数f,0≤f<1,乘积f*k的分数部分在0～1之间，用这个分数部分的值与n（哈希表的长度）相乘，乘积的整数部分就是对应的哈希值，显然这个哈希值落在0～n-1之间。其表达公式为：Hash(k)=「n*(f*k%1)」其中“f*k%1”表示f*k 的小数部分，即f*k%1=f*k-「f*k」[5] ↑

  例10，对下列关键字值集合采用随机乘数法计算哈希值，随机数f=0.103149002 哈希表长度n=100得图(6)：

| k      | f*k         | n*((f*k)的小数部分) | Hash(k) |
| ------ | ----------- | ------------------- | ------- |
| 319426 | 32948.47311 | 47.78411            | 47      |
| 718309 | 74092.85648 | 86.50448            | 86      |
| 629443 | 64926.41727 | 42.14427            | 42      |
| 919697 | 84865.82769 | 83.59669            | 83      |

  此方法的优点是对n的选择不很关键。通常若地址空间为p位就是选n=2p.Knuth对常数f的取法做了仔细的研究，他认为f取任何值都可以，但某些值效果更好。如f=（-1）/2=0.6180329...比较理想
- 10. 伪随机数法
----------------------------------------------------------------------------------------------------
伪随机数法是将利用数据的键值经过随机数法的运算后的结果作为数据存储的位置。其公式如下（a和c为质数）：

Y=（a * Key + c）mod 数组的大小

例12，某公司的某女员工的编号是321547，现该公司共有107个女职工，我们取a=13,c=5则

Y=(13*321547+5)%107

 =(4180111+5)%107

 =54

则取54当作该员工数据存储的位置。

#### 哈希冲突

- [哈希表&哈希冲突](https://www.cnblogs.com/s-b-b/p/6208565.html)
