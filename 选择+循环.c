//1.选择
//#include<stdio.h>
//int main()
//{
//	int num = 0;
//	printf("请问你是否要学习？\n是请按1，不是请按2：\n请输入：");
//	scanf_s("%d", &num);
//	if (num == 1)//if语句后面的括号没有分号，但是下面的语句有         0表示假，非零表示真
//		printf("明智的选择");
//	else//else是和未匹配的最近的if相搭配
//		printf("等着进厂拧螺丝吧");
//	return 0;
//	
//}


//
//2.循环         continue只能在循环语句中使用，并且continue运行后是结束循环体内的}之前，continue之后的所有语句   continue；.....},直到碰到循环体的大括号
                 //也就是continue使用后，其后面的语句都不在使用，直到碰见循环体的大括号
// 
// 
// 2.1    while循环
//#include<stdio.h>
//int main()
//{
//	int n = 0, sum = 0;
//	while (n < 101)//while括号里的是循环的条件，  循环的内容放在大括号里---“{}”      while()括号里的内容只要是真---非0，就是能判断成功
//	{
//		sum = sum + n;
//		n++;//n=n+1
//	}
//	printf("%d", sum);
//	return 0;
//}

//2.2    for循环
//#include<stdio.h>
//int main()
//{
//	//for (;;)//这种括号内没条件的for循环会永远循环下去,for循环中的判断条件是恒为正。  注意，如果判断条件是数字0，或者是赋值为0，这个判断会被认定为假，不去循环
//	//{
//	//	printf("shdjasd")
//	//}
//	int sum = 0;
//	for (int i = 0; i < 101; i++)//for(init;condition;increment)----init首先会被执行且只执行一次，这里可以声明初始化变量，也可以不写任何语句      执行完init就会执行conditon（条件）
//								//不满足条件就会执行for语句下面的其他语句，如果满足条件就会执行循环体           执行完循环体就会执行increment        具体看例子
//	{
//		sum += i;
//	}
//	printf("%d", sum);
//	return 0;
//}






//2.2   for循环中判断语句可以有两个变量支持，例如下面
//#include<stdio.h>
//int main()
//{
//	int x, y;
//	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++);
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}
//补充：在for循环中如果不满足判断条件了则不会进行for循环中大括号中的内容了，如for（int i=1;i<5;i++）则会在i等于4最后一次运行下面的内容，然后i++
//补充：在for循环中间的判别式，只有条件为真的时候才会执行下面的语句







//2.3  do....while循环
//#include<stdio.h>
//int main()
//{
//	int i = 1, sum = 0;
//	do
//	{
//		sum = sum + i;
//		i++;
//	} while (i < 101);//这个是条件，在条件执行前循环会执行一次。  do后面没有分号，分号在这里
//	printf("这个sum=%d", sum);
//	return 0;
//}

//2.4 goto循环
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int sum = 0;
//zheli:    //跳到这里，注意使用的是“：”
//	a++;
//	sum = sum + a;
//	if (sum <100)
//	{
//		goto zheli;
//	}
//	printf("%d", sum);
//	return 0;
//}

//break语句只能用于for和switch语句中，在i语句中不能使用，因为if不是循环语句，所以不能用break结束，但是被套在循环里面就可以用

