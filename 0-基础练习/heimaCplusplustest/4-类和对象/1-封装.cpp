#include<iostream> 
using namespace std;
#include <string>

const double PI = 3.14;

//class 代表设计一个类，类后面紧跟着类名称 
class Circle
{
	//访问权限
	//公共权限 
public:	
	//属性，变量 
	int m_r;
	//行为，函数
	double cal()
	{
		return 2 * PI * m_r;
	} 
};

//设计一个学生类，属性有姓名和学号，
//可以给姓名和学号赋值，可以显示学生的姓名和学号
class Student
{
public:
	//类中的 属性和行为，统一称为 成员 
	//属性称为 成员属性、成员变量 
	string m_name;
	string m_ID;
	
	//行为称为 成员函数、成员方法 
	void ShowStudent()
	{
		cout << m_name << " " << m_ID << endl;
	}
	
	//通过行为对属性进行赋值 
	void setName(string name)		
	{
		m_name = name;
	}
	void setID(string ID)
	{
		m_ID = ID;
	}
};

//封装意义二:
//类在设计时，可以把属性和行为放在不同的权限下，加以控制访问权限有三种
//访问权限： 
//1.public 公共权限              成员 类内可以访问 类外可以访问 
//2. protected 保护权限          成员 类内可以访问 类外不可以访问 儿子可以访问父亲中的保护内容    
//3. private私有权限			 成员 类内可以访问 类外不可以访问 儿子不可以访问父亲中的保护内容    
//后两个在学习继承的时候可以体会到区别 
class Person
{
public://公有权限 
	string m_Name;
protected://保护权限 
	string m_Car;
private://私有权限 
	int m_Password;	
private://成员函数也可以设置为私有或者公有 
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机"; 
		m_Password = 123456; 
	} 
}; 

//struct和class区别
//struct默认权限是 公共 public
//class 默认权限是 私有 privateci 
class C1
{
	int m_A; //默认权限 私有 
};
struct C2
{
	int m_A;//默认权限 公有 
};


//成员属性设置为私有
//优点1∶将所有成员属性设置为私有，可以自己控制读写权限
//优点2:对于写权限，我们可以检测数据的有效性
class Person2
{
//把成员变量设置为私有，通过公有的函数接口来进行访问 
public:
	void setName(string name) 
	{
		m_Name = name;
	}
	string getName()
	{
		return m_Name;
	}
	int getAge()//可写 
	{
//		m_Age = 20;
		return m_Age;
	}
	void setAge(int age)//可读可写，如果想修改，范围在（0-150） 
	{
		if(age < 0 || age > 150)
		{
			m_Age = 0; 
			cout << "你这个老妖精" << endl;
			return; //设置失败直接返回 
		}
		m_Age = age;
	}
	void setLover(string lover)
	{
		m_Lover = lover;
	}
private:
	string m_Name;		//姓名 可读可写 
	int m_Age;			//年龄 只读 
	string m_Lover;		//情人 只读 
} ;


int main(){
	
	Circle c1;//实例化（通过类创建一个具体的对象)
	c1.m_r = 10;//给类的对象进行赋值 	
	cout << c1.cal() << endl;//调用函数的行为 
	
	Student s1;
	s1.m_name = "yan";
	s1.m_ID = "210321041670";
	s1.ShowStudent();
	s1.setName("luo");
	s1.ShowStudent();
	
	Person p1;	
	p1.m_Name = "李四";
//	p1.m_Car = "奔驰";
//	p1.m_Password = 123; 
//	p1.func();		
	
	C1 c11;
	//c11.m_A = 100;
	C2 c22;
	c22.m_A = 100;
	cout << '\n' << endl;
	
	Person2 p2;
	p2.setName("张三");
	cout << p2.getName() << endl;
	cout << p2.getAge() << endl;
//	p2.m_Age = 18;
//	p2.setAge(18);
	p2.setLover("苍井"); 
//	cout << p2.getLover() << endl;
	p2.setAge(1000);
	cout << p2.getAge() << endl;
	p2.setAge(40);
	cout << p2.getAge() << endl;

	return 0;
}


