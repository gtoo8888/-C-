#include <iostream> 
using namespace std;
#include <string>
#include <typeinfo> 
//��ģ��
//��ģ���﷨
//��ģ������:
//����һ��ͨ���࣬���еĳ�Ա�������Ϳ��Բ������ƶ�����һ�����������������
//�﷨:
//template<typename T>
//��
//template ---��������ģ��
//typename ---���������ķ����ǡ����������ͣ�������class����
//T ---ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ

template<class NameType,class AgeType> 
class Person{
public:
	Person(NameType name,AgeType age){
		this -> m_Name = name;
		this -> m_Age = age;
	}
	void show(){
		cout << this ->m_Name << " " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
}; 

void test01(){
	Person<string,int> p1("�����",999);
	p1.show();
}

//��ģ���뺯��ģ������
//��ģ���뺯��ģ��������Ҫ������:
//1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
//2.��ģ����ģ������б��п�����Ĭ�ϲ���
template<class NameType,class AgeType> 
class Person02{
public:
	Person02(NameType name,AgeType age){
		this -> m_Name = name;
		this -> m_Age = age;
	}
	void show(){
		cout << this ->m_Name << " " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
}; 
//1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
void test02(){
//	Person02 p1("�����",100);//�����޷����Զ������Ƶ�
	Person02<string,int>p1("�����",100);//��ȷ��ֻ������ʾָ������

	p1.show();
}
//2.��ģ����ģ������б��п�����Ĭ�ϲ���
void test03(){
//	Person<string> p1("��˽�",999);//�����intû��ָ������Ϊ������Ĭ�ϲ�����
	//����C++11���� 
	//�ں���ģ���в�����ô�� 
//	p1.show();
}


//��ģ���г�Ա��������ͨ���г�Ա��������ʱ�����������:
//��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
//��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���

//��ģ���г�Ա��������ʱ��
//��ģ���г�Ա�����ڵ���ʱ��ȥ����
class Person03{
public:
	void showPerson03(){
		cout << "showPerson03" << endl;
	}
}; 
class Person04{
public:
	void showPerson04(){
		cout << "showPerson04" << endl;
	}
}; 

template<class T>
class MyClass{
public:
	T obj;
	void func3(){//��ģ���еĳ�Ա����
		obj.showPerson03();
		//��������ģ��ĳ�Աû�б�ʵ������ʱ�����������������ǲ��ᱻ������ 
	}
	void func4(){
		obj.showPerson04();
	}
};

void test04(){
	MyClass<Person03> m;
	//ֻ�е�ȷ��T�Ժ�ȷ�����滻��Person03������û��showPerson04()������� 
	m.func3();
//	m.func4();//���õ�ʱ��Żᱨ�� 
}


//��ģ��������������� 
//ѧϰĿ��:
//��ģ��ʵ�������Ķ����������εķ�ʽ
//�������ִ��뷽ʽ:
//1.ָ�����������---ֱ����ʾ�������������
//2.����ģ�廯---�������еĲ�����Ϊģ����д���
//3.������ģ�廯---�������������ģ�廯���д���
template<class NameType,class AgeType> 
class Person05{
public:
	Person05(NameType name,AgeType age){
		this -> m_Name = name;
		this -> m_Age = age;
	}
	void show(){
		cout << this ->m_Name << " " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
}; 
//1.ָ����������͡������ 
void print1Person5(Person05<string,int> &p){
	p.show();
}
void test05(){
	Person05<string,int> p("�����",100); 
	print1Person5(p);
}
//2.����ģ�廯
template <class T1,class T2>
void print2Person5(Person05<T1,T2> &p){
	p.show();
	cout << typeid(T1).name() << endl;//��ģ�����Ƴ�������ʲô���� 
	cout << typeid(T2).name() << endl;
}
void test06(){
	Person05<string,int> p("��˽�",90); 
	print2Person5(p);
}
//3.������ģ�廯
template <class T>
void print3Person5(T &p){
	p.show();
	cout << typeid(T).name() << endl;
}
void test07(){
	Person05<string,int> p("��ɮ",30); 
	print3Person5(p);
}

//����ģ�������̳�ʱ����Ҫע��һ�¼���:
//������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
//�����ָ�����������޷�����������ڴ�
//��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
//��ģ����̳�
//�ܽ�:�����������ģ�壬������Ҫָ����������T����������
template<class T> 
class Base{
	T m;
};
//class Son :public Base //���󣬱���Ҫ֪�������е�T���ͣ����ܼ̳и�����
class Son:public Base<int> {
};
void test08(){
	Son s1;
}
//��������ָ��������T���ͣ�����Ҳ��Ҫ����ģ��
template<class T1,class T2>
class Son2:public Base<T2>{
public:
	Son2(){
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	T1 obj;
};
void test09(){
	Son2<int,char> s1;
}


//��ģ���Ա��������ʵ��
template<class NameType,class AgeType> 
class Person06{
public:
	Person06(NameType name,AgeType age);//��������ʵ��  
//	{
//		this -> m_Name = name;
//		this -> m_Age = age;
//	}
	void show();
//	{
//		cout << this ->m_Name << " " << this->m_Age << endl;
//	}
	NameType m_Name;
	AgeType m_Age;
}; 
//���캯������ʵ��
template<class T1,class T2> 
Person06<T1,T2>::Person06(T1 name,T2 age){
	this -> m_Name = name;
	this -> m_Age = age;
}
//��Ա��������ʵ��
template<class T1,class T2> 
void Person06<T1,T2>::show(){
	cout << this ->m_Name << " " << this->m_Age << endl;
}
void test10(){
	Person05<string,int> p("TOM",20); 
	p.show();
}

//��ģ������Ԫ
//ȫ�ֺ�������ʵ�֨Cֱ��������������Ԫ����
//ȫ�ֺ�������ʵ�֨C��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
//�ܽ�:����ȫ�ֺ���������ʵ�֣��÷��򵥣����ұ���������ֱ��ʶ��
//��ǰ�ñ�����֪��Person�����
template<class T1,class T2> 
class Person07;
//ȫ�ֺ�������ʵ��
template<class T1,class T2> 
void show2(Person07<T1,T2> p){
	cout << p.m_Name << " " << p.m_Age << endl;
}
template<class T1,class T2> 
class Person07{
	//ȫ�ֺ�������ʵ�� 
	friend void show(Person07<T1,T2> p){
		cout << p.m_Name << " " << p.m_Age << endl;
	}
	//ȫ�ֺ�������ʵ��
	//�ӿ�ģ������б�<>
	//���ȫ�ֺ���������ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ���
	friend void show2<>(Person07<T1,T2> p);
//����һ����ͨ�ĺ�����������ģ��ĺ�������������д���Ǻ���ģ��ĺ���ʵ��
public:
	Person07(T1 name,T2 age){
		this -> m_Name = name;
		this -> m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
}; 
//1.ȫ�ֺ�������ʵ�� 
void test11(){
	Person07<string,int> p("TOM",20); 
	show(p);
}
//2.ȫ�ֺ�������ʵ��
void test12(){
	Person07<string,int> p("Jerry",20); 
	show2(p);
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
	test06();
	test07();
	cout << endl;	
	
	test08();
	test09();
	cout << endl;
	
	test10();
	cout << endl;		
	
	test11();
	test12();
	cout << endl;	
    return 0;
}
