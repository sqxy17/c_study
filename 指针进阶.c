//1.指针的进阶
// （1）字符指针 （2）数组指针 （3）指针数组 （4）数组传参和指针传参 （5）函数指针 （6）函数指针数组 （7）指向函数指针数组的指针 （8）回调函数 

// #include<stdio.h>
// #include<string.h>
// void test(int arr[])//虽然定义的是一个arr数组，但是这个arr其实是一个指针          -----自定义函数中的形参是数组，其本质上是一个指针
// {
//     int sz=sizeof(arr)/sizeof(arr[0]);//sizeof（arr）这个64位就是8,32位就是4.sz的结果可能不一样
//     printf("%d\n",sz);//输出的结果是2，也就是说明sizeof (arr),如果这个数组是形参中的，那么认为它是一个指针，而不是全部数组的大小
// }
// int main(void)
// {
//     int arr[10]={0};
//     test(arr);
//     return 0;
// }


// int main(void)
// {
//     char *p="abcdefg";//此处的叫做定义的字符串常量,注意常量这两个字，这串字符串并不能被修改          -----这个指针指向的是这串字符的首字母的地址
//     printf("%s\n",p);
// }

//#include<stdio.h>
// int main(void)
// {
//     char arr1[]="abcdefg";
//     char arr2[]="abcdefg";
//     char* p1="abcdefg";
//     char* p2="abcdefg";
//     if(arr1==arr2)//字符串不能直接用来比较        -----两个数组，肯定开辟了两个不同的空间，因此地址肯定不一样
//     {
//         printf("hehe\n");
//     }
//     else
//     {
//         printf("这俩不相等\n");
//     }
//
//     if(p1==p2)//既然是常量，那么常量的内存空间就是相对不变的。因为这个常量不存放在数组中，因此两个指针指向的都是这个常量在内存中的位置
//     {
//         printf("hehe\n");
//     }
//     else
//     {
//         printf("这俩不相等\n");
//     }
// }






//2.指针数组----数组             -----指针数组--也就是存放指针的数组
//#include<stdio.h>
// int main(void)
// {
//     int arr[10]={0};
//     char ch[5]={0};
//     int* p_int[5];//什么类型的数组，存放什么类型的元素，因此指针数组的类型必须是着指针类型 例如--int* char* float*等等
//                    //指针数组里面的元素都是相同类型的指针，类型和数组类型相同          但是各个元素指针指向的数组大小并不做要求

//     char* p_char[5];//只能存放字符指针的数组，指针类型都是char*.     扩展一下就是指针就是地址，也就是说里面存放的是某种类型的地址
// }
//当然也能存放其他类型的地址，主要看你用来干什么。


//#include<stdio.h>
// int main(void)//常见的一种用法
// {
//     int arr1[]={1,2,3,4,5};
//     int arr2[]={2,3,4,5,6};
//     int arr3[]={3,4,5,6,7};
//     int* p_arr[]={arr1,arr2,arr3};
//     for(int i=0;i<3;i++)
//     {
//         for(int j=0;j<5;j++)
//         {
//             printf("%d ",*(p_arr[i]+j));//地址直接就能进行解引用
//         }
//         printf("\n");
//     }
// }

//int* arr1[10];//整型指针的数组
//char* arr2[4];//以及字符指针的数组
//char** arr3[5] //二级字符指针的数组          -----数组什么类型，里面就存放设么类型的指针，也就是里面存放着5个二级字符指针

//补充：指针数组里面的元素都是指针，如果是常量字符串，里面存放的是首个字母的地址
// char *a[]={"hello","word"};首元素地址和里面存放的地址不一样，对首元素地址进行解引用得到的是里面存放的元素的地址
//所以要记住这句话。---数组名一般代表着数组首元素的地址，对于指针数组，对数组名解引用得到的是首元素，也就是一个地址（指针）

//!!!补充：指针数组的创建必须指定数组的大小   即不能写成 int* arr[]; 要么规定数组的大小，要么直接用大括号进行初始化，但是不能int* arr[]={0}这样定义
//普通数组可以这样












