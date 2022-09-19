#include <iostream>
using namespace std;
#include <string>
//函数对象概念
//概念:
//重载函数调用操作符的类，其对象常称为函数对象
//函数对象使用重载的()时，行为类似函数调用，也叫仿函数
//本质:
//函数对象(仿函数)是一个类，不是一个函数

//函数对象特点:
//1.函数对象在使用时，可以像普通函数那样调用,可以有参数，可以有返回值
class MyAdd{
public:
	int operator() (int v1,int v2){
	//这个仿函数，可以有参数，可以有返回值 
		return v1 + v2;
	}
};
//函数对象并不是函数，是类创建的一个对象 
void test01(){
	MyAdd myadd;
	cout << myadd(10,10) << endl;
}

//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint{
public:
	MyPrint(){
		this -> count = 0;
	} 
	int operator() (string test){
		cout << test << endl;
		count++;
	}
	
	int count;//内部自己的状态 
	//普通函数没有这个能力，需要借助外力，外部的变量才能记录自己被调用了多少次 
	//函数对象只要用内部的属性就可以记录了 
};
void test02(){
	MyPrint myprint;
	myprint("hello world!");
	myprint("hello world!");
	myprint("hello world!");
	
	cout << myprint.count << endl;
}
//3.函数对象可以作为参数传递
void doPrint(MyPrint &mp,string test) {
	mp(test);
}
void test03(){
	MyPrint myprint;
	doPrint(myprint,"Hello C++");	
}

int main(){
    test01();
    test02();
    test03();
    cout << endl;
   
    return 0;
}



















