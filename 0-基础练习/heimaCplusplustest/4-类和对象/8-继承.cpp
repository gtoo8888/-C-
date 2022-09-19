#include <iostream>
using namespace std;
// 我们发现，定义这些类时，下级别的成员除了拥有上一级的共性，还有自己的特性。
// 这个时候我们就可以考虑利用继承的技术，减少重复代码
class Java{
public:
    void header(){
        cout << "header" << endl;
    }
    void footer(){
        cout << "footer" << endl;
    }
    void left(){
        cout << "left" << endl;
    }
    void content(){
        cout << "JAVA" << endl;
    }
};

class Python{
public:
    void header(){
        cout << "header" << endl;
    }
    void footer(){
        cout << "footer" << endl;
    }
    void left(){
        cout << "left" << endl;
    }
    void content(){
        cout << "Python" << endl;
    }
};

class CPP{
public:
    void header(){
        cout << "header" << endl;
    }
    void footer(){
        cout << "footer" << endl;
    }
    void left(){
        cout << "left" << endl;
    }
    void content(){
        cout << "CPP" << endl;
    }
};

void test01(){
    cout << "java page" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();

    cout << "---------------------" << endl;
    cout << "Python page" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();

    cout << "---------------------" << endl;
    cout << "CPP page" << endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}

class BasePage{
public:
    void header(){
        cout << "header" << endl;
    }
    void footer(){
        cout << "footer" << endl;
    }
    void left(){
        cout << "left" << endl;
    } 
};

// 我们发现，定义这些类时，下级别的成员除了拥有上一级的共性，还有自己的特性。
// 这个时候我们就可以考虑利用继承的技术，减少重复代码5
//继承的好处: 减少重复代码
//语法: class 子类:继承方式 父类
//子类 也称为 派生类
//父类 也称为基类

class Java2:public BasePage{
public:
    void content(){
        cout << "Java2" << endl;
    }
};
class Python2:public BasePage{
public:
    void content(){
        cout << "python2" << endl;
    }
};
class CPP2:public BasePage{
public:
    void content(){
        cout << "CPP2" << endl;
    }
};

void test02(){
    cout << "java page" << endl;
    Java2 ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();

    cout << "---------------------" << endl;
    cout << "Python page" << endl;
    Python2 py;
    py.header();
    py.footer();
    py.left();
    py.content();

    cout << "---------------------" << endl;
    cout << "CPP page" << endl;
    CPP2 cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}

//继承方式一共有三种:
class Base1{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;		
};
//公共继承
class Son1:public Base1{
public:
	void func(){
		m_a = 10;//父类中的公共权限成员到 子类中依然是公共权限
		m_b = 10;//父类中的保护权限成员到 子类中依然是保护权限;
//		m_c = 10;//父类中的私有权限成员 子类访问不到
	}
};
//保护继承
class Son2:protected Base1{
public:
	void func(){
		m_a = 10;//父类中公共成员，到子类中变为保护权限
		m_b = 10;//父类中保护成员，到子类中变为保护权限
//		m_c = 10;//父类中的私有权限成员 子类访问不到
	}
};
//私有继承
class Son3:private Base1{
public:
	void func(){
		m_a = 10;//父类中公共成员，到子类中变为私有权限
		m_b = 10;//父类中保护成员，到子类中变为私有权限
//		m_c = 10;//父类中的私有权限成员 子类访问不到
	}
};
class GrandSon3:public Son3{
public:
	void func(){
//		m_a = 1000;
//		m_b = 1000;
	}
};

void test03(){
	Son1 s1;
	s1.m_a = 100;
	//s1.m_b = 100;//到Son1中m_B是保护权限类外访问不到
	
	Son2 s2;
	//s2.m_a = 1000;//在Son2中 m_A变为保护权限﹐因此类外访问不到
	//s2.m_b = 1000;//在Son2中 m_B保护权限不可以访问

	Son2 s3;
	//s3.m_a = 1000;//在Son3中 m_A变为私有成员 类外不可以访问
	//s3.m_b = 1000;//在Son3中 m_B变为私有成员 类外不可以访问
} 

//子类继承父类后，当创建子类对象，也会调用父类的构造函数
//问题:父类和子类的构造和析构顺序是谁先谁后?
class Base2{
public:
	Base2(){
		cout << "Base2 的构造函数" << endl; 
	}
	~Base2(){
		cout << "Base2 的析构函数" << endl; 
	}
};

