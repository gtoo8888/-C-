#include <iostream> 
using namespace std;

// C++思想：面向对象，泛型编程
// C++提高编程，C++泛型编程和STL技术做详细讲解，探讨C++更深层的使用
// 泛型编程就是用模板技术
// 模板就是建立通用的模具，大大提高复用性
// 注意：
// 模板不能直接使用，他只是一个框架
// 模板很通用但不是万能的

// C++提供两种模板机制:函数模板和类模板
// 函数模板作用:类型参数化
// 建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表。
template<typename T>//声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}
void test01(){
    int a = 10;
    int b = 20;
    //利用函数模板交换
    //两种方式使用函数模板
    //1、自动类型推导
    mySwap(a,b);
    //2、显示指定类型
    mySwap<int>(a,b);
    cout << a << endl;
    cout << b << endl;
}


//函数模板注意事项
//1、自动类型推导，必须推导出一致的数据类型T才可以使用
template<class T>//typename可以替换成class,函数模板，类模板
void mySwap2(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}
void test02(){
    int a = 10;
    int b = 20;
    char c = 'c';

    mySwap(a,b);
    // mySwap(a,c);//推导不出一致的T类型

    cout << a << endl;
    cout << b << endl;
}
//2、模板必须要确定出T的数据类型，才可以使用
template<class T>
void func(){
    cout << "func的调用" << endl;
}
void test03(){
    func<int>(); 
}

int main(){

    test01();

    test02();
    test03();
    return 0;
}
