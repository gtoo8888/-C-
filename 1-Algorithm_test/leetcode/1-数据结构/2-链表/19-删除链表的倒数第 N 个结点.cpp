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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dunmhead = new ListNode(0,head);
		ListNode* slow = dunmhead;
		ListNode* fast = dunmhead;
		while(n-- && fast != nullptr){
			fast = fast->next;
		}
		fast = fast->next;
//		printListNode(fast);
		while(fast != nullptr){
			slow = slow->next;
			fast = fast->next;
		}
		slow->next = slow->next->next;
		return dunmhead->next;
    }
};

int main(){
	Solution solution;
	ListNode* ans;
	int n = 2;//倒数第几个 
	vector<int> v = {1,2};
	int len = v.size() - 1;
	ListNode* head = new ListNode(v[len]);
	for(int i = len - 1;i >= 0;i--){
		head = new ListNode(v[i],head);
	}
	
	ans = solution.removeNthFromEnd(head,n);
		
	printListNode(ans);

	deleteListNode(head);
	return 0;
}
