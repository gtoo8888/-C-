#include <iostream> 
using namespace std;
#include <string>


// ǳ����:�򵥵ĸ�ֵ��������
// ���:�ڶ�����������ռ䣬���п�������
class Person {
public:
	Person() {
		cout << "�޲ι��캯��" << endl;
	}
	Person(int age ,int height) {
		cout << "�вι��캯��" << endl;
		m_age = age;
		m_height = new int(height);
	}
	Person(const Person& p) {//�Լ�ʵ�ֿ������캯�����ǳ��������������
		//�������������ڶ����������ڴ棬�ᵼ��ǳ�����������ظ��ͷŶ�������
//		m_age = p.m_age;//������Ĭ��ʵ�־������д��� 
		m_height = new int(*p.m_height);//�������
	}
	~Person() {
		//�������룬�����������������ͷŲ���
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
	}
	int m_age;
	int* m_height;
};
//�����ǳ���� 
void test01(){
	Person p1(18, 180);
	Person p2(p1);
	cout << "p1�����䣺 " << p1.m_age << " ��ߣ� " << *p1.m_height << endl;
	cout << "p2�����䣺 " << p2.m_age << " ��ߣ� " << *p2.m_height << endl;
}

//��ʼ���б�
class Person2 {
public:
	//Person2(int a, int b, int c) {
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}
	//��ʼ���б�ʽ��ʼ��
//	Person2(int a, int b, int c) :m_A(10), m_B(20), m_C(30) {}
	Person2(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
	int m_A;
	int m_B;
	int m_C;
};

void test02(){
//	Person2 p(1, 2, 3);
//	Person2 p;
	Person2 p(3, 2, 1);
	cout << "mA:" << p.m_A << endl;
	cout << "mB:" << p.m_B << endl;
	cout << "mC:" << p.m_C << endl;
}

//�������Ϊ���Ա
//C++���еĳ�Ա��������һ����Ķ������ǳƸó�ԱΪ�����Ա
//B�����ж���A��Ϊ��Ա��AΪ�����Ա
//��ô������B����ʱ��A��B�Ĺ����������˳����˭��˭��? 
class Phone
{
public:
	Phone(string name){
		m_PhoneName = name;
		cout << "Phone����" << endl;
	}
	~Phone(){
		cout << "Phone����" << endl;
	}
	string m_PhoneName;

};
class Person3{
public:
//	Phone Phone = pName��ʽת����
	Person3(string name, string pName) :m_Name(name), m_Phone(pName){
		cout << "Person����" << endl;
	}

	~Person3(){
		cout << "Person����" << endl;
	}
	string m_Name;
	Phone m_Phone;
};
//�������������Ϊ�����Ա������ʱ���ȹ���������ٹ�������������˳���빹���෴
//Phone��Person3�ȹ���
void test03()
{
	Person3 p("����" , "ƻ��X");
	cout << p.m_Name << " " << p.m_Phone.m_PhoneName << endl;
}

//��̬��Ա
//��̬��Ա�����ڳ�Ա�����ͳ�Ա����ǰ���Ϲؼ���static����Ϊ��̬��Ա
//��̬��Ա��Ϊ:
//	
//��̬��Ա����
//���ж�����ͬһ������
//�ڱ���׶η����ڴ�
//���������������ʼ��
class Person4{
public:
	static int m_a;	
//��̬��Ա����Ҳ���з���Ȩ�޵�
private:
	static int m_b;
};
int Person4::m_a = 100;
int Person4::m_b = 200;
void test04(){
	Person4 p;
	cout << p.m_a << endl;
	Person4 p2;
	p2.m_a = 200;
	cout << p2.m_a << endl;
//	cout << p.m_b << endl;
}
//��̬��Ա����������ĳ�������ϣ����ж��󶼹���ͬһ������
//��˾�̬��Ա���������ַ��ʷ�ʽ
void test05(){
	Person4 p;
	cout << p.m_a << endl;//1��ͨ��������з���
	cout << Person4::m_a << endl;//2��ͨ���������з���	
}

//��̬��Ա����
//���ж�����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����	
class Person5{
public:
	static void func(){
		m_a = 100;//��̬��Ա�������Է��ʾ�̬��Ա����
//		m_b = 200;//��̬��Ա���������Է��ʷǾ�̬��Ա����
		//�޷����ֵ������ĸ������m_b
		cout << "static void func()�ĵ���"<<endl;
	}
	static int m_a;//��̬��Ա����
	int m_b;//�Ǿ�̬��Ա����
private:
	static void func2(){
		cout << "static void func2()�ĵ���"<<endl;
	}
};
int Person5::m_a = 0;
//��̬��Ա����
void test06(){
	Person5 p;
	p.func();//1��ͨ���������
	Person5::func();//2��ͨ����������	
//	Person5::func2();
}	

