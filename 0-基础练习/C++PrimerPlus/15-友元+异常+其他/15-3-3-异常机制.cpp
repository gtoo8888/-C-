#include <iostream> 
using namespace std;

double hmean(double a,double b){
	if(a == -b) 
		throw "bad hname() arguments";		// throw语句实际上是转跳
		// throw表示引发异常，后面的值指出了异常的特征
		// 发生异常以后，沿着函数调用序列往后寻找，寻找到catch块处理异常
		// throw类似于执行程序的返回语句，终止函数的执行，着函数调用序列往后寻找，寻找到catch块处理异常
	return 2.0*1*b/(a+b);
}

int main()
{
	double x,y,z;
	while(cin >> x >> y){
		try{	// try用来表示特定的异常可能被激活的代码块
		// 花括号中的代码，需要注意这些代码引发的异常
			z = hmean(x,y);
		}catch(const char *s){	// 异常处理程序，用来捕获异常
			// 花括号的代码段，表述要采取的措施
			// 指出当异常发生的时候，程序要跳到这个位置进行执行
			cout << s << endl;
			continue;
		}
		cout << x << " " << y << " " << z << endl;
	}
	return 0;
}

