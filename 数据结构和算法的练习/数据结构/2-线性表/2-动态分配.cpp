///********顺序表的实现——动态分配********/ 
//#include <stdio.h>
//#include <stdlib.h>//包含了malloc/free函数的头文件
// 
//#define InitSize 10//默认的最大长度 
//typedef struct{
//	int *data;//指示动态分配数组的指针 
//	int MaxSize;//顺序表的最大容量 
//	int length;//顺序表当前长度 
//}SqList; 
//void display(SqList &L);
//
//void InitList(SqList &L)
//{//(int *)malloc返回的指针一定要和定义的数据类型的指针的类型是一致的，强制转换过去 
//	L.data = (int *)malloc(InitSize * sizeof(int));//用malloc函数申请一片连续的储存空间 
//	L.length = 0;//初始长度为0 
//	L.MaxSize = InitSize;
//	for(int i = 0;i < L.MaxSize;i++)//如果不初始化可能有原来数组里面的乱数据，之前存的数据 
//		L.data[i] = 0;//表中数据全部为0
//}
//
//void IncreaseSize(SqList &L,int len)//增加相应的数组长度 
//{
//	int *p = L.data;
//	L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));//realloc有坑 
//	//L.length = L.MaxSize + len;//在扩展后需要改变length的长度,如果不改变，会有原来的脏数据 
//	for(int i = 0;i < L.length;i++)
//		L.data[i] = p[i];//将数据复制到新的区域,时间开销很大	
//	for(int i = L.MaxSize;i < L.MaxSize + len;i++)//新扩展的区域需要初始化 
//		L.data[i] = 0;
//	L.MaxSize = L.MaxSize + len;
//	free(p);//释放内存空间 
//}
//
//int GetElem(SqList &L,int i)//按位查找，获取表L中第i个位置的元素的值 
//{
//	return L.data[i-1];
//}
//
//int LocateElem(SqList &L,int e)//按值查找，在表L中查找具有给定关键字值的元素 
//{
//	for(int i = 0;i < L.length;i++)
//		if(L.data[i] == e)
//			return i+1;
//	return 0;
//}
//
//int main()
//{
//	SqList L;//声明
//	InitList(L);//初始化
//	IncreaseSize(L,5);//增加相应的数组长度 
//	
//	int e1 = -1;//接收按位查找回来的元素 
//	int e2 = -1; //接收按值查找回来的元素 
//	
//	{int Initlength = 10;
//	for(int i = 0;i < Initlength;i++)//自己对线性表原来元素的初始化 
//		L.data[i] = Initlength-i;
//	L.length = Initlength;}
//
//	
//	e1 = GetElem(L,5);//按位查找
//	e2 = LocateElem(L,9);//按值查找
//	printf("%d %d\n\n",e1,e2);
//	
//	display(L);//增加完后数组的值都乱了？？？ 
//
//	return 0;
//}
//
//void display(SqList &L)//显示顺序表中的元素 
//{
//	for(int i = 0;i < L.MaxSize;i++)
//		printf("%2d %2d\n",i+1,L.data[i]);
//	putchar('\n'); 	
//}
