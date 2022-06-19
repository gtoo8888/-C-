#include <stdio.h> 
#include <stdlib.h>
//一步到位定义方法
typedef struct LNode{//定义单链表节点类型 并且数据类型重命名为LNode 
	int data;			//数据域 
	struct LNode *next;	//指针域
}LNode,*LinkList;//数据类型重命名同时定义了一个变量与一个指针*LinkList 

/***************初始化一个空的单链表 带头节点 *********************/ 
//带头结点的单链表，头结点不存储数据，他的指针域指向下一个节点 
bool InitList(LinkList &L){
	L = (LNode *)malloc(sizeof(LNode));//分配出来一个头结点 	
	if(L == NULL)// 内存不足分配失败,直接返回 
		return false;
	L -> next = NULL;//头节点之后暂时还没有节点 
	L -> data = -1;//头结点中不应该有数据。王道没有定义，不知道该不该定义 
	return true;
}

/***************判断单链表是否为空(带头结点)*********************/ 
bool Empty(LinkList L){
	if(L -> next == NULL) 
		return true;
	else
		return false;
}

/***************按位查找，返回第i个元素（带头结点） *********************/ 
LNode *GetElem(LinkList L,int i){
	if(i < 0)
		return NULL;
	LNode *p;
	int j = 0;
	p = L;
	while(p != NULL && j < i){
		p = p -> next;
		j++;
	}
	return p;
} 

/***************按值查找，找到数据域==e的结点（带头结点） *********************/ 
LNode *LocateElem(LinkList L,int e,int &i){
	LNode *p = L -> next;//从第一节点开始查找 
	i = 1;
	while(p != NULL && p -> data != e) 
	{
		i++;//自己加的变量i，为了找出查的那个数字的位序 
		p = p -> next;
	}	
	return p;//找到后返回该结点的指针，否则返回NULL 
}

/***************后插操作：在p节点之后插入元素e*********************/ 
bool InsertNextNode(LNode *p,int e){
	if(p == NULL)//正常人怎么可能传入空指针？实际上为了衔接上的按位查找，如果没找到，就会返回空指针 
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL)//内存分配失败，考试的时候可以不用写 
		return false;//这个主要考虑实际情况，比如内存空间分配完了 
	s -> data = e;
	s -> next = p ->next;
	p -> next = s;
	return true;		
}

/***************前插操作：在p节点之前插入元素e*********************/ 
//这样的时间复杂度是O(1)，但是如果在第一个节点操作插入的时候，会把输入调换到头结点里面去，出现bug 
bool InsertPriorNode(LNode *p,int e){//原来节点 
	if(p == NULL)//这是什么不知道啊 
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));//申请一个新节点s 
	if(s == NULL)//内存分配失败
		return false;
	s -> next = p ->next;//这个节点s作为原来节点p节点的后继节点 
	p -> next = s;//p节点指向新节点 
	s -> data = p -> data;//将原来的s中的数据传到新的s节点中 
	p -> data = e;//现在原来的p节点已经是前驱节点了，所以将需要的数据传到p里面去
	//对于节点，都是先操作新的，后操作老的
	//对于成员，先操作指针的指向，后操作数据 
	return true;		
}

/***************在第i个位置插入元素e（带头结点） *********************/ 
bool ListInsert(LinkList &L,int i,int e){//按位序插入(带头结点) 
	if(i < 1)//判断输入是否合法，i为位序，位序是从1开始的 
		return false;//插入失败 	
//	LNode *p;	//指针p指向当前扫描到的节点 
//	int j = 0;	//j表示p指向的是第几个结点 
//	p = L;		//p指向头结点，头结点是第 0个结点（第0个结点其实是虚设的，因为实际上结点是从1开始的） 
//
//	{//循环找到第i-1个结点 	
//		while(p != NULL && j < i-1){
//			p = p -> next;
//			j++;
//		}
//	} 
	LNode *p = GetElem(L,i-1);//上面的全都可以用按位查找替换 
//	{//在i-1结点之后插入新的结点 
//		if(p == NULL)//i结点太大，直接返回插入失败 
//			return false;
//		LNode *s = (LNode *)malloc(sizeof(LNode));//申请一个新的结点空间 
//		s -> data = e;//把参数e存入新结点 
//		s -> next = p -> next;//新结点的指针指向的位置 = p结点（当前扫描到的节点）指针指向的位置
//		//可以理解为将新的结点空间连到p的下一个节点，也就是s和p下一个节点指向的是同一个节点
//		p -> next = s;//p结点的指针指向新的结点s（将s连接到p之后） 
//		return true;//插入成功
//	} 
	return InsertNextNode(p,e);//直接调用后插操作（这两个写的内容是重复的）可以实现 
	
}

