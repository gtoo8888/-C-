#include <iostream> 
#include <memory>
using namespace std;

template <typename T>
class Node{
public:
	Node(const T& value) : _pPre(NULL) , _value(value) {
		cout << "Node()" << endl;
	}
	
	~Node(){
		cout << "~Node()" << endl;
		cout << "this:" << this <<endl;
	}
	
	shared_ptr<Node<T>> _pPre;
	shared_ptr<Node<T>> _pNext;
	T _value;
};

void show_ptr(shared_ptr<Node<int>> sp1, shared_ptr<Node<int>> sp2){
	printf("sp1--value:%d count:%d\n", sp1->_value, sp1.use_count());
	printf("sp2--value:%d count:%d\n", sp2->_value, sp2.use_count());
}

void Funtest(){
	shared_ptr<Node<int>> sp1(new Node<int>(10));
	shared_ptr<Node<int>> sp2(new Node<int>(20));
	
	show_ptr(sp1, sp2);
	
	// sp1->_pNext = sp2;//没有互相指向，就可以调用析构了 
	sp2->_pPre = sp1;
	
	show_ptr(sp1, sp2);

	sp1.swap(sp2); //交换两个智能指针的指向
	show_ptr(sp1, sp2);

	sp1.unique();//判断是否是唯一的指针，如果是，返回true，否则返回false
	cout << sp1.unique() << endl;
}

int main(){
	Funtest();
	return 0;
}
