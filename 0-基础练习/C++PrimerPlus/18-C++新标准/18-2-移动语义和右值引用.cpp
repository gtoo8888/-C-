#include <iostream> 
using namespace std;

class Useless{
private:
	int n;
	char* pc;
	static int ct;
	void showobject() const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k,char cn);
	Useless(const Useless& f);
	Useless(Useless && f);
	~Useless();
	Useless operator+(const Useless & f) const;
	void showdata() const;
};

int Useless::ct = 0;

Useless::Useless(){
	++ct;
	n = 0;
	pc = nullptr;
	cout << "默认构造函数，object的数量：" << ct << endl;
	showobject();
}

Useless::Useless(int k) : n(k){
	++ct;
	cout << "有参构造函数(int k)，object的数量：" << ct << endl;
	pc = new char[n];
	showobject();
}

Useless::Useless(int k,char ch) : n(k){
	++ct;
	cout << "有参构造函数(int k,char cn)，object的数量：" << ct << endl;
	pc = new char[n];
	for(int i = 0;i < n;i++)
		pc[i] = ch;
	showobject();
}

// 复制构造函数
// 深拷贝
Useless::Useless(const Useless& f) : n(f.n) {
	++ct;
	cout << "拷贝构造函数(const Useless& f)，object的数量：" << ct << endl;
	pc = new char[n];
	for(int i = 0;i < n;i++)
		pc[i] = f.pc[i];
	showobject();
}

// 移动构造函数
Useless::Useless(Useless && f) : n(f.n) {
	++ct;
	cout << "移动构造函数，object的数量：" << ct << endl;
	pc = f.pc;	// 偷取了原来数据的地址，偷取了原来数据的所有权
	f.pc = nullptr;	// 将老地址置空，防止二次析构
	f.n = 0;
	showobject();
}

Useless::~Useless(){
	cout << "析构函数，object的数量：" << --ct << endl;
	showobject();
	delete [] pc;
}

Useless Useless::operator+(const Useless & f) const{	
	cout << "Entering operator+" << endl;
	Useless temp = Useless(n+f.n);
	for(int i = 0;i < n;i++)
		temp.pc[i] = pc[i];
	for(int i = n;i < temp.n;i++)
		temp.pc[i] = f.pc[i-n];
	cout << "Leaving operator+" << endl;
	return temp;
}

void Useless::showobject() const{
	cout << n << " " << (void*)pc << endl;
}

void Useless::showdata() const{
	if(n == 0)
		cout << "empty";
	else
		for(int i = 0;i < n;i++)
			cout << pc[i];
	cout << endl;
}


int main(void){
	// C++11只会创建4个对象
	Useless one(10,'x');
	Useless two = one;	// 使用了拷贝构造函数
	Useless three(20,'o');
	Useless four(one+three);	// 使用了移动构造函数
	one.showdata();
	two.showdata();
	three.showdata();
	four.showdata();
	return 0;
}

