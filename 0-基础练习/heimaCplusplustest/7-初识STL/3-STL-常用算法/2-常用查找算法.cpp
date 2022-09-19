#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string> 
//���ò����㷨
//find//����Ԫ��
//find_if//����������Ԫ��
//adjacent_find//���������ظ�Ԫ��binary_search1/���ֲ��ҷ�
//count//ͳ��Ԫ�ظ���
//count_if//������ͳ��Ԫ�ظ���

//���ò����㷨find
//����������������
void test01(){
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);	
	vector<int>::iterator it = find(v.begin(),v.end(),5);
	if(it == v.end())//�����ҵ���񣬶��᷵��һ��������
	//�Ҳ�����v.end()���ҵ������� 
		cout << "no find" << endl;
	else
		cout << "find:" << *it << endl;	
}
//�����Զ�����������
class Person{
public:
	Person(string name,int age){
		this -> m_name = name;
		this -> m_age = age;
	}
	//����==�ײ�find֪����ζԱ�person��������
	bool operator==(const Person &p){
		if(this -> m_name == p.m_name && this -> m_age == p.m_age)
			return true;
		else
			return false;
	}
	string m_name;
	int m_age;
};
void test02(){
	vector<Person>v;
	
	Person p1("aa",10);
	Person p2("bb",20);
	Person p3("cc",30);
	Person p4("dd",40);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person pp("dd",40);
	
	vector<Person>::iterator it = find(v.begin(),v.end(),pp);
	if(it == v.end())
		cout << "no find" << endl;
	else
		cout << "find:" << it->m_name<< " " << it->m_age << endl;	
}

//find_if
//��������:
//����������Ԫ��
//����ԭ��:
//find_if(iterator beg, iterator end��_Pred) ;
////��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//// beg ��ʼ������
//// end����������
//// _Pred��������ν��(����bool���͵ķº���)

//����������������
class GreaterFive{//ν�� 
public:
	bool operator() (int val){
		return val > 5;
	}
};
void test03(){
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);			
		
	vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());		
	if(it == v.end())
		cout << "no find" << endl;
	else
		cout << "find:" << *it << endl;	
}
//�����Զ�����������
class Person2{//�������Զ����������� 
public:
	Person2(string name,int age){
		this -> m_name = name;
		this -> m_age = age;
	}
	string m_name;
	int m_age;
};
class Greater20{
public:
	bool operator() (Person2 &p){
		return p.m_age > 20;
	}
};
void test04(){
	vector<Person2>v;
	Person2 p1("aaa",10);
	Person2 p2("bbb",20);
	Person2 p3("ccc",30);
	Person2 p4("ddd",40);		
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person2>::iterator it = find_if(v.begin(),v.end(),Greater20());
	if(it == v.end())
		cout << "no find" << endl;
	else
		cout << "find:" << it->m_name << " " << it ->m_age << endl;	
}

//adjacent_find
//��������:���������ظ�Ԫ��
//����ԭ��:
//adjacent_find(iterator beg, iterator end ) ;
////���������ظ�Ԫ��,��������Ԫ�صĵ�һ��λ�õĵ�����
//// beg��ʼ������
//// end����������
void test05(){//ʵ�����õıȽ��٣�һ�������п� 
	vector<int>v;
	v.push_back(0);	
	v.push_back(2);	
	v.push_back(0);	
	v.push_back(3);	
	v.push_back(1);	
	v.push_back(0);	
	v.push_back(4);	
	v.push_back(3);	
	v.push_back(3);	
	
	vector<int>::iterator pos = adjacent_find(v.begin(),v.end());
	if(pos == v.end())
		cout << "no find" << endl;
	else
		cout << "find:" << *pos << endl;	
}


//binary_search�������ֲ��� 
//��������:����ָ��Ԫ���Ƿ����
//����ԭ��:
//bool binary_search(iterator beg, iterator end��value);
////����ָ����Ԫ�أ��鵽����true����false
////ע��:�����������в�����
//// beg��ʼ������
//// end����������
//// value���ҵ�Ԫ��
void test06(){//ʵ�����õıȽ��٣�һ�������п� 
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);	
	//v.push_back(2);������������У����δ֪!	
	//�����������Ƿ���9Ԫ��
	//ע��:�������������������
	bool ret = binary_search(v.begin(),v.end(),9);
	
	if(ret)
		cout << "yes" << endl;
	else
		cout << "no" << endl;	
}


//count
//��������:ͳ��Ԫ�ظ���
//����ԭ��:
//count(iterator beg, iterator end, value);
//// ͳ��Ԫ�س��ִ���
//// beg��ʼ������
//// end����������
//// valueͳ�Ƶ�Ԫ��

//1��ͳ��������������
void test07(){
	vector<int>v;
	v.push_back(10);	
	v.push_back(40);	
	v.push_back(30);	
	v.push_back(40);	
	v.push_back(20);	
	v.push_back(40);	
	
	int num = count(v.begin(),v.end(),40) ;	
	cout << num << endl;
}
//2��ͳ���Զ�����������
class Person3{//�������Զ����������� 
public:
	Person3(string name,int age){
		this -> m_name = name;
		this -> m_age = age;
	}
	bool operator==(const Person3 &p){
		if(this -> m_age == p.m_age)
			return true;
		else
			return false;
	}
	string m_name;
	int m_age;
};
void test08(){
	vector<Person3>v;
	Person3 p1("����",35);
	Person3 p2("����",35);
	Person3 p3("�ŷ�",30);
	Person3 p4("����",30);
	Person3 p5("�ܲ�",40);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	Person3 p("�����",35);
	
	int num = count(v.begin(),v.end(),p) ;	
	cout << num << endl;
}

//count_if
//��������:������ͳ��Ԫ�ظ���
//����ԭ��:
//count_if(iterator beg, iterator end��_pred ) ;
////������ͳ��Ԫ�س��ִ���
//// beg ��ʼ������
//// end����������
//// _Predν��

//1��ͳ��������������
class Greater20G{
public:
	bool operator() (int val){
		return val > 20;
	}
};
void test09(){
	vector<int>v;
	v.push_back(10);	
	v.push_back(40);	
	v.push_back(30);	
	v.push_back(20);	
	v.push_back(40);	
	v.push_back(20);	
	
	int num = count_if(v.begin(),v.end(),Greater20G()) ;	
	cout << num << endl;
}
//2��ͳ���Զ�����������
class Person4{//�������Զ����������� 
public:
	Person4(string name,int age){
		this -> m_name = name;
		this -> m_age = age;
	}
	string m_name;
	int m_age;
};
class AgeGreater20{
public:
	bool operator()(const Person4 &p){
		return p.m_age >  20;
	}
};
void test10(){
	vector<Person4>v;
	Person4 p1("����",35);
	Person4 p2("����",35);
	Person4 p3("�ŷ�",35);
	Person4 p4("����",30);
	Person4 p5("�ܲ�",20);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	int num = count_if(v.begin(),v.end(),AgeGreater20()) ;	
	cout << num << endl;
}


int main(){
    test01();
    test02();
    cout << endl;
 
    test03();
    test04();
    cout << endl;  
    
    test05();
    cout << endl;  

    test06();
    cout << endl; 
    
    test07();
    test08();
    cout << endl; 
    
    test09();
    test10();
    cout << endl; 
    return 0;
}



















