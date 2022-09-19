#include <iostream>
#include <vector> 
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x,ListNode *next) : val(x), next(next){}
};


void printListNode(ListNode* head) {
	while(head != nullptr)	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
} 

void deleteListNode(ListNode* head) {
	if (head == nullptr) {
		cout << "OK all" << endl;
	}
	else
		while (head != nullptr) {
			ListNode* temp = head;
			head = head->next;
			delete temp;
			cout << "OK one" << endl;
		}
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	ListNode* dummyhead = new ListNode(0,head);
    	ListNode* cur = dummyhead;
    	while(cur->next != nullptr && cur->next->next != nullptr){
		//&&�жϵ�˳���Ǵ�ǰ�������ǰ���� cur->next->next�ᱬ�� 
//			printListNode(dummyhead);
    		ListNode* slow = cur->next;
    		ListNode* fast = cur->next->next->next;
    		
    		cur->next = cur->next->next;
    		cur->next->next = slow;
    		cur->next->next->next = fast;//��ÿ���ڵ����θ�ֵ 
    		
    		cur = cur->next->next;
		}
		return dummyhead->next;
    }
};

		
int main() {
	Solution solution;
	vector<int> v = {1,2,3,4,5};
	int n = v.size() - 1;
	ListNode* head = new ListNode(v[n]);
	ListNode* ans;
	for(int i = n - 1;i >= 0;i--) {
		head = new ListNode(v[i],head);
	}

	ans = solution.swapPairs(head);
	
    printListNode(ans);
    deleteListNode(head);
	return 0;
}



