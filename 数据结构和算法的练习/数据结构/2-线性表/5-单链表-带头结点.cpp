#include <stdio.h> 
#include <stdlib.h>
//һ����λ���巽��
typedef struct LNode{//���嵥����ڵ����� ������������������ΪLNode 
	int data;			//������ 
	struct LNode *next;	//ָ����
}LNode,*LinkList;//��������������ͬʱ������һ��������һ��ָ��*LinkList 

/***************��ʼ��һ���յĵ����� ��ͷ�ڵ� *********************/ 
//��ͷ���ĵ�����ͷ��㲻�洢���ݣ�����ָ����ָ����һ���ڵ� 
bool InitList(LinkList &L){
	L = (LNode *)malloc(sizeof(LNode));//�������һ��ͷ��� 	
	if(L == NULL)// �ڴ治�����ʧ��,ֱ�ӷ��� 
		return false;
	L -> next = NULL;//ͷ�ڵ�֮����ʱ��û�нڵ� 
	L -> data = -1;//ͷ����в�Ӧ�������ݡ�����û�ж��壬��֪���ò��ö��� 
	return true;
}

/***************�жϵ������Ƿ�Ϊ��(��ͷ���)*********************/ 
bool Empty(LinkList L){
	if(L -> next == NULL) 
		return true;
	else
		return false;
}

/***************��λ���ң����ص�i��Ԫ�أ���ͷ��㣩 *********************/ 
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

/***************��ֵ���ң��ҵ�������==e�Ľ�㣨��ͷ��㣩 *********************/ 
LNode *LocateElem(LinkList L,int e,int &i){
	LNode *p = L -> next;//�ӵ�һ�ڵ㿪ʼ���� 
	i = 1;
	while(p != NULL && p -> data != e) 
	{
		i++;//�Լ��ӵı���i��Ϊ���ҳ�����Ǹ����ֵ�λ�� 
		p = p -> next;
	}	
	return p;//�ҵ��󷵻ظý���ָ�룬���򷵻�NULL 
}

/***************����������p�ڵ�֮�����Ԫ��e*********************/ 
bool InsertNextNode(LNode *p,int e){
	if(p == NULL)//��������ô���ܴ����ָ�룿ʵ����Ϊ���ν��ϵİ�λ���ң����û�ҵ����ͻ᷵�ؿ�ָ�� 
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL)//�ڴ����ʧ�ܣ����Ե�ʱ����Բ���д 
		return false;//�����Ҫ����ʵ������������ڴ�ռ�������� 
	s -> data = e;
	s -> next = p ->next;
	p -> next = s;
	return true;		
}

/***************ǰ���������p�ڵ�֮ǰ����Ԫ��e*********************/ 
//������ʱ�临�Ӷ���O(1)����������ڵ�һ���ڵ���������ʱ�򣬻�����������ͷ�������ȥ������bug 
bool InsertPriorNode(LNode *p,int e){//ԭ���ڵ� 
	if(p == NULL)//����ʲô��֪���� 
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));//����һ���½ڵ�s 
	if(s == NULL)//�ڴ����ʧ��
		return false;
	s -> next = p ->next;//����ڵ�s��Ϊԭ���ڵ�p�ڵ�ĺ�̽ڵ� 
	p -> next = s;//p�ڵ�ָ���½ڵ� 
	s -> data = p -> data;//��ԭ����s�е����ݴ����µ�s�ڵ��� 
	p -> data = e;//����ԭ����p�ڵ��Ѿ���ǰ���ڵ��ˣ����Խ���Ҫ�����ݴ���p����ȥ
	//���ڽڵ㣬�����Ȳ����µģ�������ϵ�
	//���ڳ�Ա���Ȳ���ָ���ָ�򣬺�������� 
	return true;		
}

/***************�ڵ�i��λ�ò���Ԫ��e����ͷ��㣩 *********************/ 
bool ListInsert(LinkList &L,int i,int e){//��λ�����(��ͷ���) 
	if(i < 1)//�ж������Ƿ�Ϸ���iΪλ��λ���Ǵ�1��ʼ�� 
		return false;//����ʧ�� 	
//	LNode *p;	//ָ��pָ��ǰɨ�赽�Ľڵ� 
//	int j = 0;	//j��ʾpָ����ǵڼ������ 
//	p = L;		//pָ��ͷ��㣬ͷ����ǵ� 0����㣨��0�������ʵ������ģ���Ϊʵ���Ͻ���Ǵ�1��ʼ�ģ� 
//
//	{//ѭ���ҵ���i-1����� 	
//		while(p != NULL && j < i-1){
//			p = p -> next;
//			j++;
//		}
//	} 
	LNode *p = GetElem(L,i-1);//�����ȫ�������ð�λ�����滻 
//	{//��i-1���֮������µĽ�� 
//		if(p == NULL)//i���̫��ֱ�ӷ��ز���ʧ�� 
//			return false;
//		LNode *s = (LNode *)malloc(sizeof(LNode));//����һ���µĽ��ռ� 
//		s -> data = e;//�Ѳ���e�����½�� 
//		s -> next = p -> next;//�½���ָ��ָ���λ�� = p��㣨��ǰɨ�赽�Ľڵ㣩ָ��ָ���λ��
//		//�������Ϊ���µĽ��ռ�����p����һ���ڵ㣬Ҳ����s��p��һ���ڵ�ָ�����ͬһ���ڵ�
//		p -> next = s;//p����ָ��ָ���µĽ��s����s���ӵ�p֮�� 
//		return true;//����ɹ�
//	} 
	return InsertNextNode(p,e);//ֱ�ӵ��ú�������������д���������ظ��ģ�����ʵ�� 
	
}

