#include<iostream> 
using namespace std;

//����Ĭ�ϲ��� 
//����ֵ���� ������ ������= Ĭ��ֵ��{} 
int func(int a,int b = 20,int c = 30) 
{
	return a + b + c;
}

//1. ���ĳ��λ�ò�����Ĭ��ֵ����ô�����λ�����󣬴������ң����붼Ҫ��Ĭ��ֵ
//int func2(int a ,int b = 10,int c,int d) 
//{
//	return a + b + c;
//}

//2. �������������Ĭ��ֵ������ʵ�ֵ�ʱ��Ͳ�����Ĭ�ϲ���
//������ʵ��ֻ����һ��Ĭ�ϲ��� 
//int func3(int a = 10,int b = 20);
//
//int func3(int a = 10,int b = 20)
//{
//	return a + b;
//}

//ռλ���� 
//����ֵ���� ������ (��������){}
//Ŀǰ�׶�ռλ����û���ã�����Ŀγ̻��õ� 
void func4(int a,int)
{
	cout << "!!!!!" << endl;
} 

//ռλ����������Ĭ�ϲ��� 
void func5(int a,int = 10)
{
	cout << "@@@@@" << endl;
} 

int main(){
	
	cout << func(10) << endl;
	cout << func(10 , 30) << endl;//���˾��ô���ֵ��û����ȱʡֵ 
	
//	cout << func3(40,50) << endl;

	func4(10,20);
	func5(10);
	
	return 0;
}
