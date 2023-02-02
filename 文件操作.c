
//这个章节可以处理上节通讯录关机就会删除信息的情况    .实际情况下更多的数应用于记录日志
//1.什么是文件
//磁盘上的文件是文件   但是在程序设计中，我们谈的文件一般有两种;程序文件、数据文件

//程序文件：
//包括源文件（后缀为.c），目标文件（win环境下后缀为.obj），可执行程序（win环境下后缀为.exe）    这些文件能够运行或者被编译，   程序文件是用来操作数据文件的
//目标文件一般是编译后产生的

//数据文件：
//文件的内容不一定是程序，而是程序运行时读取的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件           本章讨论这个

//以前各章所处理数据的输入输出都是以终端为对象，从终端的键盘输入数据，运行结果在显示器上显示。其实我们有的时候会把信息输出到磁盘上，当需要的时候再从磁盘上把数据读取到内存中
//使用，这里就是处理磁盘上的文件













//2.文件名
//一个文件要有一个唯一的文件标识，以便用户识别和引用。
//文件名包含三部分：文件路径+文件名主干+文件后缀
//例如 c:\code\test.txt     （这三个放在一起叫文件名）
//为了方便起见，文件标识通常被称为文件名












//3.文件类型
//请注意，上述例子中的.txt并不是一种类型，它仅仅是一个后缀
//根据数据的组织形式，数据文件被称为 文本文件 或者 二进制文件                       -----也可以说数据文件分为： 1.文本文件  2.二进制文件
//数据在内存中以二进制的形式存储，如果不加转换的输出到外存，就是二进制文件               ps：外存就文件上记录的内容。比如一个源文件上显示的代码
//内存上的数据都是二进制形式存储的，内存中的数据我们如何查看？就是在屏幕上显示的一个个文件上       -----这些文件直接将二进制显示出来的叫二进制文件     转换后（转换）再显示的叫文本文件

//文本文件中放的都是我们能看的懂得。没有乱码什么的
//二进制文件里面的内容用记事本打开后我们开看不懂，一般是乱码的形式

//如果要求在外存上以ascll码的形式存储，则需要在存储前转换。以ascll字符形式存储的文件就是文本文件

//字符一律以ascll形式存储，数值型数据既可以用ascll码存储，也可以用二进制存储               -----数字以外的东西都叫字符
//比如整数10000,ascll形式输出到磁盘上需要五个字节（磁盘中一个字符占一个字节），而二进制形式输出，则在磁盘上只占4个字节（VS2013测试）

//10000的两种存放形式：             -----这都是在内存中的存放形式
//ascll形式：       00110001  00110000  00110000  00110000  00110000
// 1的ascll值是49，0的是48，每个字符都要成单独计算ascll值。1 0 0 0 0，均放入一个字节里面。这样的存储形式是文本文件

//二进制形式：       00000000  00000000  00100111  00010000       也就是将10000的十进制转换为二进制数字


//总结就是：汉字，英文字母在内存中有只有一种存放形式ascll。         数字在内存中有两种形式

//
//#include<stdio.h>
//int main()
//{
//    int a=10000;
//    FILE* pf=fopen("test.txt","wb");//fopen（）打开文件的函数，第一个参数是文件的名字，第二个参数是怎样操作这个文件（wb以二进制的写入这个文件，也就是更改）
//    //fopen（）这个函数会打开这个文件，如果这个文件不存在，那么会创建一个新的这个名字的文件（wb形式的），在这个文件只能以二进制的形式写入
//    //创建的这个文本会在你的工程项目内，想要打开得用二进制的形式打开。打开后显示的是在内存中存储的形式，16进制 10 27 00 00 小端存储
//     这个文件名可以将路径写清楚
//
//    //想要存放成文本文件在txt上显示的就是直接是字符。但是内存中存放的是ascll码，在屏幕上显示的内存形式是10000
//
//
//    fwrite(&a,4,1,pf);//fwrite（）函数 二进制的形式写到文件中         -----这个函数会返回写入的数据块个数
//    //第一个参数：&a，写入的东西地址在&a，表示数据的来源在a的地址处，             -----写入文件的数据地址来源
//    //第二个参数：写入4个字节。                       -----要从这个地址开始写入多少个字节
//    //第三个参数：写入1个这样的数据。                -----写入的数量
//    //第四个参数：写入到pf这个地址的文件                  -----写到哪里去
//
//    //上面的两个函数的主要作用就是将test.txt文件打开，并将10000这个数字放进去。          并且最关键的是以什么形式打开的这个文件
//
//
//    fclose(pf);//最后关闭的是文件
//    pf=NULL;
//    return 0;
//}









