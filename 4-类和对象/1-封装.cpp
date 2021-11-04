#include<iostream> 
using namespace std;
#include <string>

const double PI = 3.14;

//class �������һ���࣬���������������� 
class Circle
{
	//����Ȩ��
	//����Ȩ�� 
public:	
	//���ԣ����� 
	int m_r;
	//��Ϊ������
	double cal()
	{
		return 2 * PI * m_r;
	} 
};

//���һ��ѧ���࣬������������ѧ�ţ�
//���Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
class Student
{
public:
	//���е� ���Ժ���Ϊ��ͳһ��Ϊ ��Ա 
	//���Գ�Ϊ ��Ա���ԡ���Ա���� 
	string m_name;
	string m_ID;
	
	//��Ϊ��Ϊ ��Ա��������Ա���� 
	void ShowStudent()
	{
		cout << m_name << " " << m_ID << endl;
	}
	
	//ͨ����Ϊ�����Խ��и�ֵ 
	void setName(string name)		
	{
		m_name = name;
	}
	void setID(string ID)
	{
		m_ID = ID;
	}
};

//��װ�����:
//�������ʱ�����԰����Ժ���Ϊ���ڲ�ͬ��Ȩ���£����Կ��Ʒ���Ȩ��������
//����Ȩ�ޣ� 
//1.public ����Ȩ��              ��Ա ���ڿ��Է��� ������Է��� 
//2. protected ����Ȩ��          ��Ա ���ڿ��Է��� ���ⲻ���Է��� ���ӿ��Է��ʸ����еı�������    
//3. private˽��Ȩ��			 ��Ա ���ڿ��Է��� ���ⲻ���Է��� ���Ӳ����Է��ʸ����еı�������    
//��������ѧϰ�̳е�ʱ�������ᵽ���� 
class Person
{
public://����Ȩ�� 
	string m_Name;
protected://����Ȩ�� 
	string m_Car;
private://˽��Ȩ�� 
	int m_Password;	
private://��Ա����Ҳ��������Ϊ˽�л��߹��� 
	void func()
	{
		m_Name = "����";
		m_Car = "������"; 
		m_Password = 123456; 
	} 
}; 

//struct��class����
//structĬ��Ȩ���� ���� public
//class Ĭ��Ȩ���� ˽�� privateci 
class C1
{
	int m_A; //Ĭ��Ȩ�� ˽�� 
};
struct C2
{
	int m_A;//Ĭ��Ȩ�� ���� 
};


//��Ա��������Ϊ˽��
//�ŵ�1�ý����г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
//�ŵ�2:����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��
class Person2
{
//�ѳ�Ա��������Ϊ˽�У�ͨ�����еĺ����ӿ������з��� 
public:
	void setName(string name) 
	{
		m_Name = name;
	}
	string getName()
	{
		return m_Name;
	}
	int getAge()//��д 
	{
//		m_Age = 20;
		return m_Age;
	}
	void setAge(int age)//�ɶ���д��������޸ģ���Χ�ڣ�0-150�� 
	{
		if(age < 0 || age > 150)
		{
			m_Age = 0; 
			cout << "�����������" << endl;
			return; //����ʧ��ֱ�ӷ��� 
		}
		m_Age = age;
	}
	void setLover(string lover)
	{
		m_Lover = lover;
	}
private:
	string m_Name;		//���� �ɶ���д 
	int m_Age;			//���� ֻ�� 
	string m_Lover;		//���� ֻ�� 
} ;


int main(){
	
	Circle c1;//ʵ������ͨ���ഴ��һ������Ķ���)
	c1.m_r = 10;//����Ķ�����и�ֵ 	
	cout << c1.cal() << endl;//���ú�������Ϊ 
	
	Student s1;
	s1.m_name = "yan";
	s1.m_ID = "210321041670";
	s1.ShowStudent();
	s1.setName("luo");
	s1.ShowStudent();
	
	Person p1;	
	p1.m_Name = "����";
//	p1.m_Car = "����";
//	p1.m_Password = 123; 
//	p1.func();		
	
	C1 c11;
	//c11.m_A = 100;
	C2 c22;
	c22.m_A = 100;
	cout << '\n' << endl;
	
	Person2 p2;
	p2.setName("����");
	cout << p2.getName() << endl;
	cout << p2.getAge() << endl;
//	p2.m_Age = 18;
//	p2.setAge(18);
	p2.setLover("�Ծ�"); 
//	cout << p2.getLover() << endl;
	p2.setAge(1000);
	cout << p2.getAge() << endl;
	p2.setAge(40);
	cout << p2.getAge() << endl;

	return 0;
}


