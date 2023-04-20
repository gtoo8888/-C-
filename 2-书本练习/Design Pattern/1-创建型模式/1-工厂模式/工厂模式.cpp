#include <iostream> 
#include <vector> 
#include <string>
#include <queue>
using namespace std;

// 抽象水果类
class AbstractFruit{
public:
    virtual void ShowName() = 0;
};

// 苹果
class Apple : public AbstractFruit{
public:
    virtual void ShowName(){
        cout << "I'm Apple!" << endl;
    }
};

// 香蕉
class Banana : public AbstractFruit{
public:
    virtual void ShowName(){
        cout << "I'm Banana!" << endl;
    }
};

// 鸭梨
class Pear : public AbstractFruit{
public:
    virtual void ShowName(){
        cout << "I'm Pear!" << endl;
    }
};

// 抽象工厂
class AbstractFruitFactory{
public:
    virtual AbstractFruit* CreateFruit() = 0;
};

// 苹果工厂
class AppleFactory : public AbstractFruitFactory{
public:
    virtual AbstractFruit* CreateFruit(){
        return new Apple;
    }
};

// 香蕉工厂
class BananaFactory : public AbstractFruitFactory{
public:
    virtual AbstractFruit* CreateFruit(){
        return new Banana;
    }
};

// 鸭梨工厂
class PearFactory : public AbstractFruitFactory{
public:
    virtual AbstractFruit* CreateFruit(){
        return new Pear;
    }
};

// 使用工厂模式
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



