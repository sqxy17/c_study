//#define _CRT_SECURE_NO_WARNINGS 1
//#include<math.h>
//现在这个函数和add.h的那个头文件一起来表示函数的模块化怎么实现
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int weishu(int x)//测试输入的数字一共含有几位
//{
//	int num1=0;//用来返回位数的
//	int num3;//用来接收没被除尽的整数
//	while(x!=0)
//	{
//		x= (floor(x / 10));//ceil(变量或者数字)：向右取整2.5>>>3   floor(变量):向左取整2.5>>>>2.0      这两个是函数，返回的变量用整形来接收
//		num1 = num1 + 1;
//	}
//	return num1;
//}



//如果其他的源文件想要不经过add.h的头文件声明还要使用add.h里面的函数可以这样
//extern int Add(int x,int y);//这样叫做引用外部函数的声明，这个函数所在的源文件必须和主函数所在的源文件处于同一文件夹下。

//#ifndef __ADD_H__
//#define __ADD_H__
//int add(int x,int y)//避免这个函数被多次的包括，加上这些东西
//{
//    return x+y;
//}
//#endif

//另外一种写法就是
//#pragma once//请注意这里是小写      这种写法也可以很好的避免这里被多次包括编译
//int add(int x,int y)
//{
//    return x+y;
//}



