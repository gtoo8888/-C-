//#include <stdio.h> 
//#include <stdlib.h> 
//
////struct LNode{//���嵥����ڵ����� 				�ڵ� 
////	int data;//ÿ���ڵ���һ������Ԫ�� 		������ 
////	struct LNode *next; //ָ��ָ����һ���ڵ� 	ָ���� 
////};//�������巽�� 
////struct LNode *p = (struct LNode *)malloc(sizeof(struct LNode));
////����һ���µĽ�㣺���ڴ�������һ���������ռ䣬����ָ�� p ָ��������
////typedef�ؼ��֡�������������������һ�����ڽṹ�壩 
////typedef struct LNode LNodel;//��(struct LNode)�ܳ���һ�����ֱ����һֻ��һ��LNode 
////LNode *p = (LNode *)malloc(sizeof(LNode));//������ԱȾͼ���� 
//
//
////һ����λ���巽��
//typedef struct LNode{//���嵥����ڵ����� ������������������ΪLNode 
//	int data;			//������ 
//	struct LNode *next;	//ָ����
//}LNode,*LinkList;//��������������ͬʱ������һ��������һ��ָ��*LinkList 
////��Ч���������� ��Ҳ��Ϊ�˶��巽�� LinkListֱ���е��������˼ 
////typedef struct LNode LNode;
////typedef struct *LinkList;//Ϊ���ֱܷ�������������Ӧ��ָ��
////LNode 	*L;//���������Ч������ʾ 
////LinkList L;//����һ��	ָ�������һ�ڵ��ָ��
////�������ɶ��Ը�ǿ������ָ��ȴû����*��������ֱ�ӱ�ʾָ�� 
////��*ǿ����һ���ڵ�
////û��*ǿ����һ������ 
//
//LNode *GetElem(LinkList L,int i){
////LNodeǿ�����ص���һ���ڵ�
////LinkListǿ������һ������ 
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
//bool InitList(LinkList &L){//��ʼ��һ���յĵ����� ����ͷ�ڵ� 
//	L = NULL;//�ձ���ʱ��û���κνڵ� ��Ϊ�˷�ֹ������Ǹ�Lָ��ԭ�����ڴ����������� 
//	return true;
//}
//
////bool Empty(LinkList L){//�жϵ������Ƿ�Ϊ�� 
////	if(L == NULL)
////		return true;
////	else
////		return false;
////} 
//bool Empty(LinkList L){//�жϵ������Ƿ�Ϊ�� 
//	return (L == NULL);//�򵥵�д��������������㱾��ͻ��������ֵ 
//}
//
////�ڵ�i��λ�ò���Ԫ��e����ͷ��㣩 
//bool ListInsert(LinkList &L,int i,int e){//��λ�����(��ͷ���) 
//	LNode *p;	//ָ��pָ��ǰɨ�赽�Ľڵ� 
//	int j = 0;	//j��ʾpָ����ǵڼ������ 
//	p = L;		//pָ��ͷ��㣬ͷ����ǵ� 0����㣨��0�������ʵ������ģ���Ϊʵ���Ͻ���Ǵ�1��ʼ�ģ� 
//	if(i < 1)//�ж������Ƿ�Ϸ���iΪλ��λ���Ǵ�1��ʼ�� 
//		return false;//����ʧ�� 
//	{//�����һ�����Ĳ�����������㲻ͬ 
//		if(i == 1){
//			LNode *s = (LNode *)malloc(sizeof(LNode));
//			s -> data = e;
//			s -> next  =L;
//			L = s;
//			return true;
//		}
//	} 
//	{//�ҵ���i-1����� 	
//		while(p != NULL && j < i-1){
//			p = p -> next;
//			j++;
//		}
//	} 
//	{//��i-1���֮������µĽ�� 
//		if(p == NULL)//i���̫��ֱ�ӷ��ز���ʧ�� 
//			return false;
//		LNode *s = (LNode *)malloc(sizeof(LNode));//����һ���µĽ��ռ� 
//		s -> data = e;//�Ѳ���e�����½�� 
//		s -> next = p -> next;//�½���ָ��ָ���λ�� = p��㣨��ǰɨ�赽�Ľڵ㣩ָ��ָ���λ��
//		//�������Ϊ���µĽ��ռ�����p����һ���ڵ㣬Ҳ���ǽ�s��p��һ���ڵ��������� 
//		p -> next = s;//p����ָ��ָ���µĽ��s����s���ӵ�p֮�� 
//		return true;//����ɹ�
//	} 
//}
//
//int main(void) 
//{
//	LinkList L;//����һ��ָ�������ָ�룬�ڴ��лῪ�ٿռ䣬���ͷָ��L 
//	InitList(L);//��ʼ��һ���ձ� 
//	
//	printf("OK!\n");
//	return 0;
//}
