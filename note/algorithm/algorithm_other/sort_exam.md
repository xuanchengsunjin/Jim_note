#### 稳定性 & 时间复杂度
----------------------------------------------------------------------------------------------

|   排序算法   |最好时间|平均时间|最坏时间|辅助储存|稳定性|      备注      |
| --- | --- | --- | --- | --- | --- | --- |
|简单选择排序|O(n2)|O(n2)|O(n2)|O(1)|不稳定|n小时较好|
|直接插入排序|O(n)|O(n2)|O(n2)|O(1)|稳定|大部分已有序时较好|
|冒泡排序|O(n)|O(n2)|O(n2)|O(1)|稳定|n小时较好|
|希尔排序|O(n)|O(nlogn)|O(n2) 1<s<2|O(1)|不稳定|s是所选分组|
|快速排序|O(nlogn)|O(nlogn)|O(n2)|O(logn)|不稳定|n大时较好|
|堆排序|O(nlogn)|O(nlogn)|O(nlogn)|O(1)|不稳定|n大时较好|
|归并排序|O(nlogn)|O(nlogn)|O(nlogn)|O(n)|稳定|n大时较好|

#### 试题
----------------------------------------------------------------------------------------------
- 在直接插入排序和快速排序中，若初始数据基本有序，则选用____1 __ 排序；在冒泡排序和堆排序中，若要求数据的 稳定性，则选用 ____2 __ 排序 。
  ```C++
    1.直接插入排序    2.冒泡排序
  ```
- 排序算法的稳定性是指()
  ```bash
    A.经过排序之后,能使值相同的数据保持原顺序中的相对位置不变
    B.经过排序之后,能使值相同的数据保持原顺序中的绝对位置不变
    C.算法的排序性能与被排序元素的数量关系不大
    D.算法的排序性能与被排序元素的数量关系密切
  ```

- 下面给出的四种排序法中（）排序法是不稳定性排序法。
  ```bash
    A.插入
    B.冒泡
    C.归并
    D.堆，希尔排序，快速排序
  ```

- [某顺序表含有6个元素，采用直接插入排序算法进行排序，则最坏情况和最好情况所需比较的次数分别为（）](https://www.nowcoder.com/questionTerminal/ebc825beb1514071a22aec29c8b72041)
  ```bash
    A.15,3
    B.15,5
    C.7,5
    D.7,3
  ```
