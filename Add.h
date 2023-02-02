//#ifndef __ADD_H__
//#define __ADD_H__
//int Add(int x, int y);//这个是函数的声明。
//
//#endif
//
//想要调用这个函数只需要调用以这种形式 #include "add.h"来进行调用，此后会将这些代码搬过去使用。
//
//上面的ifndef和define判断有没有函数重复的搬过去代码，节省时间和空间
//
//#ifdef __WEISHU_H__
//#define __WEISHU_H__
//int weishu(int x);
//#endif
//.c结尾的是用来放函数的定义的  ,h结尾的是用来放函数的头文件


//#pragma once//这样就可以避免头文件被重复的1引用
//#include<stdio.h>
//int add(int,int);//声明的时候可以不写参数，就写个类型