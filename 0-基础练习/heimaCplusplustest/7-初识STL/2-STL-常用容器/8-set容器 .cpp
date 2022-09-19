#include <iostream>
using namespace std;
#include <set>
#include <string>
//set/ multiset容器
//集合容器，关联式容器 
//set基本概念
//所有元素都会在插入时自动被排序
//本质:
//set/multiset属于关联式容器，底层结构是用二叉树实现
//set和multiset区别:
//set不允许容器中有重复的元素
//multiset允许容器中有重复的元素

//set构造和赋值
//功能描述:创建set容器以及赋值
//构造:
//set<T> st;//默认构造函数:
//set( const set &st);//拷贝构造函数
//赋值:
//set& operator=gconst set &st);//重载等号操作符

void printSet(set<int> &s){
	for(set<int>::iterator it = s.begin();it != s.end();it++)
		cout << *it << " ";
	cout << endl;
}
//set构造和赋值
void test01(){
	set<int> s1; 
	s1.insert(10);//插入数据只有insert方式
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);
	//遍历容器
	//set容器特点:所有元素插入时候自动被排序
	//set容器不允许插入重复值
	printSet(s1);
	
	set<int> s2(s1);
	printSet(s2);
	
	set<int> s3;
	s3 = s2;
	printSet(s2);
}

//set大小和交换
//功能描述:统计set容器大小以及交换set容器
//函数原型:
//size();//返回容器中元素的数目
//empty();//判断容器是否为空
//swap(st);//交换两个集合容器
//无法重新指定容器大小，不支持resize 
void test02(){
	set<int> s1; 
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	if(s1.empty())
		cout << "YES"  << endl;
	else{
		cout << "NO" << endl; 
		cout << s1.size() << endl;
	}
}

void test03(){
	set<int> s1; 
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int> s2; 
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);
	
	printSet(s1);
	printSet(s2);
	
	s1.swap(s2);
	printSet(s1);
	printSet(s2);	
}

//set插入和删除
//功能描述: set容器进行插入数据和删除数据
//函数原型:
//insert(elem) ;//在容器中插入元素。
//clear();//清除所有元素
//erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
//erase(beg, end) ;//册除区间[beg,end)的所有元素，返回下一个元素的迭代器。
//erase(elem);//删除容器中值为elem的元素。
void test04(){
	set<int> s1; 
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	s1.erase(s1.begin());//删除，和插入顺序无关 
	printSet(s1);
	
	s1.erase(30);//删除重载版本 
	printSet(s1);
	
	s1.erase(s1.begin(),s1.end()) ;
//	s1.clear();
	printSet(s1);
}

//set查找和统计
//功能描述:对set容器进行查找数据以及统计数据函数原型:
//find(key);//查找key是否存在,若存在，返回该键的元素的迭代器;若不存在，返回set.end();
//count(key);//统计key的元素个数
void test05(){
	set<int> s1; 
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	
	set<int>::iterator pos = s1.find(30);//查找 
	
	if(pos != s1.end())
		cout << "YES find:" << *pos << endl;
	else
		cout << "NO find" << endl;
		
	int num = s1.count(30);//统计个数 
	//对于set而言统计结果要么是0要么是1
	cout << num << endl;
}


//set和multiset区别
//区别:
//set不可以插入重复数据，而multiset可以
//set插入数据的同时会返回插入结果，表示插入是否成功
//multiset不会检测数据，因此可以插入重复数据
void test06(){
	set<int> s1; 
	pair<set<int>::iterator,bool> ret = s1.insert(10);//对组 
//	源代码中的using _Pairib =pair<iterator，bool>;

	if(ret.second)
		cout << "第一次插入成功" << endl;
	else
		cout << "第一次插入失败" << endl;

	ret = s1.insert(10);
	if(ret.second)
		cout << "第二次插入成功" << endl;
	else
		cout << "第二次插入失败" << endl;
		
	multiset<int> ms;//允许插入重复值		
//源码中的iterator insext(value_type&&_Val)
//返回了一个迭代器，只要插入正确的数据类型，就会返回迭代器 
	ms.insert(10);
	ms.insert(10);
	for(multiset<int>::iterator it = ms.begin();it != ms.end();it++)
		cout << *it << " ";
	cout << endl;
}

//pair对组创建
//功能描述:成对出现的数据，利用对组可以返回两个数据
//两种创建方式:
//pair<type, type> p ( value1, value2 );
//pair<type, type> p = make_pair( value1， value2 );
void test07(){
	//第一种方式
	pair<string,int> p("TOM",20); //不用包含头文件 
	cout << p.first << " " << p.second << endl; 
	
	//第二种方式
	pair<string,int> p2 = make_pair("Jerry",30); 
	cout << p2.first << " " << p2.second << endl; 
}

//set容器排序
//学习目标:set容器默认排序规则为从小到大，掌握如何改变排序规则
//主要技术点:
//利用仿函数，可以改变排序规则

//set存放内置数据类型
class MyCompare{
public:
	bool operator()(int v1,int v2){
		return v1 > v2;
	}
}; 
void test08(){
	set<int> s1; 
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	printSet(s1);
	
	//指定排序规则为从大到小
	set<int,MyCompare> s2;//放一个仿函数，因为这也是一个类型 
	s2.insert(30);
	s2.insert(10);
	s2.insert(20);
	s2.insert(40);
	s2.insert(30);
	for(set<int,MyCompare>::iterator it = s2.begin();it != s2.end();it++)
		cout << *it << " ";
	cout << endl;
}

//set存放自定义数据类型
class Person{
public:
	Person(string name,int age){
		this -> m_Name = name;
		this -> m_Age = age;
	}
	string m_Name;
	int m_Age;
}; 
class comparePerson{
public:
	bool operator()(const Person &p1,const Person &p2){
		return p1.m_Age > p2.m_Age;//按照年龄降序
	}
};  
void test09(){
	//自定义数据类型都会指定排序规则
	set<Person,comparePerson> s1; 	
	Person p1("刘备",24);
	Person p2("张飞",28);
	Person p3("赵云",25);
	Person p4("关羽",21);
	
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);	
	
	for(set<Person,comparePerson>::iterator it = s1.begin();it != s1.end();it++)
		cout << it -> m_Name << " " << it->m_Age << endl;
	cout << endl;
}


int main(){
    test01();
    cout << endl;
     
    test02();
    test03();
    cout << endl;
    
    test04();
    cout << endl;
    
    test05();
    cout << endl;

    test06();
    cout << endl;
    
    test07();
    cout << endl;
    
    test08();
    cout << endl;

    test09();
    cout << endl;
    return 0;
}



















