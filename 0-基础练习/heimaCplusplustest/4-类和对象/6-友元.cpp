#include <iostream> 
using namespace std;
#include <string>

// 在程序里，有些私有属性也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术
// 友元的目的就是让一个函数或者类访问另一个类中私有成员
// 友元的关键字为friend
// 友元的三种实现
// 1.全局函数做友元
// 2.类做友元
// 3.成员函数做友元

// 1.全局函数做友元
class Building{
	//goodGay全局函数是Building好朋友， 可以访问Building中私有成员
	friend void GoodGay(Building *building);
public:
	Building(){
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom;
private:
	string m_BedRoom; 
};
void GoodGay(Building *building){
	cout << building -> m_SittingRoom << endl;
	cout << building -> m_BedRoom << endl;
}
void test01(){
	Building building;
	GoodGay(&building);
}

// 2.类做友元
class Building1;
class GoodGay2{
public:
	GoodGay2();
	void visit(); //参观函数访问Building中的属性
	Building1 *building1;
};
class Building1{
	//GoodGay类是本来的好朋友，可以访问本类中私有成员
	friend class GoodGay2;
public:
	Building1();//类外写成员函数
public:
	string m_SittingRoom;
private:
	string m_BedRoom; 
};
//类外写成员函数
Building1::Building1(){
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
GoodGay2::GoodGay2(){
	building1 = new Building1;//在堆区创建一个对象
}
void GoodGay2::visit(){
	cout << building1 -> m_SittingRoom << endl;
	cout << building1 -> m_BedRoom << endl;
}
void test02(){
	GoodGay2 gg;
	gg.visit();
}

// 3.成员函数做友元
class Building2;
class GoodGay3{
public:
	GoodGay3();
	void visit(); //让visit函数可以访问Building中私有成员
	void visit2(); //让visit2函数不可以访问Building中私有成员

	Building2 *building2;
};
class Building2{
	//告诉编译器GoodGay类 下的visit成员函数作为本类的好朋友，可以访问私有成员
	friend void GoodGay3::visit();
public:
	Building2();
public:
	string m_SittingRoom;
private:
	string m_BedRoom; 
};
Building2::Building2(){
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";	
}
GoodGay3::GoodGay3(){
	building2 = new Building2;
}
void GoodGay3::visit(){
	cout << building2 -> m_SittingRoom << endl;
	cout << building2 -> m_BedRoom << endl;	
}
void GoodGay3::visit2(){
	cout << building2 -> m_SittingRoom << endl;
	// cout << building2 -> m_BedRoom << endl;
}
void test03(){
	GoodGay3 gg;
	gg.visit();
	gg.visit2();
}


int main(){
	test01();// 1.全局函数做友元
	test02();// 2.类做友元
	test03();// 3.成员函数做友元
	return 0;
}
