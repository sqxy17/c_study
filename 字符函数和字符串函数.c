//前言：c语言中对于字符和字符串的处理很频繁，但是C语言本身是没有字符串类型的，字符串通常是放在常量字符串中或者字符数组中。字符串常量适用于那些对它不做修改的字符串函数

//1.求字符串长度
//strlen()
//strlen()这个函数返回的类型是size_t，也就是unsigned int的类型               -----也就是统计了几个字符数字就返回多少

//#include<stdio.h>
//#include<string.h>
////计数器的模拟实现方法                另外还有递归的实现方式      指针减去指针的实现方式
//int my_strlen(const char* arr)
//{
//    int count=0;
//    while(*arr)//解引用出\0在while中会被判断为假，也就会停止循环,后面的循环条件中如果只有字母符号之类的，字符会转换成ascll值进行判断  例如 'a'97  '\0'0
//    {
//        count++;
//        arr++;
//    }
//    return count;
//}
//
//int main(void)
//{
//    char arr[]="hello word";
//    int num=my_strlen(arr);
//    printf("%d",num);
//    if(strlen("abc")-strlen("abcde")>0)//因为这个函数返回的数字只是无符号数字，两个无符号数字相减不可能是负数
//    {
//        printf("这两个返回数字相减大于0");
//    }
//    else
//    {
//        printf("这两个返回的数字相减是小于0的");
//    }
//}







//2.长度不受限制的字符串函数
//strcpy()   strcat()   strcmp()



//strcpy()                        -----strcpy--string copy  字符串拷贝
//源字符串必须以\0结束     会将源文件中的\0拷贝到目标空间       目标空间必须足够大，以确保能够保存原字符串        目标空间不能为常属性     学会模拟实现
//注：源原字符串也就是后面的字符串       目标空间是一个空白的数组          不能自己拷贝自己
//arr1字符串在拷贝后，原先保存的字符串消失

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
////
//////模拟函数strcpy
////char* my_strcpy(char* arr1,const char* arr2)//arr2字符串在拷贝完成后并不会消失。原函数也一样      arr1这个字符串必须是可变的，也就是不能为常量字符串
////{
////    assert(arr1!=NULL);//后面括号里面的跟着的是需要满足的条件，如果不满足就报错
////    assert(arr2!=NULL);
////    char *str=arr1;
////    while(*arr1++ = *arr2++)//判断条件中也可以进行赋值，前面的变量被赋值为0是就会停止，单独放一个'\0'也会停止。
////    {
////        ;
////    }
////    return str;
////}
////int main(void)
////{
////    char arr1[]="abcde";
////    char arr2[]="fghij";
//////    strcpy(arr1,arr2);//这个意思是将arr2中的内容拷贝到arr1中
//////    printf("%s",arr1);//拷贝之后，arr1中的实际存放情况是fjhij\0abcde\0,原先的字符串并没有消失，拷贝的字符串带上\0直接放在了原先的字符串的前面
////    my_strcpy(arr1,arr2);
////    printf("%s",arr1);
////}
//
//
////strcat 字符串追加
////这个函数是将arr2得到内容追加到arr1的后面去                     -----源字符串指的是arr2
////源字符串必须以\0结束     目标空间必须足够大，能容纳下源字符串的内容     目标空间必须可修改      不能自己追加自己     模拟实现
//
//my_strcat(char* arr1,char* arr2)//函数的模拟实现
//{
//    char* str=arr1;//将最开始的arr1的首地址进行保存
//    //第一步，找到目标空间\0的位置
//    while(*arr1!='\0')//直到找到\0的地址才会停止，停止的时候地址已经变为\0的地址
//    {
//        arr1++;
//    }
//    //第二步，进行追加
//    while(*arr1++=*arr2++)//这一步会在arr1\0位置处进行追加，直到添加完arr2的\0才会停止
//    {
//        ;
//    }
//    return str;
//}
//
//int main(void)
//{
////    char arr1[]="hello";
////    char arr2[]="word";
////    strcat(arr1,arr2);//这种写法会造成越界访问，需要先给arr1一个足够大的空间
//
////    char arr1[10]="hello";
////    char arr2[]="word";
////    strcat(arr1,arr2);//这才是正确的写法,arr2会带着\0追加到arr1后面，并且原本的arr1后面的\0会消失，arr1\0的位置会变成arr2的首个字符
////
//
////    char arr1[30]="hello\0xxxxxx";//arr2会在arr1字符串中的第一个\0处开始追加
////    char arr2[]="word";
////    strcat(arr1,arr2);
//
//    char arr1[15]="hello";
//    char arr2[]="world";
//    my_strcat(arr1,arr2);
//    printf("%s",arr1);
//}



