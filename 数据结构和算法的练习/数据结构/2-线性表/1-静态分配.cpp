///********顺序表的实现——静态分配********/ 
//#include <stdio.h>
//#define MaxSize 10//定义静态分配线性表的最大长度 
//typedef struct{
//	int data[MaxSize];//静态的数组存放数据 
//	int length;//顺序表当前长度 
//}SqList;//类型的定义 
//
//void display(SqList &L);
//
//void InitList(SqList &L)//初始化一个顺序表
////使用&是C++特有语法“按引用传递”，C中无法使用，只有改为“地址引用” ，int *a 
//{
//	for(int i = 0;i < MaxSize;i++)//如果不初始化可能有原来数组里面的乱数据，之前存的数据 
//		L.data[i] = 0;//表中数据全部为0 
//	L.length = 0;//初始长度为0 
//}
//
/////*初级的插入，无法处理异常情况*/
////void ListInsert(SqList &L,int i,int e)//在L的位序i（不是数组下标）处插入元素e 
//////仅仅是用来那种插入一个，别的元素会后退的那种插入，不是随便插入的 
////{
////	for(int j = L.length;j >= i;j--)//将第i个元素及只有的元素后移 
////		L.data[j] = L.data[j-1];
////	L.data[i-1] = e;//在位置i-1处放入e 
////	L.length++; 
////}
//
///*可以处理异常情况*/ 
//bool ListInsert(SqList &L,int i,int e)//在L的位序i处插入元素e 
//{
//	if(i < 1 || i > L.length)//判断i的范围是否有效 
//		return false;
//	if(L.length >= MaxSize)//判断是否已经存满 
//		return false;
//	for(int j = L.length;j >= i;j--)
//		L.data[j] = L.data[j-1];
//	L.data[i-1] = e;//在位置i-1处放入e 
//	L.length++; 
//	
//	return true;
//}
//
//bool ListDelete(SqList &L,int i,int &e)//在L的位序i处删除元素e 
////注意位序i和数组下标的区别 
//{
//	if(i < 1 || i > L.length)//判断i的范围是否有效 
//		return false;
//	e = L.data[i-1];
//	for(int j = i;j <= L.length;j++)//书上的例子为<但是最后一位就没有处理掉 
//		L.data[j-1] = L.data[j];
//	L.length--;
//	return true;
//}
//
//int main()
//{
//	SqList L;//声明一个顺序表 
//	InitList(L);//初始化 
//	
//	{int Initlength = 8;
//	for(int i = 0;i < Initlength;i++)//自己对线性表原来元素的初始化 
//		L.data[i] = Initlength-i;
//	L.length = Initlength;}
//	
//	int e = -1;//用变量e将删除的元素带回来，-1不是e的最终值，只是e的初始化的值 
//	
//	if(ListInsert(L,2,15))//插入操作以及测试用例 
//	//if(ListInsert(L,8,15))
//	//if(ListInsert(L,13,15))
//		display(L);
//	else
//		printf("NO!\n");
//	putchar('\n');
//		
//	if(ListDelete(L,3,e))//删除操作以及测试用例 
//	//if(ListInsert(L,8,15))
//	//if(ListInsert(L,13,15))
//		printf("%d\n\n",e);
//	else
//		printf("NO!\n\n");
//	
//	display(L);
//}
//
//void display(SqList &L)//显示顺序表 
//{
//	for(int i = 0;i < MaxSize;i++)
//		printf("%d %d\n",i,L.data[i]);
//	putchar('\n'); 	
//}
//

