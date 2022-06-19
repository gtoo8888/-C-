#include <string>
#include <iostream>
 
using namespace std;
 
template <typename T>
class Sharedptr {
public:
	//空参数构造， 空指针
	Sharedptr():count(0), ptr((T*) 0){}
	//构造函数 count 必须new出来
	Sharedptr(T* p) : count(new int(1)), ptr(p){}
	//拷贝构造函数，使其引用次数加一
	Sharedptr(Sharedptr<T>& other) : count(&(++ *other.count)), ptr(other.ptr){}
	//重载operator*和operator->实现指针功能
	T* operator->() { return ptr;}
	T& operator*() { return *ptr; }
	//重载operator =
	//如果原来的sharedptr已经有对象，则让其引用对象次数减一并判断引用是否为零（是否调用delete),然后将新的引用对象次数加一
	Sharedptr<T>& operator = (Sharedptr<T>& other) {
		if (this == &other) return *this;
		++* other.count;
		if (this->ptr && 0 == -- * this->count) {
			delete count;
			delete ptr;
			cout << "delete ptr =" << endl;
		}
		this->ptr = other.ptr;
		this->count = other.count;
		return *this;
	}
	//析构函数 使用引用次数减一并判断引用是否为零，即是否调用delete
	~Sharedptr() {
		if (ptr && -- * count == 0) {
			delete count;
			delete ptr;
			cout << "delete ptr ~" << endl;
		}
	}
	int getRef() {
		return *count;
	}
private:
	int* count;
	T* ptr;
};
 
int main(int argc, const char* argv[]) {
	Sharedptr<string> pstr(new string("abc"));
	cout << "pstr:" << pstr.getRef() << " " << *pstr << endl;
 
	Sharedptr<string> pstr2(pstr);
	cout << "pstr:" << pstr.getRef() << " " << *pstr << endl;
	cout << "pstr2:" << pstr2.getRef() << " " << *pstr2 << endl;
 
	Sharedptr<string> pstr3(new string("hao"));
	cout << "pstr3:" << pstr3.getRef() << " " << *pstr3 << endl;
	
	pstr3 = pstr2;
	cout << "pstr:" << pstr.getRef() << " " << * pstr << endl;
	cout << "pstr2:" << pstr2.getRef() << " " << *pstr2 << endl;
	cout << "pstr3:" << pstr3.getRef() << " " << *pstr3 << endl;
 
	return 0;
}
