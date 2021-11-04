#include <iostream> 
using namespace std;

//多态是C++面向对象三大特性之一多态分为两类
//静态多态:函数重载和运算符重载属于静态多态，复用函数名
//动态多态:派生类和虚函数实现运行时多态
//静态多态和动态多态区别:
//静态多态的函数地址早绑定–编译阶段确定函数地址
//动态多态的函数地址晚绑定–运行阶段确定函数地址

class Animal{
public:
	//重写 函数返回值类型 函数名 参数列表 完全相同
    virtual void speak(){//虚函数 
    	cout << "动物在说话" << endl; 
	}
};

class Cat :public Animal{
public:
	void speak(){
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal{
public:
	void speak(){
		cout << "小狗在说话" << endl;
	}
};
//执行说话的函数
//地址早绑定在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定
//需要在运行阶段进行绑定，地址晚绑定

//动态多态满足条件
//1、有继承关系
//2、子类重写父类的虚函数

//动态多态使用
//父类的指针或者引用执行子类对象
void dospeak(Animal & animal) {// Animal & animal = cat; 
	animal.speak();
}

void test01(){
    Cat cat;
    dospeak(cat);
    
    Dog dog;
    dospeak(dog);
}

//多态的原理剖析 
//vfptr-虚函数（表）指针
//v - virtual
//f - function
//ptr - pointer
//
//vftable-虚函数表
//v - virtual
//f - function
//table - table
//当父类的指针或者引用指向子类对象时候,发生多态
void test02(){
    cout << sizeof(Animal) <<endl; 
}

int main(){
	test01();
    cout << endl;

	test02();
    cout << endl;
    return 0;
}

