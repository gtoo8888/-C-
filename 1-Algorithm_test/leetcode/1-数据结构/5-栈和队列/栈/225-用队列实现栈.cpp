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
    	q2.push(x);//���Ȳ����Ԫ�ض���ȥ 
    	while (!q1.empty()) {//�ѵ��˶����е�����Ԫ�ض�ȡ���� 
    		q2.push(q1.front());//��ԭ���Ĵ���ÿ����һ���������µ�ջ����ȥ 
    		q1.pop();//Ԫ�ص������Ժ���ԭ���Ķ�����ɾ���� 
		}
		swap(q1,q2);
    }
    
    int pop() {// �Ƴ�������ջ��Ԫ�ء�
    	int r = q1.front();//����ǰȡ������Ȼ���ȵ����ˣ���ȡ����ջ��Ԫ��Ϊջ����һ����Ԫ�� 
		q1.pop();
		return r;
    }
    
    int top() {// ����ջ��Ԫ�ء�
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
	//û�������ԣ�ֱ���õ�leetcode 
	
	return 0;
}
