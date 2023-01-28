
//#include<stdio.h>
//int main()
//{
//	//int ch = getchar();//从键盘获取一个字符，只能获取一个，类型可以是char,也可以是int,输进去多个就取第一个
//	//putchar(ch);//和下面的printf作用相同，输出得到的字符
//	//printf("%c", ch);
//	//return 0;
//	 int ch1 = 0;
//	 while (ch1 = getchar() != EOF);//这个--EOF--end of file值为-1，文件结束标志           这里想获取这三个字符按Ctrl+z,能直接获三个字符
//                                  //EOF 相当于字符串后面的\0，是一个文件结束标志.因为字符的ascll码是0~127，不会出现-1
//	 {
//		 putchar(ch1);
//	 }
//	 return 0;
//}

//getchar  scanf碰到空格或者回车会停止读取
//#include<stdio.h>
//int main()
//{
//	char password[20] = { 0 };
//	int num=0;
//	int  ch=0;
//	
//	printf("请输入密码：");
//	scanf("%s", password);//scanf和getchar用这俩获得的内容叫输入函数，例如password和num            在你输入内容之前会有一个《输入缓冲区》，这个缓冲区就是在等待你输入内容
//	                   //等你输入后这些东西会放在这个缓冲区里面，然后scanf或者getchar会拿走你输入的他需要的内容。
//	/*getchar();*/
//
//	printf("确认输入的密码是否正确Y/N\n");
//	num = getchar();//上面的输入密码然后 回车，注意，这个回车也有一个ascll码值，但是在scanf中并不读取，所以留在了缓冲区，因此直接被getchar()直接读取，并没有你输入YN的机会
//	//while (ch = getchar != '\n')//解决办法：可以用循环套用获得回车空格之类的,直到读取结束符号
//	//{
//	//	;
//	//}
//	if (num == 'Y')
//	{
//		printf("密码正确");
//	}
//	else
//	{
//		printf("密码错误");
//	}
//
//	scanf("%s", password);
//	/*int a = getchar();//getchar获得的是ascll码的编号，你输入一个字母它会转换成相应的ascll值
//	printf("%d", a);*/
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int ch = 0;
//	while (ch = getchar() != EOF)//getchar获取的是你输入的字符的ascll码值，putchar是将ascll码值转换为相应的字符并且输出
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//		putchar(ch);
//		
//	}
//	return 0;
//}