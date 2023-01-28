//1.枚举
//也就是把可以取值的一一列举出来  例如：
//enum sex
//{
// male,      //注意，后面的成员变量不再是分号      成员变量也叫做枚举常量              -----位段的定义是变量后面是分号加：
// female,
// secret//最后一个成员变量后面就不用写逗号了，因为后面没有变量了
//};
//
//enum color
//{
////    red,//第一个默认是0     可以理解为red=0；        并且是 int red=0;也就是大小为4个字节
////    green,//第二个默认是1
////    blue//2
//
////    red=2,//可以通过赋值来改变这些枚举常量的默认值，并且在这个常量赋值以后，后面的常量的默认值也会从2开始排序
////    green,//此时为3
////    blue=7,//
////    yellow//后面的值的默认值只和前面的值有关。blue是7，那么此时的yellow就是8
//
//     red=2,
//     green=4,
//     blue=9//三个常量都可以进行赋值改变默认值     前提是在刚开始定义的这个枚举类型内，如果在main()函数内就无法改变
//};




//#include<stdio.h>
//int main(void)                 //enum color   这就是枚举常量类型，是一种和结构体变量类似的类型
//{
//    enum sex s1=male;//因为是枚举类型的变量，所以枚举类型只能在这三个成员变量中选中一个为枚举变量进行赋值
//    s1=female;//一个枚举变量就一个值，因此直接用枚举变量进行赋值就可以
//    printf("%d\n",s1);
//
//    enum color c1=blue;
//    printf("%d\n",c1);
//
////    enum color c2=2;//这种写法是错误的   前面是enum color类型  后面是int类型的
//}






//2.为什么用枚举
//#define red 0
//#define green 1
//#define blue 2    //为什么不这样用呢？   注意，这种red仅仅就是个符号，并没有类型

//枚举的优点:
//增加代码的可读性和可维护性
//和#define定义的标识符比较，枚举有类型检查，语法上更加严谨
//防止命名污染（封装）   //也就是将这些
//便于调试， 使用方便，一次可以定义多个常量


//C语言的源代码运行过程：  预编译---编译---链接---可执行程序   这个可执行程序执行起来才能够进行调试

//预编译：这个过程能将#define定义的符号全部替换为相应的数字，而且还能将源文件中的注释删除掉等   但是调试进行的执行文件中已经替换为数字了，出现错误也无法进行及时的判断
//但是就像这一句：int a=red;右边的是一个int类型的，但是左边的值是没有类型，显得不够严谨






//3.枚举的使用
//#include<stdio.h>
//int main(void)
//{
//    enum color
//    {
//        red,
//        green,
//        blue
//    };
//    enum color c1=blue;//定义什么的类型，赋值什么类型才不会出错           这个枚举变量c1大小是4个字节
//    c1=blue;//创建了一个枚举变量重新进行赋值是允许的    这个创建出来的叫变量
//    printf("%d",c1);//并且打印出来的数字就是最新赋值的那个数
//}







//4.联合体（也叫共用体）
//联合也是一种特殊的自定义类型，这种类型定义的变量也包括一系列的成员，特征是这些成员共用一块空间（所以联合体也叫共用体）---公用同一块空间

//结构体的各个成员都是独立的（在内存空间上），但是联合体是公用相同的字节空间
//union un
//{
//    char c;
//    int i;
//};
////一块空间有4个字节  c先占用这块空间的第一个字节，i占用全部的字节，但是也是从第一个字节开始的  所以导致了两个变量的地址是相同的情况
////也就是两个变量从同一个地址开始往后放
//
//#include<stdio.h>
//int main(void)
//{
//    union un u;//开辟了一块空间，空间大小是4个字节
//    printf("%d\n",sizeof(u));//4
//    printf("%p\n",&(u.c));
//    printf("%p\n",&(u.i));
//    printf("%p\n",&u);
//}

//联合体的特点
//联合体的成员共用同一块内存空间，这样一个联合体（比如上面的u）变量的大小，至少是里面成员变量最大成员的大小（因为联合体至少得有能力保存最大的那个成员）

//联合体里面的变量不能同时进行使用，并且里面的变量改一个等于改所有，毕竟地址都是一样的

//在复习一遍。低地址存低位，高地址存高位 小端字节存储模式
//拿出来的字节是先从低地址处开始
//现在用联合体的方式进行实现判断大小端
//#include<stdio.h>
//int main(void)
//{
//    union un
//    {
//        char a;
//        int b;
//    };
//    union un u1={0};
//    u1.b=1;
//    printf("%d",(int)u1.a);//char只能保存一个字节，刚好用到int的第一个字节的空间。也刚好是int的低地址处。判断char的数字就能判断这个电脑是大端还是小端
//}
//1位于低位处，char首先输出的是低地址的字节，如果输出是1也就是低地址存低位。如果输出的是0就是低地址存的是高位







//5.联合体大小的计算
//联合的大小至少是最大成员的大小
//当最大成员大小不是最大对齐数的整数倍的时候，就要找到最大对齐数的整数倍
//union un
//{
//    int a;
//    char arr[5];//结构体里面的数组对齐数依然是前面的类型的大小 char 1 int 4
//    //也就是整数组的大小。不是最大对齐数的整数倍，就得找最大对齐数的倍数
//};
//#include<stdio.h>
//int main(void)
//{
//    printf("%d",sizeof(union un));
//}