///********˳��ջ��ʵ��*******/
//#include <stdio.h> 
//#define MaxSize 10
//typedef struct{
//	int data[MaxSize];
//	int top;//ջ����ָ�룿�� 
//} SqStack;//˳��ջ�Ķ��� 
//
///********��ʼ��ջ*******/
//void InitStack(SqStack &S){
//	S.top = -1;//��ʼ��ջ��ָ�� ����ʱջ��ָ��ָ��ջ��Ԫ�� 
//	//S.top = 0;//��ʱָ��ָ��ջ��Ԫ����һ����λ�� 
//	for(int i = 0;i < MaxSize;i++)//���ջ��Ԫ�� 
//		S.data[i] = 0;
//}
//
///********�ж�ջ��*******/
//bool StackEmpty(SqStack S){
//	if(S.top == -1)
//		return true;
//	else
//		return false;
//}
//
///********��ջ*******/
//bool Push(SqStack &S,int x) {
//	if(S.top == MaxSize - 1)//ջ�������� 
//		return false;
////	S.top += 1;//ָ���ȼ�1 
////	S.data[S.top] = x;//��Ԫ����ջ 
//	S.data[++S.top] = x;//�ȼ�д��
////	S.data[S.top++] = x;//����д���������Ḳ�ǵ�ԭ��S.data[S.top]������ 
//	return true; 
//}
//
///********��ջ*******/
//bool Pop(SqStack &S,int &x) {
//	if(S.top == -1)//ջ�գ����� 
//		return false;
////	x = S.data[S.top];//ջ��Ԫ���ȳ�ջ 
////	S.top -= 1;//ָ���ټ�1 
//	S.data[S.top--] = x;//�ȼ�д�����ȳ�ջ��ָ���ٱ仯 
////	S.data[--S.top] = x;//����д��
//	return true; 
//}
//
///********��ȡջ��Ԫ��*******/
//bool GetTop(SqStack &S,int &x) {
//	if(S.top == -1)//ջ�գ����� 
//		return false;
//	x = S.data[S.top];
//	return true; 
//}
//
//void display(SqStack &S);
//
//
//int main(void) 
//{
//	SqStack S;
//	int get_top = 0; 
//	int out_num[MaxSize] = {0};
//	InitStack(S);
//	
//	Push(S,13);
//	Push(S,19);
//	Push(S,23);
//	Push(S,77);
//	Push(S,53);
//	
//	display(S);
//	
//	GetTop(S,get_top);
//	printf("%d\n\n",get_top);
//	
//	Pop(S,out_num[0]);
//	Pop(S,out_num[1]);
//	
//	display(S);
//	
//	return 0;
//}
//
//void display(SqStack &S)//������ջ��������ջ�׵ķ�ʽ��ʾ 
//{
//	for(int i = MaxSize - 1;i >= 0;i--)
//		printf("%d %d\n",i,S.data[i]);
//	putchar('\n'); 	
//}
//
///********���干��ջ*******/
//#define MaxSize 10
//typedef struct{
//	int data[MaxSize];
//	int top0;		//0��ջ��ָ�� 
//	int top1;	//1��ջ��ָ�� 
//} SqStack;//˳��ջ�Ķ��� 
//
///********��ʼ������ջ*******/
//void InitStack(SqStack &S){
//	S.top0 = -1;
//	S.top1 = MaxSize;
//}
///********�жϹ���ջ��*******/
//bool StackFull(SqStack S){
//	if(S.top0 + 1 == top1)
//		return true;//���� 
//	else
//		return false;
//}

