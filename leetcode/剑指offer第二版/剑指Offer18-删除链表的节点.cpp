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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val)
            return head->next;
        ListNode* head_tmp = head;
        while(head_tmp != NULL) {
            if(head_tmp->next->val == val) {
                break;
            }
            head_tmp = head_tmp->next;
        }
        head_tmp->next = head_tmp->next->next;
        return head;
    }
};



int main(){
	Solution sol;
	vector<int> value = {-3,5,9};
	int len = value.size();
	ListNode* head = new ListNode(value[len -1]);
	for(int i = 1;i < len;i++)
		head = new ListNode(value[len-1-i],head);
    int val = -3;
	
	// printlist(head);

	auto ans = sol.deleteNode(head,val);
	
	printlist(ans);
	return 0;
}
