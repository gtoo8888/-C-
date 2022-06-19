#include <iostream> 
#include <vector>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode() : val(0),next(nullptr) {}
	ListNode(int x) : val(x),next(nullptr) {}
	ListNode(int x,ListNode* next) : val(x),next(next) {}
};

void printBool(bool val){
	if(val == true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	cout << endl;
}

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

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
    bool isPalindrome(ListNode* head) {
    	if(head->next == nullptr)
    		return true;
    		
    	ListNode* temp = head;
		stack<ListNode*> sta;
		sta.push(temp);
		temp = temp->next;
		while(temp != nullptr){
//			if(sta.empty())
//				return false;

//			cout << sta.top()->val << " " << temp->val << endl;	
			
			if(sta.empty() || sta.top()->val != temp->val)
				sta.push(temp);
			else
				sta.pop();
			
			temp = temp->next;
		}
		if(sta.empty())
			return true;
		else
			return false;
    }
};

int main(){
	Solution solution;
	vector<int> value = {1,0,1};
   	int len = value.size();
    ListNode* head = new ListNode(value[len-1]);
    for (int i = 1; i < len; i++) {
        head = new ListNode(value[len-1-i], head);
    }
	bool ans;
	
	ans = solution.isPalindrome(head);
	
	deleteListNode(head);
	printBool(ans);
	
	return 0;
}
