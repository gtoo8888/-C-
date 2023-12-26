#include <stdio.h>
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

void show_ptr(shared_ptr<int> sp1){
	printf("value:%d count:%d\n", *sp1, sp1.use_count());
}

void test_use_count(){
	shared_ptr<int> sp1(new int(11));
	
	show_ptr(sp1);
	shared_ptr<int> sp2;
	sp2 = sp1;
	show_ptr(sp2);
	
	shared_ptr<int> sp3;
	sp3 = sp1;
	show_ptr(sp3);
	show_ptr(sp1);
	
	printf("----------%s:%d\n\n",__func__,__LINE__);
}

void test_swap(){
	shared_ptr<int> sp1 = make_shared<int>(10);
	shared_ptr<int> sp2 = make_shared<int>(20);

	show_ptr(sp1);show_ptr(sp2);
	sp1.swap(sp2);
	show_ptr(sp1);show_ptr(sp2);
	printf("----------%s:%d\n\n",__func__,__LINE__);
}

void test_reset(){
	shared_ptr<int> sp1 = make_shared<int>(10);
	shared_ptr<int> sp2;
	sp2 = sp1;
	shared_ptr<int> sp3 = sp2;

	show_ptr(sp1);show_ptr(sp2);show_ptr(sp3);

	sp1.reset(new int(20));// ���������¶���Ȼ�����ü�����1�����ü���Ϊ0��������Person(1)
                        	// ����¶����ָ�뽻������ָ��
	show_ptr(sp1);show_ptr(sp2);show_ptr(sp3);



	shared_ptr<int> sp10 = make_shared<int>(10);
	show_ptr(sp10);
	sp10.reset();
	// show_ptr(sp10);

	printf("----------%s:%d\n\n",__func__,__LINE__);
}

void test_get(){
	shared_ptr<int> sp1 = make_shared<int>(10);
	int* ans = sp1.get(); // get()����ԭʼָ��
	show_ptr(sp1);
	printf("ans:%d\n", *ans);
	printf("----------%s:%d\n\n",__func__,__LINE__);
}

void test_unique(){
	// C++17��������
	shared_ptr<int> sp1 = make_shared<int>(10);
   	if (sp1.unique()) { // �ж��Ƿ���Ψһ��ָ�룬����ǣ�����true�����򷵻�false
        sp1.reset();
    } else {
        
    }
	printf("----------%s:%d\n\n",__func__,__LINE__);
}

int main(){
	test_use_count();
	test_swap();
	test_reset();
	test_get();
	test_unique();

	return 0;
}