//3.数组指针----指针
//#include<stdio.h>
// int main(void)
// {
//     int *p=NULL;//p是整形指针->指向整形的指针--可以存放整型的地址
//     char *pc=NULL;//pc是字符指针->指向字符的指针————可以存放字符的地址
//     int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     &arr;//这个形式是整个数组的地址。像这种    int*p=&arr;这种写法就是错误的，int类型的指针无法存放数组类型的指针
//     int (*p_arr)[10]=&arr; //数组指针->指向数组的指针--可以存放数组的地址->存放是&arr,整个数组的地址
//     //*p_arr就是数组指针       int
// }
//单独一个变量&a就只有一个地址。但是&arr这样的形式，是将所有元素的地址都得让指针变量保存下来
//指针，就是*p的这种形式，所以，在这个int(*p_arr)[10]=&arr当中，把*p_arr去掉之后，剩下 int[10],这个就是数组的类型，也就是包含着10个整型元素的数组


// int main(void)
// {
//     char* arr[5];
//     char*(*pa)[5]=&arr;//此处的[5]代表着pa指向的数组是五个元素，char*代表着pa指向的数组元素类型是char*        -----指向指针数组的数组指针
        //这个指针指向的数组里面的5个元素全是char*类型的指针
// }

//#include<stdio.h>
// int main(void)
// {
//     int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     int(*pa)[10]=&arr;
//     int i=0;
//     for(i=0;i<10;i++)
//     {                           //*能把&抵消掉，也就是说&arr在*（&arr）之后就变成了arr，就能配合下标使用了
//          printf("%d ",(*pa)[i]);//对*pa进行解引用，*pa等价于数组名。相当于拿到了整个数组,*pa是一个整体，要用括号括起来.这时第一种写法
//          printf("%d ",*(*pa+i));//第二种写法，记得*能把&抵消。即pa=&arr,*p=arr.然后进行操作。   这种使用方法就是对数组某个元素的地址进行解引用
//     }//其实数组下标的使用方法就是使用首元素字母的地址[下标]就能使用，小提示&arr和arr打印出来的地址是一样的
//     return 0;
// }


//注意事项：什么类型的数据要用到什么类型的指针。哪怕是指针类型的数组，用到的就是数组类型的指针


//数组指针一般是二维数组以上才方便一些
// void my_printf1(int arr[3][5],int x,int y)//遍历打印二维数组的元素---第一种方法
// {//参数是数组的形式             此处的x,y代表着数组的行下标和列下标
//     int i=0;
//     int j=0;
//     for(i=0;i<x;i++)
//     {
//         for(j=0;j<y;j++)
//         {
//             printf("%d ",arr[i][j]);4
//         }
//         printf("\n");
//     }
// }

// void my_printf2(int(*arr)[5],int x,int y)//注意:如果定义成指针的形式去接收地址，此时的首元素地址是二维数组的第一行的一维数组的地址。现在需要定义的是一个数组指针
// {//参数是指针的形式
//     int i=0;
//     for(i=0;i<x;i++)//有几行就循环几次呗
//     {
//         int j=0;
//         for(j=0;j<y;j++)//将本行的元素全部打印出来呗
//         {
//             printf("%d ",*(*(arr+i)+j));//注意解引用的格式*（arr+i)这个第一行，但是还是第一行的第一个元素的地址>>>*（*（arr+i)+j)
            //    printf("%d",(*arr+i)[j]);//这种格式同样能够输出
//         }//首先此处二维数组arr，元素名是第一行的地址解引用后，得到第一行第一个元素的地址，再解引用，得到第一行第一个元素的的值
//第一行的地址和第一行第一个元素的地址在数值上是一样的，但是其逻辑意义上是不同的，就好比普通数组的名字就是第一个元素的地址，对二维数组第一行进行解引用，就等于得到了普通数组的名字
//         printf("\n");
//     }
// }

// int main(void)
// {
//     int arr[3][5]={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
//     my_printf1(arr,3,5);//就算是二维数组，数组名还是首元素地址。但是二维数组的首元素地址 ，就是第一行那个一维数组的地址
//     printf("\n");
//     my_printf2(arr,3,5);//
//     return 0;
// }


