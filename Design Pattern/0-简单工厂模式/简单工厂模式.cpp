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

// 水果工厂，简单工厂
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

// 不使用简单工厂模式，直接创建的情况
void test01(){
    AbstractFruit* apple = new Apple;   // 直接自己new一个新的对象
    apple->ShowName();
    delete apple;

    AbstractFruit* banana = new Banana;
    banana->ShowName();
    delete banana;

    AbstractFruit* pear = new Pear;
    pear->ShowName();
    delete pear;
}

// 使用简单工厂模式
// 用在不需要关心创建过程，就想要用这个类
// 比如创建过程很复杂，但是我只是想用这个类，那我就用这个简单工厂创建一下就行，具体的创建过程都放在工厂里面
// 但是不符合开闭原则，如果需要增加创建的水果类型，就需要修改源代码
void test02(){
    FruitFactory* factory = new FruitFactory;   // 先创建了一个可以生成各种水果对象的工厂
    AbstractFruit* apple = factory->CreateFruit("apple");   // 开始创建各种水果，不是自己创建的，通过工厂来生产
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



