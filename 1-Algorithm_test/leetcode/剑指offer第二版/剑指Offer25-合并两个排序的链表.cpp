#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* ans = new ListNode(0,nullptr);
		ListNode* tmp = ans;
		while(l1 != nullptr && l2 != nullptr){
			// printf("%d %d\n",l1->val,l2->val);
			if(l1->val < l2->val){
				tmp->next = l1;
				l1 = l1->next;
			}else{
				tmp->next = l2;
				l2 = l2->next;
			}
			tmp = tmp->next;
		}
		tmp->next = l1 != nullptr ? l1 : l2;	// 把剩下的补充过去
		return ans->next;
    }
};

int main(){
	Solution sol;

	vector<int> value1 = {1,2,4};
	ListNode* list1 = CreateListNode(value1);
	vector<int> value2 = {1,3,4,5,6,7};
	ListNode* list2 = CreateListNode(value2 );

	PrintListNode(list1);
	PrintListNode(list2);
	auto ans = sol.mergeTwoLists(list1,list2);
	
	PrintListNode(ans);
	return 0;
}
