#include <iostream> 
#include <cstdlib> 	// abort()
using namespace std;

double hmean(double a,double b){
	if(a == -b) {
		cout << "error" << endl;
		abort();	// 向标准错误流，发送消息
		// 错误发生后会直接退出程序
		// 需要头文件cstdlib支持
	}
	return 2.0*1*b/(a+b);
}

int main()
{
	double x,y,z;
	while(cin >> x >> y){
		z = hmean(x,y);
		cout << x << " " << y << " " << z << endl;
	}
	return 0;
}

