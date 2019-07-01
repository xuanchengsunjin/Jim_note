<!-- GFM-TOC -->
* [一.安装VScode&配置环境](#一.安装VScode&配置环境)
    * [下载安装](#下载安装)
    * [安装相关插件](#安装相关插件)
    * [安装相关软件](#安装相关软件)
* [二.VScode简单使用](#VScode简单使用)
    * [第一个C++工程](#第一个C++工程)
    * [简单使用g++](#简单使用g++)
* [三.VScode下C++工程编译&调试](#三.VScode下C++工程编译&调试)
    * [简介](#简介)
    * [配置task.json](#配置task.json)
    * [配置launch.json](#配置launch.json)
    * [编译&调试快捷使用](#编译&调试快捷使用)
<!-- GFM-TOC -->

# 一.安装VScode&配置环境

## 下载安装

**1. VScode官网** 

[下载链接](https://code.visualstudio.com/)

<div align="center"> <img src="/resource/img/C++/vscode_link.png" width="900px"> </div><br>

## 安装相关插件

**1. 搜索插件快捷键** 

Ctrl + Shift + x:
- 在搜索框中输入插件名称
- 单击install
<div align="center"> <img src="/resource/img/C++/plagin_vccode.png" width="900px"> </div><br>

**2. 搜安装相关插件** 

在这里我们选择安装C/C++、C++ Intellisense、Code Runner 和Include Autocomplete这四插件

#＃　安装相关软件 

- 1.安装g++/gcc: apt-get install g++ / apt-get install gcc
- 2.安装gdb: apt-get install gdb

# 二.VScode简单使用

## 第一个C++工程

**1. 新建目录** 

- 1:工程名(工程文件夹名)
- 2:工程下新建main.cpp文件
<div align="center"> <img src="/resource/img/C++/vscode_simple_pro.png" width="900px"> </div><br>

**2. 编写main.cpp** 

```C++
#include <iostream>
using namespace std;
 
// main() 是程序开始执行的地方

int main()
{
   cout << "Hello World"; // 输出 Hello World
   return 0;
}
```
## 简单使用g++

- 1:g++编译指令(g++ cpp文件(main.cpp)　-o 指定可执行文件名(main))  （cpp文件可为多个）
- 2:执行main(生成的可执行文件,windows下为main.exe)
- 3:输出结果

<div align="center"> <img src="/resource/img/C++/vscode_simple_pro_run.png" width="900px"> </div><br>

# 三.VScode下C++工程编译&调试

## 简介

**1. 工程目录**

[工程源码链接](https://github.com/xuanchengsunjin/C_ROOKIE)
<div align="center"> <img src="/resource/img/C++/vscode_c_rookie.png" width="900px"> </div><br>

## 配置task.json

## 配置launch.json

## 编译&调试快捷使用
