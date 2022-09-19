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
    void reorderList(ListNode* head) {
		ListNode* temp = head;
		int len = 0;
//		int ListNum[100];
		vector<int> ListNum(10);
		while(temp != nullptr){
			ListNum[len] = temp->val;
			len++;
			temp = temp->next;
		}
		printVector(ListNum);
		cout << len << endl;
//		int j = len-1;
		for(int i = 0,j = len-1;i < j;i++,j--){
			swap(ListNum[i],ListNum[j]);
		}
				printVector(ListNum);
    }
};

int main(){
	Solution solution;
	vector<int> value = {1,2,3,4,5};
   	int len = value.size();
    ListNode* head = new ListNode(value[len-1]);
    for (int i = 1; i < len; i++) {
        head = new ListNode(value[len-1-i], head);
    }
	printListNode(head);	
	
	solution.reorderList(head);
	deleteListNode(head);
	return 0;
}