/***************��λ��ɾ������ͷ��㣩 *********************/ 
//p�ǵ�ǰɨ�赽�Ľ�㣬q����Ҫɾ���Ľ��
//����pɨ��ȥ��ɨ���Ժ���q��pɨ���Ķ���ץס
//Ȼ���qɾ�����ڴ������ɾ����� 
bool ListDelete(LinkList &L,int i,int &e) {
	if(i < 1)
		return false;
//	LNode *p;//p��ǰɨ�赽�Ľ�� 
//	int j = 0;//pָ��ڼ������ 
//	p = L;//����p��L������ӹ��� 
//	while(p != NULL && j < i-1){//ѭ���ҵ�Ҫɾ�� 
//		p = p -> next;
//		j++;
//	}
	LNode *p = GetElem(L,i-1);//�����ȫ�������ð�λ�����滻 
	
	if(p == NULL)//����������ĵط�ȥ�� 
		return false;
	if(p -> next == NULL)
		return false;
	LNode *q;
	q = p -> next;//�ҵ�Ҫɾ�Ľ����ƽ���q 
	e = q -> data;
	p -> next = q -> next;//��ɾ�� 
	free(q);
	return true;
}

/***************ָ������ɾ������ͷ��㣩 *********************/ 
//Ч����ɾ����ͷ��㡣���������Ѻ���Ĳ������� 
bool DeleteNode(LNode *p){
	if(p == NULL)
		return false;
	LNode *temp;//��ʱ�������ڱ�����Ҫɾ���Ľ��
	temp = p -> next;//����µĽڵ�����Ҫɾ���ڵ����һ���ڵ�
	p -> data = temp -> data;//
	p -> next = temp -> next;
	free(temp);
	return true;
} 

/***************������ĳ��ȣ���ͷ��㣩 *********************/ 
int Length(LinkList L){
	int len = 0;
//	LNode *p = L;
//	while(p -> next != NULL)
	LNode *p = L -> next;
	while(p)//�򵥵�д�� 
	{
		p = p -> next;
		len++;
	}
	return len;
}


void OutputList(LinkList &L);//��������е����� 
LNode *ReverseList(LNode *pHead );//����ת 

int main(void) 
{
	LinkList L;//����һ��ָ�������ָ�룬�ڴ��лῪ�ٿռ䣬���ͷָ��L 
	int delete_num;

	InitList(L);//��ʼ��һ���ձ� 
	
	ListInsert(L,1,2);//�ڵ�i��λ�ò���Ԫ��e 
	ListInsert(L,2,21);
	ListInsert(L,3,55);
	ListInsert(L,4,47);
	ListInsert(L,5,81);
	ListInsert(L,6,99);
	ListInsert(L,7,67);
	
	
	OutputList(L);
	
	InsertNextNode(L,133);//ֱ�ӵ��ú���������ͷ�巨 
	InsertNextNode(L,1794);
	
	OutputList(L);
	
	InsertPriorNode(L,3);//ֱ��ǰ�������Ч��������һ������Ϊ���Ǵ�ͷ��ʼ���� 
	InsertPriorNode(L,77);
	InsertPriorNode(L,678);
	
	OutputList(L);
	
	ListDelete(L,3,delete_num) ;//��λ��ɾ�� 
	OutputList(L);
	ListDelete(L,3,delete_num) ;
	OutputList(L);
	
	DeleteNode(L);//ָ�����ɾ�� 
	OutputList(L);
	DeleteNode(L);//ָ�����ɾ�� 
	OutputList(L);
	
	LinkList FOUND;
	
	FOUND = GetElem(L,6);//��λ���ң�����λ��ʲô���� 
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

/***************��������е����� *********************/ 
void OutputList(LinkList &L){
	LinkList p;//����һ���������������� 
	p = L ;//��ͷ�������ĵ�һ���ڵ㿪ʼ���� 
	int i = 0;
	while(p){//Ϊ��NULL������û����һ�������ʱ��ֹͣѭ��  
		printf("%d %d\n",i,p->data);//������� 
		i++;
		p = p -> next;
	}
	printf("\n");
}

LNode *ReverseList(LNode *pHead ) {//����ת 
    LNode* pre = NULL;//�������Ϊ������һ��ԭ������ת����������ԭ���������Ŷ�ȡ 
    LNode* cur = pHead;//ָ��ǰ�����һ�� 
    LNode* next = pHead->next;//ָ��ǰ����ڶ���
	//��ת�����ʱ�� ���ϵ��������ȥһ���ӵ�һ������ڵ� 
    while(cur)
	{
        next = cur->next;//����ڶ����ڵ������ 
        cur->next = pre;//�ϵ���һ���͵ڶ��������� 
        pre = cur;//������õ���������ĵ�һ����� 
        cur = next;//��һ���ڵ�ת���˱��������ĵڶ����ڵ� 
    }
    return pre;//���������� 
}


