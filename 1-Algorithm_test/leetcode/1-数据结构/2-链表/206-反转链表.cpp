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
		cout << "����Ϊ��\n";
	while(head != nullptr){
		ListNode* temp;
		temp = head;
		head = head -> next;
		delete temp;
		cout << "ɾ���ڵ�\n"; 
	}
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	ListNode* slow = nullptr;
    	ListNode* fast = head;
    	
    	while(fast != nullptr){
    		ListNode* temp = fast->next;//��ָ��ı���һ�£���Ϊ�������ϵ� 
    		fast->next = slow;//�ı�ָ�� 
    		slow = fast;
    		fast = temp;
//    		delete temp;
		}
    	
		return slow;
    }
};

int main(){
	Solution solution;
	ListNode* ans;
	vector<int> v = {1,2,3,4,5,3,4,5,6,6,7,78,7,5,46,34,3};
	int len = v.size() - 1;
	ListNode* head = new ListNode(v[len]);
	for(int i = len - 1;i >= 0;i--){
		head = new ListNode(v[i],head);
	}
	
	ans = solution.reverseList(head);
		
	printListNode(ans);

	deleteListNode(head);
	return 0;
}