//4.文件缓冲区
//ANSIC标准采用“缓冲文件系统”处理数据文件的，所谓缓冲文件系统是指系统自动的在内存中为程序中每一个正在使用的文件开辟一块“文件缓冲区”。
//文件缓冲区分为两个：输入缓冲区、输出缓冲区            输出到磁盘中               输入到数据区（内存）中
//从内存向磁盘输出数据会先送到内存中的缓冲区，装满缓冲区后才一起送到磁盘上。
//如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区），然后再从缓冲区逐个地将数据送到程序数据区（程序变量等）。缓冲区的大小是由c编译器决定的。
//缓冲区的数据存满了才会继续下一步

//一般也就分为两步：从终端（键盘）输入到内存   从内存输出到磁盘           键盘到内存（中间用得到输入缓冲区）   内存到磁盘（中间用得到输出缓冲区）
//               从磁盘输入到内存，从内存输出到终端（屏幕）             磁盘到内存（中间用得到输入缓冲区）  内存到屏幕（中间用得到输出缓冲区）

//gcc编译环境中sleep是小写，（）里面是秒的意思
//printf()输出hehe在屏幕上，这个过程也是有一个内存缓冲区








//5.文件指针
//缓冲文件系统中，关键的概念是"文件类型指针"，简称"文件指针"
//每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息（如文件的名字，文件状态及文件当前的位置等）。这些信息是保存在了一个结构变量中的
//-----也就是打开这个文件后会开辟出一个文件信息区       并且这个文件信息区的本质上是一种结构体

//。该结构体类型是有系统声明的，取名FILE，例如vs2008环境提供的stdio.h头文件中有以下的文件类型申明
//开辟的这块空间实际上是一个FILE类型的变量，并且是结构体类型是FILE         每使用一个文件，都会存在一个相应的文件信息区与之对应（也就是结构体变量）

//FILE* pf//创建了一个文件类型的指针

//定义pf是一个指向FILE类型数据的指针变量。可以使pf指向某个文件的文件信息区（是一个结构体变量）。通过该文件信息区中的信息就能够访问该文件。
//也就是说通过文件指针变量能够找到与它关联的文件          指针->文件信息区->该文件








//6.文件的打开与关闭
//文件在读写之前应该先打开文件，在使用结束之后应该关闭文件！！！！

//流：流是一种数据传输的模式

//写程序的时候，打开文件的同时，会返回一个FILE*的指针变量指向该文件，相当于建立了指针和文件的关系
//ANSCI规定fopen（）函数打开文件，fclose（）函数关闭文件

//fopen（）函数定义         FILE* fopen(const char* filename,const char* mode)          filename:文件名字      mode：方式
//fclose()函数定义         int fclose(FILE* stream);
//
//#include<stdio.h>
//#include<errno.h>
//#include<string.h>
//int main()
//{
//    FILE* pf=fopen("../test.txt","w");//这总就是相对路径的写法，因为test.txt和当前的源文件是同一个文件夹        如果这个test在上一层文件夹内要这样写 ../test.txt
//    //..表示上一级路径  上一级路径的上一级路径就是 ..\..\test.txt
//    //这里的test.txt文件也可以写成绝对路径，绝对路径的写法：  c:\\xxx\\xxxx\\test.txt       两个\\是因为防止转义    也可以一个/，注意方向，斜杠/需要一个，\反斜杠两个
//
////    打开这个文件，首先创建了一个（test.txt）的文件信息区，这个文件信息区与test.txt文件相关联，系统会将文件信息区所需要的内容从文件填充上去
////    打开失败的话，这个文件信息区就不会去创建
//
////fopen()用相对路径打开，这个打开的文件要在源文件的debug版本的文件夹内而不是当前源文件的文件夹内。上下级的话可以用..   \来进行调整
//
////"w"的形式：write写，会将原来的文件内容销毁，给你腾出一个空白的文件让你好好写。不存在这个文件也会创建一个新的文件让你写
//
//    if(pf==NULL)
//    {
//        printf("失败");
//        printf("%s",strerror(errno));//返回错误类型的地址，并打印出来
//    }
//    else
//    {
//        printf("victory");
//    }
//   fclose(pf);//也就是将pf所指向的这个文件信息区释放掉，但是pf并没有被置成空指针               里面的参数是文件类型的指针
//   pf=NULL;//释放空间后的指针就是野指针的
//}
//"r"只读，成功会返回地址，不成功会返回一个空指针









