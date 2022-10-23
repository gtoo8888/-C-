#include <iostream> 
using namespace std;
#include <string>


// 浅拷贝:简单的赋值拷贝操作
// 深拷贝:在堆区重新申请空间，进行拷贝操作
class Person {
public:
	Person() {
		cout << "无参构造函数" << endl;
	}
	Person(int age ,int height) {
		cout << "有参构造函数" << endl;
		m_age = age;
		m_height = new int(height);
	}
	Person(const Person& p) {//自己实现拷贝构造函数解决浅拷贝带来的问题
		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
//		m_age = p.m_age;//编译器默认实现就是这行代码 
		m_height = new int(*p.m_height);//深拷贝操作
	}
	~Person() {
		//析构代码，将堆区开辟数据做释放操作
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
	}
	int m_age;
	int* m_height;
};
//深拷贝和浅拷贝 
void test01(){
	Person p1(18, 180);
	Person p2(p1);
	cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;
	cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
}

//初始化列表
class Person2 {
public:
	//Person2(int a, int b, int c) {
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}
	//初始化列表方式初始化
//	Person2(int a, int b, int c) :m_A(10), m_B(20), m_C(30) {}
	Person2(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
	int m_A;
	int m_B;
	int m_C;
};

void test02(){
//	Person2 p(1, 2, 3);
//	Person2 p;
	Person2 p(3, 2, 1);
	cout << "mA:" << p.m_A << endl;
	cout << "mB:" << p.m_B << endl;
	cout << "mC:" << p.m_C << endl;
}

//类对象作为类成员
//C++类中的成员可以是另一个类的对象，我们称该成员为对象成员
//B类中有对象A作为成员，A为对象成员
//那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后? 
class Phone
{
public:
	Phone(string name){
		m_PhoneName = name;
		cout << "Phone构造" << endl;
	}
	~Phone(){
		cout << "Phone析构" << endl;
	}
	string m_PhoneName;

};
class Person3{
public:
//	Phone Phone = pName隐式转换法
	Person3(string name, string pName) :m_Name(name), m_Phone(pName){
		cout << "Person构造" << endl;
	}

	~Person3(){
		cout << "Person析构" << endl;
	}
	string m_Name;
	Phone m_Phone;
};
//当其他类对象作为本类成员，构造时候先构造类对象，再构造自身，析构的顺序与构造相反
//Phone比Person3先构造
void test03()
{
	Person3 p("张三" , "苹果X");
	cout << p.m_Name << " " << p.m_Phone.m_PhoneName << endl;
}

//静态成员
//静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员
//静态成员分为:
//	
//静态成员变量
//所有对象共享同一份数据
//在编译阶段分配内存
//类内声明，类外初始化
class Person4{
public:
	static int m_a;	
//静态成员变量也是有访问权限的
private:
	static int m_b;
};
int Person4::m_a = 100;
int Person4::m_b = 200;
void test04(){
	Person4 p;
	cout << p.m_a << endl;
	Person4 p2;
	p2.m_a = 200;
	cout << p2.m_a << endl;
//	cout << p.m_b << endl;
}
//静态成员变量不属于某个对象上，所有对象都共享同一份数据
//因此静态成员变量有两种访问方式
void test05(){
	Person4 p;
	cout << p.m_a << endl;//1、通过对象进行访问
	cout << Person4::m_a << endl;//2、通过类名进行访问	
}

//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量	
class Person5{
public:
	static void func(){
		m_a = 100;//静态成员函数可以访问静态成员变量
//		m_b = 200;//静态成员函数不可以访问非静态成员变量
		//无法区分到底是哪个对象的m_b
		cout << "static void func()的调用"<<endl;
	}
	static int m_a;//静态成员变量
	int m_b;//非静态成员变量
private:
	static void func2(){
		cout << "static void func2()的调用"<<endl;
	}
};
int Person5::m_a = 0;
//静态成员函数
void test06(){
	Person5 p;
	p.func();//1、通过对象访问
	Person5::func();//2、通过类名访问	
//	Person5::func2();
}	

