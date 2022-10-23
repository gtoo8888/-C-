#include <iostream> 
#include <functional> 
using namespace std;
#include "18-5-somedefs.h"


double dub(double x) {return 2.0 * x;}
double square(double x) {return x*x;}

int main(void){
	// 调用特征标double(char,int)
	// 接受一个char和一个int参数，返回一个double
	// 返回一个double值的的任何(函数指针、函数对象、lambda表达式)
	function<double(char,int)> fdci;	// 从(调用特征标)的角度定义了一个对象

	double y = 1.21;
	function<double(double)> ef1 = dub;
	function<double(double)> ef2 = square;
	function<double(double)> ef3 = Fq(10.0);
	function<double(double)> ef4 = Fq(10.0);
	function<double(double)> ef5 = [](double u) {return u*u;};
	function<double(double)> ef6 = [](double u) {return u+u/2.0;};

	cout << use_f(y,ef1) << endl;
	cout << use_f(y,ef2) << endl;
	cout << use_f(y,ef3) << endl;
	cout << use_f(y,ef4) << endl;
	cout << use_f(y,ef5) << endl;
	cout << use_f(y,ef6) << endl;
 	return 0;
}

