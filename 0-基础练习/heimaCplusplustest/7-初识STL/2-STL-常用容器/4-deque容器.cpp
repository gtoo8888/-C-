#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>
//deque容器:双端数组，可以对头端进行插入删除操作
// deque与vector区别:
// vector对于头部的插入 删除效率低，数据量越大，效率越低
// deque相对而言, 对头部的插入删除速度回比vector快
// vector访问元素时的速度会比deque快，这和两者内部实现有关

// deque内部工作原理:
// 内部有一个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
// 中控器维护的是每个缓冲区的地址,使得使用deque时像一片连续的内存空间
// deque容器的迭代器也是支持随机访问的

// deque<T>deqT;//默认构造形式
// deque(beg，end);//构造函数将[beg, end)区间中的元素拷贝给本身。
// deque(n, elem);//构造函数将n个elem拷贝给本身
// deque(const deque &deq);| //拷贝构造函数

void printDeque(deque<int> &d){//为了防止这个容器被修改，作为只读来使用
    for(deque<int>::const_iterator it = d.begin();it != d.end();it++)
        cout << *it << " ";//容器中的数据不可以被修改了
    cout << endl;
}
//构造函数 
void test01(){
    deque<int>d1;
    for(int i = 0;i < 10;i++)
        d1.push_back(i);
    printDeque(d1);

    deque<int>d2(d1.begin(),d1.end());
    printDeque(d2);

    deque<int>d3(10,100);
    printDeque(d3);

    deque<int>d4(d3);
    printDeque(d4);
}

//deque赋值操作
void test02(){
    deque<int>d1;
    for(int i = 0;i < 10;i++)
    	d1.push_back(i);
    printDeque(d1);
    
    deque<int>d2;
    d2 = d1;
    printDeque(d2);
    
    deque<int>d3;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);
    
    deque<int>d4;
    d4.assign(10,100);
    printDeque(d4);  
}

//deque大小操作
//deque.empty( );//判断容器是否为空
//deque.size();//返回容器中元素的个数
//deque.resize(num ) ;//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。//如果容器变短，则末尾超出容器长度的元素被删除。
//deque.resize(num，elem);//重新指定容器的长度为num,若容器变长，则以elem值填充新位置。//如果容器变短，则末尾超出容器长度的元素被删除。
void test03(){
    deque<int>d1;
    for(int i = 0;i < 10;i++)
    	d1.push_back(i);
    printDeque(d1);
	
	if(d1.empty())    
		cout << "YES" << endl;
	else{
		cout << "NO" << endl;
		cout << d1.size() << endl;
		// deque容器没有容量概念
	}
	d1.resize(15,1);
    printDeque(d1);	

	d1.resize(5);
    printDeque(d1);	
}

//deque插入和删除
//两端插入操作:
//push_back(elem);//在容器尾部添加一个数据
//push_front(elem) ;//在容器头部插入一个数据
//pop_back();//删除容器最后一个数据
//pop_front();//删除容器第一个数据
//指定位置操作:
//insert(pos ,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
//insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
//insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
//clear();//清空容器的所有数据
//erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
//erase(pos);//删除pos位置的数据，返回下一个数据的位置。

//两端操作
void test04(){
    deque<int>d1;
    
    d1.push_back(10);//尾插 
    d1.push_back(20);
    
    d1.push_front(100);//头插 
    d1.push_front(200);
    printDeque(d1);	
    
    d1.pop_back();//尾删 
	printDeque(d1);	 
	
	d1.pop_front();//头删 
	printDeque(d1);	
}
//指定位置操作
void test05(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);	

	d1.insert(d1.begin(),1000) ;//insert插入
	printDeque(d1);	
	
	d1.insert(d1.begin(),2,10000);
	printDeque(d1);	
	
	deque<int>d2;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);	
    
    d1.insert(d1.begin(),d2.begin(),d2.end());
    printDeque(d1);	
}
//删除操作 
void test06(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    
    deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);	

	d1.erase(d1.begin(),d1.end());//按区间方式删除
//	d1.clear();
	printDeque(d1);	
}

//deque数据存取
//at(int idx);//返回索引idx所指的数据
//operator[];//返回索引idx所指的数据
//front();//返回容器中第一个数据元素
//back();//返回容器中最后一个数据元素
void test07(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
    
    for(int i = 0;i < d1.size();i++)
    	cout << d1[i] << " ";
    cout << endl;

    for(int i = 0;i < d1.size();i++)
    	cout << d1.at(i) << " ";
    cout << endl;
    
    cout << d1.front() << endl;
    cout << d1.back() << endl;
}

//deque排序
//sort(iterator beg, iterator end); //对beg和end区间内元素进行排序
void test08(){
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
	printDeque(d1);	
	
	//排序默认排序规则从小到大升序
	//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
	//vector容器也可以利用sort进行排序
	sort(d1.begin(),d1.end());
	printDeque(d1);   
}

int main(){
    test01();//构造函数
    cout << endl;
    
    test02();//deque赋值操作
    cout << endl;
    
    test03();//deque大小操作
    cout << endl;
    
    test04();//两端插入 
    test05();//指定位置插入 
    test06();//删除操作 
    cout << endl;
    
    test07();//deque数据存取
    cout << endl;
    
    test08();//deque排序
    cout << endl;
    return 0;
}



















