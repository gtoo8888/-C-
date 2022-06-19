#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
	int data;
	LNode *next;
}LNode,*LinkList;


bool Initlist(LinkList &L){
	L = NULL;
	return true;
}

bool Insetlist(LinkList &L,int i,int e){
	LinkList p;
	int j = 0;
	if(i == 1)
	{
		p = (LNode *)malloc(sizeof(LNode));
		p -> data = e;
		p -> next = L;
		L = p;
		return true;
	while(p != NULL && j < i-1){
		p = p -> next;
		j++;
	}

		p = (LNode *)malloc(sizeof(LNode));
		p -> data = e;
		p -> next = L -> next;
		L -> next = p;		

	return true;
}

void outlist(LinkList &L)
{
	LinkList p;
	p = L;
	int i = 1;
	while(p)
	{
		printf("%d %d\n",i++,p -> data);
		p = p -> next;
	}	
	putchar('\n');
}

int main(void)
{
	LinkList L;
	
	Initlist(L);
	Insetlist(L,1,2);
	Insetlist(L,2,3);
	Insetlist(L,3,4);
	Insetlist(L,4,6);
	Insetlist(L,5,4);
	Insetlist(L,6,7);
	Insetlist(L,7,8);
	Insetlist(L,8,4);
	
	outlist(L);
	
	
	return 0;
} 
