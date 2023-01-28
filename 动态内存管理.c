//   这些函数的头文件是 stdlib.h

//1.为什么存在动态内存分配
//当前我们知道内存的使用方式 ： 创建一个变量（局部变量是在栈上开辟的空间，全局变量是在静态区上）、
//#include<stdio.h>
//
//struct S
//{
//    char name[20];
//    int age;
//};

//int main(void)
//{
//    int n=0;
//    scanf("%d",&n);
//    struct S stu[n];//c99的标准才支持这种变长数组的形式。也就是创建的数组的长度n可以是变量           这样可以在运行程序的过程中创建自己需要的空间
//}
//记住只有c99或者c99以后的标准才支持变长数组
//结构体内的变成数组必须放在最后一位







//2.malloc()一个动态内存开辟的函数    void* malloc(size_t size),后面的参数就是开辟的空间大小,单位是字节数   下面是基本的使用方法
//这个函数的头文件是stdlib.h
//当开辟失败的情况下则会返回空指针            开辟成功的情况下，返回的是开辟好的空间的指针（首地址）          所以说返回的值一定要去检查
//返回值的类型是void*,所以malloc函数并不知道开辟空间的类型，具体由使用者自己决定
//如果参数是0，malloc函数的行为并没有规定怎么处理，取决于编译器
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<errno.h>
//#include <limits.h>
//
//int main(void)
//{
//    int* p=(int*)malloc(sizeof(int)*10);//向堆区中申请10个int类型的空间，也就是40个字节，申请后，返回的是这个空间首地址.
////    //还需要注意的是这个动态内存开辟函数返回的是void*类型的指针，需要用指针去接收，并且在接收之前要用强制类型去转换一下。  但是gcc的编译器下面不用
//
//    if(p==NULL)
//    {
//        printf("%s\n",strerror(errno));
//    }
//    else
//    {
//        int i=0;//开辟成功，可以正常使用了         在开辟之后，如果未对此块空间进行操作，里面存放的值都是随机的。         -----也就是最好先进行以下初始化
//        for(i=0;i<10;i++)
//        {
//            *(p+i)=i;
//        }
//        for(i=0;i<10;i++)
//        {
//            printf("%d ",*(p+i));
//        }
//    }
//    //当动态申请的空间不再使用的时候，就应该返回给操作系统也就free()函数
//}
//也就是memory allocation         存储器分配






//3.free()   这个函数是专门用来做动态内存的释放和回收的    void free(void* ptr),里面的参数是一个指针
//参数中的地址如果不是由动态开辟函数,alloc,malloc,申请的，那free函数的行为是未定义的
//如果参数是NULL指针，则函数什么事都不做                    这两个函数的头文件都是stdlib.h
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<errno.h>
//#include <limits.h>
//
//int main(void)
//{
//    int* p=(int*)malloc(sizeof(int)*10);
//
//
//    if(p==NULL)
//    {
//        printf("%s\n",strerror(errno));
//    }
//    else
//    {
//        int i=0;
//        for(i=0;i<10;i++)
//        {
//            *(p+i)=i;
//        }
//        for(i=0;i<10;i++)
//        {
//            printf("%d ",*(p+i));
//        }
//    }
//    //当动态申请的空间不再使用的时候，就应该返回给操作系统也就free()函数
//    free(p);
//    p=NULL;//可能会出现free释放p后，虽然空间还回去了，但是还是还是能找到刚才的那块空间
//}//也就是说 malloc 和 free这两个函数成对出现








