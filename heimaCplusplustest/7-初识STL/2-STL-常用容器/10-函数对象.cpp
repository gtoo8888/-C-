#include <iostream>
using namespace std;
#include <string>
//�����������
//����:
//���غ������ò��������࣬����󳣳�Ϊ��������
//��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ�зº���
//����:
//��������(�º���)��һ���࣬����һ������

//���������ص�:
//1.����������ʹ��ʱ����������ͨ������������,�����в����������з���ֵ
class MyAdd{
public:
	int operator() (int v1,int v2){
	//����º����������в����������з���ֵ 
		return v1 + v2;
	}
};
//�������󲢲��Ǻ��������ഴ����һ������ 
void test01(){
	MyAdd myadd;
	cout << myadd(10,10) << endl;
}

//2.�������󳬳���ͨ�����ĸ����������������Լ���״̬
class MyPrint{
public:
	MyPrint(){
		this -> count = 0;
	} 
	int operator() (string test){
		cout << test << endl;
		count++;
	}
	
	int count;//�ڲ��Լ���״̬ 
	//��ͨ����û�������������Ҫ�����������ⲿ�ı������ܼ�¼�Լ��������˶��ٴ� 
	//��������ֻҪ���ڲ������ԾͿ��Լ�¼�� 
};
void test02(){
	MyPrint myprint;
	myprint("hello world!");
	myprint("hello world!");
	myprint("hello world!");
	
	cout << myprint.count << endl;
}
//3.�������������Ϊ��������
void doPrint(MyPrint &mp,string test) {
	mp(test);
}
void test03(){
	MyPrint myprint;
	doPrint(myprint,"Hello C++");	
}

int main(){
    test01();
    test02();
    test03();
    cout << endl;
   
    return 0;
}



















