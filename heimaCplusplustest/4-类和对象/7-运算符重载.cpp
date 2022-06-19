#include <iostream> 

using namespace std;

// ��������ظ���:�����е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
// �ܽ�1: �������õ��������͵ı��ʽ�ĵ�������ǲ����ܸı��
//����1+1=2����Ū��1-1=0
// �ܽ�2: ��Ҫ�������������


//�Ӻ����������
//1����Ա��������+��
class Person{
public:
//    1����Ա��������+��
//     Person operator+(Person &p){
//         Person temp;
//         temp.m_A = this ->m_A + p.m_A;
//         temp.m_B = this ->m_B + p.m_B;
//         return temp;
//     }
    int m_A;
    int m_B;
};
//2��ȫ�ֺ�������+��
Person operator+(Person &p1,Person &p2){
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}
Person operator+(Person &p1,int p2){
    Person temp;
    temp.m_A = p1.m_A + p2;
    temp.m_B = p1.m_B + p2;
    return temp;
}

void test01(){
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    Person p2;
    p2.m_A = 20;
    p2.m_B = 20;

    //��Ա�������ر��ʵ���
//    Person p3 = p1. operator+(p2) ;
    //ȫ�ֺ������ر��ʵ���
    //Person p3 = operator+ (p1,p2) ;
    Person p3 = p1 + p2;
    cout << p3.m_A << endl;
    cout << p3.m_B << endl;

    //��������أ�Ҳ���Է�����������
    Person p4 = p1 + 100;//Person + int
    cout << p4.m_A << endl;
    cout << p4.m_B << endl; 
}

//�������������
class Person2{
    friend ostream &operator << (ostream &cout,Person2 p);
public:
    Person2(int a,int b){
        m_a = a;
        m_b = b;
    }
private:
    //���ó�Ա�����������������p.operator<<(cout) �򻯰汾 p << cout
    //�������ó�Ա��������<<���������Ϊ�޷�ʵ��cout�����
    // void operator<<(cout){
    // }
    int m_a;
    int m_b;
};
//ֻ������ȫ�ֺ����������������
ostream &operator << (ostream &cout,Person2 p){
    //����operator << (cout,p)��cout
    cout << p.m_a << endl;
    cout << p.m_b << endl;
    return cout;
}
void test02(){
    Person2 p(10,10);
    // p.m_a = 10;
    // p.m_b = 10;
    cout << p << endl;
}

//���ص���������������Լ�д�ݼ�
class MyInteger{
    friend ostream &operator<<(ostream &cout,MyInteger myint);
public:
    MyInteger(){
        m_Num = 0;
    }
    //����ǰ��++���������������Ϊ��һֱ��һ�����ݽ��е�������
    MyInteger &operator++(){
        m_Num++;//�Ƚ���++����
        return *this;//�ٽ�����������
    }
    //���غ���++�����
    // void operator++(int) int����ռλ������������������ǰ�úͺ��õ���
    //���õ��� һ��Ҫ����ֵ���������ý��������˾ֲ��Ķ��󣬻ᱻ�ͷŵ�
    MyInteger operator++(int){
        MyInteger temp = *this;//�ȼ�¼��ʱ���
        m_Num++;//֮�����
        return temp;//��󽫼�¼���������
    }
private:
    int m_Num;
};
ostream &operator<<(ostream &cout,MyInteger myint){
    cout << myint.m_Num;
    return cout;
}
void test03(){//ǰ�õ���
    MyInteger myint;
    cout << ++(++myint) << endl;  
    cout << myint << endl;  
}
void test04(){//���õ���
    MyInteger myint;
    cout << myint++ << endl;  
    cout << myint << endl;  
}

// C++���������ٸ����������4������
// 1.Ĭ�Ϲ��캯��(�޲Σ�������Ϊ��)
// 2.Ĭ����������(�޲Σ�������Ϊ��)
// 3.Ĭ�Ͽ������캯���������Խ���ֵ����
// 4.��ֵ�����operator=�������Խ���ֵ����
// �������������ָ�����������ֵ����ʱҲ�������ǳ��������
class Person3{
public:
    Person3(int age){
        m_age = new int (age);
    }
    ~Person3(){
       if(m_age != NULL) {
           delete m_age;
           m_age = NULL;
       }
    }
    //���ظ�ֵ�����
	Person3& operator=(Person3 &p){
        //m_age = p.m_age;//�������ṩ��ǳ����
        //Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
		if(m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
		m_age = new int(*p.m_age);//��� 
		return *this;
    }
    int *m_age;
};
void test05(){
    Person3 p1(18);
    Person3 p2(20);
    Person3 p3(30);

    p3 = p1 = p2;

    cout << *p1.m_age << endl;
    cout << *p2.m_age << endl;
    cout << *p3.m_age << endl;
}

//���ع�ϵ����� 
class Person4{
public:
	Person4(string name,int age){
		m_name = name;
		m_age = age;
	}
	bool operator==(Person4 &p){
		if(this -> m_name == p.m_name && this -> m_age == p.m_age)
			return true;
		else
			return false;
	}
	bool operator!=(Person4 &p){
		if(this -> m_name == p.m_name && this -> m_age == p.m_age)
			return false;
		else
			return true;
	} 
	string m_name;
	int m_age;	
};
void test06(){
    Person4 p1("TOM",18);
    Person4 p2("TOM",18);
    
    if(p1 == p2)
    	cout << "p1 same p2" << endl;
    else
    	cout << "p1 no same p2" << endl;
    	
    Person4 p3("JARRY",18);
    if(p1 != p3)
    	cout << "p1 no same p3" << endl;
    else
		cout << "p1 same p3" << endl; 
}

//�����������������
//�������������()Ҳ��������
//�������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
//�º���û�й̶�д�����ǳ����
class Myprint{
public:
	void operator()(string test){
		cout << test << endl;
	}
};
void Myprint02(string test){
	cout << test << endl;
}
void test07(){
    Myprint myprint;
    
    myprint("hello world");//����ʹ�������ǳ������ں������ã���˳�Ϊ�º���
    Myprint02("hello world");
}
//�º����ǳ���û�й̶���д��
//�ӷ���
class MyAdd{
public:
	int operator()(int num1,int num2){
		return num1 + num2;
	}
};
void test08(){
    MyAdd myadd;
    int ret = myadd(100,100);
    cout << ret << endl;
    //������������
	cout << MyAdd ()(100,100)<< endl;
}

int main(){
	test01();//�Ӻ����������
    cout << endl;

    test02();//�������������
    cout << endl;

    int a = 10 ;
    cout <<++(++a)<< endl;
    cout << a << endl;
    test03();//���ص��������
    test04();//���ص��������
    cout << endl;

	int a1 = 10;
	int b1 = 20;
	int c1 = 30;
	c1 = b1 = a1;
	cout << a1 << ' ' << b1 << ' ' << c1 << ' ' << endl; 
    test05();//���ظ�ֵ�����
    cout << endl;
    
    test06();//���ع�ϵ����� 
    cout << endl;
    
    test07();//�����������������
    test08();//�º��� 
    cout << endl;
    return 0;
}
