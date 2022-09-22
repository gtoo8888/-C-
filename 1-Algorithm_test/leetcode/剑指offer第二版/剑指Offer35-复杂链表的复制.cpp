#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"



// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    unordered_map<Node*,Node*> map;
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        
        if(!map.count(head)){
            Node* tmp = new Node(head->val);
            map[head] = tmp;
            tmp->next = copyRandomList(head->next);
            tmp->random = copyRandomList(head->random);
        }
        return map[head];
    }
};


int main(){
	Solution sol;
	vector<int> value = {1,2,3,4,5};
	int len = value.size();
	ListNode* head = new ListNode(value[len -1]);
	for(int i = 1;i < len;i++)
		head = new ListNode(value[len-1-i],head);
	
	// printlist(head);

	// auto ans = sol.copyRandomList(head);
	
	// PrintListNode(ans);
	return 0;
}
