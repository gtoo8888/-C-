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


//class Solution {//����ɾ�� 
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//    	while(head != nullptr && head -> val == val){//ѭ������ͷ��㣬��ֹ��һ��Ԫ��һֱ���� 
//    		ListNode* temp = head;
//    		head = head -> next;
//    		delete temp;
//		}
//		
//    	if(head == nullptr)//��������� 
//    		return head;
//			  		
//		ListNode* slow = head;//����ָ�봦�� 
//		ListNode* fast = head -> next;
//		while(slow -> next !=  nullptr && slow != nullptr){
//			if(fast -> val == val){
//				ListNode* temp = fast;
//				slow -> next = fast -> next;
//				fast = fast -> next;	
//				delete temp;
//			}
//			else{
//				slow = slow -> next;
//				fast = fast -> next;
//			}
//		}
//		return head;
//    }
//};

class Solution {//����ͷ��� 
public:
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode* dummyhead = new ListNode(0,head);//����ͷ���
    	ListNode* cur = dummyhead;
    	
    	while(cur != nullptr && cur -> next != nullptr){
    		if(cur->next->val == val){
    			ListNode* temp = cur->next;
    			cur->next = cur->next->next;
    			delete temp;
			}
			else
				cur = cur->next;
		}
		 
		return dummyhead -> next;
    }
};

int main(){
	Solution solution;
	ListNode* ans;
	int val = 7;
	vector<int> v = {7,1,2,3,7,7,7,7};
	int len = v.size() - 1;
	ListNode* head = new ListNode(v[len]);
	for(int i = len - 1;i >= 0;i--){
		head = new ListNode(v[i],head);
	}
	
	ans = solution.removeElements(head,val);
		
	printListNode(ans);

	deleteListNode(head);
	return 0;
}
