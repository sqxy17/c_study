
//1.一维数组的创建和初始化
//数组是一组相同类型元素的集合。  创建形式   类型 变量名[这个括号里面可以有个数可以没有,如果是字母一定要是一个常量，不能用变量]
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3 };//这种情况叫不完全初始化。剩下的元素默认为0
//	printf("%d,%d\n",arr[6],sizeof(arr));//虽然没有被定义但是打印出来的是0
//	printf("%d\n", strlen(arr));//这个函数只能计算字符数组的元素个数，并不能计算整型数组元素的个数
//
//	char arr1[5] = { 'a','b','c' };//这种也叫不完全初始化，剩下的元素也是默认为0
//
//	char arr2[6] = "abc";//这种初始化方法传进去a,b,c,\0   arr3[3]虽然输出的是0,但是传进去的是\0
//	printf("%c\n", arr2[3]);
//
//	char arr3[] = "abc de";//这种初始化的方式是传进去了6个元素（\0）
//	printf("%d,%d", sizeof(arr3), strlen(arr3));//sizeof是计算占用总字节的\0这种无效字符也包含在内。  strlen是计算字符个数的，空格算字符。碰见\0就停止但不计入\0
//	//int的字节是4，char所占用的字节是1；    stlen是求字符串长度的且只能针对字符串求长度 ，使用要引用头文件     计算的单位是字节  
//
//	char arr3[] = { 'a','s','t' };//这种如果使用strlen检测长度，输出的长度是随机的。在{}里面输入的就是全部，不会自己添加一个\0
//  此外还需要注意的是这样的形式 char arr[5]="abcde"    刚好十五个字符，数组中没有保存\0,在以%s或者strlen计算的时候还可能会出现错误

//	return 0;//strlen输出的字符是一个无符号整型
//}//strlen
//


//2.一维数组在内存中的存储
//%p打印的是地址   

//数组在内存中连续存放的，；里面的元素也是低地址到高地址          -----数组元素先存放在低地址，再存放在高地址


//3.二维数组的创建和初始化
//基本类型 int arr[3][4]     char arr[4][5]   double arr[3][4]表格的形式，前面的数字表示行，后面的数字表示的是列。有几列也就表示这一行能存多少元素
//每一行的下标都是从零开始的

//int arr[3][4]={1,2,3,4,5}这种形式的初始化是现将1234放满第一行，再开始将5放到第二行
//int arr[3][4]={{1,2,3},{4,5}}；{}里面的每一个大括号就代表这一样存储的元素
//int arr[][?]={1,2,3,4,5,6};[]里面没元素的初始化方式，列里面的元素不能省略，否则会报错        ---------也就是二维数组定义的时候列的下标不能省略


//4.二维数组在内存中的存储
//二位数组在内存中存储也是连续的（线性关系）
// 
//往往我们写代码的时候，会将数组作为参数传个函数，比如：我要实现一个冒泡排序函数将一个整型数组排序
// 
//将数组作为参数进行传参，传递的其实是数组收元素的地址
// 
//数组名就是首元素的地址（有两种情况是意外），1.sizeof(数组名)计算的就是整个数组的大小   2.&数组名，取出的是数组的地址，表示整个数组
// 
//数组的单个元素地址加一显示的是下个元素的地址      &数组名+1  这样的是将这真整个数组跳过去显示的是跳过去后紧挨着的地址

//char arr[]={"dasd"};printf("%s",arr),将会打印出来这串字符，如果是 char*p=arr；printf("%s",p)；打印出来的同样是字符。

//数组名本身就是地址了，不需要再去进行取地址

//补充：二维数组的数组名除了那两种情况之外，代表着第一行的地址    数组名+1 代表第二行的地址

//二维数组的几行元素地址都是挨着的

//可以直接使用数组名打印字符串数组

