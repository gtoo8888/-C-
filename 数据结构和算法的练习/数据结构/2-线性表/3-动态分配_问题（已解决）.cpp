///********˳����ʵ�֡�����̬����********/ 
//#include <stdio.h>
//#include <stdlib.h>//������malloc/free������ͷ�ļ�
// 
//#define InitSize 10//Ĭ�ϵ���󳤶� 
//typedef struct{
//	int *data;//ָʾ��̬���������ָ�� 
//	int MaxSize;//˳����������� 
//	int length;//˳���ǰ���� 
//}SqList; 
//void display(SqList &L);
//
//void InitList(SqList &L)
//{//(int *)malloc���ص�ָ��һ��Ҫ�Ͷ�����������͵�ָ���������һ�µģ�ǿ��ת����ȥ 
//	L.data = (int *)malloc(InitSize * sizeof(int));//��malloc��������һƬ�����Ĵ���ռ� 
//	L.length = 0;//��ʼ����Ϊ0 
//	L.MaxSize = InitSize;
//	for(int i = 0;i < L.MaxSize;i++)//�������ʼ��������ԭ����������������ݣ�֮ǰ������� 
//		L.data[i] = 0;//��������ȫ��Ϊ0
//	//display(L); 
//}
//
//void IncreaseSize(SqList &L,int len) 
//{
//	int *p = L.data;
//	L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));//realloc�п� 
//	//����չ����Ҫ�ı�length�ĳ��� 
//	for(int i = 0;i < L.length;i++)
//		L.data[i] = p[i];//�����ݸ��Ƶ��µ�����,ʱ�俪���ܴ�	
//	//����չ��������Ҫ��ʼ�� 
//	L.MaxSize = L.MaxSize + len;
//	free(p);//�ͷ��ڴ�ռ� 
//}
//
//int main()
//{
//	SqList L;//����
//	InitList(L);//��ʼ�� 
//	
//	IncreaseSize(L,5);//������Ӧ�����鳤�� 
//	
//	display(L);//������������ֵ�����ˣ����� 
//	return 0;
//}
//
//void display(SqList &L)
//{
//	for(int i = 0;i < L.MaxSize;i++)
//		printf("%d %d\n",i+1,L.data[i]);
//	putchar('\n'); 	
//}
