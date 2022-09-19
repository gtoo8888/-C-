#include <iostream>
using namespace std;
#include <queue>
//queue容器 
//Queue是一种先进先出(First ln First Out,FIFO)的数据结构，它有两个出口
//只有队头和队尾能祯外界访问，因此不允许有遍历行为

//构造函数:
//queue<T> que ;//queue采用模板类实现，queue对象的默认构造形式
//queue(const queue &que);//拷贝构造函数
//赋值操作:
//queue& operator=(const queue &que);//重载等号操作符
//数据存取:
//push(elem);//往队尾添加元素
//pop();//从队头移除第一个元素
//back();//返回最后一个元素
//front();//返回第一个元素
//大小操作:
//empty();//判断堆栈是否为空
//size();//返回栈的大小

class Person{
public:
	Person(string name,int age){
		this -> m_name = name;
		this -> m_age = age;
	}
	string m_name;
	int m_age;
};

void test01(){
	queue<Person>q;
	
	Person p1("唐僧",30);
	Person p2("孙悟空",1000);
	Person p3("猪八戒",800);
	Person p4("沙僧",900);
	
	q.push(p1);//入队 
	q.push(p2);
	q.push(p3);
	q.push(p4);
	
	cout << q.size() << endl;	
	while(!q.empty()){
		cout << q.front().m_name << q.front().m_age << endl;
		cout << q.back().m_name << q.back().m_age << endl;
		q.pop();
	}
	cout << q.size() << endl;
}

int main(){
    test01();
    cout << endl;
      
    return 0;
}



















