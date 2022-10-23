#include <iostream> 
#include <cstring> 
using namespace std;


class Action{
	int a;
public:
	Action(int i = 0) : a(i) {};
	int val() const {return a;};
	virtual void f(char ch) const{
		cout << val() << ch << endl;
	}
};

class Bingo : public Action{
public:
	Bingo(int i = 0) : Action(i){}
	virtual void f(char* ch) const{	
		// 如果下面变成了char* 会直接覆盖掉上面上的虚方法
		cout << val() << ch << endl;
	}
};



class Action1{
	int a;
public:
	Action1(int i = 0) : a(i) {};
	int val() const {return a;};
	virtual void f(char ch) const {
		cout << val() << ch << endl;
	}
};

class Bingo1 : public Action1{
public:
	Bingo1(int i = 0) : Action1(i){}
	// virtual void f(char* ch) const override{// 因为加上override报错了
	virtual void f(char ch) const override{// 只有和上面一样才不报错
		// override 在子类中使用,在写虚方法的时候可以加上这个
		// 就是在重写虚方法的时候，写错了，直接让编译器提示写错了
		// 虚说明符override指出要覆盖一个虚函数，如果声明的方法和基类的方法不匹配，那就直接报错
		cout << val() << ch << endl;
	}
};



class Action2{
public:
	virtual void print(void) {
		cout << "!!!" << endl;
	}
};

class Bingo2 : public Action2{
public:
	virtual void print(void) {
		cout << "Bingo2 !!!" << endl;
	}
};

// class Bingo3 : public Action2{
// public:
// 	virtual void Print(void) {	// Print和基类对比写错了
// 		cout << "Bingo3 !!!" << endl;
// 	}
// };

class Bingo3 : public Action2{
public:
	// virtual void Print(void) override{	// 有了override会提示基类中没有这个方法
	virtual void print(void) override{	// 有了override会提示基类中没有这个方法
		cout << "Bingo3 !!!" << endl;
	}
};

int main(void){
	Bingo b(10);
	// b.f('@');


	Bingo2 bingo2;
	bingo2.print();
	Bingo3 bingo3;
	bingo3.print();	// 其实想调用自己重写的虚方法，但是由于打错了，所以就没法用了
	return 0;
}

