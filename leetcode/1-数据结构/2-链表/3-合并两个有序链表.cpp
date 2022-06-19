#include <iostream>
#include <malloc.h>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
};


void display(struct ListNode* p){
	struct ListNode* l = (struct ListNode*)malloc(sizeof(struct ListNode*));
	l = p;
	while(l != NULL)
	{
		cout << l -> val  << endl;
		l = l -> next;
	}	
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	struct ListNode *result =(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p;
	p = result;
	
	while(l1 && l2)
	{
//		cout << l1 -> val << " " << l2 -> val << "\n" << endl;
		if(l1 -> val <= l2 -> val)
		{
			result -> next = l1;
			l1 = l1 -> next;
		}
		else
		{
			result -> next = l2 ;
			l2 = l2 -> next;
		}
		result = result -> next;
	}
	result -> next = l1 ? l1 : l2;
	
	return p -> next;
}	




int main()
{
	struct ListNode a1,a2,a3,a4;
	struct ListNode b1,b2,b3,b4;
	struct ListNode* l1 = &a1;
	struct ListNode* l2 = &b1;
	struct ListNode* result = NULL;
	
	a1.val = 1;
	a1.next = &a2;
	a2.val = 2;
	a2.next = &a3;
	a3.val = 4;
	a3.next = NULL;

	b1.val = 1;
	b1.next = &b2;
	b2.val = 3;
	b2.next = &b3;
	b3.val = 4;
	b3.next = NULL;
//	b4.val = 9;
//	b4.next = NULL;
		
//	a1.val = 6;
//	a1.next = NULL;
//	b1.val = 5;
//	b1.next = NULL;	

	result = mergeTwoLists(l1,l2);	
	
	display(result);
	
	return 0;
}