class Son10:public Base2{
public:
	Son10(){
		cout << "Son10 的构造函数" << endl; 
	}
	~Son10(){
		cout << "Son10 的析构函数" << endl; 
	}
};
void test04(){
	//继承中的构造和析构顺序如下:
	//先构造父类，再构造子类,析构的顺序与构造的顺序相反
	Base2 b; 
	cout << endl;
	Son10 s;
} 


//继承同名成员处理方式
//问题:当子类与类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢?
//访问子类同名成员直接访问即可
//访问父类同名成员需要加作用域
class Base3{
public:
	Base3(){
		m_a = 100;
	}
	void func(){
		cout << "Base3 - func()调用" << endl; 
	}
	void func(int a){
		cout << "Base3 - func(int a)调用" << endl; 
	}
	int m_a;
};
class Son20 :public Base3{
public:
	Son20(){
		m_a = 200;
	}
	void func(){
		cout << "Son - func()调用" << endl; 
	}
	int m_a;
};

void test05(){
	Son20 s;
	cout << s.m_a << endl;
	cout << s.Base3::m_a << endl;//如果通过子类对象访问到父类中同名成员，需要加作用域
} 
void test06(){
	Son20 s;
	s.func();//直接调用调用是子类中的同名成员
	s.Base3::func();//如何调用到父类中同名成员函数?
	//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
	//如果想访问到父类中被隐藏的同名成员函数，需要加作用域
	s.Base3::func(100);
} 
//总结:
//1.子类对象可以直接访问到子类中同名成员
//2.子类对象加作用域可以访问到父类同名成员
//3.当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数


//继承同名静态成员处理方式
//问题:继承中同名的静态成员在子类对象上如何进行访问?
//静态成员和非静态成员出现同名，处理方式一致
//访问子类同名成员直接访问即可
//访问父类同名成员需要加作用域
class Base4{
public:
	static int m_a;
	
	static void func(){
		cout << "Base4 - static void func()" << endl;
	} 
	static void func(int a){
		cout << "Base4 - static void func(int a)" << endl;
	} 
};
int Base4::m_a = 100;

class Son30:public Base4{
public:
	static int m_a;
	
	static void func(){
		cout << "Son30 - static void func()" << endl;
	}
};
int Son30::m_a = 200;

void test07(){
	cout <<"通过对象访问:"<< endl;
	Son30 s;
	cout << "Son30 下m_a = " << s.m_a << endl;
	cout << "Base4  下m_a = " << s.Base4::m_a << endl;
	
	cout <<"通过类名访问:" << endl;
	cout << "Son30 下m_A = "  << Son30::m_a << endl ;
	//第一个::代表通过类名方式访问 第二个::代表访问父类作用域下
	cout << "Base4 下 m_A = " << Son30::Base4::m_a<< endl;	
} 

void test08(){
	cout <<"通过对象访问:"<< endl;		
	Son30 s;
	s.func();
	s.Base4::func();
	
	cout <<"通过类名访问:" << endl;
	Son30::func();
	Son30::Base4::func();
	//子类出现和父类同名静态成员函数，也会隐藏父类中所有同名成员函数
	//如果想访问父类中被隐藏同名成员，需要加作用域[
	Son30::Base4::func(10);
}
//总结:同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式(通过对象和通过类名)

//多继承语法
//C++允许一个类继承多个类
//多继承可能会引发父类中有同名成员出现，需要加作用域区分
//C++实际开发中不建议用多继承
class Base5{
public:
	Base5(){
		m_a = 100;
	}
	int m_a;
};

class Base6{
public:
	Base6(){
		m_a = 200;
	}
	int m_a;
};

//子类需要继承Base1和Base2 I
//语法:class子类 : 继承方式 父类1,继承方式 父类2 ..... 
class Son40:public Base5,public Base6{
public:
	Son40(){
		m_c = 300;
		m_d = 400;
	}
	int m_c;
	int m_d;
};

void test09(){
	Son40 s;
	cout << sizeof(s) << endl;
	//当父类中出现同名成员，需要加作用域区分
	cout << s.Base5::m_a << endl;
	cout << s.Base6::m_a << endl;
}

//菱形继承概念:
//两个派生类继承同一个基类
//又有某个类同时继承者两个派生类
//这种继承被称为菱形继承，或者钻石继承


int main(){
    test01();
    cout << endl;

    test02();
    cout << endl;
    
    test03();
    cout << endl;
    
    test04();
    cout << endl;
    
    test05();
    test06();
    cout << endl;
    
    test07();
    test08();
    cout << endl;
    
    test09();
    cout << endl;
    return 0;
}



