/***************按位序删除（带头结点） *********************/ 
//p是当前扫描到的结点，q是需要删除的结点
//先用p扫过去，扫到以后，用q把p扫到的东西抓住
//然后把q删掉，内存清掉，删除完成 
bool ListDelete(LinkList &L,int i,int &e) {
	if(i < 1)
		return false;
//	LNode *p;//p当前扫描到的结点 
//	int j = 0;//p指向第几个结点 
//	p = L;//先用p把L的任务接过来 
//	while(p != NULL && j < i-1){//循环找到要删的 
//		p = p -> next;
//		j++;
//	}
	LNode *p = GetElem(L,i-1);//上面的全都可以用按位查找替换 
	
	if(p == NULL)//到链表结束的地方去了 
		return false;
	if(p -> next == NULL)
		return false;
	LNode *q;
	q = p -> next;//找到要删的结点后，移交给q 
	e = q -> data;
	p -> next = q -> next;//都删了 
	free(q);
	return true;
}

/***************指定结点的删除（带头结点） *********************/ 
//效果：删掉了头结点。。。。。把后面的补上来了 
bool DeleteNode(LNode *p){
	if(p == NULL)
		return false;
	LNode *temp;//暂时变量用于保存需要删除的结点
	temp = p -> next;//这个新的节点是需要删除节点的下一个节点
	p -> data = temp -> data;//
	p -> next = temp -> next;
	free(temp);
	return true;
} 

/***************求单链表的长度（带头结点） *********************/ 
int Length(LinkList L){
	int len = 0;
//	LNode *p = L;
//	while(p -> next != NULL)
	LNode *p = L -> next;
	while(p)//简单的写法 
	{
		p = p -> next;
		len++;
	}
	return len;
}


void OutputList(LinkList &L);//输出链表中的数据 
LNode *ReverseList(LNode *pHead );//链表反转 

int main(void) 
{
	LinkList L;//声明一个指向单链表的指针，内存中会开辟空间，存放头指针L 
	int delete_num;

	InitList(L);//初始化一个空表 
	
	ListInsert(L,1,2);//在第i个位置插入元素e 
	ListInsert(L,2,21);
	ListInsert(L,3,55);
	ListInsert(L,4,47);
	ListInsert(L,5,81);
	ListInsert(L,6,99);
	ListInsert(L,7,67);
	
	
	OutputList(L);
	
	InsertNextNode(L,133);//直接调用后插操作就是头插法 
	InsertNextNode(L,1794);
	
	OutputList(L);
	
	InsertPriorNode(L,3);//直接前插操作，效果和上面一样，因为都是从头开始插入 
	InsertPriorNode(L,77);
	InsertPriorNode(L,678);
	
	OutputList(L);
	
	ListDelete(L,3,delete_num) ;//按位序删除 
	OutputList(L);
	ListDelete(L,3,delete_num) ;
	OutputList(L);
	
	DeleteNode(L);//指定结点删除 
	OutputList(L);
	DeleteNode(L);//指定结点删除 
	OutputList(L);
	
	LinkList FOUND;
	
	FOUND = GetElem(L,6);//按位查找，第六位是什么数字 
	if(FOUND == NULL)
		printf("NO\n\n");
	else
		printf("%d\n\n",FOUND -> data);
		
	FOUND = GetElem(L,11);
	if(FOUND == NULL)
		printf("NO\n\n");
	else
		printf("%d\n\n",FOUND -> data);
	
	int found_num; 
	FOUND = LocateElem(L,99,found_num);
	if(FOUND == NULL)
		printf("NO\n\n");
	else
		printf("%d\n\n",found_num);	
		
	FOUND = LocateElem(L,91,found_num);
	if(FOUND == NULL)
		printf("NO\n\n");
	else
		printf("%d\n\n",found_num);	
		
	int link_len;
	link_len = Length(L);
	printf("%d\n\n",link_len);	
	return 0;
}

/***************输出链表中的数据 *********************/ 
void OutputList(LinkList &L){
	LinkList p;//定义一个用来遍历的链表 
	p = L ;//从头结点往后的第一个节点开始遍历 
	int i = 0;
	while(p){//为空NULL，就是没有下一个链表的时候停止循环  
		printf("%d %d\n",i,p->data);//输出数字 
		i++;
		p = p -> next;
	}
	printf("\n");
}

LNode *ReverseList(LNode *pHead ) {//链表反转 
    LNode* pre = NULL;//可以理解为创建了一个原来链表反转的新链表，把原来的链表倒着读取 
    LNode* cur = pHead;//指向当前链表第一个 
    LNode* next = pHead->next;//指向当前链表第二个
	//反转链表的时候 ，老的链表保存过去一个扔掉一个链表节点 
    while(cur)
	{
        next = cur->next;//保存第二个节点的数据 
        cur->next = pre;//断掉第一个和第二个的链接 
        pre = cur;//新链表得到了老链表的第一个结点 
        cur = next;//第一个节点转向了被保护过的第二个节点 
    }
    return pre;//把新链表返回 
}


