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


void structListNode(ListNode* head,int pos) {//构造环形链表 	
	ListNode* start = head;
	ListNode* end = head;
	
	while(end->next != nullptr){
		end = end->next;
	}
//	cout << end->val << endl;
	while(pos--) {
		start = start->next;		
	}
	end->next = start;
}


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	if(head == nullptr || head->next == nullptr)
    		return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
//        	cout << slow->val << " " << fast->val << endl;
        	slow = slow->next;
			fast = fast->next->next;     
        	if(slow == fast) {//找到了环 
        		ListNode* temp1 = head;
        		ListNode* temp2 = fast;
        		
        		while(temp1 != temp2){//寻找入口 
        			cout << temp1->val << " " << temp2->val << endl;
        			temp1 = temp1->next;
        			temp2 = temp2->next;
				}
				return temp1;
        	}
		}
		return nullptr;
    }
};

		
int main() {
	Solution solution;
	vector<int> v1 = {3,2,0,-4};
	int n1 = v1.size() - 1;
	int pos = 1;
	ListNode* head = new ListNode(v1[n1]);
	ListNode* ans;
	for(int i = n1 - 1;i >= 0;i--) {
		head = new ListNode(v1[i],head);
	}	
	
	structListNode(head,pos);

	ans = solution.detectCycle(head);	
	
//    printListNode(head);
    
//    printListNode(ans);
    
	return 0;
}