//7.文件的顺序读写    fputc()     fgetc()
//fputc（）写入字符文件函数        int fputc(int c,FILE* stream);第一个参数是想要写入的字符       第二个字符是想写入到哪个文件中去         函数返回的是写入的ascll码值
//这个函数仅仅能在文件中写入字符，不能写入汉字

//fgetc（）读取字符文件函数        int fgetc(FILE* stream)     函数返回的是获取的ascll码值


//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//int main(void)//写入test.txt文件内字符成功
//{
//    FILE* pf=fopen("../test.txt","w");//注意文件的路径是注释的那个斜杠       不是转义的那个斜杠
//    if(pf==NULL)//pf是为了向文件中写东西，这叫文件输出流
//    {
//        printf("%s",strerror(errno));
//        return 0;
//    }
//    else
//    {
//        fputc('b',pf);//这个函数写入文字会出现错误，写入数字显示出来的看不懂
//        fputc('i',pf);
//        fputc('t',pf);
//    }
//    fclose(pf);
//    pf=NULL;
//    return 0;
//}


//int main(void)
//{
//    FILE* pf=fopen("../test.txt","r");//展示读文件
//    if(pf==NULL)//这个pf是为了读字符而得到的，这叫输入流             上面的那个文件的指针叫输出流
//    {
//        printf("%s",strerror(errno));
//        return 0;
//    }
//    else
//    {
//        printf("%c",fgetc(pf));
//        printf("%c",fgetc(pf));
//        printf("%c",fgetc(pf));        //cmd+d将选中的本行快速复制到下一行
//    }
//    fclose(pf);
//    pf=NULL;
//    return 0;
//}

//注意：往内存走的都是输入          内存外的都是输出


//从键盘输入     输出到屏幕
//这个键盘和屏幕都是外部设备

//键盘-标准输入设别        屏幕-标准输出设备       这两个是程序运行起来默认的流设备
//只要程序运行起来，就会默认打开三个流 stdin stdout  stderr    这三个流的类型都是FILE*的            -----FILE*类型的都可以叫做流
//stdin:标准输入设备   stdout:标准输出设备              输入的是到内存中去的，输出的是到磁盘中去的


//这些流使用的例子
//#include<stdio.h>
//int main(void)ol
//
//    int ch=fgetc(stdin);//get操控的是输入流    输入流的意思就是输入到内存中去的流           这些流的本质还是地址（要流入或流出到文件或者数据区中），以及从什么地方流出流入
//    fputc(ch,stdout);//put操控的是输出流     输出流的意思就是从内存中输出到其他地方的流
//}

//这些函数操作的就是流。无论是文件中的，还是键盘上屏幕上的                 给变量赋值，也就是给内存中的变量赋值673
// -----从键盘也是先输入到内存，再从内存输出到屏幕







//8.文件操作的小例子
//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//int main(void)
//{
//    FILE* pf=fopen("../test.txt","w");//write:也就是写的形式对文件进行操作         文件不存在创建一个新的，文件存在清空内容写
//    if(pf==NULL)
//    {
//        printf("%s",strerror(errno));
//    }
//    else
//    {
//       fputc('a',pf); //可以对文件进行操作了。内存到磁盘上是输出流，存放的文件是在磁盘上。                  -----函数有的是操控输入流的，有的是操控输出流的
//       fputc('b',pf);
//       fputc('c',pf);
//       printf("写入成功\n");
//    }
//    fclose(pf);
//    pf=NULL;
//}


