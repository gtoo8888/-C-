#include <iostream> 
#include <cmath> 
#include <vector> 
#include <ctime> 
#include <algorithm> 
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"
using namespace std;


// lambda基本语法
// [ capture ] ( params ) opt -> ret { body; };
// capture 是捕获列表
// params 是参数表
// opt 是函数选项
// ret 是返回值类型
// body是函数体

// 示例写法：
// [&](int x) {count += x%3 == 0;};	// count是一个外部变量
// 带有返回值的写法：
// [](double x)->double{int y = x;return x - y;};

// [] 不捕获任何变量。
// [&] 捕获外部作用域中所有变量，并作为引用在函数体中使用（按引用捕获）。
// [=] 捕获外部作用域中所有变量，并作为副本在函数体中使用（按值捕获）。
// [=，&foo] 按值捕获外部作用域中所有变量，并按引用捕获 foo 变量。
// [bar] 按值捕获 bar 变量，同时不捕获其他变量。
// [this] 捕获当前类中的 this 指针，让 lambda 表达式拥有和当前类成员函数同样的访问权限。如果已经使用了 & 或者 =，就默认添加此选项。捕获 this 的目的是可以在 lamda 中使用当前类的成员函数和成员变量。

// 混合使用
// [ted] 按值访问ted
// [&ted]	按引用访问ted
// [ted,&ted2] 按值访问ted，按引用访问ted2
// [&,ted] 按引用访问所有变量，按值访问ted
// [=,&ted] 按值访问所有变量，按引用访问ted



const long size1 = 39L;
const long size2 = 100*size1;
const long size3 = 100*size2;
bool f3(int x) {return x % 3 == 0;}
bool f13(int x) {return x % 13 == 0;}

int main(void){
	vector<int> numbers(size1);

	srand(time(0));
	generate(numbers.begin(),numbers.end(),rand);
	cout << size1 << endl;
	// PrintVector(numbers);
	int count3 = count_if(numbers.begin(),numbers.end(),f3);	// 得到容器中满足条件的元素数量
	cout << count3 << endl;
	int count13 = count_if(numbers.begin(),numbers.end(),f13);
	cout << count13 << endl;


	numbers.resize(size2);
	generate(numbers.begin(),numbers.end(),rand);
	cout << size2 << endl;
	class f_mod{
	private:
		int dv;
	public:
		f_mod(int d = 1) : dv(d) {}
		bool operator()(int x) {return x%dv == 0;}
	};
	count3 = count_if(numbers.begin(),numbers.end(),f_mod(3));	
	cout << count3 << endl;
	count13 = count_if(numbers.begin(),numbers.end(),f_mod(13));
	cout << count13 << endl;


	numbers.resize(size3);
	generate(numbers.begin(),numbers.end(),rand);
	cout << size3 << endl;

	count3 = count_if(numbers.begin(),numbers.end(),
			 [](int x){return x%3 == 0;});	
	cout << count3 << endl;
	count13 = count_if(numbers.begin(),numbers.end(),
			 [](int x){return x%31 == 0;});	
	cout << count13 << endl;
	auto mod3 = [](int x){return x%3 == 0;};	// 给lambda指定一个名称
	count3 = count_if(numbers.begin(),numbers.end(),mod3);	
	cout << count3 << endl;
	int z = 15;
	bool result = mod3(z);
	return 0;
}

