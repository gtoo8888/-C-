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




int main(){
    test01();
    test02();
    cout << endl;
 
  
    return 0;
}



