//int main(void)
//{
//    FILE* pf=fopen("../test.txt","r");         "r",文件只以可读的形式打开
//    if(pf==NULL)
//    {
//        printf("%s",strerror(errno));
//    }
//    else
//    {
//        printf("%c",fgetc(pf));
//        printf("%c",fgetc(pf));
//        printf("%c",fgetc(pf));//fgetc函数不能在文件以读的形式打开时获得字符。必须关闭了再以写的形式打开才行
//    }
//    fclose(pf);
//    pf=NULL;
//}









//8.文件操作函数（整行）
// fgets()        函数定义：char* fgets(char* string,int n,FILE* stream)             从磁盘输入到内存，操控的是输入流
//第一个参数：读取的字符串将要放入的位置       第二个参数：读取多少个字符              第三个字符：将要读取的流的位置，从这里面开始读
//读取的实际的字符是n-1个，因为要在最后自动加上\0    这个返回值数据存放的位置

// fputs()        函数定义：int fputs(const char* string,FILE* stream);第一个参数：自己的字符串    第二个参数：把这个字符串整进去的这个流中
//写一个字符串传入到这个流中

//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//int main()//fgets()的使用方法
//{
//    char arr[100];
//    FILE* pf=fopen("../test.txt","r");
//    if(pf==NULL)
//    {
//        printf("%s",strerror(errno));
//    }
//    else
//    {
//        fgets(arr,100,pf);
////        printf("%s",arr);//每次读取一行的时候后面可能会有一个换行符     就是你写下一行的时候敲了一个回车。最后一行时你不敲回车就没有，敲了就有
//        puts(arr);
//        fgets(arr,100,pf);
////        printf("%s",arr);//和上面的fgetc类似，那个是一次拿一个字符，再用换下一个。          这个fgets()函数在第二次使用的时候会读取下一行
//        puts(arr);//puts天生的打印完之后会换行，如果字符串有换行那就换两行
//    }
//    fclose(pf);
//    pf=NULL;
//    return 0;
//}
////puts():写一个字符串到屏幕上（标准输出上）      int puts(const char* string)     头文件stdio.h


//int main(void)//fputs()函数的使用方法，也就是将数据写入到文件      put=input也就是输入
//{
//    FILE* pf=fopen("../test.txt","w");//pf这个指针就是流
//    if(pf==NULL)
//    {
//        printf("%s",strerror(errno));
//    }
//    else
//    {
//        fputs("hello\n",pf);
//        fputs("world\n",pf);
//    }
//    fclose(pf);
//    pf=NULL;
//    return 0;
//}


//int main(void)//演示一下默认流的使用           stdin:标准输入设备   stdout:标准输出设备
//{
//    //从键盘读取一行文本信息
////    char arr[100];//自己在程序中定义的变量是在内存中的，所以是输入到内存   用的也就是fgets（）操作的是输入流
////    fgets(arr,100,stdin);//将从键盘上得到的流输入到自己在内存中定义的数组中去         这里面输入换行，会将换行符号\n直接打印出来
////    fputs(arr,stdout);//将这个数组的中的字符串输出到这个流中（一般这个流是文件，也就是将指定的东西写入到某个文件中去），现在指定的是屏幕
//
//    char arr[100];
//    gets(arr);//这两个函数默认的流就是键盘和屏幕，     从键盘读         //但是使用这个函数时不安全的，没有设定缓冲区的大小
//    puts(arr);//从屏幕上输出
//}









//9.fprintf(）函数和 fscanf()函数
//fprintf()      函数定义：int fprintf(FILE* stream,const char* format[,argument]....]);       这个可以指定流进行输出，printf()这个函数就指定了输出的流是屏幕

//fscanf()       函数定义：int fscanf(FILE* stream,const char* format[,argument]...);       这个可以指定流里面的东西，往自己指定的内存输出（指定的内存：比如自己定义的变量）
//struct S
//{
//    int n;
//    float score;
//    char arr[10];
//};
//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//int main(void)//演示fprintf()的使用方法
//
//{
//    struct S s={100,3.14f,"bit"};
//    FILE* pf=fopen("../test.txt","w");//这些文件指针和标准输出标准输入是等价的。意思为输出的目标和输入的目标
//    if(pf==NULL)
//    {
//        printf("%s",strerror(errno));
//    }
//    else//格式化的形式写文件
//    {
//        fprintf(pf,"%d\n %f\n %s\n",s.n,s.score,s.arr);//这个函数可以指定输出流到哪里
//    }
//    fclose(pf);
//    pf=NULL;
//}


