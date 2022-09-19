/***********************8.1只有到标识符#的时候才停止输入 ***************/
//#include <stdio.h> 
//int main(void)
//{
//	char ch;
//	while((ch = getchar()) != '#') 
//		putchar(ch);
//	return 0;
//}

/**********8.2只有当ctrl+z表示文档末尾的时候才停止输入 ***********/
//#include <stdio.h>
//int main(void)
//{
//	int ch;
//	while((ch = getchar()) != EOF)
//		putchar(ch);
//	return 0;
//} 
 
/*********************8.3重定向文件 *************************/
//#include <stdio.h>
//#include <stdlib.h>	//为了使用exit() 
//
//int main()
//{
//	int ch;
//	FILE * fp;
//	char fname[50];//储存文件名 
//	
//	printf("Enter the name of the file:");
//	scanf("%s",fname);
//	fp = fopen(fname,"r");//打开待读取文件 
//	if(fp == NULL)//如果读取失败 
//	{
//		printf("Failed to open file.Bye\n");
//		exit(1);//退出程序 
//	}
//	while((ch = getc(fp)) != EOF)
//		putchar(ch);
//	fclose(fp);//关闭文件 
//	return 0;
//} 

///***************8.4使用缓冲输入，同时会发送换行符，需要妥善处理麻烦的换行符*********************/
//#include <stdio.h>
//int main(void)
//{
//	int guess = 1;
//	char response;//定义一个变量来获取输入 
//	 
//	printf("tip:\n");//猜一个从1-100的数，通过n和y表示对的或者错的，一个一个猜下去 
//	while((response = getchar()) != 'y')//直接读取会一次性读取到输入以及换行符 
//	{
//		if(response == 'n')
//			printf("%d\n",++guess);
//		else//来规避除了n以外的输入 
//			printf("I dont konw\n");
//		while(getchar() != '\n');//直接跳过换行符 
//			continue;
//	}
//	return 0;
//}

///***************8.5 数字和字符混合输入 *********************/
//#include <stdio.h>
//
//void display(char cr,int lines,int width) 
//{
//	int row,col;
//	for(row = 1; row <= lines;row++)
//	{
//		for(col = 1;col <= width;col++)
//			putchar(cr);
//		putchar('\n');
//	}
//}
/////*********************错误的版本 8.5**************/ 
//////int main(void)
//////{
//////	int ch;//int类型读取字符，为了检测EOF 
//////	int rows,cols;
//////	printf("tip:\n");
//////	while((ch = getchar()) != '\n') //读取每个字符包括 空格，制表符，换行符 
//////	//按逻辑想要一次又一次读取，但是只读取一次就结束了，由于getchar()捕捉到了输入的换行符                        
//////	{
//////		scanf("%d %d",&rows,&cols);//能读取数字跳过 空格，制表符，换行符 
//////		display(ch,rows,cols);
//////	}
//////	return 0;
//////}
/////*********************正确的版本 8.6**************/ 
//int main(void)
//{
//	int ch;//int类型读取字符，为了检测EOF 
//	int rows,cols;
//	printf("tip:\n");
//	while((ch = getchar()) != '\n') 
//	{
//		if(scanf("%d %d",&rows,&cols) != 2)//让scanf的返回值为2，一个或者两个输入值不是整数或者遇到文件结尾时候会停止程序 
//			break;
//		display(ch,rows,cols);
//		while(getchar() != '\n')//处理掉数字后面的换行符 
//			continue;
//	}
//	return 0;
//}

/*************************8.7 输入验证**************************/
#include <stdio.h>
#include <stdbool.h>

long get_long(void);

bool bad_limits(long begin,long end,long low,long high);

double sum_squares(long a,long b);

int main(void)
{
	const long MIN = -10000000L;
	const long MAX = +10000000L;
	long start;
	long stop;
	double answer;
	
	printf("tip\n");
	start = get_long();
	printf("");
	stop = get_long();
	while(start != 0 ||stop != 0)
	{
		if(bad_limits(start,stop,MIN,MAX))
			printf("again\n");
		else
		{
			answer = sum_squares(start,stop);
			printf("%ld,%ld,%ld",start,stop,answer);
		}
		start = get_long();
		stop = get_long(); 
		
	}
	return 0;
}

long get_long(void)
{
	long input;
	char ch;
	
	while(scanf("ld",&input) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch);
	}
	
	return input;
}

double sum_squares(long a,long b)
{
	double total = 0;
	long i;
	for(i = a;i <= b;i++)
		total += (double)i * (double)i;
		
	return total;
}

bool bad_limits(long begin,long end,long low,long high)
{
	bool not_good = false;
	
	if(begin > end)
	{
		printf("%ld,%ld",begin,end);
		not_good = true;
	}
	if(begin < low || end < low)
	{
		printf("%ld",low);
		not_good = true;
	}
	if(begin > high || end > high)
	{
		printf("%ld",high);
		not_good = true;
	}
	return not_good;
}



















