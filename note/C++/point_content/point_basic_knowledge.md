#### C指针 & C++引用 & Java引用区别
--------------------------------------------------------------------------------------------------

#### [指针基础](https://www.runoob.com/cprogramming/c-pointers.html)
--------------------------------------------------------------------------------------------------
  - [ ] 结构体指针(http://c.biancheng.net/view/246.html)
  

#### 指针扩展
--------------------------------------------------------------------------------------------------
  - [ ] [const修饰指针](https://www.cnblogs.com/xudong-bupt/p/3509567.html)
    - 只有一个const，如果const位于*左侧，表示指针所指数据是常量，不能通过解引用修改该数据；指针本身是变量，可以指向其他的内存单元。
    - 只有一个const，如果const位于*右侧，表示指针本身是常量，不能指向其他内存地址；指针所指的数据可以通过解引用修改。
    - 两个const，*左右各一个，表示指针和指针所指数据都不能修改。
    ```C++
      #include<iostream>
      using namespace std;
      int main(){
        int a1=3;   ///non-const data
        const int a2=a1;    ///const data

        int * a3 = &a1;   ///non-const data,non-const pointer
        const int * a4 = &a1;   ///const data,non-const pointer
        int * const a5 = &a1;   ///non-const data,const pointer
        int const * const a6 = &a1;   ///const data,const pointer
        const int * const a7 = &a1;   ///const data,const pointer

        return 0;
      }
     ```
     - const修饰指针作函数参数
      > 在实际程序中,指向const的指针被用作函数的参数形式。它作为一个约定来保证:<br>
      > 被传递给函数的实际对象在函数中不会被修改。
      ```C++
      void func_test (const char *c){
      
      }
      ```
      
     - const 修饰函数的返回值
      > 如果返回const data,non-const pointer，返回值也必须赋给const data,non-const pointer。因为指针指向的数据是常量不能修改。
      ```C++
        const int * mallocA(){  ///const data,non-const pointer
          int *a=new int(2);
          return a;
        }

        int main()
        {
            const int *a = mallocA();
            ///int *b = mallocA();  ///编译错误
            return 0;
        }
      ```
     
#### [C++引用基础](https://www.runoob.com/cplusplus/cpp-references.html)
--------------------------------------------------------------------------------------------------

#### C++引用扩展
--------------------------------------------------------------------------------------------------

#### [Java引用](https://github.com/xuanchengsunjin/Jim_note/new/sandbox/note/code/java#Java基础)
--------------------------------------------------------------------------------------------------