//4.calloc()也是一个内存开辟函数      void *calloc(size_t num,size_t size)num；元素的个数    size，每个元素的长度
//函数的功能是为num个大小为size的元素开辟一个空间，并把空间的每个字节初始化为0          这两个函数的区别就是后者会将申请的字节初始化为0
//这个函数的返回类型还是void*类型的，使用的时候根据环境注意强制类型转换
//开辟的空间还是在堆上进行，如果空间不够用（或者开辟失败）也会返回NULL               正常的情况返回的还是开辟的空间的首地址
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<errno.h>
//int main(void)
//{
//    int *p=(int *)calloc(10,sizeof(int));
//    int i=0;
//    if(p==NULL)
//    {
//        printf("%s\n",strerror(errno));
//    }
//    else
//    {
//        for(i=0;i<10;i++)
//        {
//            printf("%d ",*(p+i));//能够看出来，用calloc函数开辟的空间被全部初始化为0
//        }
//    }
//    free(p);//因为这个空间是动态内存函数开辟的空间，所以还得用free释放      alloc函数 free函数也是成对出现的
//    //也就是说free函数是用来释放动态开辟的空间的
//    return 0;
//}

//也就是clear  allocation







//5.realloc()                         void* realloc(void* memblock,size_t size)
// memblock是一个内存块，就是需要调整的空间是哪，也就是之前开辟的内存块。                      size新的总大小的字节。并不是追加的空间的字节
//realloc函数的出现让动态内存管理更加灵活     realloc可以调整动态函数开辟的空间大小
//也就是第一个内存是需要调整的地址，并且这个地址是用内存管理函数开辟出来的
//这个函数调整空间是有两种情况的
//(1)原空间在紧挨着追加需要的大小后，这个追加的空间没有被其他的数据所占用。那么在追加后返回的地址还是原来的地址

//(2)返回的地址可能是原地址（在原来的空间上新增一些，达到总size的字节数。）        -----这种情况是原来空间后面没有被使用，没存放其他数据
//   当然，返回的地址也可能是新的地址，指向的新的空间的总大小是size字节数。原来的空间会被函数直接free掉。   -----这样的情况是因为原空间后面有数据，如果紧挨着增加的话可能会造成内存泄露

//（3）返回的新地址依然包含着原来的老数据
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<errno.h>
//int main()
//{
//    int *p=(int *)malloc(20);
//    if(p==NULL)
//    {
//        printf("%s\n",strerror(errno));
//    }
//    else
//    {
//        int i=0;
//        for(i=0;i<5;i++)//在使用malloc开辟的空间
//        {
//            *(p+i)=i;
//        }
//        //假设上面开辟的20个字节的空间不满足使用，现在需要使用40个字节
//        //现在在这里就可以使用realloc来调整动态开辟的内存
//
//        int *ptr=(int*)realloc(p,40);//先判断一下有没有调整成功，调整成功的话再讲这个地址赋值给p
//        if(ptr==NULL)
//        {
//            printf("开辟失败");//开辟失败的情况下返回一个空指针
//        }
//        else
//        {
//            p=ptr;
//            for (i = 5; i < 10; i++)
//            {
//                *(p + i) = i;//返回的地址要么是刚才的老空间的首元素地址，要么是新空间开辟的新地址
//            }
//            for (i = 0; i < 10; i++)
//            {
//                printf("%d ", *(p + i));
//            }
//        }
//        free(p);//不管是哪个函数动态开辟的空间，到最后都得将开辟的这个空间释放掉
//        p=NULL;
//        return 0;
//    }
//}

//也就是reset allocation   重置分配


//使用realxxloc函数的注意事项
//一.如果p指向的空间之后有足够的内存空间可以追加，则直接追加，后返回p
//二.没有足够的空间可以追加，则realloc函数会重新找一个内存区域，并开辟一个满足需求的空间，并且把原来的数据拷贝过来，释放旧的内存空间，最后返回新开辟的空间地址
//三.如果调整失败，会返回一个空指针
//四.并且新增加的这部分空间，会直接进行初始化

//realloc可以直接实现malloc函数的给你功能，也就是直接开辟空间
//使用方法：int *p=realloc(NULL,40);










//5.常见的动态内存操作错误
//

