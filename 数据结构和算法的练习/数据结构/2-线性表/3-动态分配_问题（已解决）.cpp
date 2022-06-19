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
//	//display(L); 
//}
//
//void IncreaseSize(SqList &L,int len) 
//{
//	int *p = L.data;
//	L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));//realloc有坑 
//	//在扩展后需要改变length的长度 
//	for(int i = 0;i < L.length;i++)
//		L.data[i] = p[i];//将数据复制到新的区域,时间开销很大	
//	//新扩展的区域需要初始化 
//	L.MaxSize = L.MaxSize + len;
//	free(p);//释放内存空间 
//}
//
//int main()
//{
//	SqList L;//声明
//	InitList(L);//初始化 
//	
//	IncreaseSize(L,5);//增加相应的数组长度 
//	
//	display(L);//增加完后数组的值都乱了？？？ 
//	return 0;
//}
//
//void display(SqList &L)
//{
//	for(int i = 0;i < L.MaxSize;i++)
//		printf("%d %d\n",i+1,L.data[i]);
//	putchar('\n'); 	
//}
