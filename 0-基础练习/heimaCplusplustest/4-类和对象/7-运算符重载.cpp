#include <iostream> 

using namespace std;

// 运算符重载概念:对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
// 总结1: 对于内置的数据类型的表达式的的运算符是不可能改变的
//比如1+1=2不能弄成1-1=0
// 总结2: 不要滥用运算符重载


//加号运算符重载
//1、成员函数重载+号
class Person{
public:
//    1、成员函数重载+号
//     Person operator+(Person &p){
//         Person temp;
//         temp.m_A = this ->m_A + p.m_A;
//         temp.m_B = this ->m_B + p.m_B;
//         return temp;
//     }
    int m_A;
    int m_B;
};
//2、全局函数重载+号
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

    //成员函数重载本质调用
//    Person p3 = p1. operator+(p2) ;
    //全局函数重载本质调用
    //Person p3 = operator+ (p1,p2) ;
    Person p3 = p1 + p2;
    cout << p3.m_A << endl;
    cout << p3.m_B << endl;

    //运算符重载，也可以发生函数重载
    Person p4 = p1 + 100;//Person + int
    cout << p4.m_A << endl;
    cout << p4.m_B << endl; 
}

//重载左移运算符
class Person2{
    friend ostream &operator << (ostream &cout,Person2 p);
public:
    Person2(int a,int b){
        m_a = a;
        m_b = b;
    }
private:
    //利用成员函数重载左移运算符p.operator<<(cout) 简化版本 p << cout
    //不会利用成员函数重载<<运算符，因为无法实现cout在左侧
    // void operator<<(cout){
    // }
    int m_a;
    int m_b;
};
//只能利用全局函数重载左移运算符
ostream &operator << (ostream &cout,Person2 p){
    //本质operator << (cout,p)简化cout
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

//重载递增运算符，课下自己写递减
class MyInteger{
    friend ostream &operator<<(ostream &cout,MyInteger myint);
public:
    MyInteger(){
        m_Num = 0;
    }
    //重载前置++运算符，返回引用为了一直对一个数据进行递增操作
    MyInteger &operator++(){
        m_Num++;//先进行++运算
        return *this;//再将自身做返回
    }
    //重载后置++运算符
    // void operator++(int) int代表占位参数，可以用于区分前置和后置递增
    //后置递增 一定要返回值，返回引用仅仅返回了局部的对象，会被释放掉
    MyInteger operator++(int){
        MyInteger temp = *this;//先记录当时结果
        m_Num++;//之后递增
        return temp;//最后将记录结果做返回
    }
private:
    int m_Num;
};
ostream &operator<<(ostream &cout,MyInteger myint){
    cout << myint.m_Num;
    return cout;
}
void test03(){//前置递增
    MyInteger myint;
    cout << ++(++myint) << endl;  
    cout << myint << endl;  
}
void test04(){//后置递增
    MyInteger myint;
    cout << myint++ << endl;  
    cout << myint << endl;  
}

// C++编译器至少给—个类添加4个函数
// 1.默认构造函数(无参，函数体为空)
// 2.默认析构函数(无参，函数体为空)
// 3.默认拷贝构造函数，对属性进行值拷贝
// 4.赋值运算符operator=，对属性进行值拷贝
// 如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
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
    //重载赋值运算符
	Person3& operator=(Person3 &p){
        //m_age = p.m_age;//编译器提供的浅拷贝
        //应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
		if(m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
		m_age = new int(*p.m_age);//深拷贝 
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

//重载关系运算符 
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

//函数调用运算符重载
//函数调用运算符()也可以重载
//由于重载后使用的方式非常像函数的调用，因此称为仿函数
//仿函数没有固定写法，非常灵活
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
    
    myprint("hello world");//由于使用起来非常类似于函数调用，因此称为仿函数
    Myprint02("hello world");
}
//仿函数非常灵活，没有固定的写法
//加法类
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
    //匿名函数对象
	cout << MyAdd ()(100,100)<< endl;
}

int main(){
	test01();//加号运算符重载
    cout << endl;

    test02();//重载左移运算符
    cout << endl;

    int a = 10 ;
    cout <<++(++a)<< endl;
    cout << a << endl;
    test03();//重载递增运算符
    test04();//重载递增运算符
    cout << endl;

	int a1 = 10;
	int b1 = 20;
	int c1 = 30;
	c1 = b1 = a1;
	cout << a1 << ' ' << b1 << ' ' << c1 << ' ' << endl; 
    test05();//重载赋值运算符
    cout << endl;
    
    test06();//重载关系运算符 
    cout << endl;
    
    test07();//函数调用运算符重载
    test08();//仿函数 
    cout << endl;
    return 0;
}
