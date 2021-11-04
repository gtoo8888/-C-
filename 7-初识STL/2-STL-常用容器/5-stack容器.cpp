#include <iostream>
using namespace std;
#include <stack>

//栈不允许有遍历行为，因为只有栈顶元素才能被外界访问到 
//栈可以判断容器是否为空
//栈可以返回元素个数

//stack常用接口
//构造函数:
//stack<T> stk;//stack采用模板类实现， stack对象的默认构造形式
//stack( const stack &stk);//拷贝构造函数
//赋值操作:
//stack& operator=( const stack &stk);//重载等号操作符
//数据存取:
//push(elem);//向栈顶添加元素
//pop();//从栈顶移除第一个元素
//top();//返回栈顶元素
//大小操作:
//empty( );//判断堆栈是否为空
//size();//返回栈的大小


void test01(){
 	stack<int> s;
	 
	s.push(10);//入栈 
	s.push(20);
	s.push(30);
	s.push(40);
	cout << s.size() << endl;//栈的大小 
	while(!s.empty()) {//只要栈不为空，查看栈顶，并且执行出栈操作
		 cout << s.top() << endl;//查看栈顶元素
		 s.pop();//出栈 
	}
	cout << s.size() << endl;//栈的大小 
}

 
int main(){
    test01();
    cout << endl;

    return 0;
}







