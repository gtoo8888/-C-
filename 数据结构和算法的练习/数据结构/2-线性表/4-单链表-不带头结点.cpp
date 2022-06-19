//#include <stdio.h> 
//#include <stdlib.h> 
//
////struct LNode{//定义单链表节点类型 				节点 
////	int data;//每个节点存放一个数据元素 		数据域 
////	struct LNode *next; //指针指向下一个节点 	指针域 
////};//基础定义方法 
////struct LNode *p = (struct LNode *)malloc(sizeof(struct LNode));
////增加一个新的结点：在内存中申请一个结点所需空间，并用指针 p 指向这个结点
////typedef关键字——数据类型重命名（一般用于结构体） 
////typedef struct LNode LNodel;//把(struct LNode)很长的一个名字变成了一只有一个LNode 
////LNode *p = (LNode *)malloc(sizeof(LNode));//和上面对比就简洁了 
//
//
////一步到位定义方法
//typedef struct LNode{//定义单链表节点类型 并且数据类型重命名为LNode 
//	int data;			//数据域 
//	struct LNode *next;	//指针域
//}LNode,*LinkList;//数据类型重命名同时定义了一个变量与一个指针*LinkList 
////等效于下面两句 ，也是为了定义方便 LinkList直译有单链表的意思 
////typedef struct LNode LNode;
////typedef struct *LinkList;//为了能分别定义链表和链表对应的指针
////LNode 	*L;//上下两句等效，都表示 
////LinkList L;//声明一个	指向单链表第一节点的指针
////下面代码可读性更强，定义指针却没有用*，用语义直接表示指针 
////有*强调是一个节点
////没有*强调是一个链表 
//
//LNode *GetElem(LinkList L,int i){
////LNode强调返回的是一个节点
////LinkList强调这是一个链表 
//	int j = 1;
//	LNode *p = L -> next;
//	if(i == 0)
//		return 0;
//	if(i < 1)
//		return NULL;
//	while(p != NULL && j < i){
//		p = p -> next;
//		j++;
//	}
//	return p;	
//}
//
//bool InitList(LinkList &L){//初始化一个空的单链表 不带头节点 
//	L = NULL;//空表，暂时还没有任何节点 ，为了防止定义的那个L指针原来的内存中有脏数据 
//	return true;
//}
//
////bool Empty(LinkList L){//判断单链表是否为空 
////	if(L == NULL)
////		return true;
////	else
////		return false;
////} 
//bool Empty(LinkList L){//判断单链表是否为空 
//	return (L == NULL);//简单的写法，由于这个运算本身就会产生布尔值 
//}
//
////在第i个位置插入元素e（带头结点） 
//bool ListInsert(LinkList &L,int i,int e){//按位序插入(带头结点) 
//	LNode *p;	//指针p指向当前扫描到的节点 
//	int j = 0;	//j表示p指向的是第几个结点 
//	p = L;		//p指向头结点，头结点是第 0个结点（第0个结点其实是虚设的，因为实际上结点是从1开始的） 
//	if(i < 1)//判断输入是否合法，i为位序，位序是从1开始的 
//		return false;//插入失败 
//	{//插入第一个结点的操作与其他结点不同 
//		if(i == 1){
//			LNode *s = (LNode *)malloc(sizeof(LNode));
//			s -> data = e;
//			s -> next  =L;
//			L = s;
//			return true;
//		}
//	} 
//	{//找到第i-1个结点 	
//		while(p != NULL && j < i-1){
//			p = p -> next;
//			j++;
//		}
//	} 
//	{//在i-1结点之后插入新的结点 
//		if(p == NULL)//i结点太大，直接返回插入失败 
//			return false;
//		LNode *s = (LNode *)malloc(sizeof(LNode));//申请一个新的结点空间 
//		s -> data = e;//把参数e存入新结点 
//		s -> next = p -> next;//新结点的指针指向的位置 = p结点（当前扫描到的节点）指针指向的位置
//		//可以理解为将新的结点空间连到p的下一个节点，也就是将s和p下一个节点连起来了 
//		p -> next = s;//p结点的指针指向新的结点s（将s连接到p之后） 
//		return true;//插入成功
//	} 
//}
//
//int main(void) 
//{
//	LinkList L;//声明一个指向单链表的指针，内存中会开辟空间，存放头指针L 
//	InitList(L);//初始化一个空表 
//	
//	printf("OK!\n");
//	return 0;
//}
