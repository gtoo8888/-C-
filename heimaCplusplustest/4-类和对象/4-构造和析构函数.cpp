#include<iostream> 
using namespace std;

//构造函数:进行初始化操作
//析构函数:进行清理操作 

//构造函数语法:
//1.构造函数，没有返回值也不写void
//2.函数名称与类名相同
//3.构造函数可以有参数，因此可以发生重载
//4.程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次

//析构函数语法:
//1.析构函数，没有返回值也不写void
//2函数名称与类名相同,在名称前加上符号~
//3.析构函数不可以有参数，因此不可以发生重载
//4.程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用—次

class Person{
public://需要设为公共，外面才能访问的到 
	Person()//构造函数，不需要void 
	{
		cout << "Person 构造函数的调用" << endl;
		//不写具体内容，编译器也会给一个，但是是空函数 
	} 
	~Person()//析构函数 
	{
		cout << "Person 析构函数的调用" << endl;
	} 
};


//构造和析构都是必须有的实现，自己不写，编译器会提供空实现 
void test01(){
	Person p;//仅仅创建对象，就会调用构造函数
	//在栈上的数据，test01执行完毕后，释放这个对象 
}

//构造函数的分类
//按参数分为:有参构造和无参构造（默认构造） 
//按类型分为:普通构造和拷贝构造
class Person2{
public:
	Person2()//无参构造 （默认构造） 
	{
		cout << "Person 的无参构造函数调用"  << endl; 
	}
	Person2(int a)//有参构造 
	{
		age = a;
		cout << "Person 的有参构造函数调用"  << endl; 
	}
	//拷贝构造，除了拷贝构造，都是普通构造
	Person2(const Person2 &test)//拷贝构造，把原来的类一模一样的构造一份 
	//用const因为传入的类不应该受到改变 
	{
		age = test.age;//将传入的人身上的所有属性，拷贝到我身上
		cout << "Person 的拷贝构造函数调用"  << endl; 
	}
	
	~Person2()
	{
		cout << "析构函数"  << endl; 
	}
	
	int age; 
}; 

//三种调用方式:
//括号法
//显示法
//隐式转换法
void test02(){
	//括号法 
	Person2 p1;//默认构造函数调用 
	Person2 p2(10);//有参构造函数的调用 
	Person2 p3(p2);//拷贝构造函数的调用，将已经创建的传进来 
	cout << p2.age << endl; 
	cout << p3.age << endl; 
	//注意事项1
	//调用默认构造函数时候，不要加()
	//因为下面这行代码，编译器会认为是一个函数的声明,不会认为在创建对象 
	Person2 p4();

	//显示法 
	Person2 p5;//默认构造函数调用 
	Person2 p6 = Person2(10);//有参构造函数的调用，传入了整型
	Person2 p7 = Person2(p6);//拷贝构造函数的调用
	
	Person2(10);//匿名对象，单独拿出来没有名字，放在等号右侧，左侧就是他的名字 
	//匿名对象特点:当前行执行结束后，系统会立即回收掉匿名对象
	cout << "aaaaaa" << endl;
	
	//注意事项2
	//不要利用拷贝构造函数初始化匿名对象 编译器会认为Person (p3) === Person p3;会视为对象的声明 
	//Person (p7);

	//隐式转换法
	//3、隐式转换法
	Person2 p8 = 10;//有参构造函数的调用,当于写了Person p4 = Person(10)
	Person2 p9 = p8;//拷贝构造函数的调用
} 

// C++中拷贝构造函数调用时机通常有三种情况
class Person3{
public:
	Person3(){
		cout << "Person 的默认构造函数调用"  << endl; 
	}
	Person3(int a){
		age = a;
		cout << "Person 的有参构造函数调用"  << endl; 
	}
	Person3(const Person3 &p){
		cout << "Person 的拷贝构造函数调用"  << endl; 
		age = p.age;
	}
	~Person3(){
		cout << "Person 的析构函数调用"  << endl; 
	}
	int age; 
};

// 1.使用一个已经创建完毕的对象来初始化一个新对象
void test03(){
	Person3 p1(20);
	Person3 p2(p1);
	cout << p2.age << endl;
}
// 2.值传递的方式给函数参数传值
void doWork(Person3 p){
}
void test04(){
	Person3 p;
	doWork(p);//应用了值传递
}
// 3.以值方式返回局部对象
Person3 doWork2(){
	Person3 p1;
	cout << (int*)&p1 << endl;
	return p1;
}
void test05(){
	Person3 p = doWork2();
	cout << (int*)&p << endl;
}

// 构造函数调用规则
// 默认情况下，C++编译器至少给一个类添加3个函数
// 默认构造函数(无参，函数体为空)
// 默认析构函数(无参，函数体为空)
// 默认拷贝构造函数(对属性进行值拷贝)
class Person4{
public:
	// Person4(){
	// 	cout << "Person 的默认构造函数调用"  << endl;
	// }
	Person4(int a){
		age = a;
		cout << "Person 的有参构造函数调用"  << endl;
	}
	// Person4(const Person3 &p){
	// 	cout << "Person 的拷贝构造函数调用"  << endl; 
	// 	age = p.age;
	// }
	~Person4(){
		cout << "Person 的析构函数调用"  << endl;
	}
	int age;
};

// 构造函数调用规则如下:
// // 1.默认情况下，C++编译器至少给一个类添加3个函数
// void test06(){
// 	Person4 p;
// 	p.age = 18;
//
// 	Person4 p2(p);//在没有拷贝构造的情况下，依然会有默认的拷贝构造
// 	cout << p2.age << endl;
// }

// 2.如果用户定义有参构造函数 C++不在提供默认无参构造，但是会提供默认拷贝构造
void test07(){
	Person4 p(18);
	Person4 p2(p);
	cout << p2.age << endl;
}

// 3.如果用户定义拷贝构造函数，C++不会再提供其他构造函数
class Person5{
public:
	// Person4(){
	// 	cout << "Person 的默认构造函数调用"  << endl;
	// }
	// Person4(int a){
	// 	age = a;
	// 	cout << "Person 的有参构造函数调用"  << endl;
	// }
	Person5(const Person3 &p){
		cout << "Person 的拷贝构造函数调用"  << endl; 
		age = p.age;
	}

	~Person5(){
		cout << "Person 的析构函数调用"  << endl;
	}
	int age;
};
// void test08(){
// 	Person5 p;
// }

int main(){
	test01();	
	Person p;//主函数中，程序没有结束运行，就不会运行析构函数 
	system("pause");
	
	test02();
	system("pause");	

	test03();// 1.使用一个已经创建完毕的对象来初始化一个新对象
	cout << '\n' << endl;
	test04();// 2.值传递的方式给函数参数传值
	cout << '\n' << endl;
	test05();// 3.以值方式返回局部对象
	system("pause");

	// test06();//1.默认情况下，C++编译器至少给一个类添加3个函数
	test07();//2.如果用户定义有参构造函数 C++不在提供默认无参构造，但是会提供默认拷贝构造
	// test08();//3.如果用户定义拷贝构造函数，C++不会再提供其他构造函数

	return 0;
}