//int main(vpid)//fscanf()函数使用的例子
//{
//        struct S s={0};//现就要演示从文件中读取数据输入到s中去
//        FILE* pf=fopen("../test.txt","r");//这些文件指针和标准输出标准输入是等价的。意思为输出的目标和输入的目标
//        if(pf==NULL)
//        {
//            printf("%s",strerror(errno));
//        }
//        else//格式化的形式写文件
//        {
//            fscanf(pf,"%d\n %f\n %s\n",&s.n,&s.score,s.arr);//这个函数可以指定输出流到哪里
//        }
//        fclose(pf);
//        pf=NULL;
//        return 0;
//}


//int main()//两个标准流的演示
//{
//    struct S s={0};
//
//    fscanf(stdin,"%d%f%s",&s.n,&s.score,s.arr);
//    fprintf(stdout,"%d\n%3.2f\n%s\n",s.n,s.score,s.arr);
//}






//10.sscanf和sprintf
//（1）对比一组函数 scanf/fscanf/sscanf         printf/fprintf/sprintf

//scanf/printf:是针对标准输入流，标准输出流的格式化输入/输出语句

//fscnaf/fprintf:是针对所有输入流/输出流的格式化输入/输出语句

//sscanf/sprintf:
//sscanf     函数定义：int sscanf(const char*buffer,const char* format[,argument]..);  从一个字符串里面读一个格式化的数据
//sprintf    函数定义 int sprintf(char* buffer,char*buffer,const char* format[,argument]..)  写一个个格式化的数据到字符串中去

//sscanf和sprintf的使用
//#include<stdio.h>
//struct S
//{
//    int n;
//    float score;
//    char arr[100];
//};
//
//int main(void)//这俩函数常用格式化字符的拼接
//{
//    struct S s={100,3.14,"abcdef"};
//    char buf[1024]={0};
//    struct S tmp={0};
//
//    sprintf(buf,"%d %f %s",s.n,s.score,s.arr);//将这些格式化的数据整到这个数组字符串里面去
//    //把格式化的数据转换成字符串存储到buf字符串数组中
//    printf("%s\n",buf);
//
//    sscanf(buf,"%d %f %s",&tmp.n,&tmp.score,tmp.arr); //现在我们将要把上面的buf字符串里面的内容整到定义的结构体tmp中
//    //把buf字符数组中存储的格式化的数据读取到tmp中
//    printf("%d %f %s",tmp.n,tmp.score,tmp.arr);
//}
//总结：这两个函数并不是针对输入流和输出流的函数，一个是从字符串中读取格式化的数据    一个是把格式化的数据存储到字符串中









//11.二进制的输入和输出
//fread()以二进制的形式从文件里面读信息      fwrite()和以二进制的形式写入到文件里面去

//fwrite() 函数定义：size_t fwrite(const void char* buffer,size_t size,size_t count,FILE* stream);
//第一个参数：   被写入数据的地址    第二个参数：写入的元素的大小（单个字符的字节数）     第三个参数写入的元素的个数       第四个参数：流的地址

//fread() 函数定义：换了一下函数的名字，参数都是一样的。不同的是，这个函数是将文件中的内容读出并复制到给定的变量当中去
//这个函数的返回值就是读取文件中的数据块的个数。这个返回值和count有关，count假如是10，但是里面只有五个元素，就会返回5，

//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
////
//struct S
//{
//    char name[20];
//    int age;
//    double score;
//};
//
//int main(void)//首先是fwrite的例子
//{
//    struct S s={0};
//    FILE* pf=fopen("../test.txt","wb");//二进制的形式写入这个文件信息        这个写入和"w"都是先将文件清空再写入，没有这个文件就创建一个文件
//    if(pf==NULL)
//    {
//        fprintf(stdout,"%s",strerror(errno));
//    }
//    else
//    {
//        fwrite(&s,sizeof(struct S),1,pf);//成功的将创建的这个结构体变量以二进制的形式写入到了这个文件中
//    }
//    fclose(pf);
//    pf=NULL;
//    return 0;
//}