//strcmp（）字符串比较函数    比较两个字符串是否相同，从第一个字符开始比较，直到\0，不管两个字符串的长短，只要中间有一对字符比较时出现ascll不一样的情况
                           //arr1里的字符大于arr2里的字符的就返回1(vs环境下)，小于的就返回-1（vs环境下）
                           //但是在gcc编译器下，在一对字符中返回的是arr1那个字符的ascll减去arr2中的那个字符的ascll的差值（strcmp(arr1,arr2））就是前面
                           //的减去后面的，（arr2,arr1）那就是arr2-arr1     总结就是大于的返回正数，小于的返回负数，正数负数刚好是那一对的ascll差值
                           //这个函数知识比较两个字符串是不是相同，但不能比较长短

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
////模拟函数strcmp的实现
//int my_strcmp(const char* arr1,const char* arr2)
//{
//    assert(arr1 && arr2);
//    while(*arr1==*arr2)//只有每对字符都相同时才会返回0
//    {
//        if(arr1=='\0')//这是最后一对相同并且两个都是\0那就证明这两个字符串是一样的了
//        {
//            return 0;
//        }
//        arr1++;
//        arr2++;
//    }
//    return (*arr1-*arr2);//碰到一对字符不一样直接返回他们两个的差值
//}
//
//int main(void)
//{
//    int *arr1="abcdef";
//    int *arr2="abc";
//    int *arr3="abc";
////    if("abc"==arr2==arr3)//里面这样的比较是字符串的地址，并且因为是常量字符串，所以指向的是一样的,所以这样的比较方式是错误的
////    {
////        printf("一样的");
////    }
//    int num=my_strcmp(arr1,arr2);
//    printf("%d",num);
//}









//3.长度受限制的字符串函数介绍          对后面操作的长短进行了限制
//strncpy()   strncat()   strncmp()

//strncpy(char* dest,const char* str,size_t count)选择性的拷贝，也就是对拷贝的内容做了长度的限制.最后的参数单位是字节。    只是恰好字符位1字节

//#include<stdio.h>
//#include<string.h>
//
////模拟实现指定个数的字符串拷贝
//char* my_strncpy(char* arr1,char* arr2,int num)//这里设置为int，是因为这个是用于字符串的函数，而且刚好字符的大小是一字节
//{
//    int count=0;
//    char* str=arr1;
//    while(count!=num)
//    {
//        *arr1++=*arr2++;
//        count++;//直到最后一个字符被拷贝到前面，现在count是3，此时arr2已经是\0了
//        if(*arr2=='\0')
//        {
//            while(count!=num)
//            {
//                ++count;
//                *arr1='\0';
//                arr1++;
//            }
//            break;
//        }
//    }
//    return str;
//}
//
//int main(void)
//{
////    char arr1[5]="abc";
////    char arr2[]="hello world";
////    strncpy(arr1,arr2,4);//这个函数的功能就是指定源字符串中的字符个数，拷贝进目标空间。注意，指定的个数里面要是没有\0那就没有\0，而且指定的那些字符会放在目标
////    //空间的最前方，并且，如果目标空间中有字符没有指定长度的字符覆盖，那么在打印这个拷贝完成的字符串时会打印出来。直到碰到\0
////    printf("%s",arr1);
//
//    char arr1[10]="abcdexxxxx";
//    char arr2[]="bit";
////    strncpy(arr1,arr2,6);//arr2中也就4个字符（算上\0），但是却拷贝了6个字符到目标空间。剩余的两个会补成\0
//    my_strncpy(arr1,arr2,6);
//    printf("%s",arr1);
//}



