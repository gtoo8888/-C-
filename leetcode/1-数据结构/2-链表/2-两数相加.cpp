#include <iostream> 
#include <math.h>
#include <malloc.h>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode* q1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* q2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
	q1 = l1;
	q2 = l2;
	
	int temp;
	
	while(q1 != NULL)
		while(q2 != NULL)
		{
			q1 -> val = (q1 -> val + q2 -> val) % 10;
			temp = (q1 -> val + q2 -> val) / 10;
			
			q1 = q1 -> next;
			q2 = q2 -> next;
			
			q1 -> val += temp;
		}
}	

////老实人做法，直接被100000000000爆掉 
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
//	int l1_len=0,l2_len=0;
//	int l1_num[100],l2_num[100],sum[100];
//	unsigned long long l1_result=0,l2_result=0;
//	unsigned long long sum_result=0;
//	
//	while(l1 != NULL)
//	{
//		l1_num[l1_len] = l1 -> val;
//		l1_len++;
//		l1 = l1 -> next;
//	}
//	for(int i = 0;i < l1_len;i++)
//	{
//		l1_result += l1_num[i] * pow(10,i);
//	}
//	
//	while(l2 != NULL)
//	{
//		l2_num[l2_len] = l2 -> val;
//		l2_len++;
//		l2 = l2 -> next;
//	}
//	for(int i = 0;i < l2_len;i++)
//	{
//		l2_result += l2_num[i] * pow(10,i);
//	}
//
//	sum_result = l1_result + l2_result;
//	
//	int sum_len = 0;	
//	int sum_temp =  sum_result;//临时变量替换掉，防止改变原来的数字 
//	
//	if(sum_result == 0) 
//	{
//		sum[0] = 0;
//		sum_len = 1;
//	}
//	else	
//		while(sum_temp != 0)
//		{
//			sum[sum_len] = sum_temp%10;
//			sum_len++;
//			sum_temp /= 10;
//		}
//	int i = 0; 
//	struct ListNode* len_sum;
//	
//	len_sum = (struct ListNode*)malloc(sizeof(struct ListNode));
//	len_sum -> next = NULL;
//	len_sum -> val = sum[0];
//	if(sum_len > 1)
//	{ 
//		i++;
//		do{		
//			struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
//			
//			p -> val = sum[sum_len-i];
//			p -> next = len_sum -> next;
//			len_sum -> next = p;
//			i++;			
//		}while(i < sum_len);
//	}	
//	return len_sum;
//}
//


int main()
{
	struct ListNode a1,a2,a3,a4;
	struct ListNode b1,b2,b3,b4;
	struct ListNode* l1 = &a1;
	struct ListNode* l2 = &b1;
	struct ListNode* result = NULL;
	struct ListNode* seek = NULL;
	
//	a1.val = 2;
//	a1.next = &a2;
//	a2.val = 4;
//	a2.next = &a3;
//	a3.val = 9;
//	a3.next = NULL;
//
//	b1.val = 5;
//	b1.next = &b2;
//	b2.val = 6;
//	b2.next = &b3;
//	b3.val = 4;
//	b3.next = &b4;
//	b4.val = 9;
//	b4.next = NULL;
		
	a1.val = 6;
	a1.next = NULL;
	b1.val = 5;
	b1.next = NULL;	
		
	seek = &a1;
	
	result = addTwoNumbers(l1,l2);	
	
//	while(result != NULL)
//	{
//		cout << result -> val << '\n' << endl;
//		result = result -> next;
//	}
	
	return 0;
}
