#include <iostream> 
#include <string> 
using namespace std;

// 0个参数的情况
void show_list3() {}

// 1个参数的情况,特殊处理，不打印最后的逗号
template<typename T>
void show_list3(const T& value) {
	cout << value << endl;
}

// 2个以上参数的情况
template<typename T,typename... Args>
void show_list3(const T& value,const Args&... args){
	cout << value << ",";
	show_list3(args...);
}

int main(void){
	int n = 14;
	double x = 2.71828;
	string mr = "Mr. string";
	// 这四种调用方式都是匹配的
	show_list3();
	show_list3(n);
	show_list3(n,x);
	show_list3(x*x,'!',7,mr);	
	

 	return 0;
}

