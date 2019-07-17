#### 队列(排队)

1.　按底层数据结构实现方式分为以下几种:

- 数组队列
  - [ ] [循环队列](https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/note/algorithm/data_structure/circle_queue.md)
  - [ ] 因为数组初始化后长度固定,队列插入元素个数大于数组长度时,需要进行数组扩容,成本太大,需要谨慎考虑,但是循环队列思想值得思考。
- 链表队列
  - [ ] 用链表实现队列,长度变化灵活,应用广泛,但是内存使用比数组队列大。
  - [ ] 实现(单链表):
  ```C++
  
  ```
2.  总结:
  - [ ] 各有优势,应结合具体场景分析使用。
  
3.  使用场景:
  - [ ] [消息队列](https://www.cnblogs.com/LipeiNet/p/9877189.html)
  - [ ] [延迟队列](https://github.com/xuanchengsunjin/Jim_note/edit/sandbox/note/tec_practice/delay_queue.md)
  - [ ] [定时器(优先队列实现)](https://github.com/xuanchengsunjin/Jim_note/edit/sandbox/note/tec_practice/delay_queue.md)
  