/*
既能包含字符串又能包含数字的数据形式，还要保持各信息的独立 
*/

///******************** 14.1 结构体声明与创建********************/
//#include <stdio.h>
//#include <string.h> 
//char * s_gets(char * st, int n);//前几章的函数 
//#define MAXTITL 41//书名的最大长度+1 
//#define MAXAUTL 31//作者名字的最大长度+1 
//
////结构体的声明，此时仅仅只有声明，还没有创建实际对象占用空间 book叫做结构的标记 
//struct book{
//	char title[MAXTITL];//结构体成员，可以是任意数据结构，也可以为其他结构 
//	char author[MAXAUTL];
//	float val;
//};
////struct book{
////	char title[MAXTITL];
////	char author[MAXAUTL];
////	float val;
////}libray;//定义+声明可以结合成一个过程 
////
////struct {//可以不用标记，但是这样只能声明一次，如果要多次使用还是得加上 
////	char title[MAXTITL];
////	char author[MAXAUTL];
////	float val;
////}libray;
//
//int main(void)
//{
//	struct book library;//创建结构，此时有了具体的储存空间 
//	
//	printf("title:\n");
//	s_gets(library.title,MAXTITL);//访问结构体成员的方法，a.title 
//	s_gets(library.author,MAXAUTL);
//	scanf("%f",&library.val);
//	printf("%s\n%s\n%.2f\n",library.title,library.author,library.val) ;
//	
////	struct book abc = { //书上说可以这么初始化，这个编译器会报错 
////		.val = 7.3
////		.author = "James Braodfool",
////		.title = "RUE"
////	};
//	struct book abc;
//	abc.val = 4.6; 
//	
//	printf("\n%.2f\n",abc.val) ;
//	
//}
//
//char * s_gets(char * st, int n)//前几章的内容，还没看？疑问待解决 
//{
//	char *ret_val;
//	char *find;
//	
//	ret_val = fgets(st,n,stdin);
//	if(ret_val)
//	{
//		find = strchr(st,'\n');//查找换行符 
//		if(find)//如果地址不是NULL 
//			*find = '\0';//在此处放置一个空字符 
//		else
//			while(getchar() != '\n')
//				continue;//处理输入行中的剩余字符 
//	}
//    return ret_val;
//}
///*运行示例： 
//Chicken of the Andes
//Disma Lapoutlt
//29.99
//*/ 

///******************** 14.2 结构体数组********************/
//#include <stdio.h>
//#include <string.h> 
//char * s_gets(char * st, int n);
//#define MAXTITL 40
//#define MAXAUTL 40
//#define MAXBKS 100//结构体数组占用的空间很大，和内容内存不足，最好能开小一点 
//
//struct book{
//	char title[MAXTITL];
//	char author[MAXAUTL];
//	float val;
//};
//
//int main(void)
//{
//	struct book library[MAXBKS];//声明结构体数组 
//	int count = 0;
//	int index;
//	
//	printf("%d",sizeof(library));
//	while(count < 3 && s_gets(library[count].title,MAXTITL) != NULL //这个判断首字符是否为空字符，如果输入一个回车，那么就等于一个空字符 
//	&& library[count].title[0] != '\n')//while循环读取多个项，
//	//上面的3可以改为MAXBKS，写3为了测试方便 
//	{
//		s_gets(library[count].author,MAXAUTL);
//		scanf("%f",&library[count++].val);
//		while(getchar() != '\n')//弥补了 scanf遇到换行就结束读取的问题，可能会导致把换行当做了空字符，结束循环 
//			continue;//实际运行中这两句话好像没有用... 
//		if(count < MAXAUTL)
//			printf("继续:\n");
//	}
//	if(count > 0)
//	{
//		for(index = 0;index < count;index++)
//			printf("%s\n%s\n%.2f\n",library[index].title,//访问结构体数组的方法 
//									library[index].author,
//									library[index].val);
//	}
//	else
//		printf("NO book\n");
//	return 0;
//}
//
//char * s_gets(char * st, int n)//前几章的内容，还没看？疑问待解决 
//{
//	char *ret_val;
//	char *find;
//	
//	ret_val = fgets(st,n,stdin);
//	if(ret_val)
//	{
//		find = strchr(st,'\n');//查找换行符 
//		if(find)//如果地址不是NULL 
//			*find = '\0';//在此处放置一个空字符 
//		else
//			while(getchar() != '\n')
//				continue;//处理输入行中的剩余字符 
//	}
//    return ret_val;
//}
///*运行示例：输入多个。。。。 
//Chicken of the Andes
//Disma Lapoutlt
//29.99
//*/ 


/******************** 14.3 嵌套结构 *******************/
/******************** 14.4 指向结构的指针 *******************/
#include <stdio.h>
#define LEN 20

struct names{
	char first[LEN];
	char last[LEN];
};

struct guy{
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main(void)
{
	struct guy fellow[2] = {
		{{"Ewen","Villard"},
		"grill",
		"preson",
		68112.00
		},
		{{"Rod","Swill"},
		"trip",
		"table",
		432400.00,
		}
	};
	struct guy *him;
	printf("%p %p\n\n",&fellow[0],&fellow[1]);
	him = &fellow[0];
	printf("%p %p\n\n",him,him + 1);
	printf("%.2f %.2f\n\n",him -> income,(*him).income);
	him++;
	printf("%s %s\n\n",him -> favfood,him -> handle.last);
	return 0;
}





