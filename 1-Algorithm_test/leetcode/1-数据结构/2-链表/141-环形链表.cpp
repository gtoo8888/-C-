#include <iostream> 
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	//ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(struct ListNode *head){
    	struct ListNode *fast =(struct ListNode*)malloc(sizeof(struct ListNode));
    	if(head -> next == NULL || head == NULL)
    		return false;
        fast = head -> next;
        while(fast != head){
			head = head -> next;
			fast = fast -> next -> next;
//			cout << head -> val  << " " << fast -> val << endl;
			if((fast -> next == NULL) && fast -> next == NULL)
				return false;
		}
		return true;
    }
};


int main(){
	Solution sol;
	struct ListNode a1,a2,a3,a4;
	struct ListNode* l1 = &a1;
	struct ListNode* result = NULL;
	
	bool result_bool;
		
	a1.val = 3;
	a1.next = &a2;
	a2.val = 2;
	a2.next = &a3;
	a3.val = 0;
	a3.next = &a4;	
	a4.val = -4;
	a4.next = &a2;	


//	a1.val = 3;
//	a1.next = NULL;
////	a2.val = 2;
////	a2.next = &a1;

	
	
	result_bool = sol.hasCycle(l1);	
	
	if(result_bool)
		cout << "有环" << endl; 
	else
		cout << "无环" << endl;
}



