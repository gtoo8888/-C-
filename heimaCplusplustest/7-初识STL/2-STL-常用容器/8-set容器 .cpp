#include <iostream>
using namespace std;
#include <set>
#include <string>
//set/ multiset����
//��������������ʽ���� 
//set��������
//����Ԫ�ض����ڲ���ʱ�Զ�������
//����:
//set/multiset���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��
//set��multiset����:
//set���������������ظ���Ԫ��
//multiset�������������ظ���Ԫ��

//set����͸�ֵ
//��������:����set�����Լ���ֵ
//����:
//set<T> st;//Ĭ�Ϲ��캯��:
//set( const set &st);//�������캯��
//��ֵ:
//set& operator=gconst set &st);//���صȺŲ�����

void printSet(set<int> &s){
	for(set<int>::iterator it = s.begin();it != s.end();it++)
		cout << *it << " ";
	cout << endl;
}
//set����͸�ֵ
void test01(){
	set<int> s1; 
	s1.insert(10);//��������ֻ��insert��ʽ
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);
	//��������
	//set�����ص�:����Ԫ�ز���ʱ���Զ�������
	//set��������������ظ�ֵ
	printSet(s1);
	
	set<int> s2(s1);
	printSet(s2);
	
	set<int> s3;
	s3 = s2;
	printSet(s2);
}

//set��С�ͽ���
//��������:ͳ��set������С�Լ�����set����
//����ԭ��:
//size();//����������Ԫ�ص���Ŀ
//empty();//�ж������Ƿ�Ϊ��
//swap(st);//����������������
//�޷�����ָ��������С����֧��resize 
void test02(){
	set<int> s1; 
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	if(s1.empty())
		cout << "YES"  << endl;
	else{
		cout << "NO" << endl; 
		cout << s1.size() << endl;
	}
}

void test03(){
	set<int> s1; 
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int> s2; 
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);
	
	printSet(s1);
	printSet(s2);
	
	s1.swap(s2);
	printSet(s1);
	printSet(s2);	
}

//set�����ɾ��
//��������: set�������в������ݺ�ɾ������
//����ԭ��:
//insert(elem) ;//�������в���Ԫ�ء�
//clear();//�������Ԫ��
//erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
//erase(beg, end) ;//�������[beg,end)������Ԫ�أ�������һ��Ԫ�صĵ�������
//erase(elem);//ɾ��������ֵΪelem��Ԫ�ء�
void test04(){
	set<int> s1; 
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	s1.erase(s1.begin());//ɾ�����Ͳ���˳���޹� 
	printSet(s1);
	
	s1.erase(30);//ɾ�����ذ汾 
	printSet(s1);
	
	s1.erase(s1.begin(),s1.end()) ;
//	s1.clear();
	printSet(s1);
}

//set���Һ�ͳ��
//��������:��set�������в��������Լ�ͳ�����ݺ���ԭ��:
//find(key);//����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�����;�������ڣ�����set.end();
//count(key);//ͳ��key��Ԫ�ظ���
void test05(){
	set<int> s1; 
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	
	set<int>::iterator pos = s1.find(30);//���� 
	
	if(pos != s1.end())
		cout << "YES find:" << *pos << endl;
	else
		cout << "NO find" << endl;
		
	int num = s1.count(30);//ͳ�Ƹ��� 
	//����set����ͳ�ƽ��Ҫô��0Ҫô��1
	cout << num << endl;
}


//set��multiset����
//����:
//set�����Բ����ظ����ݣ���multiset����
//set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
//multiset���������ݣ���˿��Բ����ظ�����
void test06(){
	set<int> s1; 
	pair<set<int>::iterator,bool> ret = s1.insert(10);//���� 
//	Դ�����е�using _Pairib =pair<iterator��bool>;

	if(ret.second)
		cout << "��һ�β���ɹ�" << endl;
	else
		cout << "��һ�β���ʧ��" << endl;

	ret = s1.insert(10);
	if(ret.second)
		cout << "�ڶ��β���ɹ�" << endl;
	else
		cout << "�ڶ��β���ʧ��" << endl;
		
	multiset<int> ms;//��������ظ�ֵ		
//Դ���е�iterator insext(value_type&&_Val)
//������һ����������ֻҪ������ȷ���������ͣ��ͻ᷵�ص����� 
	ms.insert(10);
	ms.insert(10);
	for(multiset<int>::iterator it = ms.begin();it != ms.end();it++)
		cout << *it << " ";
	cout << endl;
}

//pair���鴴��
//��������:�ɶԳ��ֵ����ݣ����ö�����Է�����������
//���ִ�����ʽ:
//pair<type, type> p ( value1, value2 );
//pair<type, type> p = make_pair( value1�� value2 );
void test07(){
	//��һ�ַ�ʽ
	pair<string,int> p("TOM",20); //���ð���ͷ�ļ� 
	cout << p.first << " " << p.second << endl; 
	
	//�ڶ��ַ�ʽ
	pair<string,int> p2 = make_pair("Jerry",30); 
	cout << p2.first << " " << p2.second << endl; 
}

//set��������
//ѧϰĿ��:set����Ĭ���������Ϊ��С����������θı��������
//��Ҫ������:
//���÷º��������Ըı��������

//set���������������
class MyCompare{
public:
	bool operator()(int v1,int v2){
		return v1 > v2;
	}
}; 
void test08(){
	set<int> s1; 
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	printSet(s1);
	
	//ָ���������Ϊ�Ӵ�С
	set<int,MyCompare> s2;//��һ���º�������Ϊ��Ҳ��һ������ 
	s2.insert(30);
	s2.insert(10);
	s2.insert(20);
	s2.insert(40);
	s2.insert(30);
	for(set<int,MyCompare>::iterator it = s2.begin();it != s2.end();it++)
		cout << *it << " ";
	cout << endl;
}

//set����Զ�����������
class Person{
public:
	Person(string name,int age){
		this -> m_Name = name;
		this -> m_Age = age;
	}
	string m_Name;
	int m_Age;
}; 
class comparePerson{
public:
	bool operator()(const Person &p1,const Person &p2){
		return p1.m_Age > p2.m_Age;//�������併��
	}
};  
void test09(){
	//�Զ����������Ͷ���ָ���������
	set<Person,comparePerson> s1; 	
	Person p1("����",24);
	Person p2("�ŷ�",28);
	Person p3("����",25);
	Person p4("����",21);
	
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);	
	
	for(set<Person,comparePerson>::iterator it = s1.begin();it != s1.end();it++)
		cout << it -> m_Name << " " << it->m_Age << endl;
	cout << endl;
}


int main(){
    test01();
    cout << endl;
     
    test02();
    test03();
    cout << endl;
    
    test04();
    cout << endl;
    
    test05();
    cout << endl;

    test06();
    cout << endl;
    
    test07();
    cout << endl;
    
    test08();
    cout << endl;

    test09();
    cout << endl;
    return 0;
}



