//注意：下面4种输出的方式是等价的，包括多维数组
// int main(void)
// {
//     int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     int i=0;
//     int *p=arr;            //指针p就是arr，*p就是*arr
//     for(i=0;i<10;i++)
//     {
//         printf("%d ",p[i]);
//         printf("%d ",*(p+i));
//         printf("%d ",*(arr+i));
//         printf("%d ",arr[i]);//这四种方式是一样的
//     }
// }


//注意区分
// int* p1[10];//注意区分这个是指针数组--指针类型的数组，存放的都是int类型的指针（数组的名字就可以看作为指针变量--指针变量是地址，数组名也是地址）
// int (*p2)[10];//首先*和p2进行结合说明是指针，剩下个int[10],说明这个是一个指向了int[10]类型的指针，仅仅指向了一个数组

// int (*arr[10])[5];//arr是一个数组，包含了10个元素，每个元素都是数组指针。该数组指针指向的数组有5个元素，每个元素是int
//也就是说上面那个是单个的，下面这个能直接指向一堆

//补充：指针的类型，去掉指针的名字，就是指针的类型





//4.数组参数和指针参数
//在写代码的时候难免要把【数组】或者【指针】传给参数，那函数的参数如何进行设计呢

//—————— 一维数组传参：（代码没什么意义）
// void test(int arr[])
// {}
// void test(int arr[10])
// {}
// void test(int *arr)
// {}
// void test2(int *arr[20])
// {}
// void test2(int **arr)
// //注意这个参数，arr2定义的就是指针数组，里面存放的就是指针。传过来的数组名也就是首元素的地址，里面的元素都是指针，所以要用二级指针来接收
// {}

// int main(void)
// {
//     int arr[10]={0};
//     int *arr2[10]={0};   //指针数组里面的元素已经是指针了，数组名字还是首元素的地址，因此还是要
//     test(arr);
//     test2(arr2);
// }


//—————— 二维数组传参：(代码没什么意义)
// void test(int arr[3][5])
// {}
// void test(int arr[][])//这种就是错误的形式
// {}
// void test(int [][5])
// {}
// //总结;二维数组进行传参，函数形参的设计，只能省略第一个[]中的数字
// //因为对一个二维数组来说，可以不知道有多少行，但一定要知道一行有多少个元素

// void test(int arr)//err
// {}
// void test(int* arr[5])//err
// {}
// void test(int (*arr)[5])
// {}
// int main()
// {
//     int arr[3][5]={0};
//     test(arr);//二维数组的数组名是第一行所有元素的地址。第一行其实就是一个一维数组，所以要用数组指针来进行接收
//   也就是二维数组的数组名实际上就是一位数组的总的地址，类似于&一维数组名字          在对第一行进行解引用后，也就得到了一维数组名字
// }



//—————— 一级指针传参
// #include<string.h>
// void print(int *p,int sz)//用指针接收就行
// 一级指针接收一级指针，类似于a=b  b=c,虽然形参指针和实参指针保留着相同的地址，但是形参指针是额外的新的创建的指针，和实参指针没有关系。但是形参指针也能改变实参指针指向的地址的变量的值

// {
//     int i=0;
//     for(i=0;i<sz;i++)
//     {
//         printf("%d\n",*(p+i));
//     }
// }

// int main(void)
// {
//     int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     int *p=arr;
//     int sz=sizeof(arr)/sizeof(arr[0]);//sizeof是直接计算数组所占的字节数（也就是空间的大小）
//     printf("sizeof=%d\n",(int)sizeof(arr));
//     print(p,sz);//将指针当做参数
// }


// ——————二级指针传参
// void test(int** ptr)
// {
//     printf("num=%d\n",**ptr);
// }
// int main(void)
// {
//     int n=10;
//     int *p=&n;
//     int** pp=&p;
//     test(pp);
//     test(&p);//这就是二级指针传参的两个常见的例子
//     int *arr[10];//这个指针数组就可以直接传arr这个名字。  -----数组的名字就是首元素的地址，其首元素的值是一个指针，因此要用二级指针来接收
//     return 0;
// }

