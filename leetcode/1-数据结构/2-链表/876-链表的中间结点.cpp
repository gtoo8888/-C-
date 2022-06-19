#include <iostream> 
#include <vector>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode() : val(0),next(nullptr) {}
	ListNode(int x) : val(x),next(nullptr) {}
	ListNode(int x,ListNode* next) : val(x),next(next) {}
};

void printListNode(ListNode* head){
	while(head != nullptr){
		cout << head-> val  << " ";
		head = head ->next;
	}
	cout << endl;
}

void deleteListNode(ListNode* head){
	if(head == nullptr)
		cout << "链表为空\n";
	while(head != nullptr){
		ListNode* temp;
		temp = head;
		head = head -> next;
		delete temp;
		cout << "删除节点\n"; 
	}
}

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    	int len = 0;
    	ListNode* temp = head;
    	while(temp != nullptr){
    		temp = temp->next;
    		len++;
		}
		int len_ans = len/2 + 1;
		ListNode* ans = head;
		while(--len_ans){
//			cout << ans->val << endl;
			ans = ans->next;	
		}
		return ans;
    }
};

int main(){
	Solution solution;
	ListNode* ans;
	vector<int> v = {1,2,3,4,5,6,7};
	int len = v.size() - 1;
	ListNode* head = new ListNode(v[len]);
	for(int i = len - 1;i >= 0;i--){
		head = new ListNode(v[i],head);
	}
	
	ans = solution.middleNode(head);
		
	printListNode(ans);
	deleteListNode(head);
	return 0;
}
