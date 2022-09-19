#include <iostream> 
using namespace std;

// 虚析构和纯虚析构
// 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
// 解决方式:将父类中的析构函数改为虚析构或者纯虚析构

// 虚析构和纯虚析构共性:
// 可以解决父类指针释放子类对象都需要有具体的函数实现
// 虚析构和纯虚析构区别:
// 如果是纯虚析构，该类属于抽象类，无法实例化对象

class Animal{
public:
    virtual void speak() = 0;
};

class Cat :public Animal{
public:
	virtual void speak(){
		cout << "小猫在说话" << endl;
	}
};

void test01(){
   Animal *animal = new Cat;//父类的指针指向一个子类的对象
   animal -> speak();
   delete animal;
}

int main(){
	test01();
    cout << endl;

    return 0;
}

