#include <algorithm> 
#include <iostream>
#include <vector>
#include <stack>
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

class CQueue {
public:
    stack<int> instack,outstack;
    void in_to_out() {
        while(!instack.empty()){
            outstack.push(instack.top());
            instack.pop();
        }
    }
    
    CQueue() {

    }
    
    void appendTail(int value) {
        instack.push(value);
    }
    
    int deleteHead() {
        if(outstack.empty()) {
            if(instack.empty())
                return -1;
            in_to_out();
        }
        int ans = outstack.top();
        outstack.pop();
        return ans;
    }
};



int main(){
	Solution sol;
	vector<int> value = {1,3,2};
	int len = value.size();
	ListNode* head = new ListNode(value[len -1]);
	for(int i = 1;i < len;i++)
		head = new ListNode(value[len-1-i],head);
	
//	printlist(head);

	auto ans = sol.reversePrint(head);
	
	PrintVector(ans);
	return 0;
}
