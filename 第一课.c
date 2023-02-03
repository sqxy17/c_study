/*#include<stdio.h>//std-标准，即standard input output，标准输入输出，这也是一种声明，因为下面调用了printf函数，所以以后用到数学之类的也需要调用库函数
int main()//1  main()主函数，也称为程序的入口，代码不能没有main()函数。并且只有一个.  2  main（）前面的int表示main函数调用返回一个整型值
{
	int a = 3;
	char b1 = 'A';
	float c = 3.15;
	float c1 = 3.16;
	double d = 3.15;         
	double d1 = 3.16;
	printf("%d\n", a);
	printf("%c\n", b1);
	printf("%f\n", c);
	printf("%f\n", c1);
	printf("%lf\n", d);
	printf("%lf\n", d1);
	printf("hello word\n");//print打印 function函数-printf打印函数
	char hz = '我';
	char zm = 'D';
	printf("%d\n", sizeof(hz));
	printf("%d,%c\n", sizeof(zm), zm);
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));

	return 0;

}
//char 字符类型要用单引号包括          单引号引起来的字符代表这个字符的ascll值          双引号引起来的叫做字符串，用int类型的变量接收实际上接收的是这个字符串的地址
//
//%c---显示的是字符类型的数据，比如printf("%c",ch)      %d---打印整形格式，比如printf（"%d",a)       %f---打印的是浮点型数据      %p---以地址的形式打印     %x---打印的是16进制
//
// %lf--打印时表示双精度变量  f的格式是打印单精度变量。想固定的打印出规定的位数，那就>>>%.3f（小数点后保存三位）  这个3就是保留的位数   %u打印出十进制无符号整形的变量值

//%s可以通过地址直接打印字符串，不用通过解引用。也就是说char类型的数组里面的内容可以char arr[];printf("%s",arr);能直接将数组里面的内容全部打印出来
//%s打印字符串额数组中所有元素的原理就是，打印到碰到\0为止             %3s意思是输出3列   %5s是输出5个字符并且是右对齐，  想要左对齐是%-3s  %-5s


//字符串双引号的本质是第一个字符的地址，单引号才是ascll值

 //\t是制表符,和按一下tab的间距是相同的

//
//计算机的单位  bit-比特位  byte-字节  kb  mb  gb  tb  pb	1kb是1024字节，后面都是1024
//
//一个字节就是8个比特位   在二进制中01这就是两位，01010这是五位。
//
//sizeof()函数是检测函数或者变量所占内存，检测出来的是字节数
//
//float内存占了7个有效位（最前面的一位表示正负数）*/

//byte字节      bite位 一个字节等于8位     ------字节是byte   位是bit




//char	1 字节 - 128 到 127         -128就是10000000
// 
//unsigned char	1 字节	0 到 255
// 
//signed char	1 字节 - 128 到 127
// 
//int	（微机中）2 或 （32 64位机器都是）4 字节 - 32, 768 到 32, 767 或 - 2, 147, 483, 648 到 2, 147, 483, 647
// 
//unsigned int	（微机中）2 或（32 64 位机器都是） 4 字节	0 到 65, 535 或 0 到 4, 294, 967, 295
// 
//short	2 字节 - 32, 768 到 32, 767
// 
//unsigned short	2 字节	0 到 65, 535
// 
//long	32位机器是4字节，64位机器是8字节 - 2, 147, 483, 648 到 2, 147, 483, 647
// 
//unsigned long	4 字节	0 到 4, 294, 967, 295
// 
//float	4 字节	1.2E-38 到 3.4E+38	6 位有效小数位
// 
//double	8 字节	2.3E-308 到 1.7E+308	15 位有效小数位
// 
//long double	16 字节	3.4E-4932 到 1.1E+4932	19 位有效位

//0x代表着16进制的数字

//记得在牛客网刷题

//%3d是C语言中格式化输出字符，代表的意思是指的输出3个字符长度的整数。     %3s就代表输出的是字符串。


// 可以在“%”和字母之间插进数字表示最大场宽。

// 例：%5d表示输出5位整型数，不够5位右对齐。

// 而在"%-3d"中，-号表示对齐方式，即左对齐。如果是+号或者不写，表示右对齐。

// %9s表示输出9个字符的字符串，不够9个字符右对齐。如果字符串的长度、或整型数位数超过说明的场宽，将按其实际长度输出。

// %8.2f表示输出场宽为8的浮点数，其中小数位为2，整数位为5，小数点占一位，不够8位右对齐。

//右对齐就是右边占满，左边不够的用空格补齐。          左对齐是右边不够的补空格。         正数是右对齐，负数是左对齐
//实际上

// 但对浮点数，若整数部分位数超过了说明的整数位宽度，将按实际整数位输出；若小数部分位数超过了说明的小数位宽度，则按说明的宽度以四舍五入输出。

//2、%ms。
//输出字符串占m列，如果字符串本身长度超过m，则可以超过m列，全数输出；如果字符串小于m，则左补空格。

//3、%-ms。
//输出字符串占m列，如果字符串小于m，则字符串靠左，右补空格。

//4、%m.ns。     ---右对齐m位，但是只取字符串左边的n个字符，将这n个字符进行右对齐不够依然用哦空格进行补齐
//5、-%m.ns。    ----左对齐m位，取字符串左面的n个字符，不够右侧补空格。


//补充：0.0还是0

