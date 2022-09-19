#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include <queue>
#define null 0xffff


void test01(){
    // 定义简单的lambda表达式
    auto basicLambda = [] { cout << "Hello, world!" << endl; };
    // 调用
    basicLambda();   // 输出：Hello, world! 
}

void test02(){
    // 指明返回类型
    auto add = [](int a, int b) -> int { return a + b; };
    // 自动推断返回类型
    auto multiply = [](int a, int b) { return a * b; };

    int sum = add(2, 5);   // 输出：7
    int product = multiply(2, 5);  // 输出：10
    cout << sum << " " << product << endl; 
}

void test03(){
    int x = 10;
    // 前面的方括号就是用来定义捕捉模式以及变量，我们又将其称为lambda捕捉块
    auto add_x = [x](int a) { return a + x; };  // 复制捕捉x
    auto multiply_x = [&x](int a) { return a * x; };  // 引用捕捉x
    
    cout << add_x(10) << " " << multiply_x(10) << endl;  
}

void test04(){
    int x = 10;
    auto add_x = [x](int a) mutable { x *= 2; return a + x; };  // 复制捕捉x
    // 有了mutable可以改动传入的值
    cout << add_x(10) << endl; // 输出 30
    cout << x << endl;    
}

void test05(){
    auto a = [] { cout << "A" << endl; };
    auto b = [] { cout << "B" << endl; };

    // a = b;   // 非法，lambda无法赋值
    auto c = a;   // 合法，生成一个副本

    cout << a << endl; 
    b;
    c;
}

// []：默认不捕获任何变量；
// [=]：默认以值捕获所有变量；
// [&]：默认以引用捕获所有变量；
// [x]：仅以值捕获x，其它变量不捕获；
// [&x]：仅以引用捕获x，其它变量不捕获；
// [=, &x]：默认以值捕获所有变量，但是x是例外，通过引用捕获；
// [&, x]：默认以引用捕获所有变量，但是x是例外，通过值捕获；
// [this]：通过引用捕获当前对象（其实是复制指针）；
// [*this]：通过传值方式捕获当前对象；

// 在上面的捕获方式中，注意最好不要使用[=]和[&]默认捕获所有变量

int main() {
    test01();
    test02();
    test03();
    test04();
    test05();

	return 0;
}



