#include <iostream> 
#include <string> 
using namespace std;


// 可变参数模板
// 语法：
// template<typename... Args>
// void show_list1(Args... args){
// ...
// }
// Args 模板参数包
// args 函数参数包



void show_list3() {}

template<typename T,typename... Args>
void show_list3(T value,Args... args){
	cout << value << ",";
	show_list3(args...);
}

int main(void){
	int n = 14;
	double x = 2.71828;
	string mr = "Mr. string";
	// 这四种调用方式都是匹配的
	show_list3();
	cout << endl;
	show_list3(n);
	cout << endl;
	show_list3(n,x);
	cout << endl;
	show_list3(x*x,'!',7,mr);	
	

 	return 0;
}