//void test(int **p_arr)  //首先我们要明白，int a变量，int* p=a ,int** p=&p;     pp变量当中保存的还是能指向其他地址的指针
////其次，二维数组的名字也是地址（指针的本质还是地址），这个地址中保存的是指向其他地址的指针。   因此也要用二级指针来接收二维数组的
//{
//
//}
//int main()
//{
//    int a=1;
//    int b=2;
//    int c=3;
//    int* arr[3]={&a,&b,&c};
//    test(arr);
//}


//补充：虽然二级指针当做参数传递时，虽然可以在自定义函数中的形参用一级指针去接受，但是接受了**形参的时候会进行报错，无法解引用










//5.函数指针：                -----和数组指针类似，数组指针--指向数组的指针           函数指针---指向函数的指针
//其实就是指向函数的指针——————一定要记住，函数指针指向的是函数————存放函数地址的一个指针  int(*add)(int x,int y)              和数组指针多像int(*p)[5]
// int add(int x,int y)
// {
//     int z=0;
//     z=x+y;
//     return z;
// }

// int main(void)
// {
//     int a=20;
//     int b=10;
//     printf("%p\n",add);//在函数中，add表示的地址和&add表示的地址是一样的———————&函数名 和 函数名 都是函数的地址.
//     printf("%p\n",&add);//这就是add函数的地址
//                                      // printf("%p\n",test+1);
//                                        //printf("%p",(&test)+1);这两个输出的地址都是一样的，足以证明test和&test没什么区别


//     int(*pa)(int,int)=&add;//这就是函数指针的写法         形参可以写可以不写    也就是int x,int y这俩形参变量是可以省略的1
//     printf("对函数指针的应用：%d\n",(*pa)(a,b));
//     printf("对函数指针的应用：%d\n",(**pa)(a,b));
//     printf("对函数指针的应用：%d\n",(***pa)(a,b));//发现不管带多少*都能成功的将函数解引用出来并且使用
//     printf("对函数指针的应用：%d\n",(pa)(a,b));//函数的指针能够直接进行调用使用函数。也可以解引用调用使用函数
//     printf("对函数指针的应用：%d\n",(&add)(a,b));
//     //但是不能这样去调用printf("对函数指针的应用：%d\n",*pa(a,b));>>>>>因为*的优先级不高，所以pa会先调用函数，然后再去解引用
//函数的指针可以直接调用函数                    -----也就是记住*的优先级不高，记得1他的解引用次序
//     //总结：函数的地址可以直接进行调用函数，也可以通过指针的解引用去调用，并且解引用的次数不限，甚至函数名加个取地址照样能使用(&add)(a,b)
//  也就是说函数名的使用不受取地址啊，解引用啊这些符号的影响

// }



// //类似于空函数的指针如下
// void print(char*str);>>>void (*p)(char*)//函数指针的类型和函数的返回值类型有关，可以不写形参，只写形参的类型

// void* pfun2();//这个pfun2仅仅是一个函数名        -----即使函数没有形参，指针也要用括号圈起来  例如：int(*p)()

//提示类似于int(*)[8]   void(*)(char*)，void(*)()等，当指针没有名字的时候，这种仅仅只是一个类型              -----请记住这种没名字的指针是类型

//int(*)[8]:类型为数组指针      void（*）(char*):函数指针      void(*)():函数指针            能用作函数的声明，里面的形参。   和强制类型转换     以及做函数的返回类型

//比如int(*add(int x,int y))(char*)       int(*add(int x,int y))[8]       确实可以当做函数的返回类型





//——————两个有趣的函数

// (*(void(*)())0)();//首先看到一个void(*)()类型的函数指针>>>把类型放在括号里面叫强制类型转换>>>把0强制类型转换成为一个地址>>>
//外面的*进行解引用地址>>>>其实就是调用了一次函数
//将0强制类型转换为某个void类型的函数地址，后面进行解引用调用

// void(*signal(int,void(*)(int)))(int);//signal函数名字  参数（int,void(*)(int))   
// >>>类似与int add(int,int);将函数的名字和形式参数去掉就是函数的类型  将上面的参数和名字去掉后>>>void(*                )(int)>>>就是这个类型的指针
//所以这个语句就是函数的声明；返回类型就是函数指针

