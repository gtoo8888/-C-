#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class printqueue{
public:
	void operator()(int val){
		cout << val << " ";
	}
};

class MyStack {
public:
	queue<int> q1;
	queue<int> q2;
    MyStack() {

    }
    
    void push(int x) {
    	q2.push(x);//把先插入的元素顶上去 
    	while (!q1.empty()) {//把单端队列中的所有元素都取出来 
    		q2.push(q1.front());//按原来的次序，每弹出一个，顶到新的栈上面去 
    		q1.pop();//元素弹出来以后，在原来的队列中删除掉 
		}
		swap(q1,q2);
    }
    
    int pop() {// 移除并返回栈顶元素。
    	int r = q1.front();//得提前取出，不然被先弹出了，读取到的栈顶元素为栈顶下一个的元素 
		q1.pop();
		return r;
    }
    
    int top() {// 返回栈顶元素。
		return q1.front();
    }
    
    bool empty() {
		return q1.empty();
    }
};


 
int main(){
//	MyStack mystack ;
//
//	mystack.push(1);
//	mystack.push(2);
	//没有做测试，直接用的leetcode 
	
	return 0;
}
