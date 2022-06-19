#include<iostream> 
using namespace std;

//函数默认参数 
//返回值类型 函数名 （参数= 默认值）{} 
int func(int a,int b = 20,int c = 30) 
{
	return a + b + c;
}

//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
//int func2(int a ,int b = 10,int c,int d) 
//{
//	return a + b + c;
//}

//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
//声明和实现只能有一个默认参数 
//int func3(int a = 10,int b = 20);
//
//int func3(int a = 10,int b = 20)
//{
//	return a + b;
//}

//占位参数 
//返回值类型 函数名 (数据类型){}
//目前阶段占位参数没有用，后面的课程会用到 
void func4(int a,int)
{
	cout << "!!!!!" << endl;
} 

//占位参数可以有默认参数 
void func5(int a,int = 10)
{
	cout << "@@@@@" << endl;
} 

int main(){
	
	cout << func(10) << endl;
	cout << func(10 , 30) << endl;//传了就用传的值，没传用缺省值 
	
//	cout << func3(40,50) << endl;

	func4(10,20);
	func5(10);
	
	return 0;
}