//重要：定义函数指针的返回类型只能这样定义  void(*函数名（参数，参数）)（参数）；        并且数组指针也是这样定义的
//void(*         signal(int,void(*)(int))         )(int);
//对上面的代码进行解释：signal是一个函数声明；
//signal函数的参数有两个，第一个是int,第二个是函数指针，该函数指针指向的函数的参数是int,返回类型是void
//signal函数的返回类型也是一个函数指针：该函数指向的参数是int，返回类型是void

//类型太麻烦可以重定义,但是定义的形式和普通的类型重定义不一样>>>
//普通类型重定义：typedef unsigned int u_int;
//函数指针重定义：typedef void(* void_int)(int)   此处的void_int是重定义的新名字，并不是指针的名字，请注意
//由此重定义可以化简上面的语句：>>>void_int signal(int,void_int);>>>重定以后，此时定义函数的返回类型就可以和普通类型的定义相同了。


//总结:函数指针类型即可以定义变量类型，也可以定义返回值类型
//补充：函数地址中的内存，存放的值其实是函数本身的地址
//补充：函数指针的指针名，指针名是地址，和函数名地址相同也就是 int add(int x,int y);int(*padd)(int ,int y);此处的add=padd=*padd,当函数的参数是个数组指针的时候，
//可以直接将函数名传进去。

// int(*     (*p)(int,int)    )(int,int)   先看指针，再看指向哪，最后看指向的返回类型










//6.函数指针数组           -----也就是存放着一堆函数指针的数组

// int(*arr[7])(int,int)---->这个就是函数指针数组，我们应该想到普通数组的定义   类型 名字[元素个数]  那么函数指针数组也是这样定义的，只是有小小的区别
//首先是函数指针的类型int(*)(int,int)        再根据上面的定义变量的规则，在()里面定义       所以就是这样定义函数指针数组的    int(*arr[5])(int,int)


// int add(int x,int y)
// {
//     return x+y;
// }

// int sub(int x,int y)
// {
//     return x-y;
// }

// int mul(int x,int y)
// {
//     return x*y;
// }

// int div(int x,int y)
// {
//     return x/y;
// }

// int main(void)
// {
//     int* arr[5];
//     int(*p)(int,int)=add;//函数名也是地址
//     //而且上述函数的指针类型全部相同，都能用*p进行存储，此时就需要一个数组。数组可以存放四个函数的地址————函数指针的数组
//     int(*parr[4])(int,int)={&add,sub,mul,div};//这就是函数指针的数组，对于数组的地址，可以加&，不影响
//     printf("%p\n",parr);
//     printf("%p\n",parr[0]);//函数指针数组的数组名和函数的首元素的地址不相同
//     printf("%d\n",parr[0](3,3));


//     //下面是使用的方法
//     int i=0;
//     for(i=0;i<4;i++)
//     {
//         printf("%d\n",parr[i](2,3));//函数可以通过地址直接进行调用，不用解引用
//     }
//     printf("\n");
//     for(i=0;i<4;i++)
//     {
//         printf("%d\n",(*(parr+i))(2,2));//这可以算作第二种方法，数组名就是首地址，+i往后用。对数组解引用+1，是跳过单个元素。 不解引用的+1是跳过整个数组
//     }
// }

// int *parr1[10](); int(*)()parr2[10];-------->这两种写法都是胡整，什么都不是


//____________函数指针的用户：转移表      详细见实际题目测试25.
//这种通过函数指针调用其他函数的用途，就是转移表的形式进行实现的

// char* my_strcpy(char *dest,const char* src);
// //（1）写一个函数指针pf，能够指向my_strcpy
// char*(*pf)(char*,const char*)
// //(2)写一个函数指针数组pfarr,能够存放4个my_strcpy函数的地址
// char*(*pfarr[4])(char*,const char*);











