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




int main(){
    test01();
    test02();
    cout << endl;
 
  
    return 0;
}



















