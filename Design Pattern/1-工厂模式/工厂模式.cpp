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

// ���󹤳�
class AbstractFruitFactory{
public:
    virtual AbstractFruit* CreateFruit() = 0;
};

// ƻ������
class AppleFactory : public AbstractFruitFactory{
public:
    virtual AbstractFruit* CreateFruit(){
        return new Apple;
    }
};

// �㽶����
class BananaFactory : public AbstractFruitFactory{
public:
    virtual AbstractFruit* CreateFruit(){
        return new Banana;
    }
};

// Ѽ�湤��
class PearFactory : public AbstractFruitFactory{
public:
    virtual AbstractFruit* CreateFruit(){
        return new Pear;
    }
};

// ʹ�ù���ģʽ
void test01(){
    AbstractFruitFactory* factory = NULL;   
    AbstractFruit* fruit = NULL;

    factory = new AppleFactory;
    fruit = factory->CreateFruit();
    fruit->ShowName();
    delete factory;
    delete fruit;

    factory = new BananaFactory;
    fruit = factory->CreateFruit();
    fruit->ShowName();
    delete factory;
    delete fruit;

    factory = new PearFactory;
    fruit = factory->CreateFruit();
    fruit->ShowName();
    delete factory;
    delete fruit;
}


int main() {
    test01();

	return 0;
}



