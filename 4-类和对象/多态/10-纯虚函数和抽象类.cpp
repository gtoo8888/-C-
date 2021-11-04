#include <iostream> 
using namespace std;


// 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
// 因此可以将虚函数改为纯虚函数
// 当类中有了纯虚函数，这个类也称为抽象类
// 纯虚函数和抽象类
class Base{
public:
    //纯虚函数
    //只要有一个纯虚函数，这个类称为抽象类
    //抽象类特点:
    //1、无法实例化对象
    //2、抽象类的子类必须要重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;//在虚函数基础上写=0，就不会出现问题

};

//写纯虚函数，就是为了要重写父类中的纯虚函数，不然连创建对象的资格都没有
// class Son :public Base{//仅仅这样写也是不可以的
// public:
// }

class Son :public Base{//仅仅这样写也是不可以的
public:
    virtual void func(){
        cout << "func() " << endl;
    }
};

void test01(){
    // Base b;//抽象类是无法实例化对象
    // new Base;//抽象类是无法实例化对象

    //Son s;//子类必须重写父类中的纯虚函数，否则无法实例化对象

    Base *base = new Son;
    base -> func();

}


int main(){
	test01();
    cout << endl;

    return 0;
}