//7.指向函数指针数组的指针                    -----牢记一点，去掉名字就是类型，这个类型可以用作其他
//指向函数指针数组的指针是一个指针，指针指向一个数组，数组的元素都是函数指针            --
//-----指针数组   int* arr[5]    ---函数指针数组 int(*arr[5])(int,int)      ----数组指针 int(*p)[5]      ---指向函数指针数组的指针int(*(*p))(int,int)
// int add(int x,int y)
// {
//     return x+y;
// }
// int main(void)
// {
//     int arr[10]={0};
//     int(*p)[10]=&arr;
//     int(*pfarr[4])(int,int);//函数指针数组>>>>>>函数指针数组，存放函数地址（函数指针）
//     int(*   (*ppfarr)  [4])(int,int)=&pfarr;//记住一点，指针去掉名字就是类型             ----函数指针数组类型的指针，就得用函数指针数组来定义
//     // ppfarr是一个数组指针，指针指向的数组有4个元素。
//     // 指向的数组的每个元素的类型是一个函数指针 int(*)(int,int)        可以通过这个类型进行无限的套娃就想二级指针三级指针

// }










//8.回调函数                  ----一个函数指针指向某函数a，我把这个指针传递给别的函数b，函数b通过接收的函数指针调用函数a，就是回调函数
//回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数，传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数
//回调函数不是由该函数的实现方式直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应
//回调函数一般用函数指针进行实现

//回调函数的实际应用
// int add(int x,int y)
// {return x+y;}

// int sub(int x,int y)
// {return x-y;}

// int mul(int x,int y)
// {return x*y;}

// int div(int x,int y)
// {return x/y;}

// void calc(int(*pf)(int,int))
// {
//     int x=0;
//     int y=0;
//     printf("请输入连个操作数：\n");
//     scanf("%d%d",&x,&y);
//     printf("%d\n",pf(x,y));//根据形式参数接收到地址去进行调用，调用谁，谁就是回调函数
// }

// void menu()
// {
//     printf("**** 1.add       2.sub **********\n");
//     printf("**** 3.mul       4.div **********\n");
//     printf("********  0.exit  ***************\n");
// }
// int main(void)
// {
//     int input=0;
//     do
//     {
//         menu();
//         printf("请选择计算方式：\n");
//         scanf("%d",&input);
//         switch(input)
//         {
//             case 1:
//                 calc(add);
//                 break;
//             case 2:
//                 calc(sub);
//                 break;
//             case 3:
//                 calc(mul);
//                 break;
//             case 4:
//                 calc(div);
//                 break;
//             case 0:
//                 printf("退出");
//                 break;
//             default:
//                 printf("输入错误请重新输入");
//                 break;
//         }
       

//     } while (input);
    
// }


//第二个小例子：
// void print(char* str)
// {
//     printf("hehe:%s",str);
// }

// void test(void(*p)(char*))
// {
//     printf("test\n");
//     p("bit");//print函数地址被当做参数传递，并且通过这个地址去调用到了原函数，这就是回调函数
// }
// int main(void)
// {
//     test(print);
//     return 0;
// }


// qsort排序
//#include<stdlib.h>
//#include<string.h>
//#include<stdio.h>

