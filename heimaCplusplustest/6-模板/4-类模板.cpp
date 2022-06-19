#include <iostream> 
using namespace std;
#include <string>
#include <typeinfo> 
//类模板
//类模板语法
//类模板作用:
//建立一个通用类，类中的成员数据类型可以不具体制定，用一个虚拟的类型来代表。
//语法:
//template<typename T>
//类
//template ---声明创建模板
//typename ---表面其后面的符号是—种数据类型，可以用class代替
//T ---通用的数据类型，名称可以替换，通常为大写字母

template<class NameType,class AgeType> 
class Person{
public:
	Person(NameType name,AgeType age){
		this -> m_Name = name;
		this -> m_Age = age;
	}
	void show(){
		cout << this ->m_Name << " " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
}; 

void test01(){
	Person<string,int> p1("孙悟空",999);
	p1.show();
}

//类模板与函数模板区别
//类模板与函数模板区别主要有两点:
//1.类模板没有自动类型推导的使用方式
//2.类模板在模板参数列表中可以有默认参数
template<class NameType,class AgeType> 
class Person02{
public:
	Person02(NameType name,AgeType age){
		this -> m_Name = name;
		this -> m_Age = age;
	}
	void show(){
		cout << this ->m_Name << " " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
}; 
//1.类模板没有自动类型推导的使用方式
void test02(){
//	Person02 p1("孙悟空",100);//错误，无法用自动类型推导
	Person02<string,int>p1("孙悟空",100);//正确，只能用显示指定类型

	p1.show();
}
//2.类模板在模板参数列表中可以有默认参数
void test03(){
//	Person<string> p1("猪八戒",999);//后面的int没有指定，因为上面有默认参数了
	//好像C++11才有 
	//在函数模板中不能这么用 
//	p1.show();
}


//类模板中成员函数和普通类中成员函数创建时机是有区别的:
//普通类中的成员函数一开始就可以创建
//类模板中的成员函数在调用时才创建

//类模板中成员函数创建时机
//类模板中成员函数在调用时才去创建
class Person03{
public:
	void showPerson03(){
		cout << "showPerson03" << endl;
	}
}; 
class Person04{
public:
	void showPerson04(){
		cout << "showPerson04" << endl;
	}
}; 

template<class T>
class MyClass{
public:
	T obj;
	void func3(){//类模板中的成员函数
		obj.showPerson03();
		//当整个类模板的成员没有被实例化的时候，这里面的这个函数是不会被创建的 
	}
	void func4(){
		obj.showPerson04();
	}
};

void test04(){
	MyClass<Person03> m;
	//只有当确定T以后，确定是替换成Person03，所以没有showPerson04()这个函数 
	m.func3();
//	m.func4();//调用的时候才会报错 
}


//类模板对象做函数参数 
//学习目标:
//类模板实例化出的对象，向函数传参的方式
//共有三种传入方式:
//1.指定传入的类型---直接显示对象的数据类型
//2.参数模板化---将对象中的参数变为模板进行传递
//3.整个类模板化---将这个对象类型模板化进行传递
template<class NameType,class AgeType> 
class Person05{
public:
	Person05(NameType name,AgeType age){
		this -> m_Name = name;
		this -> m_Age = age;
	}
	void show(){
		cout << this ->m_Name << " " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
}; 
//1.指定传入的类型——最常用 
void print1Person5(Person05<string,int> &p){
	p.show();
}
void test05(){
	Person05<string,int> p("孙悟空",100); 
	print1Person5(p);
}
//2.参数模板化
template <class T1,class T2>
void print2Person5(Person05<T1,T2> &p){
	p.show();
	cout << typeid(T1).name() << endl;//看模板中推出来的是什么类型 
	cout << typeid(T2).name() << endl;
}
void test06(){
	Person05<string,int> p("猪八戒",90); 
	print2Person5(p);
}
//3.整个类模板化
template <class T>
void print3Person5(T &p){
	p.show();
	cout << typeid(T).name() << endl;
}
void test07(){
	Person05<string,int> p("唐僧",30); 
	print3Person5(p);
}

//当类模板碰到继承时，需要注意一下几点:
//当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
//如果不指定，编译器无法给子类分配内存
//如果想灵活指定出父类中T的类型，子类也需变为类模板
//类模板与继承
//总结:如果父类是类模板，子类需要指定出父类中T的数据类型
template<class T> 
class Base{
	T m;
};
//class Son :public Base //错误，必须要知道父类中的T类型，才能继承给子类
class Son:public Base<int> {
};
void test08(){
	Son s1;
}
//如果想灵活指定父类中T类型，子类也需要变类模板
template<class T1,class T2>
class Son2:public Base<T2>{
public:
	Son2(){
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	T1 obj;
};
void test09(){
	Son2<int,char> s1;
}


//类模板成员函数类外实现
template<class NameType,class AgeType> 
class Person06{
public:
	Person06(NameType name,AgeType age);//进行类外实现  
//	{
//		this -> m_Name = name;
//		this -> m_Age = age;
//	}
	void show();
//	{
//		cout << this ->m_Name << " " << this->m_Age << endl;
//	}
	NameType m_Name;
	AgeType m_Age;
}; 
//构造函数类外实现
template<class T1,class T2> 
Person06<T1,T2>::Person06(T1 name,T2 age){
	this -> m_Name = name;
	this -> m_Age = age;
}
//成员函数类外实现
template<class T1,class T2> 
void Person06<T1,T2>::show(){
	cout << this ->m_Name << " " << this->m_Age << endl;
}
void test10(){
	Person05<string,int> p("TOM",20); 
	p.show();
}

//类模板与友元
//全局函数类内实现–直接在类内声明友元即可
//全局函数类外实现–需要提前让编译器知道全局函数的存在
//总结:建议全局函数做类内实现，用法简单，而且编译器可以直接识别
//提前让编译器知道Person类存在
template<class T1,class T2> 
class Person07;
//全局函数类外实现
template<class T1,class T2> 
void show2(Person07<T1,T2> p){
	cout << p.m_Name << " " << p.m_Age << endl;
}
template<class T1,class T2> 
class Person07{
	//全局函数类内实现 
	friend void show(Person07<T1,T2> p){
		cout << p.m_Name << " " << p.m_Age << endl;
	}
	//全局函数类外实现
	//加空模板参数列表<>
	//如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
	friend void show2<>(Person07<T1,T2> p);
//这是一个普通的函数，不是类模板的函数，但是下面写的是函数模板的函数实现
public:
	Person07(T1 name,T2 age){
		this -> m_Name = name;
		this -> m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
}; 
//1.全局函数类内实现 
void test11(){
	Person07<string,int> p("TOM",20); 
	show(p);
}
//2.全局函数类外实现
void test12(){
	Person07<string,int> p("Jerry",20); 
	show2(p);
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
	test06();
	test07();
	cout << endl;	
	
	test08();
	test09();
	cout << endl;
	
	test10();
	cout << endl;		
	
	test11();
	test12();
	cout << endl;	
    return 0;
}
