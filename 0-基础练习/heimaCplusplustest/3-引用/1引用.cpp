#include<iostream> 
using namespace std;
//���õı�����C++�ڲ�ʵ����һ��ָ�볣�� 

void mySwap01(int a,int b)//ֵ���� 
{
	int temp = a;
	a = b;
	b = temp;
}

void mySwap02(int* a,int* b)//��ַ���ݣ��βλ�����ʵ�� 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void mySwap03(int &a,int &b)//���ô��ݣ��βλ�����ʵ�� 
{
	int temp = a;
	a = b;
	b = temp;
}

/**********************************************************************************************************/

int& test01(void)//�ֲ�������Ҫ�������� 
{
	int a = 10;
	return a;
}

int& test02(void)//��������ķ���ֵ�����ã���������ĵ��ÿ�����Ϊ��ֵ 
{
	static int a = 10;//��̬�����������������ͷ� 
	return a;
}

void showValue(const int &val)//Ϊ�˷�ֹ������޸�ֵ������const,����޸ģ��ͻᱨ��
{
	//val = 1000;
	cout << val << endl;
}

int main(){
	 
	int a = 10;
	
	int  &b = a;
	//�Զ�ת��Ϊint* const b = &a; 
	
	cout << a << endl;
	cout << b << endl;
	b = 100;
	cout << a << endl;
	cout << b << '\n' << endl;
	
	 
	int c = 22;
	mySwap01(a,c);//ֵ���� 
	cout << a << endl;
	cout << c  << endl;
	mySwap02(&a,&c);//��ַ���� 
	cout << a << endl;
	cout << c << endl;
	mySwap03(a,c);//���ô��� 
	cout << a << endl;
	cout << c << '\n' << endl;	
	
	
	int &ref = test01();
	cout << ref << endl;//��һ����ȷ�Ǳ��������˱��� 
	cout << ref << endl;//�ڶ��δ���a���ڴ��Ѿ��ͷŵ���
	int &ref2 = test02(); 
	cout << ref2 << endl;
	cout << ref2 << endl;
	test02() = 10000;//��������ķ���ֵ�����ã���������ĵ��ÿ�����Ϊ��ֵ 
	cout << ref2 << endl;
	cout << ref2 << '\n' << endl;	
	

	//int &ref3 = 40;
	const int &ref4 = 40;//int temp = 10;const int &ref4 = temp;temp��ϵͳ���㴴����ԭ��������ֻ���ñ�����
	//ref4 = 50;
	
	int aaa = 30;
	showValue(aaa);
	cout << aaa << endl;
			
	//system("pause");
	return 0;
}
