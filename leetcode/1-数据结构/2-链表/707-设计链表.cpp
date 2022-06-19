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


class MyLinkedList {
public:
    MyLinkedList() {

    }
    
    int get(int index) {

    }
    
    void addAtHead(int val) {

    }
    
    void addAtTail(int val) {

    }
    
    void addAtIndex(int index, int val) {

    }
    
    void deleteAtIndex(int index) {

    }
};
		
int main() {

	

	return 0;
}


