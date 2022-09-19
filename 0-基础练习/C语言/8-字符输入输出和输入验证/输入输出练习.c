/***********************8.1ֻ�е���ʶ��#��ʱ���ֹͣ���� ***************/
//#include <stdio.h> 
//int main(void)
//{
//	char ch;
//	while((ch = getchar()) != '#') 
//		putchar(ch);
//	return 0;
//}

/**********8.2ֻ�е�ctrl+z��ʾ�ĵ�ĩβ��ʱ���ֹͣ���� ***********/
//#include <stdio.h>
//int main(void)
//{
//	int ch;
//	while((ch = getchar()) != EOF)
//		putchar(ch);
//	return 0;
//} 
 
/*********************8.3�ض����ļ� *************************/
//#include <stdio.h>
//#include <stdlib.h>	//Ϊ��ʹ��exit() 
//
//int main()
//{
//	int ch;
//	FILE * fp;
//	char fname[50];//�����ļ��� 
//	
//	printf("Enter the name of the file:");
//	scanf("%s",fname);
//	fp = fopen(fname,"r");//�򿪴���ȡ�ļ� 
//	if(fp == NULL)//�����ȡʧ�� 
//	{
//		printf("Failed to open file.Bye\n");
//		exit(1);//�˳����� 
//	}
//	while((ch = getc(fp)) != EOF)
//		putchar(ch);
//	fclose(fp);//�ر��ļ� 
//	return 0;
//} 

///***************8.4ʹ�û������룬ͬʱ�ᷢ�ͻ��з�����Ҫ���ƴ����鷳�Ļ��з�*********************/
//#include <stdio.h>
//int main(void)
//{
//	int guess = 1;
//	char response;//����һ����������ȡ���� 
//	 
//	printf("tip:\n");//��һ����1-100������ͨ��n��y��ʾ�ԵĻ��ߴ�ģ�һ��һ������ȥ 
//	while((response = getchar()) != 'y')//ֱ�Ӷ�ȡ��һ���Զ�ȡ�������Լ����з� 
//	{
//		if(response == 'n')
//			printf("%d\n",++guess);
//		else//����ܳ���n��������� 
//			printf("I dont konw\n");
//		while(getchar() != '\n');//ֱ���������з� 
//			continue;
//	}
//	return 0;
//}

///***************8.5 ���ֺ��ַ�������� *********************/
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
/////*********************����İ汾 8.5**************/ 
//////int main(void)
//////{
//////	int ch;//int���Ͷ�ȡ�ַ���Ϊ�˼��EOF 
//////	int rows,cols;
//////	printf("tip:\n");
//////	while((ch = getchar()) != '\n') //��ȡÿ���ַ����� �ո��Ʊ�������з� 
//////	//���߼���Ҫһ����һ�ζ�ȡ������ֻ��ȡһ�ξͽ����ˣ�����getchar()��׽��������Ļ��з�                        
//////	{
//////		scanf("%d %d",&rows,&cols);//�ܶ�ȡ�������� �ո��Ʊ�������з� 
//////		display(ch,rows,cols);
//////	}
//////	return 0;
//////}
/////*********************��ȷ�İ汾 8.6**************/ 
//int main(void)
//{
//	int ch;//int���Ͷ�ȡ�ַ���Ϊ�˼��EOF 
//	int rows,cols;
//	printf("tip:\n");
//	while((ch = getchar()) != '\n') 
//	{
//		if(scanf("%d %d",&rows,&cols) != 2)//��scanf�ķ���ֵΪ2��һ��������������ֵ�����������������ļ���βʱ���ֹͣ���� 
//			break;
//		display(ch,rows,cols);
//		while(getchar() != '\n')//��������ֺ���Ļ��з� 
//			continue;
//	}
//	return 0;
//}

/*************************8.7 ������֤**************************/
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



















