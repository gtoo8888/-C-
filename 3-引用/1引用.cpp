#include<iostream> 
using namespace std;
//引用的本质在C++内部实现是一个指针常量 

void mySwap01(int a,int b)//值传递 
{
	int temp = a;
	a = b;
	b = temp;
}

void mySwap02(int* a,int* b)//地址传递，形参会修饰实参 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void mySwap03(int &a,int &b)//引用传递，形参会修饰实参 
{
	int temp = a;
	a = b;
	b = temp;
}

/**********************************************************************************************************/

int& test01(void)//局部变量不要返回引用 
{
	int a = 10;
	return a;
}

int& test02(void)//如果函数的返回值是引用，这个函数的调用可以作为左值 
{
	static int a = 10;//静态变量，程序结束后才释放 
	return a;
}

void showValue(const int &val)//为了防止误操作修改值，加了const,如果修改，就会报错
{
	//val = 1000;
	cout << val << endl;
}

int main(){
	 
	int a = 10;
	
	int  &b = a;
	//自动转化为int* const b = &a; 
	
	cout << a << endl;
	cout << b << endl;
	b = 100;
	cout << a << endl;
	cout << b << '\n' << endl;
	
	 
	int c = 22;
	mySwap01(a,c);//值传递 
	cout << a << endl;
	cout << c  << endl;
	mySwap02(&a,&c);//地址传递 
	cout << a << endl;
	cout << c << endl;
	mySwap03(a,c);//引用传递 
	cout << a << endl;
	cout << c << '\n' << endl;	
	
	
	int &ref = test01();
	cout << ref << endl;//第一次正确是编译器做了保留 
	cout << ref << endl;//第二次错误，a的内存已经释放掉了
	int &ref2 = test02(); 
	cout << ref2 << endl;
	cout << ref2 << endl;
	test02() = 10000;//如果函数的返回值是引用，这个函数的调用可以作为左值 
	cout << ref2 << endl;
	cout << ref2 << '\n' << endl;	
	

	//int &ref3 = 40;
	const int &ref4 = 40;//int temp = 10;const int &ref4 = temp;temp是系统给你创建的原名，现在只能用别名了
	//ref4 = 50;
	
	int aaa = 30;
	showValue(aaa);
	cout << aaa << endl;
			
	//system("pause");
	return 0;
}