//��Ա�����ͳ�Ա�����ֿ��洢
//��C++�У����ڵĳ�Ա�����ͳ�Ա�����ֿ��洢
//ֻ�зǾ�̬��Ա������������Ķ����� 
class Person6{
} ;
class Person7{
	int m_a;//�Ǿ�̬��Ա����������Ķ�����
} ;
class Person8{
	int m_a;
	static int m_b;;//��̬��Ա���� �������������
	void func(){} //�Ǿ�̬��Ա����
} ;
int Person8::m_b = 0;
//��Ա�����ͳ�Ա�����ֿ��洢
void test07(){
	Person6 p1;
	//�ն���ռ���ڴ�ռ�Ϊ:1
	//C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << sizeof(p1) << endl;
	Person7 p2;
	cout << sizeof(p2) << endl;
	Person8 p3;
	cout << sizeof(p3) << endl;	
}

//thisָ�����
//thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
//thisָ�벻��Ҫ���壬ֱ��ʹ�ü���
class Person9{
public:
	Person9(int age){
		//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
		this -> age = age;
	}
	Person9 &Personaddage(Person9 &p) {
		this -> age += p.age;
		return *this;//thisָ��p2��ָ�룬��*thisָ��ľ���p2���������
	}
	int age;
};
//thisָ�����;:
//1.������Ƴ�ͻ�����βκͳ�Ա����ͬ��ʱ������thisָ��������
void test08(){
	Person9 p1(18);
	cout << p1.age << endl;
}
//2.����ķǾ�̬��Ա�����з��ض�������ʹ��return *this
void test09(){
	Person9 p1(20);
	Person9 p2(20);
	p2.Personaddage(p1).Personaddage(p1);//��ʽ���˼��
	cout << p2.age << endl;
}

//��ָ����ʳ�Ա����
//C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��
//����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��
class Person10{
public:
	void showclassname(){
		cout << "Person" << endl;
	}
	void showpersonage(){
		//����ԭ������Ϊ�����ָ����ΪNULL
		if(this == NULL) return;//�������ָ����ƻ� 
		cout << this -> m_age << endl;//ƽʱд��m_age����this->m_age
	}
	int m_age;
};

void test10(){
	Person10 *p = NULL;
	p -> showclassname();//��ָ����Է��ʳ�Ա
	p -> showpersonage();
}

//const���γ�Ա����
//������:
//��Ա�������const�����ǳ�Ϊ�������Ϊ���������������ڲ������޸ĳ�Ա����
//��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�
//������:
//��������ǰ��const�Ƹö���Ϊ������
//������ֻ�ܵ��ó�����
class Person11{
public:
	//thisָ��ı�����ָ�볣��ָ���ָ���ǲ������޸ĵ�
	//const Person * const this;
	//�ڳ�Ա���������const�����ε���thisָ����ָ��ָ���ֵҲ�������޸�
	void showperson() const{//������ 
//		this -> m_a = 100;
//		this = NULL;//thisָ�벻�����޸�ָ���ָ���		
		this -> m_b = 100;
	}
	void func(){}
	int m_a;
	mutable int m_b;//�����������ʹ�ڳ������У�Ҳ�����޸����ֵ,�ӹؼ���mutable
};

// void test11(){
// 	const Person1 p;//�ڶ���ǰ��const����Ϊ������
// 	//p.m_a = 100 ;
// 	p.m_b = 100; //m_B������ֵ���ڳ�������Ҳ�����޸�
	
// 	//������ֻ�ܵ��ó�����
// 	p.showperson() ;
// 	//p.furc();//�����󲻿��Ե�����ͨ��Ա��������Ϊ��ͨ��Ա���������޸�����
// }


int main() {
	test01();//�����ǳ����
	cout << endl;

	test02();//��ʼ���б�
	cout << endl;
	
	test03();//�������Ϊ���Ա
	cout << endl;

	test04();//��̬��Ա����
	test05();
	cout << endl;
	
	test06();//��̬��Ա����
	cout << endl;
	
	test07();//��Ա�����ͳ�Ա�����ֿ��洢
	cout << endl;
	
	test08();//thisָ�����
	test09();
	cout << endl;
	
	test10();//��ָ����ʳ�Ա����
	cout << endl;

//	test11();//const���γ�Ա����
//	cout << endl;
	return 0;
}


