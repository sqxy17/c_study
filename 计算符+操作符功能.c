//1."%"在算数中表示求余数  a=5%2;




//2.移位符               ----移动的是数字的二进制的补码
//#include<stdio.h>
//int main()
//{
//	short a = 1;
//	short b,c;
//	b = a << 2;//"<<"--左移位符  ">>"--右移位符   移动的是二进制位a=1即0000000000000001，左移动二位--即00000000000000100，在二进制中表示4.  如果是右移，移几个右边去掉几个，左边加上0   
//	printf("%d\n",b);
//                     //
// 
//	c = a >> 2;
//	printf("%d\n", c);
//	printf("%d\n", sizeof(c));
//	return 0;
//}
//










//3.位操作符  位操作符操作的都是补码，并且操作符号位
// 可以按着&&和||理解，第一个是都真才真（也就是且），第二个是有真即真（也就是或）
//#include<stdio.h>
//int main()
//{
//	位操作符（2进制）     -----这些位操作符操作的都是数字的二进制补码
//	"&" 按位与----下面的进制位上下对齐 ,只有都是1的时候才取“1”   0和0、0和1，都取0           "|"按位或 ，上下对齐，有真取真，无真取0          "^"按位异或----对应的二进制位相同则为0，相异则为1
//	int a = 3;//0011                                                                                                             //x^x=0   x^0=x   x^y^z=x^z^y---异或满足交换律
//	int b = 5;//0101                                                                                                             //
//	int c = a & b;//0001                                                                                                          
//	int d = a ^ b;   //记得在这里不是次方的意思，这是异或，相异取1，相同取0
//	printf("%d\n", c);
//	printf("%d\n", d);
//	a += 10;//即a=a+10,第一个字符就是需要操作的，后面的都是进行运算的
//	return 0;
//
//}
//









//4.单目、双目、三目操作符             -----操作一个变量，两个变量，三个变量的操作符
//#include<stdio.h>
//int main()
//{
//	//	一、单目操作符                -----这个操作变量的符号只能操作一个变量
//	int a = 18;
//	printf("%d\n", a);
//	printf("%d\n", !a);//逻辑反操作符，但如果a=0,   !a=1     在c语言中，0表示假   非0表示真
//	int arr[4];
//	printf("%d\n", sizeof arr);//显示出来的大小就是字节总长度
//	printf("%d\n", sizeof(int));//如果测试空间大小是变量名，则可以忽略sizeof后面的括号，但是如果测试的类型的空间大小，sizeof1后面的括号则不能省略
//	return 0;
//
//	//二、“-”号，也就是负号
//	//三、sizeof（）----计算变量、类型所占空间的大小，单位是字节
//
//}









//5.波浪号按位取反"~"              -----这个操作符同样能改变补码的符号位
//
//     
//  只要是整数，内存中储存的都是二进制的补码    正数--源码、补码、反码相同       负数--源码反码补码有自己的机制
// 
//#include<stdio.h>
//int main()
//{
//	int a = 0;                               //0000    这个是源码
//	int b = ~a;//"~"按位（二进制位）取反 ,b是有符号的整形    //b存储的二进制位是1111，存的即补码
//	//负数在存储的时候，存储的是二进制的补码，二进制最前面的一位是符号位，代表正负
//	printf("%d", b);//打印的时候的是这个是的源码    1111-1，然后符号位不变接着按位取反1001，即-1
//	return 0;
//}

//6.   ++    --
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int b = a++;//后置++，先使用a的值（即先把a的值赋给b），然后再进行自增    a--相同规则
//	int c = ++a;//前置++，先自增，再赋值        --a规则相同
//	printf("%d\n%d\n%d", a, b,c);
//	return 0;
//}

//7.*操作符，后续会讲

//8.强制类型转换    格式就是  int a=(int)3.14
//#include<stdio.h>
//int main()
//{
//	int a = (int)3.14;
//	printf("%d", a);
//	return 0;
//}


//9.  >  <  >=  <=  !=  ==



//10.  &&逻辑与（）     ||逻辑或      ！逻辑非           -----请注意对别：按位与&     按位或|     按位异或^




//11.条件操作符   exp1 ? exp2 : exp3    也叫三目操作符，因为有三个操作数
//#include<stdio.h>
//int main()
//{
//	int a = 100;
//	int b = 20;
//	int max = 0;
//	max = (a > b ? a : b);//a是否大于b，如果是，则max=a，如果不是，则max=b。   即exp1是判断条件，如果判断为真执行第二个条件，如果判断不符合，则执行第三个条件
//	//同等于下面语句
//	/*if (a > b)
//		max = a;
//	else
//		max = b;*/
//	printf("%d", max);
//	return 0;
//}



//补充；/=  *=   += -=  会将右边的所有内容当做一个整体