//int main(void)//现在展示一下fread（）函数的使用方法
//{
//    struct S s={0};
//    FILE* pf=fopen("../test.txt","rb");//以二进制的形式从这个文件中读出信息
//    if(pf==NULL)
//    {
//        fprintf(stdout,"%s",strerror(errno));
//    }
//    else
//    {
//        fread(&s,sizeof(struct S),1,pf);//从这个文件流中读取 1个结构体大小的变量，并将在这个变量保存到这个&s地址中去。
//    }
//    fprintf(stdout,"%s\n %d\n %lf\n",s.name,s.age,s.score);//输出的是0是因为上面的函数并没有输进去任何东西
//    fclose(pf);
//    pf=NULL;
//    return 0;
//}










//12.文件的随机读写  fseek（）函数
//fseek()     函数定义：  int fseek(FILE* stream,long int offset,int origin);     offest：抵消，偏移量
//这个函数可以移动文件指针到指定位置               第一个参数：文件指针         第二个参数：偏移量         第三个参数：文件指针的当前位置
//第二个参数： 偏移量offset的单位是字节，偏移了多少个字节就意味着指针向后移动多少位       偏移量可以为负数，负数就是向前
//将上面的这些参数翻译出来就是：从第三个参数（位置在下面的三个选项）的位置，向后（向前）移动几个字节。移动的就是第一个参数（也就是文件指针）
//
// 文件指针的起始位置有三个选项：
// （1）SEEK_CUR      文件指针的当前位置          current--当前的现在的
// （2）SEEK_END      文件中的末尾位置
// （3）SEEK_SET      文件起始位置
//
//根据文件指针的位置和偏移量来定位文件指针


//上面的函数都是按照顺序进行读取或者写入的，现在能不能考虑一个函数能从文件所需要的位置开始读取，也就是说文件指针直接指向需要的地址。

//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//int main(void)
//{
//    FILE* pf = fopen("test.txt", "r");
//    if (pf==NULL)
//    {
//        printf("%s", strerror(errno));
//    }
//
//    //接下来的步骤就得实现定位文件指针，并且得读取文件
//    //fseek(pf,2,SEEK_CUR);//现在就是以指针当前的位置向后偏移两个字节    中间的数字是偏移的字节数  。文件中存储的是abcdefg  ，现在输出的是c
//    fseek(pf,-5,SEEK_END);//文件中存储的是abcdefg，现在输出的还是c         SEEK_END这个位置类似于文件的\0处
//    int ch = fgetc(pf);
//    printf("%c\n", ch);
//
//    fclose(pf);
//    pf = NULL;
//}







//13.ftell函数   函数定义：long int ftell(FILE* stream);       tell告知---告知当前指针的偏移量
//这个函数是用来测试文件指针当前的的位置相对于文件开头的位置的偏移量
//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//int main(void)
//{
//    FILE* pf = fopen("../test.txt", "r");
//    if (pf==NULL)
//    {
//        printf("%s", strerror(errno));
//    }
//    printf("%d\n",ftell(pf));//这里是0，因为现在的指针位置还在起始位置
//    //接下来的步骤就得实现定位文件指针，并且得读取文件
//    //fseek(pf,2,SEEK_CUR);//现在就是以指针当前的位置向后偏移两个字节    中间的数字是偏移的字节数  。文件中存储的是abcdefg  ，现在输出的是c
//    fseek(pf,0,SEEK_SET);//如果这个数字不是1，下面计算偏移量也要记得这里的计算
//    int ch = fgetc(pf);
//    printf("%d\n",ftell(pf));//文件指针相对于当前位置的偏移量是1。是1的原因是因为，fgetc（）读取了一个字符，读取完之后指针向后移动了一位
//    printf("%c\n", ch);
//
//
//    fclose(pf);
//    pf = NULL;
//}








