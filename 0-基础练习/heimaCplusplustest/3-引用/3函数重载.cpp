#include<iostream> 
using namespace std;

//�������أ�����������һ�� 
//�������ص���������
//1��ͬһ����������
//2������������ͬ
//3�������������Ͳ�ͬ�����߸�����ͬ������˳��ͬ
void func()
{
	cout << "func() �ĵ���" << endl; 
} 

void func(int a)//�����������Ͳ�ͬ 
{
	cout << "void func(int a) �ĵ���" << endl; 
} 

void func(double a)//�����������Ͳ�ͬ
{
	cout << "void func(double a) �ĵ���" << endl; 
} 

void func(double a,int b)//��������������ͬ
{
	cout << "void func(double a,int b) �ĵ���" << endl; 
} 

void func(int a,double b)//��������˳��ͬ
{
	cout << "void func(int a,double b) �ĵ���" << endl; 
} 

////�����ķ���ֵ��������Ϊ�������ص����� 
//int func(int a,double b)
//{
//	cout << "void func(int a,double b) �ĵ���" << endl; 
//} 


void func1(int &a)//������Ϊ�������ص����� 
{
	cout << "void func1(int a)" << endl;
}

void func1(const int &a)
{
	cout << "void func1(const int a)" << endl;
}

void func2(int a,int b = 20) 
{
	cout << "void func2(int a,int b = 20)" << endl;	
}

void func2(int a)
{
	cout << "void func2(int a)" << endl;	
}

int main(){
	 
	func();
	func(10);
	func(3.14);
	func(3.14,5);
	func(5,3.14);
	cout << '\n' << endl;
	
	int a = 10;
	func1(a);
	func1(10);
	
	//func2(10);//�������غ�Ĭ�ϲ�����ϣ������� 
	
	return 0;
}

