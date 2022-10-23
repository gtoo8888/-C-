#include <iostream> 
#include <utility> 
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
	Useless & operator=(const Useless & f);	// 拷贝构造
	// Useless & opeartor=(Useless && f);	// 移动构造函数
	void showdata() const;
};

int Useless::ct = 0;

Useless::Useless(){
	++ct;
	n = 0;
	pc = nullptr;

}

Useless::Useless(int k) : n(k){
	++ct;
	pc = new char[n];
}

Useless::Useless(int k,char ch) : n(k){
	++ct;
	pc = new char[n];
	for(int i = 0;i < n;i++)
		pc[i] = ch;
}

// 复制构造函数
// 深拷贝
Useless::Useless(const Useless& f) : n(f.n) {
	++ct;
	pc = new char[n];
	for(int i = 0;i < n;i++)
		pc[i] = f.pc[i];
}

// 移动构造函数
Useless::Useless(Useless && f) : n(f.n) {
	++ct;
	pc = f.pc;	// 偷取了原来数据的地址，偷取了原来数据的所有权
	f.pc = nullptr;	// 将老地址置空，防止二次析构
	f.n = 0;
}

Useless::~Useless(){
	delete [] pc;
}

Useless & Useless::operator=(const Useless & f){	
}

// Useless & Useless::opeartor=(Useless && f){	

// }

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
	Useless one(10,'x');
	Useless two = one;	// 使用了拷贝构造函数
	one.showdata();
	two.showdata();
	Useless three,four;
	three = one;
	three.showdata();
	one.showdata();
	four = one + two;
	four.showdata();
	four = std::move(one);
	four.showdata();
	one.showdata();
	return 0;
}