//13.rewind()函数            函数定义：void rewind(FILE* stream)          wind---迂回缠绕     re---再一次又一次    将这个指针重置到文件的起始的位置
//让当前的文件指针回到文件的起始位置
//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//int main(void)
//{
//    FILE* pf=fopen("../test.txt","r");
//    if(pf==NULL)
//    {
//        printf("%s\n",strerror(errno));
//    }
//
//    fseek(pf,1,SEEK_SET);//将文件指针向后偏移1个字节     此时指向b
//    int ch=fgetc(pf);//ch获得一个字符b后。此时指向c
//    printf("%c\n",ch);//输出偏移了两个字节后指针指向的字符
//
//    fseek(pf,1,SEEK_CUR);//相对于当前位置再向后偏移一位     此时指向d
//    printf("%c\n",fgetc(pf));
//
//    rewind(pf);//下面输出的是a，这个函数是返回文件的起始位置的
//    printf("%c\n",fgetc(pf));
//
//    fclose(pf);
//    pf=NULL;
//}







//14.文件结束判定

//feof()  这个函数并不是用来判断文件是否结束的                 文件结束标志是：EOF-end of file     EOF 在定义中是 #define EOF -1
//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//int main(void)
//{
//    FILE* pf=fopen("../test.txt","r");
//    if(pf==NULL)
//    {
//        return 0;
//    }
//    char ch;
//    ch=fgetc(pf);//打开的文件最后面一个字节是EOF也就是文件结束标志     这个字符也就是-1
//    if(ch==EOF)
//        printf("%d\n",ch);
//
//    fclose(pf);
//    pf=NULL;
//}


//牢记：在文件读取的过程中，不能用feof()函数的返回值直接判断文件的读取是否结束
//而是应当应用于文件读取已经结束的时候。这个结束的原因是什么，是因为读取失败？还是因为遇到文件尾结束

//文本文件读取是否结束，判断返回值是否为EOF(用fgetc)  或者NULL（fgets)
//也就是fgetc判断返回是否为EOF    fgets判断返回值是否为NULL，              fgetc--返回的是读取的字符的ascll
//fgetc在遇见没有字符可读取的时候会读取EOF这个就在文件的最后。         fgets在遇见空白行的时候就会读取NULL;

//二进制文件判断是否读取结束，判断返回值是否小于实际要读取的个数
//因为fread返回的是读取的实际的数据块，如果想要读取10个，但是返回值为9，就说明里面的数据块只有9个，也就是读取完了




//文本文件返回错误演示
//#include<stdio.h>
//int main(void)
//{
//    int c;//注意这里的int c而不是char c，这是要用来处理EOF的
//
//    FILE* pf=fopen("../test.txt","r");
//    if(pf==NULL)//(!pf)是什么写法?
//    {
//        perror("读取错误");
//    }
//    int i=0;
//    while((c=fgetc(pf))!=EOF && i<=3)//二进制文件就是这样的  fread(&b,sizeof(double),1,pf)>=1
//    {
//        printf("%c\n ferror函数值：%d\n",c,ferror(pf));//printf("%lf",b);
//        i++;
//    }
//
//    if(ferror(pf))//ferror这个函数是用来判断文件是否读取错误的    函数定义：int ferror(FILE* stream) 检测流上是否有错误
//        //等上面的文件操作函数运行完毕后，就会进行检验这个流。判断流中是否出现错误，如果错误就会说明是因为不是正当的读取造成的停止
//        //每一次文件操作函数在上面正常的读取，这个函数都会产生一个新的值，一般都是0，这是没有错，返回其他值就会出错
//        //这个ferror函数主要是用来判断那些文件操作函数在使用的过层中是否出现了错误，不错返回值为0，出错返回值为非0
//        //如果规定取出几个字符就停止，这个函数还是返回0
//    {
//        puts("I/O error when reading");//这个是读取错误
//    }
//    else if(feof(pf))//正常情况的结束下，检测指针指向的是EOF还是NULL，看上面的函数怎么样的读取方式。正常的情况是返回1
//    {
//        printf("END of file reached successfully\n %d",feof(pf));//遇见了一个文件的结束标志
////        feof只能判断文件末尾的NULL和EOF，如果取几个有限的字符就停止函数，这个feof就不会进行判断。
//             也就是说，这个文件指针只有指向的是文件的末尾的时候并且正常停止的时候，这个feof（pf）才会返回1.其余情况返回的是0
//    }
//
//    fclose(pf);
//    pf=NULL;
//    return 0;
//}