// int cmp_int(const void* e1,const void* e2)//这个函数是用来比较两个整形的
// //规定：当e1<e2 返回小于0的数字   当e1=e2  返回0     当e1>e2  返回大于0的数字
// {
//     return *(int*)e1-*(int*)e2;//解决空函数的使用，可以强制类型转换       ----空指针还是指针，想要转换成接收前的变量就得用相应的指针进行转后。然后解引用
// }//正数需要解引用才能比较
//
// int cmp_float(const void*e1,const void*e2)//浮点数里面进行的返回
// {
//     if (*(float*)e1==*(float*)e2)         -----形式参数是void*类型的，只要强转一下就能按照要求的数据使用
//     {
//         return 0;
//     }
//     else
//     {
//         if(*(float*)e1>*(float*)e2)//浮点数也要对地址进行解引用才能比较
//         {
//             return 1;
//         }
//         else
//         {
//             return -1;
//         }
//     }
// }
//
// struct stu                -----这里有结构体了，我们应该还得想到有结构体类型的指针
//  {
//     char name[20];
//     int age;
//  };
//
//  int cmp_stu_by_age(const void* e1,const void* e2)
//  {
//     return (((struct stu*)e1)->age)-(((struct stu*)e2)->age);//结构体的指针可以用->通过指针来访问结构体的成员
//  }
//
//   int cmp_stu_by_name(const void* e1,const void* e2)//名字比较并传递数字
//   {
//     //比较名字就是比较字符串
//     //字符串比较不能直接用> < =之类的进行比较  要用strcmp（）函数进行比较  str字符串 cmp比较
//     //和函数需要的相同，strcmp比较之后相同的返回0，e1<e2的返回负数()，e1>e2的返回正数
//      这个strcmp函数比较的时候是每两两单个字符进行比较ascll码，只要出现其中一个字符ascll不相等，就会出现返回值，如果比较到\0还是一样就返回0
//      如果出现其中一个字符串已经取完字符，那么也会返回值
//      还有一点，linux是返回那一对不同的字符差值，而win返回的是固定的1，-1，0

//     return strcmp(((struct stu*)e1)->name,((struct stu*)e2)->name);
//   }
//


//qsort函数进行排序                   -----qsort函数：只要是个数组就能排，并且只排序数组
// void test1()//排列整型数组
// {
//     int arr[] = { 1,2,354,65,34,5,65,46,346,45 };
// 	   int sz = sizeof (arr) / sizeof(arr[0]);
//     qsort(arr,sz,sizeof(arr[0]),cmp_int);//调用qsort函进行排序，           -----qsort函数需要传入一个自己定义的比较两元素的函数。
//     int i=0;
// 	for (i = 0; i < sz; i++)
// 	{
// 		printf("%d   ",arr[i]);
// 	}
// }
//

// void test2()//排列浮点型数组
// {
//     float f[]={1.2,3.4,4.5,3.6,7.2,6.8,9.9};
//     int sz=sizeof(f)/sizeof(f[0]);
//     qsort(f,sz,sizeof(f[0]),cmp_float);             //--这个地方的也是float函数的比较
//     int i=0;
//     for(i=0;i<sz;i++)
//     {
//         printf("%.1f   ",f[i]);
//     }
// }
//
// void test3()
// {
//     struct stu s[3]={{"zhangsan",20},{"lisi",25},{"wangwu",15}};
//     int sz=sizeof(struct stu)/sizeof(s[0]);
//     qsort(s,sz,sizeof(s[0]),cmp_stu_by_name);
// }

// int main(void)
// {
//     test1();
//     printf("\n");
//     test2();
//     printf("\n");
//     test3();
//     printf("\n");
// 	return 0;
// }


//qsort————quick sort————快速排序
// qsort函数的系统定义如下：


// void qsort(void *base,   size_t num,   size_t width,   int( *compare)(const void *elem1,const void *elem2));//四个参数

//各参数系统的解释
//base: start of target array ————数组的首地址 ————————直接知道了需要排序的数组是哪个
//num: array size in elements ——————元素中数组的大小》》》》》元素的个数
// width: element size in bytes ——————元素大小（字节）》》》》单个元素有几个字节
//compare: comparison function ——————用来比较的两两元素的函数指针，这个函数是程序员自己额外设计的——————由base已经知道，比较的元素在哪个数组
//elem1: pointer to the key for the search ———————      elem1和elem2是我们要比较的两个元素的地址，里面的地址是挨着的
//elem2: pointer to the array element to be compared with the key
//compare:比较         第四个参数是函数指针，此函数是程序员自己设计实现的比较。想办法让数组里面的两个元素产生差值

//第一个参数：待排序数组的首元素地址
//第二个参数：待排序数组的元素个数
//第三个元素：待排序数组的单个元素的大小（字节）
//第四个参数：函数指针，比较两个元素所用的函数的地址（需要自己去实现）
//          函数指针的两个参数是：待比较的两个元素的地址

//总结，就是要设计，想要排序的参数，进行一些大小的比较












//9.模拟函数qsort的实现


