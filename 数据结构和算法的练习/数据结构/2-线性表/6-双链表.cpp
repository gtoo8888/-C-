//#include <stdio.h>
//#include <stdlib.h> 
//
//typedef struct DNode{
//	int data;						//数据域 
//	struct DNode *prior,*next;		//前驱和后继指针 
//}DNode,*DLinkList;
//
//
///***************初始化双链表 *********************/ 
//bool InitDLinkList(DLinkList &L){
//	L = (DNode *)malloc(sizeof(DNode));
//	if(L == NULL)//内存不足分配失败 
//		return false;
//	L -> prior = NULL;//头结点的前驱prior永远指向NULL 
//	L -> next = NULL;//头结点之后暂时还没有节点 
//	return true;
//}
//
///***************判断双链表是否为空********************/ 
//bool Empty(DLinkList L){
//	if(L -> next == NULL)//判断后驱next是否为空就行 
//		return true;
//	else
//		return false;
//}
//
///***************后插：在p节点时候插入s********************/ 
////还没法直接用，因为没有s，也没有具体要插入的值 
//bool InsertNextDNode(DNode *p,DNode *s){
//	if(p == NULL || s == NULL)
//		return false;
//	s -> next = p -> next;
//	if(p -> next != NULL) 
//		p -> next -> prior = s;
//	s -> prior = p;
//	p -> next = s;
//	return true;
//}
//
///***************后删：删除p节点的后继节点********************/ 
//bool DeleteNextDNode(DNode *p) {
//	if(p == NULL)	return false;
//	DNode *q = p -> next;//p的后继节点 
//	if(q == NULL)	return false;//p没有后继
//	p -> next = q -> next; 
//	if(q -> next != NULL)//q节点不是最后一个节点 
//		q -> next -> prior = p;
//	free(q);
//	return true;
//}
//
///***************销毁双链表********************/ 
//void DestoryList(DLinkList &L){
//	while(L -> next != NULL)//循环释放各个节点的数据 
//		DeleteNextDNode(L);
//	free(L);
//	L = NULL;
//}
//
//int main(void)
//{
//	DLinkList L;
//	InitDLinkList(L);
//	
//	 
//	printf("OK!\n");
//	return 0;
//}