//对空指针的解引用操作                  -----也就是需要注意对返回的是否为空指针进行判断
//int main(void)//这样的写法猛一看没什么毛病但是
//{
//    int *p=malloc(20);
//    int i=0;
//    for(i=0;i<5;i++)//没有判断malloc是否开辟成功就直接使用，会造成错误             所以要一定要判断一下返回的是不是空指针
//    {
//        *(p+i)=i;
//    }
//    free(p);
//    p=NUll;
//}


//对动态开辟内存的越界访问 。这样是错误的
//也就是开辟了20个字节，但是你使用了30个字节，这样程序就有可能出现程序崩溃的情况




//对非动态开辟的空间进行free。这样是错误的
//int a=5;
//int *p=&a;
//free(p);
//这样程序直接会报错，是非法的






//使用free释放一部分动态开辟内存           ----释放的主要目的就是不耽误别的数据使用这块空间，释放一部分还是会耽误别的数据继续使用
//int *p=(int*)malloc(40);
//if(p==NULL)
//{
//    retturn 0;
//}
//else
//{
//    int i=0;
//    for(=0;i<10;i++)//开辟的空间进行了使用
//{
//        *p++=i//到最后p指向的位置就是开辟的空间最后的位置后面。这样释放的时候p指向的位置已经越界了。
//}
//}
//free(p+2);
//p=NULL;

//另一种情况就是此时的p指向的是开辟的空间中间的地址。然后释放，这样做也是错误的

//free只能从开辟的空间的首地址开始释放





//对同一块动态内存进行多次释放
//int*p=malloc(20);
//free(p);
//free(p);//同样的地址释放了两次这样会出现错误。


//free(p);
//p=NULL;//这样写，下面就
//算是出现了多次释放的情况也不会报错
//free(p);




//对动态开辟的内存忘记释放（内存泄漏）              ----
//#include<stdio.h>
//int main(void) {
//    while (1)
//    {
//        malloc(1);//也就是一直开辟空间但是不去释放这个空间，这样就会造成内存泄露的情况。可劲占用内存，
//    }
//    return 0;
//}
//也就是要记住开辟的空间要记得释放！！！

//还有一种情况就是动态开辟空间是在自己定义的函数中进行的，但是忘记释放，这样出了调用函数就会找不到哪里没有释放，这样也是很可怕的






//7.几个经典的笔试题
//(1)
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void GetMemory(char*p)//这并不用二级指针去接收，用二级指针接收的是一级指针的地址。接收的不是一级指针的变量，接收一级变量代表着这只是形参。也就是将str里面的内容
////拷贝过去了一份
//{
//    p=(char*)malloc(100);//此处的空间在自定义函数结束、主函数没有结束的情况下，这个空间并不会消失。，如果不使用就会造成空间的浪费
//
//}
//void Test(void)
//{
//    char* str=NULL;
//    GetMemory(str);
//    strcmp(str,"hello world");//自定义函数的形参那个指针改变指向并不会影响str
//    printf("%s",str);
//}
//int main(void)
//{
//    Test();
//    return 0;
//}
//错误原因：
//运行的代码会出选崩溃的情况
//p只是函数的形参，在malloc开辟之后没有进行释放内存。并且无法找到，所以会造成内存泄露的1情况
//str是一个指针，参数应该是二级指针接收


//改正后应该是这样：
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//第一种方法
//void GetMemory(char** p)
//
//{
//    *p=(char*)malloc(100);
//}
//void Test(void)
//{
//    char* str=NULL;
//    GetMemory(&str);
//    strcpy(str,"hello world");
//    printf(str);
//    free(str);
//    str=NULL;
//}