//strncat()指定了追加字符串的个数
//#include<stdio.h>
//#include<string.h>
//
////模拟my_strncat
//char* my_strncat(char* arr1,char* arr2,int num)
//{
//    char* str=arr1;
//    int count=0;
//    while(*arr1!='\0')
//    {
//        arr1++;
//    }
//    while(count!=num)
//    {
//        *arr1=*arr2;
//        if(*arr2=='\0')//追加的字符串小于指定的长度
//        {
//            break;
//        }
//        arr1++;
//        arr2++;
//        count++;
//    }
//    if(*arr2!='\0')
//    {
//        *(arr2+1)='\0';
//    }
//}
//
//int main(void)
//{
//    char arr1[30]="hello";
//    char arr2[]="word";
////    strncat(arr1,arr2,6);//指定了追加的个数，并且是在arr1第一个\0处开始进行，追加完毕后会自动在末尾补上一个\0，如果追加的长度比字符个数还多，在追加完arr2的\0后
////    //后面的就不管了，依然是arr1的字符
//    my_strncat(arr1,arr2,3);
//    printf("%s",arr1);
//}




//strncmp(const char* arr1,const char* arr2,size_t count)指定字符串的前几位进行比较     (size_t代表着一个无符号整型，也就是要比较多少个字节)
//自己模拟实现

//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//    const char* p1="abcde";//将常量字符串的地址赋值给指针1的时候最好加上一个const修饰*p
//    const char* p2="abcsi";
////    printf("%d",strcmp(p1,p2));//这是上面不限制长度的比较字符串函数
//    printf("%d",strncmp(p1,p2,3));//这个就是指定长度的进行比较        返回的值和上面的那个函数是一样的
//}










//4.字符串查找
//strstr()   strtok()

//strstr(const char* arr1,const char* arr2)查找arr2这个字符串是否在arr1中的子字符串存在
//查找的到就返回第一次出现的的地址，查找不到就返回空指针NULL              自己模拟实现
//在输出的时候会从返回的地址一直输出到\0。

//
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
////自己实现的
//char* my_strstr(const char* arr1,const char* arr2)
//{
//    assert(arr1 && arr2);
//    char* parr1=(char*) arr1;//用来保存首元素的地址，方便后续得比较
//    char* parr2=(char*) arr2;
//    //首先防止arr2或者arr1是一个空数组   空数组里面的元素是\0
//    if(*arr2=='\0' || *arr1=='\0')//其中一个字符串为空字符串都会直接返回空值
//    {
//        return NULL;
//    }
//    while(*parr1)//将arr1的字符串的每个字符都往后与arr2进行比较，直到arr1的\0
//    {
//        arr1=parr1;//每次从开头的字符比较时先初始化，往后进行一位
//        arr2=parr2;//parr2保存的地址不进行变化，就是为了反复比较
//        while(*arr1==*arr2)//一对字符相同时才会进行继续的比较      arr1比arr2短的时候会出现\0和字符的比较，不会进行循环
//        {
//            arr1++;
//            arr2++;
//            if(*arr2=='\0')//循环到最后一次的时候，如果*arr2刚好等于0，那么就是全部的都匹配
//            {
//                return parr1;
//            }
//        }
//
//        parr1++;
//    }
//    return NULL;//上面的循环没了还没发现就返回空值
//}


////鹏哥实现的
//char* my_strstr(const char* arr1,const char* arr2)
//{
//    assert(arr1 && arr2);//对两个指针进行断言，避免传入空指针的情况
//    char* parr1=NULL;
//    char* parr2=NULL;
//    char* cur=(char*)arr1;//cur是用来保存p1的首地址的    这里面的强转是因为定义的是p1为const char*p1
//    if(*arr2=='\0')//arr2的字符串是一个空的
//    {
//        return NULL;
//    }
//    while(*cur)//对p1字符串挨个往后进行比较，对于
//    {
//        parr1=cur;//s1是用来进行从此位置往后进行比较的
//        parr2=(char*)arr2;
//        while(*parr1 && *parr2 && (*parr1==*parr2))//在没有比较到最后一个字符之前，都会进行循环，不管是s1字符串还是s2字符串
//        {
//            parr1++;
//            parr2++;
//        }
//        if(*parr2=='\0')
//        {
//            return cur;//找到子串
//        }
//        cur++;//首个元素往后进行加一
//    }
//    return NULL;//找不到子串
//}


