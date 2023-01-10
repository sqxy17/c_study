


//rand()
//需要调用库函数#include<stdlib.h>                    rand()函数，作用是生成一个0-RAND_MAX之间的整数，但是这个生成随机数是一个伪随机，有固定的顺序。
//                                                  RAND_MAX 是一个常量，不能被修改。它的默认值在不同的实现中会有所不同，但是值至少是 32767。

//时间戳：当前计算机的时间-计算机的起始时间（1970.1.1.0:0:0）=(xxxx)秒

//如果想要一个真正的随机数，则需要用 srand()函数来初始化这个起始值。但是这个srand()括号内也需要用到一个会变化的数字，则需要用到时间戳（这是一个会变化的数字）。

//srand(),rand()，用的是同一个头文件。   srand(unsigned int)time()) ------srand（）函数括号里面只能放无符号整型种子

//time_t time(time_t *timer)这个括号里的time_t本质上是一个长整型

//下面是一个猜数字的游戏，运用到了c语言中的随机函数rand（）和srand（）。需要用到头文件#include<stdlib.h>

//time函数，它返回的类型是time-t类型的数字time（）括号里面的参数类型是time_t*timer这种，是一个time_t类型的指针。    time_t本质上是一个长整形

//#include<stdlib.h>
//#include<time.h>
//void game()
//{
//	int x;//随机数
//
//	int y;//自己猜的数
//
//	srand((unsigned int) time(NULL));//rand函数的初始值生成器，会改变rand随机数的第一个值，srand（）的括号里面放的必须是一个整型还得是随机的才会真正的实现随机
//	//                               //所以在里面放置一个会变化的数字就行比如 时间戳，因为时间戳的本质是一个长整型
//	//                              //time()这个函数里面是一个指针，可以为空，有其他用途再说
//	//                               //srand（）函数在这里设置每次启动游戏时都会初始，有可能会造成生成的初始值离得很近所以要放在下面的位置
//
//	
//
//	x= rand()%100+1;//生成一个随机数字，这个随机的数字是0-RAND_MAX之间，RAND_MAX最小值是32767,但是需要用到srand（）函数生成初始值
//	          //如果想要获取范围的数字，那么可以用取余数的形式比如 x=rand()%100 获取的是0-99的数字  x=rand()%1000获取的是0-999的数字
//	
//	/*printf("%d", x);*/
//	here:
//	printf("请输入一个数字：");
//	scanf("%d", &y);
//	if (y > x)
//	{
//		printf("猜大了\n");
//		goto here;
//	}
//	else if (y < x)
//	{
//		printf("猜小了\n");
//		goto here;
//	}
//	else
//		printf("你可真牛逼\n");
//
//}
//
//void menu()
//{
//	printf("-----开始游戏请按：1-----\n");
//	printf("-----结束游戏请按：2-----\n");
//}
//
//#include<stdio.h>
//int main()
//{
//	int choose = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		scanf("%d", &choose);
//		switch (choose)
//		{
//		case 1:
//			game(); break;
//		case 2:
//			printf("结束游戏\n"); break;
//		default:
//			printf("选择错误，重新选择\n"); break;
//		}
//	} while ( choose!=2);
//}
//
//对这个随机数字的优化就是：额外使用定增序号，如下
//static unsigned int m=0;  //每次使用都把这个m++