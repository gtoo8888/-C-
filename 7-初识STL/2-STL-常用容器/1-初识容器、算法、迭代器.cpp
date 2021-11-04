#include <iostream> 
using namespace std;
#include <vector> 
#include <algorithm> //标准算法头文件 

//STL基本概念
//STL(Standard Template Library,标准模板库)
//STL 从广义上分为: 容器(container) 算法(algorithm) 迭代器(iterator)
//容器和算法之间通过迭代器进行无缝连接。
//STL 几乎所有的代码都采用了模板类或者模板函数
//
//STL六大组件
//STL大体分为六大组件，分别是:容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器
//1. 容器：各种数据结构，如vector、list、deque、set、map等,用来存放数据。
//2. 算法：各种常用的算法，如sort、find、copy、for_each等
//3. 迭代器：扮演了容器与算法之间的胶合剂。
//4. 仿函数：行为类似函数，可作为算法的某种策略。
//5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西。
//6. 空间配置器：负责空间的配置与管理。
//
//STL中容器、算法、迭代器
//容器：置物之所也
//STL容器就是将运用最广泛的一些数据结构实现出来
//常用的数据结构：数组, 链表,树, 栈, 队列, 集合, 映射表 等
//这些容器分为序列式容器和关联式容器两种:
//序列式容器:强调值的排序，序列式容器中的每个元素均有固定的位置。 关联式容器:二叉树结构，各元素之间没有
//严格的物理上的顺序关系
//
//算法：问题之解法也
//有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法(Algorithms)
//算法分为:质变算法和非质变算法。
//质变算法：是指运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等等
//非质变算法：是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻找极值等等
//
//迭代器：容器和算法之间粘合剂
//提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式。
//每个容器都有自己专属的迭代器
//迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针

void myPrint(int val){
	cout << val << endl;	
}


void test01(){
	//创建了一个vector容器，是一个数组 
	vector<int> v;//int指的是要操作的数据类型	

	//向容器中插入数据，尾插数据 
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	
	//第一种遍历方法 
	vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中第一个元素
	vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个元素 
	while(itBegin != itEnd){
		cout << *itBegin << endl;//把迭代器当做指针来操作 
		itBegin++; 
	}
	
	//第二种遍历方法
	for(vector<int>::iterator it = v.begin();it != v.end();it++){
		cout << *it << endl;
	}
	
	//第三种遍历方法，STL提供的遍历算法
	for_each(v.begin(),v.end(),myPrint);//回调技术 
}

//vector存放自定义数据类型
class Person{
public:
	Person(string name,int age){
		this -> m_Name = name;
		this -> m_Age = age;	
	}
	string m_Name;
	int m_Age;
};

void test02(){
	vector<Person> v;
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	Person p5("eee",50);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for(vector<Person>::iterator it = v.begin();it != v.end();it++){
		cout << "姓名：" << (*it).m_Name << " " << (*it).m_Age <<endl;
	}
}

void test03(){
	vector<Person*> v;
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	Person p5("eee",50);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for(vector<Person *>::iterator it = v.begin();it != v.end();it++){
		cout << ",,姓名：" << (*it)->m_Name << " " << (*it)->m_Age << endl; 
	}
}

//vector容器嵌套容器

void test04(){
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for(int i = 0;i < 4;i++){
		v1.push_back(i+1);
		v1.push_back(i+2);
		v1.push_back(i+3);
		v1.push_back(i+4);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for(vector<vector<int>>::iterator it = v.begin();it != v.end();it++){
		for(vector<int>::iterator vit = (*it).begin();vit != (*it).end();vit++){
			cout << *vit << " ";
		}
		cout << endl;
	}
}


int main(){
	
	test01(); 

	test02();
	test03();

	test04();
	return 0;
}



