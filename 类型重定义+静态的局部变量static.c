//typedef----类型定义-----即类型重定义
//#include<stdio.h>
//int main()
//{
//	typedef unsigned int u_int;//把系统给定的变量名字改变为你自己想要的   格式：typedef 系统给定的关键字 自己设定的名字
//	u_int num = 20;
//	unsigned int num1=21;//虽然改变了名字但是原来的关键字也能
//	printf("%d\n", num);
//	printf("%d\n", num1);
//	return 0;
//}


//static 修饰静态变量
//#include<stdio.h>
//static int num2;//当static修饰的是全局变量，这个全局变量只能用于全局变量内部，即改变的是作用域
//void test()
//{
//	 static int a = 1;//static修饰局部变量，改变的是变量的生命周期，出了这个函数不会销毁内存，会继续保留被修饰变量的值
//	printf("a=%d\n", a);
//	return a;
//}
//int main()
//{
//	int i = 0;
//	int a = 0;
//	while (i < 5)
//	{
//		test();
//		i++;
//	}
//	return 0;}

//#include<stdio.h>
//extern int add(int , int );
//static int num5;//static是将外部链接属性改为内部链接属性
//
//int main()
//{
//	
//	int a = 10;
//	int b = 20;
//	int sum = add(a, b);
//	printf("新sum=%d\n", sum);
//	return 0;
//}