//成员变量和成员函数分开存储
//在C++中，类内的成员变量和成员函数分开存储
//只有非静态成员变量才属于类的对象上 
class Person6{
} ;
class Person7{
	int m_a;//非静态成员变量属于类的对象上
} ;
class Person8{
	int m_a;
	static int m_b;;//静态成员变量 不属于类对象上
	void func(){} //非静态成员函数
} ;
int Person8::m_b = 0;
//成员变量和成员函数分开存储
void test07(){
	Person6 p1;
	//空对象占用内存空间为:1
	//C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
	cout << sizeof(p1) << endl;
	Person7 p2;
	cout << sizeof(p2) << endl;
	Person8 p3;
	cout << sizeof(p3) << endl;	
}

//this指针概念
//this指针是隐含每一个非静态成员函数内的一种指针
//this指针不需要定义，直接使用即可
class Person9{
public:
	Person9(int age){
		//this指针指向被调用的成员函数所属的对象
		this -> age = age;
	}
	Person9 &Personaddage(Person9 &p) {
		this -> age += p.age;
		return *this;//this指向p2的指针，而*this指向的就是p2这个对象本体
	}
	int age;
};
//this指针的用途:
//1.解决名称冲突，当形参和成员变量同名时，可用this指针来区分
void test08(){
	Person9 p1(18);
	cout << p1.age << endl;
}
//2.在类的非静态成员函数中返回对象本身，可使用return *this
void test09(){
	Person9 p1(20);
	Person9 p2(20);
	p2.Personaddage(p1).Personaddage(p1);//链式编程思想
	cout << p2.age << endl;
}

//空指针访问成员函数
//C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
//如果用到this指针，需要加以判断保证代码的健壮性
class Person10{
public:
	void showclassname(){
		cout << "Person" << endl;
	}
	void showpersonage(){
		//报错原因是因为传入的指针是为NULL
		if(this == NULL) return;//防传入空指针搞破坏 
		cout << this -> m_age << endl;//平时写的m_age就是this->m_age
	}
	int m_age;
};

void test10(){
	Person10 *p = NULL;
	p -> showclassname();//空指针可以访问成员
	p -> showpersonage();
}

//const修饰成员函数
//常函数:
//成员函数后加const后我们称为这个函数为常函数，常函数内不可以修改成员属性
//成员属性声明时加关键字mutable后，在常函数中依然可以修改
//常对象:
//声明对象前加const称该对象为常对象
//常对象只能调用常函数
class Person11{
public:
	//this指针的本质是指针常量指针的指向是不可以修改的
	//const Person * const this;
	//在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
	void showperson() const{//常函数 
//		this -> m_a = 100;
//		this = NULL;//this指针不可以修改指针的指向的		
		this -> m_b = 100;
	}
	void func(){}
	int m_a;
	mutable int m_b;//特殊变量，即使在常函数中，也可以修改这个值,加关键字mutable
};

// void test11(){
// 	const Person1 p;//在对象前加const，变为常对象
// 	//p.m_a = 100 ;
// 	p.m_b = 100; //m_B是特殊值，在常对象下也可以修改
	
// 	//常对象只能调用常函数
// 	p.showperson() ;
// 	//p.furc();//常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
// }


int main() {
	test01();//深拷贝和浅拷贝
	cout << endl;

	test02();//初始化列表
	cout << endl;
	
	test03();//类对象作为类成员
	cout << endl;

	test04();//静态成员变量
	test05();
	cout << endl;
	
	test06();//静态成员函数
	cout << endl;
	
	test07();//成员变量和成员函数分开存储
	cout << endl;
	
	test08();//this指针概念
	test09();
	cout << endl;
	
	test10();//空指针访问成员函数
	cout << endl;

//	test11();//const修饰成员函数
//	cout << endl;
	return 0;
}