//#include<stdio.h>
//
////实现bubblee_sort函数的程序员，并不知道未来排序的类型
////程序员也不知道，待比较的两个元素的类型
//struct stu
//{
//    char name[20];
//    int age;
//};
//
//swap(char* buf1,char* buf2,int width)//用来交换传进来的两个元素，不是每两两元素都传过来，只是e1<e2的两个元素才传进来
//{
//    int i=0;
//    for(i=0;i<width;i++)//本质上是将转化为一个一个的字节，并将逐个字节进行解引用操作后交换，最后合并起来还是width个字节在一起
//    {
//        char tmp=*buf1;
//        *buf1=*buf2;
//        *buf2=tmp;
//        buf1++;
//        buf2++;
//    }
//}
//
//
//void bubble_sort(void* base,int sz,int width,int(*cmp)(const void* e1,const void* e2))//传过来的是类型相匹配的比较函数————第四个参数
//{
//    int i=0;
//    for(i=0;i<sz-1;i++)//每一趟比较的对数（3，2，1——》3，2   2，1）每趟都是
//    {
//        int j=0;
//        for(j=0;j<sz-1;j++)//一次进行一对元素的比较
//        {
//            if(cmp((char*) base+(j*width),(char*) base+(j+1)*width)>0)//e1>=e2都不在进行交换
//            {
//                swap((char*)base+j*width,(char*)base+(j+1)*width,width);//用来实现交，其实是逐个字节进行交换的
//            }
//        }
//    }
//}
//
// int cmp_int(const void* e1,const void* e2)       //自己设计的函数的形参应该是void* 类型的
// {
//     return *(int*)e1-*(int*)e2;
// }
//
//  int cmp_stu_by_age(const void* e1,const void* e2)
//  {
//     return (((struct stu*)e1)->age)-(((struct stu*)e2)->age);//请注意，结构体数组里面元素的解引用用的是->.->的优先级比强转的高，强转需要带上一对括号
//  }
//
//void test4()
//{
//    int arr[10]={9,8,7,6,5,4,3,2,1,0};
//    int sz=sizeof(arr)/sizeof(arr[0]);
//    int i=0;
//    //使用bubble_qsort的程序员一定知道自己排序的是什么数据
//    //就应该知道如何比较待排序数组的元素  也就是说每次调用不同的类型都要重新设计一个
//    bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);//最后一个参数是程序员自己设计的函数
//    for(i=0;i<10;i++)
//    {
//        printf("%d ",arr[i]);
//    }
//}
//
//
// void test3()
// {
//     struct stu s[3]={{"zhangsan",20},{"lisi",25},{"wangwu",15}};
//     int sz=sizeof(struct stu)/sizeof(s[0]);
//     bubble_sort(s,sz,sizeof(s[0]),cmp_stu_by_age);
// }
//
//int main(void)
// {
//     test4();
//     test3();
//     return 0;
// }
 //总结一下就是，快速排序的本质是冒泡排序的升级版









//10.void*类型
//  int main(void)
//  {
//     int a=10;
//     // int *pa=&a;

//     void  *p=&a;//void* 叫无类型的指针，可以接收任意变量的地址
//     //void* 类型的指针，可以接收任意类型的地址

//     // *p=0;//所以void类型的指着是不能进行解引用操作的，但是可以强制类型转换后进行解引用操作
//     // p++；//不能进行加减整的操作  void函数所能操作的步长是未知的,但是可以强制类型转换后进行运算
//  }














//11.前面的各种指针的总结以及区分
// int add(int x,int y)
// {
//     return x+y;
// }
//
// int main(void)
// {
//     int* arr[10】;//指针数组————用来存放int*类型指针的数组
//
//     int* (*pa)[10]=&arr;//数组指针————指向数组的指针，并且这个数组的类型是int*,且含有10个至指针元素
//
//     int(*padd)(int,int)=add;//函数指针
//
//     int(*paddd[5])(int,int)//函数指针数组—————里面的元素全是函数指针，这个数组只能存5个函数指针，里面的函数返回类型是int，参数也是两个int
//
//     int(*(*ppadd[5]))(int,int)=&paddd;//指向函数指针数组的指针，
// }
