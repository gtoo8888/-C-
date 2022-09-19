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


void structListNode(ListNode* headA, ListNode* headB,//构造相交链表 
					int intersectVal,int skipA,int skipB) {
	ListNode* test1 = headA;
	ListNode* test2 = headB;
	skipA--;skipB--;
	while(skipA--){
		test1 = test1->next;
	}
	while(skipB--){
		test2 = test2->next;
	}
	test1->next = test2->next;//只有改变了指向才能让他们相交 
}



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode* test1 = headA;
        ListNode* test2 = headB;
        while(test1 != nullptr) {
            test1 = test1->next;
            len1++;
        }
        while(test2 != nullptr) {
            test2 = test2->next;
            len2++;
        }
        test1 = headA;
        test2 = headB;
        if(len2 > len1){
            swap(test1,test2);
            swap(len1,len2);
        }
        int sub = len2 > len1 ? len2-len1 : len1-len2;
        while(sub--){
            test1 = test1->next;
        }
        while(test1 != nullptr && test2 != nullptr){
            // cout << test1->val << " " << test2->val << endl;
            if(test1 == test2)
                return test1;
            test1 = test1->next;
            test2 = test2->next;
        }
        return NULL;
    }
};

		
int main() {
	Solution solution;
	vector<int> v1 = {0,9,1,2,4};
	vector<int> v2 = {3,2,4};
	int n1 = v1.size() - 1;
	int n2 = v2.size() - 1;
	int intersectVal = 2;
	int skipA = 3;
	int skipB = 1;
	ListNode* headA = new ListNode(v1[n1]);
	ListNode* headB = new ListNode(v2[n2]);
	ListNode* ans;
	for(int i = n1 - 1;i >= 0;i--) {
		headA = new ListNode(v1[i],headA);
	}
	for(int i = n2 - 1;i >= 0;i--) {
		headB = new ListNode(v2[i],headB);
	}
	
	
	structListNode(headA,headB,intersectVal,skipA,skipB);

//	if(headA->next->next == headB->next->next->next)
//		cout << "YES" << endl;
	ans = solution.getIntersectionNode(headA,headB);	
	
    printListNode(headA);
    printListNode(headB);
    
    printListNode(ans);
    
	return 0;
}



