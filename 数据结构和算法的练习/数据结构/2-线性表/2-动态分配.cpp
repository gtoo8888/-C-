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
//}
//
//void IncreaseSize(SqList &L,int len)//������Ӧ�����鳤�� 
//{
//	int *p = L.data;
//	L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));//realloc�п� 
//	//L.length = L.MaxSize + len;//����չ����Ҫ�ı�length�ĳ���,������ı䣬����ԭ���������� 
//	for(int i = 0;i < L.length;i++)
//		L.data[i] = p[i];//�����ݸ��Ƶ��µ�����,ʱ�俪���ܴ�	
//	for(int i = L.MaxSize;i < L.MaxSize + len;i++)//����չ��������Ҫ��ʼ�� 
//		L.data[i] = 0;
//	L.MaxSize = L.MaxSize + len;
//	free(p);//�ͷ��ڴ�ռ� 
//}
//
//int GetElem(SqList &L,int i)//��λ���ң���ȡ��L�е�i��λ�õ�Ԫ�ص�ֵ 
//{
//	return L.data[i-1];
//}
//
//int LocateElem(SqList &L,int e)//��ֵ���ң��ڱ�L�в��Ҿ��и����ؼ���ֵ��Ԫ�� 
//{
//	for(int i = 0;i < L.length;i++)
//		if(L.data[i] == e)
//			return i+1;
//	return 0;
//}
//
//int main()
//{
//	SqList L;//����
//	InitList(L);//��ʼ��
//	IncreaseSize(L,5);//������Ӧ�����鳤�� 
//	
//	int e1 = -1;//���հ�λ���һ�����Ԫ�� 
//	int e2 = -1; //���հ�ֵ���һ�����Ԫ�� 
//	
//	{int Initlength = 10;
//	for(int i = 0;i < Initlength;i++)//�Լ������Ա�ԭ��Ԫ�صĳ�ʼ�� 
//		L.data[i] = Initlength-i;
//	L.length = Initlength;}
//
//	
//	e1 = GetElem(L,5);//��λ����
//	e2 = LocateElem(L,9);//��ֵ����
//	printf("%d %d\n\n",e1,e2);
//	
//	display(L);//������������ֵ�����ˣ����� 
//
//	return 0;
//}
//
//void display(SqList &L)//��ʾ˳����е�Ԫ�� 
//{
//	for(int i = 0;i < L.MaxSize;i++)
//		printf("%2d %2d\n",i+1,L.data[i]);
//	putchar('\n'); 	
//}
