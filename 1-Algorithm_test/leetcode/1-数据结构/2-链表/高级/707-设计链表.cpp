#include <iostream> 
#include <vector>
#include <ctime>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"



class MyLinkedList {
public:
	struct linkednode{
		int val;
		linkednode* next;
		linkednode() : val(),next(nullptr){}
		linkednode(int val) : val(val),next(nullptr){}
	};

	int size;
	linkednode* dumpnode;

    MyLinkedList() {
		size = 0;
		dumpnode = new linkednode(0);
    }
    
    int get(int index) {
		if(index > (size-1) || index < 0)
			return -1;
		linkednode* tmp = dumpnode->next;
		while(index--){
			tmp = tmp->next;
		}
		return tmp->val;
    }
    
    void addAtHead(int val) {
		linkednode* tmp = new linkednode(val);
		tmp->next = dumpnode->next;	// 这是一个虚拟的头结点
		dumpnode->next = tmp;
		size++;
    }
    
    void addAtTail(int val) {
		linkednode* tmp = new linkednode(val);
		linkednode* cur = dumpnode;
		while(cur->next != nullptr){
			cur = cur->next;
		}
		cur->next = tmp;
		size++;
    }
    
    void addAtIndex(int index, int val) {
		if(index > size || index < 0)
			return;
		linkednode* tmp = new linkednode(val);
		linkednode* cur = dumpnode;
		while(index--){
			cur = cur->next;
		}
		tmp->next = cur->next;
		cur->next = tmp;
		size++;
		// printf("%d\n",cur->val);
    }
    
    void deleteAtIndex(int index) {
		if(index >= size || index < 0)
			return;
		linkednode* tmp = dumpnode;
		while(index--){
			tmp = tmp->next;
		}
		if(tmp->next == nullptr)	// 没考虑最后一个越界问题
			tmp->next = nullptr;
		else
			tmp->next = tmp->next->next;
		size--;
    }

	void PrintMylist(){
		linkednode* tmp = dumpnode;
		while(tmp->next != nullptr){
			cout << tmp->next->val << endl;
			tmp = tmp->next;
		}
		cout << endl;
	}
};



void test1(){
	MyLinkedList* obj = new MyLinkedList();
	obj->addAtHead(1);
	obj->addAtHead(2);
	obj->addAtHead(3);
	obj->addAtHead(4);
	obj->addAtTail(5);
	obj->addAtTail(6);
	obj->addAtTail(7);
	obj->addAtTail(8);

	obj->PrintMylist();

	cout << obj->get(-234) << endl;
	cout << obj->get(1) << endl;
	cout << endl;

	obj->deleteAtIndex(1);
	obj->PrintMylist();

	obj->addAtIndex(1,45);
	obj->PrintMylist();
}

void test2(){
	MyLinkedList* obj = new MyLinkedList();
	obj->addAtHead(1);
	obj->deleteAtIndex(2);
	obj->addAtHead(2);
	obj->addAtHead(7);
	obj->addAtHead(3);
	obj->addAtHead(2);
	obj->addAtHead(5);
	obj->addAtTail(5);

	obj->PrintMylist();

	cout << obj->get(5) << endl;
	obj->deleteAtIndex(6);
	obj->deleteAtIndex(4);

	obj->PrintMylist();
}

int main(){
	
	// test1();
	test2();
	
	return 0;
}
