//#include <stdio.h>
//#include <stdlib.h> 
//
//typedef struct DNode{
//	int data;						//������ 
//	struct DNode *prior,*next;		//ǰ���ͺ��ָ�� 
//}DNode,*DLinkList;
//
//
///***************��ʼ��˫���� *********************/ 
//bool InitDLinkList(DLinkList &L){
//	L = (DNode *)malloc(sizeof(DNode));
//	if(L == NULL)//�ڴ治�����ʧ�� 
//		return false;
//	L -> prior = NULL;//ͷ����ǰ��prior��Զָ��NULL 
//	L -> next = NULL;//ͷ���֮����ʱ��û�нڵ� 
//	return true;
//}
//
///***************�ж�˫�����Ƿ�Ϊ��********************/ 
//bool Empty(DLinkList L){
//	if(L -> next == NULL)//�жϺ���next�Ƿ�Ϊ�վ��� 
//		return true;
//	else
//		return false;
//}
//
///***************��壺��p�ڵ�ʱ�����s********************/ 
////��û��ֱ���ã���Ϊû��s��Ҳû�о���Ҫ�����ֵ 
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
///***************��ɾ��ɾ��p�ڵ�ĺ�̽ڵ�********************/ 
//bool DeleteNextDNode(DNode *p) {
//	if(p == NULL)	return false;
//	DNode *q = p -> next;//p�ĺ�̽ڵ� 
//	if(q == NULL)	return false;//pû�к��
//	p -> next = q -> next; 
//	if(q -> next != NULL)//q�ڵ㲻�����һ���ڵ� 
//		q -> next -> prior = p;
//	free(q);
//	return true;
//}
//
///***************����˫����********************/ 
//void DestoryList(DLinkList &L){
//	while(L -> next != NULL)//ѭ���ͷŸ����ڵ������ 
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
