
// 1.if语句
//#include<stdio.h>
//int main()
//{
//	int age;
//again:
//	printf("请输入一个数字：");
//	scanf("%d", &age);
//	if (12<18)//注意：if后面的判断条件是  括号里面的是否为真，即使与后面程序不相关也是可以执行的。  0是假  非0是真---判断成功返回的是非0值
//	{
//		printf("这是个未成年的吊毛\n");
//		goto again;
//	}
//	else if (age >= 18 && age < 25)
//	{
//		printf("这是一位年轻的吊毛\n");
//		goto again;
//	}
//	else
//	{
//		printf("这是一位老逼登\n	");
//		goto again;
//	}
//	return 0;
//}


//2.switch语句 分支语句  
/*
基本语法如下：  
switch(整型表达式)
{
	语句项;//也就是case语句，具体操作如下
	}*/
//#include<stdio.h>
//int main()
//{
//	int a;
//	again:
//	printf("请输入数字1-7\n");
//	scanf("%d", &a);
//	if (a < 1 || a>7)
//	{
//		goto again;
//	}
//	else
//	{
//		switch (a)//注意：括号里的变量只能是整型  注意：char 类型也可以，因为char在内存里存的是ascll，也是整数常量

//		{//case如果后面没有break；结束语句，那么会把后面的也一起执行下去
//		case 1://case后面跟的也是整型数字，就是算数表达式的结果是整型也可以，并且必须是常量
//			printf("上课，明天星期二"); break;
//		case 2:
//			printf("上课，明天星期三"); break;//continue在这里不适用，
//		case 3:
//			printf("上课，明天星期四"); break;
//		case 4://但是不能是判断大小的判别式，例a>b
//			printf("上课，明天星期五"); break;
//		case 5:
//			printf("上课，明天星期六"); break;
//		case 6:
//			printf("休息，明天星期日"); break;
//		case 7:
//			printf("休息，悲催的一星期又要开始了"); break;
//		}
//	}
//}


//如果碰到case1,2,3,4,5都是一样的，写了case1,2,3,4后，后面的内容可以空着不写
//#include<stdio.h>
//int main()
//{
//	int a=2;
//	int n = a;
//
//		switch (n)
//		{
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//			printf("工作日"); break;
//		case 6:
//		case 7:
//			printf("休息日"); break;
//      default://这个是默认情况，如果输入的不是1-7，就会执行这个   一般是用于处理非法情况，并且这个语句可以放到最上面，没有顺序可言
//                //每个 switch 语句中只能有一个default      如果没有break;不论是case还是default都会执行一遍
//          printf("输入错误");break;
//		}
//	return 0;
//	
//}

//3.do while循环
//#include<stdio.h>
//void game()
//{
//	printf("开始游戏\n");
//}
//
//
//void menu()
//{
//	printf("请选择数字\n1：进行游戏\n0：退出游戏\n");
//}
//
//int main()
//{
//	int input;
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//			menu();
//			case 1:
//				game();
//				break;
//			case 0:
//				printf("退出程序\n");
//				break;
//			default:
//				printf("选择错误\n");
//				break;
//		}
//	} 
//	while (input);
//}

//当判断条件为空时会被假设为真       -----也就是死循环
//对于循环的嵌套则只会终止最内层的循环

//补充：case和do while相搭配挺适合的，把case 0这个选项和while(选择的数字)可构成游戏的进入页面菜单
//      ----输入的是非零数字执行会提示是否进行下一个功能。

//while以及其他判断的条件式当中碰见这种 a=a+10 赋值的，判断的值就是a的值，0是假，非0是真