//char* my_strstr(const char* arr1,const char* arr2)//纯粹自己的思路
//{
//    int sz=strlen(arr2);
//    char* parr2=arr2;
//    char* parr1=arr1;
//    if(*arr2=='\0' || strlen(arr1)<strlen(arr2))  //如果是自己实现的函数，尽量不要去调用第三方函数
//    {
//        return NULL;
//    }
//    while(*arr1!='\0')
//    {
//        arr1=parr1;
//        arr2=parr2;
//        if(*arr1==*arr2)//判断第一个字符和arr2的首字符是否相同，相同的就往后比较sz-1个，出现不相同的就往后一个字符和arr2的首字符继续比较
//        {
//            int i=0;
//            for(i=0;i<sz;i++)
//            {
//                if(*arr1==*arr2)
//                {
//                    arr1++;
//                    arr2++;
//                }
//                if(*arr2=='\0')//直到比较到\0之前的元素都是一样的，说明存在子字符串
//                {
//                    return parr1;
//                }
//            }
//        }
//        parr1++;//截取完之后向后移动一位继续截取
//        if(parr1+sz-1=='\0')//用于判断还能不能截取与arr2长短相同的字符串，不能截取就直接返回
//        {
//            return NULL;
//        }
//    }
//    return NULL;
//}

//int main(void)
//{
//    const char* arr1="gsdfgdfgdfsgsdfgsdfh";
//    const char* arr2="gsdfh";
////    char* ret=strstr(p1,p2);//查找p2这个字符串是否存在于p1的子串中
//    char* ret=my_strstr(arr1,arr2);//接收返回的地址
//    if(ret==NULL)
//    {
//        printf("不存在于该子串中");
//    }
//    else
//    {
//        printf("%s",ret);//如果查找的到，就会返回从第一次出现的地址，直到打印结束
//    }
//}



//strtok()字符串切割函数      char* strtok(char* str,const char* sep),
//sep代表的是你用于切割的字符，并且切割符可以不止设定一个，切割符是保存在数组当中的
//工作原理：比如abc@def.hij   切割符号是@和.   首先找到@,把@这个字符改成\0，然后返回a的地址     再次调用时会从d的位置开始找，找到.并将.改为\0返回d的地址
//再次调用的时候从h的位置往后找，遇见\0，说明没有分割符了，返回h的地址（碰见第一个\0就会认为后面没了）

// str字符串是原字符串，包含了所有的字符。         sep字符串包含的是所有的切割符       。这两个字符串都是放在数组当中去的
//第一个参数指定一个字符串，它包含了0个或者多个sep字符串中的分割符，可以没在第一个参数中出现

//strtok函数找到str中的下一个标记，并将其\0结尾，返回一个指向这个标记的指针。（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝
//的内容并且可修改)>>>>>也就是说最好先复制一份待切割的字符串，切割完后会改变原字符串的内容）

//strtok函数的第一个参数不为NULL,函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。也就是说保存了字符出现的位置，哪怕是被改变以后也会保存

//strtok函数的第一个参数为NULL,函数将在同一个字符串中上一次被保存的位置开始，查找下一个标记。也就是第一次调用后，后面再去使用strtok函数第一个参数就得为NULL,看见NULL
//就会从上一次保存的位置开始进行查找下一个标记

//如果字符串中不存在更多的标记，则返回NUll指针。也就是上面的t的地址都返回了还去调用这个函数，则返回NULL


//#include<stdio.h>
//#include<string.h>j
//int main(void)
//{
////    char arr1[]="192.168.31.121";//后面的这个字符串是被.分割出来的小字符串192 168 31 121组成的，如果想拿出来这些小字符串就可以用这个函数拿出来
////ip地址的这种表示方式叫做点分十进制
//
//    char arr1[]="abc@def. .hij";//哪怕是分割符挨着，也能将小字符串成功的切出来碰见的时候只是将分割符改为\0并不返回值
//    char arr2[30];
//    char sep[]="@.";
//    strcpy(arr2,arr1);
////    printf("%s\n",strtok(arr2,sep));//这就是最基本是使用方法
////    printf("%s\n",strtok(NULL,sep));
////    printf("%s\n",strtok(NULL,sep));
//
//
//
//    //鹏哥的高级调用方式
//    char* ret=NULL;
//    for(ret=strtok(arr2,sep);ret!=NULL;ret=strtok(NULL,sep))//刚好初始化的代码之使用了一次
//    {
//        printf("%s\n",ret);
//    }
//
//}
//如果想自己实现里面的变量一定包括一个静态变量。因为传NULL也能进行调用










