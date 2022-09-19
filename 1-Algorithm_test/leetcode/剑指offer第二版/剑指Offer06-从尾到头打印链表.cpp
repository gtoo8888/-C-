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
}

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
		ListNode *fast = head;
		ListNode *slow = nullptr;
		vector<int> ans = {};
		
		while(fast != nullptr) {
			ListNode *temp = fast->next;
			fast->next = slow;
			slow = fast;
			fast = temp;			
		}
		while(slow != nullptr) {
			ans.push_back(slow->val);
			slow = slow->next;
		}
		return ans;
    }
};



int main(){
	Solution sol;
	vector<int> value = {1,3,2};
	int len = value.size();
	ListNode* head = new ListNode(value[len -1]);
	for(int i = 1;i < len;i++)
		head = new ListNode(value[len-1-i],head);
	
//	printlist(head);

	auto ans = sol.reversePrint(head);
	
	PrintVector(ans);
	return 0;
}
