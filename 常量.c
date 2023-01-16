//1.const常量
//#include<stdio.h>
//int main()
//{
//	const int num = 5;//const关键字---常属性，定义了这个num其赋值就不能改变。但是这个依然是变量，只是具有了常属性。
//	//5;
//	//3.14;
//	printf("%d\n", num);
//	///num = 10;并不能这对num进行重新赋值，因为num已经具有了常量属性
//	printf("%d\n", num);
//	return 0;
//}
//字面常量就是直接写出来的例如  5；3.14

//数组创建---int arr[10]={0}，{}里的元素个数看[]里面的数字;  int arr[n]={0},除非这个n是 #define定义的标识符常量，或者是const定义的常量
 

//2.#define定义标识符常量
/*#include<stdio.h>
int main()
{
#define num 10//#define---定义的标识符常量，格式就像左边，可以用作局部变量可以用作全局变量
	printf("sum=%d\n", num);
	return 0;
}*/


//3.枚举常量（能够一一列举）       枚举关键字---enum
//#include<stdio.h>
//enum color//声明这个color里面包含的的都有哪些常量，有点像结构体，但是不完全一样，结构体的成员变量都是用 ; 结束的，枚举常量是用 , 结束的
//{
//	red,//没输完常量之前要加  ，  号来隔开。默认第一个值为零，后面的依次加一
//	blue,
//	yellow //yellow的值为2，也可直接赋值yello=7；上面的同样可以            -----枚举常量里面的成员在不赋值的情况下默认是从零开始依次加一的       最后一个成员不用 , 结束
//                                                                   -----如果中间的一个常量赋值了其他数字，那么在这个常量之后，其他的常量是按照这个值加一
//};
//int main()
//{
//	printf("%d\n", yellow);
//	enum color x1 = red;//red，blue，yellow是按顺序排列的，如果有变量赋值了，那么x1（变量）输出的值也为1,其地址也不变             -----里面的是常量，也就是在定义之后并不能改变成员的值
//	enum color x2 = yellow;
//	printf("值为%d\n", x1);
//	printf("%p\n", x1);
//	return 0;
//}

//枚举类型输出的都是以整型或者无符号整型