//5.错误信息报告
//strerror()       strerror(int errnum)这个数字参数是0 1 2 3 4是错误码，函数的返回值是地址，也就是所对应的错误信息
//0- no error     1- operation not permitted    .......
//每一个错误码代表着一个错误信息，这个错误信息是描述这个错误码的
//函数的功能：返回错误码，所对应的错误信息。      必须包含的头文件#include<errno.h>
//#include<stdio.h>
//#include<errno.h>//全局变量errno的头文件
//#include<string.h>
//int main(void)
//{
////    char* ret=strerror(errno);//errno是一个全局的错误码变量，当C语言的库函数在执行的过程中发生了错误，就会把对应的错误码赋值到errno中
////    printf("%s",ret);
////   对文件的操作
//    FILE* pf=fopen("test.txt","r");//函数的意思为：以r(read 读)的方式打开test.txt这个文件    这个函数会返回一个FILE类型的指针
//    //正常情况下会打开这个文件，打不开就会返回空指针，在返回空指针的同时errno这个全局错误码变量会接收一个错误码
//    //这个文件需要添加到debug中
//
//    if(pf==NULL)//打不开的同时fopen会返回一个空指针      同时全局错误码变量(errno)也会受到一个错误码
//    {
//        printf("%s\n",strerror(errno));//strerror(errno)这个函数会将错误码的错误码的地址返回，也就是所对应的错误信息
//    }
//    else
//    {
//        printf("open file success");
//    }
//}


//另外还有一个函数也是用来打印错误信息的，和上面的作用大致相同就是使用的方式有些许不一样
//perror()  这个函数，比如perror("hehe")    如果出现错误会先把括号里面的信息打印出来并：错误信息     hehe:no such file ....这样









//6.字符操作函数
//字符分类函数       这些函数都是用来判断的，如果参数符合后面的条件就返回真     返回非0为真，0为假
//iscntrl()           任何控制字符
//
//isspace()           空白字符："空格"  换页'\f'  换行'\n'  回车'\r'  制表符'\t'  垂直制表符'\v'
//
//isdigit()           十进制数字0~9        头文件是ctype.h,和下面的一样
//
//isxdigit            十六进制数字0~F
//
//islower             小写字母a~z
//
//isupper             大写字母A~Z
//
//isalpha             字母a~z以及A~Z
//
//isalnum             字母或数字a~z A~Z 0~9
//
//ispunct             标点符号，任何不属于数字或者字母的图形字符（能打印的）
//
//isgraph             任何图形字符
//
//isprint             任何可打印字符，包括图形字符和空白字符



//字符转换函数
//tolower()       大写转换小写     非字母字符不做处理
//toupper()       小写转换成大写







//7.内存操作函数
//memcpy()   memmove()   memset()   memcmp()      字符操作函数操作的是字符串，和字符串数组。但是对整型的，结构体之类的东西并没有办法进行操作
// （因为很多字符串函数的参数都是char*类型的

//memcpy()内存拷贝函数
// 最后一个参数是字节数大小也就是想把sou里面的num字节拷贝进前面的空间
//前两个参数都是空间，也就是地址，最后一个参数的单位是字节
//函数memcpy从sou的位置开始向后复制num个自己的数据到des的内存位置
//这个函数在遇到\0时并不会停下来
//如果sou和des有任何的重叠，复制的结果都是未定义的                   ----这句话的意思是这两个数组在空间上不能有重叠的部分
//复制的时候是先从内存的低地址开始进行复制的
//c语言标准规定，memcpy只要能拷贝空间不重叠的字符串就行，虽然库函数也能够进行空间重叠的字符串拷贝

//void*-通用类型指针

//#include<stdio.h>
//#include<memory.h>
//#include<assert.h>

