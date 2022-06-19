///********顺序栈的实现*******/
//#include <stdio.h> 
//#define MaxSize 10
//typedef struct{
//	int data[MaxSize];
//	int top;//栈顶（指针？） 
//} SqStack;//顺序栈的定义 
//
///********初始化栈*******/
//void InitStack(SqStack &S){
//	S.top = -1;//初始化栈顶指针 ，此时栈顶指针指向栈顶元素 
//	//S.top = 0;//此时指针指向栈顶元素下一个的位置 
//	for(int i = 0;i < MaxSize;i++)//清空栈中元素 
//		S.data[i] = 0;
//}
//
///********判断栈空*******/
//bool StackEmpty(SqStack S){
//	if(S.top == -1)
//		return true;
//	else
//		return false;
//}
//
///********入栈*******/
//bool Push(SqStack &S,int x) {
//	if(S.top == MaxSize - 1)//栈满，报错 
//		return false;
////	S.top += 1;//指针先加1 
////	S.data[S.top] = x;//新元素入栈 
//	S.data[++S.top] = x;//等价写法
////	S.data[S.top++] = x;//错误写法，这样会覆盖掉原有S.data[S.top]的数据 
//	return true; 
//}
//
///********出栈*******/
//bool Pop(SqStack &S,int &x) {
//	if(S.top == -1)//栈空，报错 
//		return false;
////	x = S.data[S.top];//栈顶元素先出栈 
////	S.top -= 1;//指针再减1 
//	S.data[S.top--] = x;//等价写法，先出栈，指针再变化 
////	S.data[--S.top] = x;//错误写法
//	return true; 
//}
//
///********读取栈顶元素*******/
//bool GetTop(SqStack &S,int &x) {
//	if(S.top == -1)//栈空，报错 
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
//void display(SqStack &S)//按上面栈顶，下面栈底的方式显示 
//{
//	for(int i = MaxSize - 1;i >= 0;i--)
//		printf("%d %d\n",i,S.data[i]);
//	putchar('\n'); 	
//}
//
///********定义共享栈*******/
//#define MaxSize 10
//typedef struct{
//	int data[MaxSize];
//	int top0;		//0号栈顶指针 
//	int top1;	//1号栈顶指针 
//} SqStack;//顺序栈的定义 
//
///********初始化共享栈*******/
//void InitStack(SqStack &S){
//	S.top0 = -1;
//	S.top1 = MaxSize;
//}
///********判断共享栈满*******/
//bool StackFull(SqStack S){
//	if(S.top0 + 1 == top1)
//		return true;//满了 
//	else
//		return false;
//}

