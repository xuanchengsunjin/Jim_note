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
    
    - [limits库](http://osr600doc.sco.com/en/man/html.C%2B%2Bstd/limits.C%2B%2Bstd.html)
    
    ```C++
      #include<iostream>  
      #include<string>  
      #include <limits>  
      using namespace std;  

      int main()  
      {  
          cout << "type: \t\t" << "************size**************"<< endl;  
          cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);  
          cout << "\t最大值：" << (numeric_limits<bool>::max)();  
          cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;  
          cout << "char: \t\t" << "所占字节数：" << sizeof(char);  
          cout << "\t最大值：" << (numeric_limits<char>::max)();  
          cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;  
          cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);  
          cout << "\t最大值：" << (numeric_limits<signed char>::max)();  
          cout << "type: \t\t" << "************size**************"<< endl;  
          return 0;  
      }
    ``