//第二种方法
//char* GetMemory(char* p)
//
//{
//    p=(char*)malloc(100);//malloc函数是在堆上开辟的空间，这个自定义函数结束了空间还是会存在。除非free释放掉
//                          //也就是说栈上开辟的空间和堆上以及静态区上开辟的空间的生命周期是不一样的
//    return p;
//}
//void Test(void)
//{
//    char* str=NULL;
//    str=GetMemory(str);
//    strcpy(str,"hello world");
//    printf(str);
//    free(str);
//    str=NULL;
//}
//int main(void)
//{
//    Test();
//    return 0;
//}



//(2)
//#include<stdio.h>
//char *GetMemory(void)//函数内部变量的生命周期在这个函数返回值或者结束后就结束了。
//{
//    char p[]="hello wprld";//请注意，现在的这个数组的作用于的声明周期仅仅存在于这个自定义函数的内部。返回地址的同时，数组和这个常量字符串都被销毁了。
//    return p;//另外这些变量是在栈上开辟的内存空间。函数过后，这些内存空间全部销毁。但是在堆上的话也就是动态函数开辟的空间除了这个函数就不会销毁
//}
//void Test(void)
//{
//    char *str=NULL;
//    str=GetMemory();
//    printf(str);//这样不写格式的输出形式仅适用于字符串数组
//}
//int main(void)
//{
//    Test();
//    return 0;
//}
//错误原因：
//注意自定函数内部变量的声明周期。无论这个变量是指针还是数字或者是数组等。。。。出函数都能销毁
//除非static修饰一下这个变量



//这种情况下出了这个函数就不会销毁（指的是内存空间）
//#include<stdio.h>
//#include<stdlib.h>
//int* test()
//{
//    int* ptr=(int*)malloc(100);//这几个函数开辟的空间是在堆上的，这个函数结束了但是这个空间还是会存在。除非free掉。也就是堆上的申请的空间比较持久。
//    return ptr;//这个函数过后ptr变量依然会销毁，但是malloc在堆上开辟的内存空间并不会销毁。想要释放只能用free函数。
//}
//int main(void)
//{
//    int *p=test();
//    return 0;
//}

//#include<stdio.h>
//int main(void)
//{
//    int *p;//函数内部的指针变量没有进行初始化这个指针指向的地址是随机的。正因为是随机的，不知道指向的空间里面有什么数据，下面随意使用就会造成非法访问
//    *p=10;
//}



