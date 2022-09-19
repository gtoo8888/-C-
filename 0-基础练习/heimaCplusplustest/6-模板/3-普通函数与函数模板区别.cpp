#include <iostream> 
using namespace std;
#include <string> 
//��ͨ�����뺯��ģ������
//1����ͨ�������ÿ��Է�����ʽ����ת��
//2������ģ�����Զ������Ƶ��������Է�����ʽ����ת��
//3������ģ������ʾָ�����ͣ����Է�����ʽ����ת��
int myadd01(int a,int b){
	return a + b;	
}
template<class T>
T myadd02(T a,T b){
	return a + b;
}
//��ͨ�����뺯��ģ������
void test01(){
	int a = 10;
	int b = 20;
	char c = 'c';	
	cout << myadd01(a,c) << endl;
//	�Զ������Ƶ�
//	cout << myadd02(a,c) << endl;
	//��ʾָ������
	cout << myadd02<int>(a,c) << endl;
}

//��ͨ�����뺯��ģ��ĵ��ù���:
//1.�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
//2.����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
//3.����ģ��Ҳ���Է�������
//4.�������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ��
//�ܽ�:��Ȼ�ṩ�˺���ģ�壬��þͲ�Ҫ�ṩ��ͨ�������������׳��ֶ�����
void myprint(int a,int b){
	cout << "������ͨ����" << endl; 
}
template<class T>
void myprint(T a,T b){
	cout << "���õ�ģ��" << endl; 	
}
template<class T>
void myprint(T a,T b,T c){
	cout << "�������ص�ģ��" << endl; 	
}

void test02(){
	int a = 10;
	int b = 20;
	
	myprint(a,b);//1.�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
	myprint<>(a,b);//2.����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��	
	myprint(a,b,100);//3.����ģ��Ҳ���Է�������
	
	char c1 = 'a';
	char c2 = 'b';
	myprint(c1,c2);//4.�������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ��
} 

//ģ�������
//ģ�岢�������ܵģ���Щ�ض��������ͣ���Ҫ�þ��廯��ʽ������ʵ��

//�Ա����������Ƿ���Ⱥ���
class Person{
public:
	Person(string name,int age){
		this -> m_name = name;
		this -> m_age = age;
	}
	string m_name;
	int m_age;
};
template<class T>
bool mycompare(T &a,T &b){
	if(a == b)
		return true;
	else
		return false;
}

template<> bool mycompare(Person &p1,Person &p2){
	if(p1.m_age == p2.m_age && p1.m_name == p2.m_name)
		return true;
	else
		return false;
}

void test03(){
	int a = 10;
	int b = 20;
	
	bool ret = mycompare(a,b);
	
	if(ret)
		cout << "a==b" << endl;
	else
		cout << "a!=b" << endl; 
} 

void test04(){
	Person p1("TOM",10);
	Person p2("TOM",10);
	
	bool ret = mycompare(p1,p2);
	if(ret)
		cout << "a==b" << endl;
	else
		cout << "a!=b" << endl; 
}


int main(){
    test01();
	cout << endl;
	
	test02();
	cout << endl;
	
	test03();
	test04();
	cout << endl;
    return 0;
}