//经典的my_memcpy()                     size_t是typedef unsigned int size_t;          -----也就是本质上是一个长整形
//void* my_memcpy (void* p1,void* p2,size_t num)//复制多少个字节就循环多少次     但是这种方式是需要两个空间没有尽心重叠，也就是两个不同的空间
//{
//    void* ret=p1;
//    assert(p1 && p2);
//    for(num;num>0;num--)
//    {
//       *(char*)p1=*(char*)p2;//一次就复制一个字节
//        p1=((char*)p1)+1;//也可以改为++（char*)p1,但是循环次数得相应改变
//        p2=((char*)p2)+1;//和上面一样
//    }
//    return ret;
//}
//
//int main(void)
//{
//    int arr1[5]={};
//    int arr2[]={1,2,3,4,5};
//    memcpy(arr1,arr2,sizeof(arr2));

//    struct stu
//    {
//        char name[30];
//        char sex[5];
//        int age;
//    };
//    struct stu stu1={"zhangsan","男",17};
//    struct stu stu2;
//    memcpy(&stu2,&stu1,sizeof(stu1));//前两个参数是地址，后面的参数是需要复制到前面的空间的字节数大小
//    printf("%c\n",stu2.name[0]);

//    my_memcpy(&stu2,&stu1,sizeof(stu1));
//    printf("%s",stu2.name);
//}








//memove()  这个函数是用来处理复制的空间如果重叠的情况        void* memmove(void* dest,const void* src,size_t count)
//复制的时候需要考虑空间重叠的情况，如下
//#include<stdio.h>
//#include<memory.h>
//#include<assert.h>
//
////实现memmove     有重叠的情况下总体思路：待移动字符串首地址小于目标空间首地址，从后往前复制，如main函数里面的那个arr1数组，先将5放到7的位置上，然后6放到5的位置上.....
////                                    待移动字符串首地址大于目标空间首地址，从前往后复制.
////               空间不重叠的情况下：从前往后从后往前都可以
//
//void* my_memmove(void* dest,void* src,size_t count)//dest:目的地   src：源代码,
//{
//    assert(dest && src);
//    void* ret=dest;
//    if(dest<src)//也就是目的地的地址小于源代码的地址        -----举个例子就是将数组后面的元素放到前面
//    {
//        while(count--)
//        {
//            *(char*)dest++=*(char*)src++;//强制类型转换的优先级 大于++的优先级 大于*解引用的优先级  后置++是先解引用在进行++，并且++的是已经强制类型转换后的地址
//        }
//    }
//    else//也就是目的地的地址大于字符串的地址
//    {
//        while(count)
//        {
//            *((char *) dest + count-1 ) = *((char *) src + count-1 );
//            count--;
//        }
//    }
//    return ret;
//}
//
//int main(void)
//{
//    int arr1[9]={1,2,3,4,5,6,7,8,9};
//    int arr2[9]={1,2,3,4,5,6,7,8,9};
//    int i=0;
//
//    my_memmove(arr1,arr1+2,16);//将3456  移动到 1234的位置上去
//    my_memmove(arr2+2,arr2,16);//将1234  移动到 3456的位置上去
//   for(i=0;i<9 ;i++)
//   {
//       printf("%d ",arr1[i]);
//   }
//   printf("\n");
//   for(i=0;i<9;i++)
//   {
//       printf("%d ",arr2[i]);
//   }
//}







//memcmp（）   内存比较函数   int memcmp(const void* arr1,const void* arr2,size_t num)//最后的参数还是字节数
//里面具体的比较方式和strcmp基本相同，在某一个位置一对字节相比较，arr1>arr2返回大于0的数，小于就返回小于0的数，等于就返回0







//memset(）内存设置函数       void* memset(void* dest,int c,size_t num) c其实是设置的字符是什么
//先放参数dest也就是想要修改的空间     再放int c,这c参数可以是字符也可以是数字。也就是想把内存变为这个参数       num经典的字节数
//函数.c里面有，经常用的方式也就是在char[]数组里面
//#include<stdio.h>
//#include<memory.h>
//int main(void)
//{
//    char arr[10];
//    memset(arr,'i',sizeof(arr));
//    arr[9]='\0';
//    printf("%s",arr);
//    return 0;
//}