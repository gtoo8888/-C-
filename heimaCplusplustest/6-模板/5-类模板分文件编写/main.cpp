#include <iostream> 
using namespace std;
#include <string>

//第一种解决方式，直接包含源文件——但是很少这么做，一般都是包含.h
//#include "person.cpp"
//类模板中的成员函数最开始是不会创建的 
//仅仅包含.h的时候，仅仅看到了定义，那两个类里面的函数是没有生成的 
//并且编译器从来没有见到过cpp中的那些文件 
//所以最后这两个，构造函数和成员函数，编译器都不认识 
//但是如果包含了.cpp那就是直接看函数的定义了
//同时.cpp包含了.h同时可以得到定义类模板的代码，所以此时可以正常调用了 



//第二种解决方式，将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件Ⅰ
#include "person.hpp"
//一看到hpp就知道是类模板了，声明和是实现都写到一起了 


void test01(){
	Person<string,int> p("TOM",20); 
	p.show();
}


int main(){
    test01();
	cout << endl;	
    return 0;
}
