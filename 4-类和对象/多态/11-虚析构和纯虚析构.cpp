#include <iostream> 
using namespace std;

// �������ʹ�������
// ��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
// �����ʽ:�������е�����������Ϊ���������ߴ�������

// �������ʹ�����������:
// ���Խ������ָ���ͷ����������Ҫ�о���ĺ���ʵ��
// �������ʹ�����������:
// ����Ǵ����������������ڳ����࣬�޷�ʵ��������

class Animal{
public:
    virtual void speak() = 0;
};

class Cat :public Animal{
public:
	virtual void speak(){
		cout << "Сè��˵��" << endl;
	}
};

void test01(){
   Animal *animal = new Cat;//�����ָ��ָ��һ������Ķ���
   animal -> speak();
   delete animal;
}

int main(){
	test01();
    cout << endl;

    return 0;
}

