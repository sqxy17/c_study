//#include<stdio.h>
//short age = 20;//在这定义相当于定义了一个全局变量  没有在main方法内直接定义的变量就是全局变量,其他项目中可以使用extern调用。调用的前提是全都在一个文件夹内
// //例如extern short age
//int main()
//{
//	float weight = 23.455;
//	printf("%d\n",age );
//	printf("%f\n", weight);
//	return 0;
//}

//extern   这个函数可以在其他文件中引用这个全局变量   格式：extern short age;          -----前提引用的这个变量所在的源文件必须和引用的代码在同一个文件夹内

	


//float变量只能保留小数后面的六位，而double能保留小数后的15位。

//在输出时想想要保留规定的位数可以      printf("%.3f",weight)---即保留了三位小数      double输出时用的是"%lf"

//在{}之外的变量叫全局变量，在{}内部的叫局部变量        当局部变量和全局变量名字相同时，局部变量的优先级更高
//int add(int x, int y)
//{
//	 static int sum = 0;
//	sum = x + y;
//	return sum;
//}

//全局变量不进行初始化则默认为0；局部变量不进行初始化则为随机数

//不管怎么对变量进行更改，都是对补码进行计算的

