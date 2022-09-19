#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0),next(nullptr) {}
	ListNode(int x) : val(x),next(nullptr) {}
	ListNode(int x,ListNode *next) : val(x),next(next) {}
};

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void printlist(ListNode *head) {
	while(head != nullptr) {
		cout << head->val << " ";
		head = head->next; 
	}
	cout << endl; 
}

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* slow = head;
		ListNode* fast = head;
		while(k-- > 0){
			fast = fast->next;
		}
		while(fast != nullptr){
			slow = slow->next;
			fast = fast->next;
		}
		// printlist(fast);
		return slow;
    }
};



int main(){
	Solution sol;
	vector<int> value = {1,2,3,4,5};
	int len = value.size();
	ListNode* head = new ListNode(value[len -1]);
	for(int i = 1;i < len;i++)
		head = new ListNode(value[len-1-i],head);
    int k = 2;
	
	// printlist(head);

	auto ans = sol.getKthFromEnd(head,k);
	
	printlist(ans);
	return 0;
}
