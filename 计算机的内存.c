//1.内存的构成  栈区   堆区   静态区



//2.各个区存放的内容  
//栈区：局部变量、函数的形式参数、函数的调用也会在上面开辟空间

//堆区：动态内存分配、malloc/free、realloc、calloc  分配的就是堆区空间

//静态区：全局变量、静态变量
//当free释放掉一个指针内容后，指针变量的值（也就是地址）并不会变化，这个指针变量申请的空间会消失
//malloc的使用方法:    int *p=malloc(10*sizeof(int))这个函数的默认返回类型是void*   这是申请空间
//释放空间：free(p);      这两个函数的头文件是stdlib.h

//全局变量不初始化默认值是0，局部变量不初始化默认值是随机的


//3.各个区使用的过程
// int main()//这个main会在栈上开辟一些空间
// {
//     int a;//在main开辟的空间内会划分一些空间给a变量
// }

// void add(int x,int y)//这里的形参并不在add函数申请的空间内。但是却在栈区上
// {
//     int num=x+y;//将不在本空间的变量拉进来进行使用就叫压栈
// }
//




//内存空间详细的情况最详细的是这几种情况
//内核空间（用户的代码不能读写，这个空间是只有操作系统再使用）

//栈（向下增长）：在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时，这些存储单元自动被释放。栈内存分配运算内置于处理器的指令集中，效率很高，但是
//分配的内存有限。栈区主要存放运行函数而分配的局部变量，函数参数，返回数据，返回地址等。

//内存映射段（文件映射，动态库，匿名映射。也是一个用户无法直接使用的空间）

//堆（向上增长）：一般由程序员分配释放，若程序员不释放，程序结束后可能有系统回收，分配方式类似于链表

//静态区（又叫数据段)：存放全局变量，静态数据。程序结束后由系统释放。

//代码段：存放函数体（类成员函数，和全局函数)的二进制代码

//重点：c++/c程序内存分配的几个区域      栈区  堆区  数据段（静态区）  代码段