//(3)
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void GetMemory(char** p,int num){
//    *p=(char*)malloc(num);
//}
//void Test(void){
//    char* str=NULL;
//    GetMemory(&str,100);
//    strcpy(str,"hellp");
//    printf(str);
//    free(str);
//    str=NULL;
//}
//int main(void){
//    Test();
//    return 0;
//}
//这个代码的问题就是没有释放动态开辟的内存，导致内存泄露




//（4）
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void Test(void)
//{
//    char* str=(char*)malloc(100);
//    strcpy(str,"hello");
//    free(str);//free释放内存空间后，并不会把指针置为NULL
//    if(str!=NULL)
//    {
//        strcpy(str,"world");
//        printf(str);
//    }
//}
//
//int main(void)
//{
//    Test();
//    return 0;
//}
//错误原因：
//使用了释放后的空间。属于非法访问。能使用成功仅仅是因为"world"刚被释放刚好是空的，并且后面有\0；










//8.柔性数组
//c99标准中，结构体中的最后一个元素允许是未知大小的数组，这就叫 柔性数组 成员
//结构中的柔性数组成员前面必须至少一个其他成员               -----
//sizeof返回的这种结构大小不包括柔性数组的内存              -----sizeof不会计算
//包含柔性数组的成员的结构用malloc（）函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。

//普通情况
//struct S
//{
//    int a;
//    int arr[2]//最后的一个元素就是一个大小为2个整型的数组，包括下面创建变量的时候也是这样的大小
//};
//比如：struct S s={1,{1,2}};创建并且初始化

//柔性数组
//struct S
//{
//    int n;
//    int arr[];//最后一个位置的这种形式的数组就是柔性数组      还有另外一种写法 int arr[0];这也是柔性数组的写法    这个成员也叫做柔性数组成员
//    //柔性数组-数组的大小是可以调整的               这个柔性数组只能在结构体的最后一个元素才能实现。不在结构内或者在在结构体中间的成员变量都是错误的
//};
//#include<stdio.h>
//#include<stdlib.h>
//int main(void)
//{
////    struct S s={1,{1,2}};//这个初始化并不像上面的那种情况
//
////    struct S s1;
////    printf("%d\n",sizeof(s1));//结果是4 。因为没有使用这个柔性数组成员，不使用就没有分配空间大小也就是arr[0]
//
//    struct S* ps=(struct S*)malloc(sizeof(struct S)+5*sizeof(int));//柔性数组的基本使用方式  这样开辟的空间是连续的访问效率更高
//    //考虑好这个其他变量的大小以及需要的数组的大小然后malloc进行开辟           n和数组的内存空间
//    ps->n=6;
//    int i=0;
//    for(i=0;i<5;i++)
//    {
//        ps->arr[i]=i;
//        printf("%d ",ps->arr[i]);
//    }
//    printf("\n");
//    //如果需要新添加大小，那么需要用动态内存开辟函数进行重新设置
//    struct S* str=(struct S*)realloc(ps,44);
//    if(str!=NULL)
//    {
//        ps=str;
//    }
//    for(i=5;i<10;i++)
//    {
//        ps->arr[i]=i;
//        printf("%d ",ps->arr[i]);
//    }
//}




//想要创建一个可以自由设置大小的空间也可以这样用
//struct S {
//    int n;
//    int *arr;//类似于链表的模式，定义出一个指针，可以任意的指向，这个空间大小无所谓
//};
//#include<stdio.h>
//#include<stdlib.h>
//int main(void)
//{
////    struct  S s;
////    s.n=100;
////    s.arr=(int*)malloc(20);//也可以这样用         当然同样可以将整个结构体进进行调整空间，而不是单单调整一个arr数组。但是调整整个结构体的时候要注意整个结构体的
////    int i=0;                                   //这样开辟的空间和上面另外的成员变量的存放空间是不一样的。读取的效率会比较低
////    for(i=0;i<5;i++)
////    {
////        s.arr[i]=i;
////        printf("%d ",s.arr[i]);
////    }
////
////    //不够了依然可以调整大小     也就是realloc进行调整arr
////    free(s.arr);
////    s.arr=NULL;
////    printf("\n");
//    return 0;
//}

//malloc越多，出现的内存碎片越多。也就是剩下的空间小不能用。            内存是连续的访问的效率会更高


//柔性数组的优点
//方便内存的释放 一次free可以释放所有
//有利于访问速度，有利于减少内存碎片







//#include<stdlib.h>
//#include<stdio.h>
//#include<string.h>
//struct p1
//{
//    char name[20];
//    int age;
//    char tel[20];
//};
//
//struct p2
//{
//    int num;
//    struct p1* str;//此时的p1仅仅是个指针
//};
//int main(void)
//{
//    struct p2 m1;
//    m1.str=(struct p1*)malloc(3*sizeof(struct p1));
//    //这个指针现在指向了一个空间。这个空间可以存放多个struct p1类型的结构体。现在这个空间可以看做是一个数组，每个元素是一个结构体，这个数组的名字就是m1.str[],
//    //想要访问第一个结构体m1.str[0],第二个m1.str[1].
//    //如果这个空间不是存放结构体的话，可以不当做数组使用，看你怎么对返回的空指针进行强制类型转换了
//    m1.num=0;
//
//    strcpy(m1.str[0].name,"zhangsan");
//    m1.str[0].age=12;
//    strcpy(m1.str[0].tel,"12345678");
//
//    printf("%s\n",m1.str[0].name);
//    printf("%d\n",m1.str[0].age);
//    printf("%s\n",m1.str[0].tel);
//
//}