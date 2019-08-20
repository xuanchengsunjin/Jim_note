#### Bx树
---------------------------------------------------------------------------------------------

##### 1. B(B-)树

  - [ ] 定义
    ```
       1.定义任意非叶子结点最多只有M个儿子；且M>2；

       2.根结点的儿子数为[2, M]；

       3.除根结点以外的非叶子结点的儿子数为[M/2, M]；

       4.每个结点存放至少M/2-1（取上整）和至多M-1个关键字；（至少2个关键字）

       5.非叶子结点的关键字个数=指向儿子的指针个数-1；

       6.非叶子结点的关键字：K[1], K[2], …, K[M-1]；且K[i] < K[i+1]；

       7.非叶子结点的指针：P[1], P[2], …, P[M]；其中P[1]指向关键字小于K[1]的

           子树，P[M]指向关键字大于K[M-1]的子树，其它P[i]指向关键字属于(K[i-1], K[i])的子树；

       8.所有叶子结点位于同一层；
    ```
    例如:
    <div align="center">
      <img src="https://github.com/xuanchengsunjin/Jim_note/blob/master/resource/img/database/B_tree.JPG" width="400px">
    </div>
    <br>
    
##### 2. B+树

  - [ ] 定义
  ```
    B+树是B-树的变体，也是一种多路搜索树：

       1.其定义基本与B-树同，除了：

       2.非叶子结点的子树指针与关键字个数相同；

       3.非叶子结点的子树指针P[i]，指向关键字值属于[K[i], K[i+1])的子树

         （B-树是开区间）；

       5.为所有叶子结点增加一个链指针；

       6.所有关键字都在叶子结点出现；
  ```
  例如:
  <div align="center">
      <img src="https://github.com/xuanchengsunjin/Jim_note/blob/master/resource/img/database/B+_tree.JPG" width="400px">
  </div>
  <br>
  
##### 3. B*树

  - [ ] 定义
  ```
    是B+树的变体，在B+树的非根和非叶子结点再增加指向兄弟的指针；
    B*树定义了非叶子结点关键字个数至少为(2/3)*M，即块的最低使用率为2/3
    （代替B+树的1/2）；
    B+树的分裂：当一个结点满时，分配一个新的结点，并将原结点中1/2的数据
    复制到新结点，最后在父结点中增加新结点的指针；B+树的分裂只影响原结点和父
    结点，而不会影响兄弟结点，所以它不需要指向兄弟的指针；

    B*树的分裂：当一个结点满时，如果它的下一个兄弟结点未满，那么将一部分
    数据移到兄弟结点中，再在原结点插入关键字，最后修改父结点中兄弟结点的关键字
      （因为兄弟结点的关键字范围改变了）；如果兄弟也满了，则在原结点与兄弟结点之间增加新结点，
    并各复制1/3的数据到新结点，最后在父结点增加新结点的指针；

    所以，B*树分配新结点的概率比B+树要低，空间使用率更高；
  ```
  例如:
  <div align="center">
      <img src="https://github.com/xuanchengsunjin/Jim_note/blob/master/resource/img/database/BB_tree.JPG" width="400px">
  </div>
  <br>
  
#### 性能分析
--------------------------------------------------------------------------------------------------------------------------

##### 如何B树的平衡

  - [ ] [插入分析](https://juejin.im/entry/5b0cb64e518825157476b4a9)
  
    图解:
    <div align="center">
      <img src="https://github.com/xuanchengsunjin/Jim_note/blob/master/resource/img/database/B_insert" width="600px">
    </div>
    <br>
   
    <div align="center">
      <img src="https://github.com/xuanchengsunjin/Jim_note/blob/master/resource/img/database/B_balancea.png" width="600px">
    </div>
    <br>
    <div align="center">
      <img src="https://github.com/xuanchengsunjin/Jim_note/blob/master/resource/img/database/B_balanceb.png" width="600px">
    </div>
    <br>
    <div align="center">
      <img src="https://github.com/xuanchengsunjin/Jim_note/blob/master/resource/img/database/B_balancec.png" width="600px">
    </div>
    <br>
   
##### B&B+树

  ###### B+树的三个优点
  
  - [ ] 层级更低，IO 次数更少
  - [ ] 每次都需要查询到叶子节点，查询性能稳定
  - [ ] 叶子节点形成有序链表，范围查询方便
  
  <div align="center">
      <img src="https://github.com/xuanchengsunjin/Jim_note/blob/master/resource/img/database/B+good.png" width="600px">
  </div>
  <br>
  
#### MySql索引
------------------------------------------------------------------------------------------------------------------------

  - [ ] [mysql索引原理&优化](http://blog.codinglabs.org/articles/theory-of-mysql-index.html)
  - [ ] [Explain使用](https://segmentfault.com/a/1190000008131735)
  - [ ] [基础总结](https://github.com/CyC2018/CS-Notes/blob/master/notes/MySQL.md)
  
