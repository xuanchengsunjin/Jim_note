#### 基础
----------------------------------------------------------------------------------------------------------------------
  - [ ] [基本数据类型](https://www.runoob.com/cplusplus/cpp-data-types.html)
    - 类型表:
    
    |类型	|位	|范围|
    | --- | --- | --- |
    |char	|1 个字节	|-128 到 127 或者 0 到 255|
    |unsigned char	|1 个字节	|0 到 255|
    |signed char|	1 个字节	|-128 到 127|
    |int	|4 个字节|	-2147483648 到 2147483647|
    |unsigned int	|4 个字节|	0 到 4294967295|
    |signed int|	4 个字节|	-2147483648 到 2147483647|
    |short int	| 2 个字节|	-32768 到 32767|
    |unsigned short int	|2 个字节|	0 到 65,535|
    |signed short int|	2 个字节|	-32768 到 32767|
    |long int|	8 个字节	|-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807|
    |signed long int|	8 个字节	|-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807||
    |unsigned long int|	8 个字节|	0 to 18,446,744,073,709,551,615|
    |float	|4 个字节	|+/- 3.4e +/- 38 (~7 个数字)||
    |double	|8 个字节	|+/- 1.7e +/- 308 (~15 个数字)|
    |long double	|16 个字节|	+/- 1.7e +/- 308 (~15 个数字)|
    |wchar_t	|2 或 4 个字节|1 个宽字符|
    
    - [limits库](https://en.cppreference.com/w/cpp/types/numeric_limits)
    
    ```C++
      #include <limits>
      #include <iostream>

      int main() 
      {
          std::cout << "type\tlowest()\tmin()\t\tmax()\n\n";

          std::cout << "uchar\t"
                    << +std::numeric_limits<unsigned char>::lowest() << '\t' << '\t'
                    << +std::numeric_limits<unsigned char>::min() << '\t' << '\t'
                    << +std::numeric_limits<unsigned char>::max() << '\n';
          std::cout << "int\t"
                    << std::numeric_limits<int>::lowest() << '\t'
                    << std::numeric_limits<int>::min() << '\t'
                    << std::numeric_limits<int>::max() << '\n';
          std::cout << "float\t"
                    << std::numeric_limits<float>::lowest() << '\t'
                    << std::numeric_limits<float>::min() << '\t'
                    << std::numeric_limits<float>::max() << '\n';
          std::cout << "double\t"
                    << std::numeric_limits<double>::lowest() << '\t'
                    << std::numeric_limits<double>::min() << '\t'
                    << std::numeric_limits<double>::max() << '\n';
      }
    ```
   
#### STL库
---------------------------------------------------------------------------------------------------------------
  ##### 基础
   - [ ] [vector容器](https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html)

  ##### 源码解析
  
##### C++/C扩展
  - [ ] [内存管理](https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/note/C++/common_knowledge/memorary.md)
  - [ ] [指针&引用](https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/note/C++/point_content/point_basic_knowledge.md)
  - [ ] [多级指针](https://github.com/xuanchengsunjin/Jim_note/blob/sandbox/note/C++/point_content/multi_pointer.md)
