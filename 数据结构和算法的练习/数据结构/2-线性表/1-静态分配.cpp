///********˳����ʵ�֡�����̬����********/ 
//#include <stdio.h>
//#define MaxSize 10//���徲̬�������Ա����󳤶� 
//typedef struct{
//	int data[MaxSize];//��̬������������ 
//	int length;//˳���ǰ���� 
//}SqList;//���͵Ķ��� 
//
//void display(SqList &L);
//
//void InitList(SqList &L)//��ʼ��һ��˳���
////ʹ��&��C++�����﷨�������ô��ݡ���C���޷�ʹ�ã�ֻ�и�Ϊ����ַ���á� ��int *a 
//{
//	for(int i = 0;i < MaxSize;i++)//�������ʼ��������ԭ����������������ݣ�֮ǰ������� 
//		L.data[i] = 0;//��������ȫ��Ϊ0 
//	L.length = 0;//��ʼ����Ϊ0 
//}
//
/////*�����Ĳ��룬�޷������쳣���*/
////void ListInsert(SqList &L,int i,int e)//��L��λ��i�����������±꣩������Ԫ��e 
//////�������������ֲ���һ�������Ԫ�ػ���˵����ֲ��룬����������� 
////{
////	for(int j = L.length;j >= i;j--)//����i��Ԫ�ؼ�ֻ�е�Ԫ�غ��� 
////		L.data[j] = L.data[j-1];
////	L.data[i-1] = e;//��λ��i-1������e 
////	L.length++; 
////}
//
///*���Դ����쳣���*/ 
//bool ListInsert(SqList &L,int i,int e)//��L��λ��i������Ԫ��e 
//{
//	if(i < 1 || i > L.length)//�ж�i�ķ�Χ�Ƿ���Ч 
//		return false;
//	if(L.length >= MaxSize)//�ж��Ƿ��Ѿ����� 
//		return false;
//	for(int j = L.length;j >= i;j--)
//		L.data[j] = L.data[j-1];
//	L.data[i-1] = e;//��λ��i-1������e 
//	L.length++; 
//	
//	return true;
//}
//
//bool ListDelete(SqList &L,int i,int &e)//��L��λ��i��ɾ��Ԫ��e 
////ע��λ��i�������±������ 
//{
//	if(i < 1 || i > L.length)//�ж�i�ķ�Χ�Ƿ���Ч 
//		return false;
//	e = L.data[i-1];
//	for(int j = i;j <= L.length;j++)//���ϵ�����Ϊ<�������һλ��û�д���� 
//		L.data[j-1] = L.data[j];
//	L.length--;
//	return true;
//}
//
//int main()
//{
//	SqList L;//����һ��˳��� 
//	InitList(L);//��ʼ�� 
//	
//	{int Initlength = 8;
//	for(int i = 0;i < Initlength;i++)//�Լ������Ա�ԭ��Ԫ�صĳ�ʼ�� 
//		L.data[i] = Initlength-i;
//	L.length = Initlength;}
//	
//	int e = -1;//�ñ���e��ɾ����Ԫ�ش�������-1����e������ֵ��ֻ��e�ĳ�ʼ����ֵ 
//	
//	if(ListInsert(L,2,15))//��������Լ��������� 
//	//if(ListInsert(L,8,15))
//	//if(ListInsert(L,13,15))
//		display(L);
//	else
//		printf("NO!\n");
//	putchar('\n');
//		
//	if(ListDelete(L,3,e))//ɾ�������Լ��������� 
//	//if(ListInsert(L,8,15))
//	//if(ListInsert(L,13,15))
//		printf("%d\n\n",e);
//	else
//		printf("NO!\n\n");
//	
//	display(L);
//}
//
//void display(SqList &L)//��ʾ˳��� 
//{
//	for(int i = 0;i < MaxSize;i++)
//		printf("%d %d\n",i,L.data[i]);
//	putchar('\n'); 	
//}
//

