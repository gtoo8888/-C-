/*
���ܰ����ַ������ܰ������ֵ�������ʽ����Ҫ���ָ���Ϣ�Ķ��� 
*/

///******************** 14.1 �ṹ�������봴��********************/
//#include <stdio.h>
//#include <string.h> 
//char * s_gets(char * st, int n);//ǰ���µĺ��� 
//#define MAXTITL 41//��������󳤶�+1 
//#define MAXAUTL 31//�������ֵ���󳤶�+1 
//
////�ṹ�����������ʱ����ֻ����������û�д���ʵ�ʶ���ռ�ÿռ� book�����ṹ�ı�� 
//struct book{
//	char title[MAXTITL];//�ṹ���Ա���������������ݽṹ��Ҳ����Ϊ�����ṹ 
//	char author[MAXAUTL];
//	float val;
//};
////struct book{
////	char title[MAXTITL];
////	char author[MAXAUTL];
////	float val;
////}libray;//����+�������Խ�ϳ�һ������ 
////
////struct {//���Բ��ñ�ǣ���������ֻ������һ�Σ����Ҫ���ʹ�û��ǵü��� 
////	char title[MAXTITL];
////	char author[MAXAUTL];
////	float val;
////}libray;
//
//int main(void)
//{
//	struct book library;//�����ṹ����ʱ���˾���Ĵ���ռ� 
//	
//	printf("title:\n");
//	s_gets(library.title,MAXTITL);//���ʽṹ���Ա�ķ�����a.title 
//	s_gets(library.author,MAXAUTL);
//	scanf("%f",&library.val);
//	printf("%s\n%s\n%.2f\n",library.title,library.author,library.val) ;
//	
////	struct book abc = { //����˵������ô��ʼ��������������ᱨ�� 
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
//char * s_gets(char * st, int n)//ǰ���µ����ݣ���û�������ʴ���� 
//{
//	char *ret_val;
//	char *find;
//	
//	ret_val = fgets(st,n,stdin);
//	if(ret_val)
//	{
//		find = strchr(st,'\n');//���һ��з� 
//		if(find)//�����ַ����NULL 
//			*find = '\0';//�ڴ˴�����һ�����ַ� 
//		else
//			while(getchar() != '\n')
//				continue;//�����������е�ʣ���ַ� 
//	}
//    return ret_val;
//}
///*����ʾ���� 
//Chicken of the Andes
//Disma Lapoutlt
//29.99
//*/ 

///******************** 14.2 �ṹ������********************/
//#include <stdio.h>
//#include <string.h> 
//char * s_gets(char * st, int n);
//#define MAXTITL 40
//#define MAXAUTL 40
//#define MAXBKS 100//�ṹ������ռ�õĿռ�ܴ󣬺������ڴ治�㣬����ܿ�Сһ�� 
//
//struct book{
//	char title[MAXTITL];
//	char author[MAXAUTL];
//	float val;
//};
//
//int main(void)
//{
//	struct book library[MAXBKS];//�����ṹ������ 
//	int count = 0;
//	int index;
//	
//	printf("%d",sizeof(library));
//	while(count < 3 && s_gets(library[count].title,MAXTITL) != NULL //����ж����ַ��Ƿ�Ϊ���ַ����������һ���س�����ô�͵���һ�����ַ� 
//	&& library[count].title[0] != '\n')//whileѭ����ȡ����
//	//�����3���Ը�ΪMAXBKS��д3Ϊ�˲��Է��� 
//	{
//		s_gets(library[count].author,MAXAUTL);
//		scanf("%f",&library[count++].val);
//		while(getchar() != '\n')//�ֲ��� scanf�������оͽ�����ȡ�����⣬���ܻᵼ�°ѻ��е����˿��ַ�������ѭ�� 
//			continue;//ʵ�������������仰����û����... 
//		if(count < MAXAUTL)
//			printf("����:\n");
//	}
//	if(count > 0)
//	{
//		for(index = 0;index < count;index++)
//			printf("%s\n%s\n%.2f\n",library[index].title,//���ʽṹ������ķ��� 
//									library[index].author,
//									library[index].val);
//	}
//	else
//		printf("NO book\n");
//	return 0;
//}
//
//char * s_gets(char * st, int n)//ǰ���µ����ݣ���û�������ʴ���� 
//{
//	char *ret_val;
//	char *find;
//	
//	ret_val = fgets(st,n,stdin);
//	if(ret_val)
//	{
//		find = strchr(st,'\n');//���һ��з� 
//		if(find)//�����ַ����NULL 
//			*find = '\0';//�ڴ˴�����һ�����ַ� 
//		else
//			while(getchar() != '\n')
//				continue;//�����������е�ʣ���ַ� 
//	}
//    return ret_val;
//}
///*����ʾ������������������ 
//Chicken of the Andes
//Disma Lapoutlt
//29.99
//*/ 


/******************** 14.3 Ƕ�׽ṹ *******************/
/******************** 14.4 ָ��ṹ��ָ�� *******************/
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





