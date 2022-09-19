#include <iostream>
#include <vector> 
using namespace std;


vector<int> NumSeparate(int n) {//每个位拆开求和 
	vector<int> ans;
	int temp = n;
	while(temp != 0){
		ans.push_back(temp%10);
		temp = temp / 10;			
	}
	return ans;
}
	
	


struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x,ListNode *next) : val(x), next(next){}
};

//释放new开辟的空间，不进行会导致内存泄漏
void releaseNode(ListNode* node)
{
    ListNode* temp = NULL;
    if (node == NULL)
        cout << "链表节点内存为空\n";
    else
	    while (node != NULL){
	        temp = node;
	        node = node->next;
	        delete temp;
	        cout << "节点内存清除成功\n";
	    }
}


void printListNode(ListNode* head){
	while(head != nullptr){
		cout << head -> val << " ";
		head = head -> next;
	}
	cout << endl;
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int len1 = 0;
		int len2 = 0;

		ListNode* slow = nullptr;
		ListNode* fast = l1;
		while(fast != nullptr){
			ListNode* temp = fast->next;
			fast->next = slow;
			slow = fast;
			fast = temp;
			len1++;
		}
		l1 = slow;
		
		slow = nullptr;
		fast = l2;
		while(fast != nullptr){
			ListNode* temp = fast->next;
			fast->next = slow;
			slow = fast;
			fast = temp;
			len2++;
		}
		l2 = slow;
		
		int sub = len1 > len2 ? len1 - len2 : len2 - len1;
		cout << sub << endl;

		if(len1 < len2){
			ListNode* temp = l1;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			while(sub--) {
				ListNode* aaa = new ListNode();
				temp->next = aaa;
				temp = temp->next;
				temp->val = 0;
			}
		}
		
		printListNode(l1);		
		
		ListNode* ans = new ListNode();
		
		int jinwei = 0;
		int flag = 0;
		while(l1 != nullptr && l2 != nullptr) {
			cout << (l1->val + l2->val + jinwei)%10 << endl;
			
			ans->val = (l1->val + l2->val + jinwei)%10;	
			if(flag){
//				ans->val += jinwei;
				ans = new ListNode(0,ans);
				flag = 0;
			}
			else{
				ans = new ListNode(0,ans);
			}
			
			jinwei = (l1->val + l2->val + jinwei) / 10;
			if(jinwei)
				flag = 1;
			else
				flag = 0;
			
	
				l1 = l1->next;
				l2 = l2->next; 
		}
		
				printListNode(ans);
				
		slow = nullptr;
		if(ans->val == 0)
			fast = ans->next;
		else
			fast = ans;
		while(fast != nullptr){
			ListNode* temp = fast->next;
			fast->next = slow;
			slow = fast;
			fast = temp;
		}
		ans = slow;
		
				printListNode(ans);
    }
};

		
int main() {
	Solution solution;	
	
	vector<int> value1 = {9,9,9,9};
   	int len1 = value1.size();
    ListNode* l1 = new ListNode(value1[len1-1]);
    for (int i = 1; i < len1; i++) {
        l1 = new ListNode(value1[len1-1-i], l1);
    }
    
	vector<int> value2 = {9,9,9,9,9,9,9};
   	int len2 = value2.size();
    ListNode* l2 = new ListNode(value2[len2-1]);
    for (int i = 1; i < len2; i++) {
        l2 = new ListNode(value2[len2-1-i], l2);
    }
	
	ListNode* ans;
	
	ans = solution.addTwoNumbers(l1,l2);
		
//	printListNode(ans);
	
	 
	return 0;
}



