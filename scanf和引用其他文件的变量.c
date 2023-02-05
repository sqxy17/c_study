/*#include<stdio.h>
int main()
{
	extern short age;
	int a;
	int b;
	int sum = 0;
	printf("%d\n", age);
	scanf_s("%d%d", &a, &b);
	sum = a + b;
	printf("这个sum=%d", sum);
	return 0;
}
//c语言语法规定，变量要定义在当前代码块的最前面，要不可能会出现错误。

//&是取地址符号，先不管这个a1,a2值是多少，但他们的地址就是在&a1，&a2这里

//要么最前面加上   #pragma warning(disable:4996)   要么把scanf()换成scanf_s()，但是这个只有vs才这样用      要么加#define +提醒的内容

//全局变量的作用域是整个工程，我在这个解决方案内的第一课定义了a=3，如果我想要不定义而去使用，那么就用exten（声明外部符号的函数）进行调用，比如在这里使用
//extern int a;    并且全局变量必须定义在main()函数之前*/

//不但能调用变量，还能调用其他函数

//定义过数组名字后，输入时不用使用地址符号

//scanf遇到换行符 空格 就会停止读取,如果想要强制读取空格那么就可以使用以下方法
//1.scanf（"%[abcdef]"）也可以是a-z这表示26个英文字母，这种表示的是只能输入[]里面的东西，碰到[]之外的内容则会停止
//2.scanf("%[^\n]")这样表示的是只碰到[]中的^后面的内容才会停止，其他不会
//#include<stdio.h>
//int main()
//{
//	char ch[10];
//	scanf("%[^]", ch);
//	for (int i = 0; i <= 9; i++)
//	{
//		if (ch[i] == 0)
//			break;
//		else
//			printf("%c", ch[i]);
//	}
//	return 0;
//}

//补充：scanf以%s的形式向地址输入字符串时，会自动在其末尾补上\0
