#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string> 
//常用查找算法
//find//查找元素
//find_if//按条件查找元素
//adjacent_find//查找相邻重复元素binary_search1/二分查找法
//count//统计元素个数
//count_if//按条件统计元素个数

//常用查找算法find
//查找内置数据类型
void test01(){
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);	
	vector<int>::iterator it = find(v.begin(),v.end(),5);
	if(it == v.end())//不管找到与否，都会返回一个迭代器
	//找不到是v.end()，找到是数字 
		cout << "no find" << endl;
	else
		cout << "find:" << *it << endl;	
}
//查找自定义数据类型
class Person{
public:
	Person(string name,int age){
		this -> m_name = name;
		this -> m_age = age;
	}
	//重载==底层find知道如何对比person数据类型
	bool operator==(const Person &p){
		if(this -> m_name == p.m_name && this -> m_age == p.m_age)
			return true;
		else
			return false;
	}
	string m_name;
	int m_age;
};
void test02(){
	vector<Person>v;
	
	Person p1("aa",10);
	Person p2("bb",20);
	Person p3("cc",30);
	Person p4("dd",40);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person pp("dd",40);
	
	vector<Person>::iterator it = find(v.begin(),v.end(),pp);
	if(it == v.end())
		cout << "no find" << endl;
	else
		cout << "find:" << it->m_name<< " " << it->m_age << endl;	
}

//find_if
//功能描述:
//按条件查找元素
//函数原型:
//find_if(iterator beg, iterator end，_Pred) ;
////按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//// beg 开始迭代器
//// end结束迭代器
//// _Pred函数或者谓词(返回bool类型的仿函数)

//查找内置数据类型
class GreaterFive{//谓词 
public:
	bool operator() (int val){
		return val > 5;
	}
};
void test03(){
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);			
		
	vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());		
	if(it == v.end())
		cout << "no find" << endl;
	else
		cout << "find:" << *it << endl;	
}
//查找自定义数据类型
class Person2{//创建的自定义数据类型 
public:
	Person2(string name,int age){
		this -> m_name = name;
		this -> m_age = age;
	}
	string m_name;
	int m_age;
};
class Greater20{
public:
	bool operator() (Person2 &p){
		return p.m_age > 20;
	}
};
void test04(){
	vector<Person2>v;
	Person2 p1("aaa",10);
	Person2 p2("bbb",20);
	Person2 p3("ccc",30);
	Person2 p4("ddd",40);		
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person2>::iterator it = find_if(v.begin(),v.end(),Greater20());
	if(it == v.end())
		cout << "no find" << endl;
	else
		cout << "find:" << it->m_name << " " << it ->m_age << endl;	
}

//adjacent_find
//功能描述:查找相邻重复元素
//函数原型:
//adjacent_find(iterator beg, iterator end ) ;
////查找相邻重复元素,返回相邻元素的第一个位置的迭代器
//// beg开始迭代器
//// end结束迭代器
void test05(){//实际中用的比较少，一般面试中考 
	vector<int>v;
	v.push_back(0);	
	v.push_back(2);	
	v.push_back(0);	
	v.push_back(3);	
	v.push_back(1);	
	v.push_back(0);	
	v.push_back(4);	
	v.push_back(3);	
	v.push_back(3);	
	
	vector<int>::iterator pos = adjacent_find(v.begin(),v.end());
	if(pos == v.end())
		cout << "no find" << endl;
	else
		cout << "find:" << *pos << endl;	
}


//binary_search——二分查找 
//功能描述:查找指定元素是否存在
//函数原型:
//bool binary_search(iterator beg, iterator end，value);
////查找指定的元素，查到返回true否则false
////注意:在无序序列中不可用
//// beg开始迭代器
//// end结束迭代器
//// value查找的元素
void test06(){//实际中用的比较少，一般面试中考 
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);	
	//v.push_back(2);如果是无序序列，结果未知!	
	//查找容器中是否有9元素
	//注意:容器必须是有序的序列
	bool ret = binary_search(v.begin(),v.end(),9);
	
	if(ret)
		cout << "yes" << endl;
	else
		cout << "no" << endl;	
}


//count
//功能描述:统计元素个数
//函数原型:
//count(iterator beg, iterator end, value);
//// 统计元素出现次数
//// beg开始迭代器
//// end结束迭代器
//// value统计的元素

//1、统计内置数据类型
void test07(){
	vector<int>v;
	v.push_back(10);	
	v.push_back(40);	
	v.push_back(30);	
	v.push_back(40);	
	v.push_back(20);	
	v.push_back(40);	
	
	int num = count(v.begin(),v.end(),40) ;	
	cout << num << endl;
}
//2、统计自定义数据类型
class Person3{//创建的自定义数据类型 
public:
	Person3(string name,int age){
		this -> m_name = name;
		this -> m_age = age;
	}
	bool operator==(const Person3 &p){
		if(this -> m_age == p.m_age)
			return true;
		else
			return false;
	}
	string m_name;
	int m_age;
};
void test08(){
	vector<Person3>v;
	Person3 p1("刘备",35);
	Person3 p2("关羽",35);
	Person3 p3("张飞",30);
	Person3 p4("赵云",30);
	Person3 p5("曹操",40);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	Person3 p("诸葛亮",35);
	
	int num = count(v.begin(),v.end(),p) ;	
	cout << num << endl;
}

//count_if
//功能描述:按条件统计元素个数
//函数原型:
//count_if(iterator beg, iterator end，_pred ) ;
////按条件统计元素出现次数
//// beg 开始迭代器
//// end结束迭代器
//// _Pred谓词

//1、统计内置数据类型
class Greater20G{
public:
	bool operator() (int val){
		return val > 20;
	}
};
void test09(){
	vector<int>v;
	v.push_back(10);	
	v.push_back(40);	
	v.push_back(30);	
	v.push_back(20);	
	v.push_back(40);	
	v.push_back(20);	
	
	int num = count_if(v.begin(),v.end(),Greater20G()) ;	
	cout << num << endl;
}
//2、统计自定义数据类型
class Person4{//创建的自定义数据类型 
public:
	Person4(string name,int age){
		this -> m_name = name;
		this -> m_age = age;
	}
	string m_name;
	int m_age;
};
class AgeGreater20{
public:
	bool operator()(const Person4 &p){
		return p.m_age >  20;
	}
};
void test10(){
	vector<Person4>v;
	Person4 p1("刘备",35);
	Person4 p2("关羽",35);
	Person4 p3("张飞",35);
	Person4 p4("赵云",30);
	Person4 p5("曹操",20);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	int num = count_if(v.begin(),v.end(),AgeGreater20()) ;	
	cout << num << endl;
}


int main(){
    test01();
    test02();
    cout << endl;
 
    test03();
    test04();
    cout << endl;  
    
    test05();
    cout << endl;  

    test06();
    cout << endl; 
    
    test07();
    test08();
    cout << endl; 
    
    test09();
    test10();
    cout << endl; 
    return 0;
}



















