#include <iostream> 
using namespace std;

//��̬��C++���������������֮һ��̬��Ϊ����
//��̬��̬:�������غ�������������ھ�̬��̬�����ú�����
//��̬��̬:��������麯��ʵ������ʱ��̬
//��̬��̬�Ͷ�̬��̬����:
//��̬��̬�ĺ�����ַ��󶨨C����׶�ȷ��������ַ
//��̬��̬�ĺ�����ַ��󶨨C���н׶�ȷ��������ַ

class Animal{
public:
	//��д ��������ֵ���� ������ �����б� ��ȫ��ͬ
    virtual void speak(){//�麯�� 
    	cout << "������˵��" << endl; 
	}
};

class Cat :public Animal{
public:
	void speak(){
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Animal{
public:
	void speak(){
		cout << "С����˵��" << endl;
	}
};
//ִ��˵���ĺ���
//��ַ����ڱ���׶�ȷ��������ַ
//�����ִ����è˵������ô���������ַ�Ͳ�����ǰ��
//��Ҫ�����н׶ν��а󶨣���ַ���

//��̬��̬��������
//1���м̳й�ϵ
//2��������д������麯��

//��̬��̬ʹ��
//�����ָ���������ִ���������
void dospeak(Animal & animal) {// Animal & animal = cat; 
	animal.speak();
}

void test01(){
    Cat cat;
    dospeak(cat);
    
    Dog dog;
    dospeak(dog);
}

//��̬��ԭ������ 
//vfptr-�麯������ָ��
//v - virtual
//f - function
//ptr - pointer
//
//vftable-�麯����
//v - virtual
//f - function
//table - table
//�������ָ���������ָ���������ʱ��,������̬
void test02(){
    cout << sizeof(Animal) <<endl; 
}

int main(){
	test01();
    cout << endl;

	test02();
    cout << endl;
    return 0;
}

