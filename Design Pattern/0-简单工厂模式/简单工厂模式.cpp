#include <iostream> 
#include <vector> 
#include <string>
#include <queue>
using namespace std;

// ����ˮ����
class AbstractFruit{
public:
    virtual void ShowName() = 0;
};

// ƻ��
class Apple : public AbstractFruit{
public:
    virtual void ShowName(){
        cout << "I'm Apple!" << endl;
    }
};

// �㽶
class Banana : public AbstractFruit{
public:
    virtual void ShowName(){
        cout << "I'm Banana!" << endl;
    }
};

// Ѽ��
class Pear : public AbstractFruit{
public:
    virtual void ShowName(){
        cout << "I'm Pear!" << endl;
    }
};

// ˮ���������򵥹���
class FruitFactory{
public:
    static AbstractFruit* CreateFruit(string flag){
        if(flag == "apple"){
            return new Apple;
        }else if(flag == "banana"){
            return new Banana;
        }else if(flag == "pear"){
            return new Pear;
        }else{
            return NULL;
        }
    }
};

// ��ʹ�ü򵥹���ģʽ��ֱ�Ӵ��������
void test01(){
    AbstractFruit* apple = new Apple;   // ֱ���Լ�newһ���µĶ���
    apple->ShowName();
    delete apple;

    AbstractFruit* banana = new Banana;
    banana->ShowName();
    delete banana;

    AbstractFruit* pear = new Pear;
    pear->ShowName();
    delete pear;
}

// ʹ�ü򵥹���ģʽ
// ���ڲ���Ҫ���Ĵ������̣�����Ҫ�������
// ���紴�����̺ܸ��ӣ�������ֻ����������࣬���Ҿ�������򵥹�������һ�¾��У�����Ĵ������̶����ڹ�������
// ���ǲ����Ͽ���ԭ�������Ҫ���Ӵ�����ˮ�����ͣ�����Ҫ�޸�Դ����
void test02(){
    FruitFactory* factory = new FruitFactory;   // �ȴ�����һ���������ɸ���ˮ������Ĺ���
    AbstractFruit* apple = factory->CreateFruit("apple");   // ��ʼ��������ˮ���������Լ������ģ�ͨ������������
    apple->ShowName();
    delete apple;

    AbstractFruit* banana = factory->CreateFruit("banana");
    banana->ShowName();
    delete banana;

    AbstractFruit* pear = factory->CreateFruit("pear");
    pear->ShowName();
    delete pear;

    delete factory;
}


int main() {
    test01();
    test02();

	return 0;
}



