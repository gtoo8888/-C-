#include<iostream> 
using namespace std;

//函数重载，函数名可以一样 
//函数重载的满足条件
//1、同一个作用域下
//2、函数名称相同
//3、函数参数类型不同，或者个数不同，或者顺序不同
void func()
{
	cout << "func() 的调用" << endl; 
} 

void func(int a)//函数参数类型不同 
{
	cout << "void func(int a) 的调用" << endl; 
} 

void func(double a)//函数参数类型不同
{
	cout << "void func(double a) 的调用" << endl; 
} 

void func(double a,int b)//函数参数个数不同
{
	cout << "void func(double a,int b) 的调用" << endl; 
} 

void func(int a,double b)//函数参数顺序不同
{
	cout << "void func(int a,double b) 的调用" << endl; 
} 

////函数的返回值不可以作为函数重载的条件 
//int func(int a,double b)
//{
//	cout << "void func(int a,double b) 的调用" << endl; 
//} 


void func1(int &a)//引用作为函数重载的条件 
{
	cout << "void func1(int a)" << endl;
}

void func1(const int &a)
{
	cout << "void func1(const int a)" << endl;
}

void func2(int a,int b = 20) 
{
	cout << "void func2(int a,int b = 20)" << endl;	
}

void func2(int a)
{
	cout << "void func2(int a)" << endl;	
}

int main(){
	 
	func();
	func(10);
	func(3.14);
	func(3.14,5);
	func(5,3.14);
	cout << '\n' << endl;
	
	int a = 10;
	func1(a);
	func1(10);
	
	//func2(10);//函数重载和默认参数混合，报错了 
	
	return 0;
}

