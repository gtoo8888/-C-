#include <iostream> 
using namespace std;
#include <string> 
//普通函数与函数模板区别
//1、普通函数调用可以发生隐式类型转换
//2、函数模板用自动类型推导，不可以发生隐式类型转换
//3、函数模板用显示指定类型，可以发生隐式类型转换
int myadd01(int a,int b){
	return a + b;	
}
template<class T>
T myadd02(T a,T b){
	return a + b;
}
//普通函数与函数模板区别
void test01(){
	int a = 10;
	int b = 20;
	char c = 'c';	
	cout << myadd01(a,c) << endl;
//	自动类型推导
//	cout << myadd02(a,c) << endl;
	//显示指定类型
	cout << myadd02<int>(a,c) << endl;
}

//普通函数与函数模板的调用规则:
//1.如果函数模板和普通函数都可以实现，优先调用普通函数
//2.可以通过空模板参数列表来强制调用函数模板
//3.函数模板也可以发生重载
//4.如果函数模板可以产生更好的匹配,优先调用函数模板
//总结:既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性
void myprint(int a,int b){
	cout << "调用普通函数" << endl; 
}
template<class T>
void myprint(T a,T b){
	cout << "调用的模板" << endl; 	
}
template<class T>
void myprint(T a,T b,T c){
	cout << "调用重载的模板" << endl; 	
}

void test02(){
	int a = 10;
	int b = 20;
	
	myprint(a,b);//1.如果函数模板和普通函数都可以实现，优先调用普通函数
	myprint<>(a,b);//2.可以通过空模板参数列表来强制调用函数模板	
	myprint(a,b,100);//3.函数模板也可以发生重载
	
	char c1 = 'a';
	char c2 = 'b';
	myprint(c1,c2);//4.如果函数模板可以产生更好的匹配,优先调用函数模板
} 

//模板局限性
//模板并不是万能的，有些特定数据类型，需要用具体化方式做特殊实现

//对比两个数据是否相等函数
class Person{
public:
	Person(string name,int age){
		this -> m_name = name;
		this -> m_age = age;
	}
	string m_name;
	int m_age;
};
template<class T>
bool mycompare(T &a,T &b){
	if(a == b)
		return true;
	else
		return false;
}

template<> bool mycompare(Person &p1,Person &p2){
	if(p1.m_age == p2.m_age && p1.m_name == p2.m_name)
		return true;
	else
		return false;
}

void test03(){
	int a = 10;
	int b = 20;
	
	bool ret = mycompare(a,b);
	
	if(ret)
		cout << "a==b" << endl;
	else
		cout << "a!=b" << endl; 
} 

void test04(){
	Person p1("TOM",10);
	Person p2("TOM",10);
	
	bool ret = mycompare(p1,p2);
	if(ret)
		cout << "a==b" << endl;
	else
		cout << "a!=b" << endl; 
}


int main(){
    test01();
	cout << endl;
	
	test02();
	cout << endl;
	
	test03();
	test04();
	cout << endl;
    return 0;
}
