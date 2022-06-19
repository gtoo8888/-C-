#include <iostream>
using namespace std;
#include <list>
#include <algorithm>

//功能:将数据进行链式存储
//链表(list)是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
//链表的组成:链表由一系列结点组成
//结点的组成:一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
//STL中的链表是一个双向循环链表

//链表优点:可以对任意位置进行快速插入或删除元素
//链表缺点:容器遍历速度，没有教组快，占用空间比数组大
//由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器

//list的优点:
//采用动态存储分配，不会造成内存浪费和溢出
//链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
//list的缺点:
//链表灵活，但是空间(指针域)和时间(遍历)额外耗费较大
//List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。
//总结:STL中List和vector是两个最常被使用的容器，各有优缺点


//list构造函数
//功能描述:创建list容器
//函数原型:
//list<T> lst;//list采用采用模板类实现,对象的默认构造形式:
//list(beg,end) ;//构造函数将[beg, end)区间中的元素拷贝给本身。
//list(n,elem);//构造函数将n个elem拷贝给本身。
//list(const list &lst);//拷贝构造函数。

void printList(list<int> &l){
	for(list<int>::iterator it = l.begin();it != l.end();it++)
		cout << *it << " ";
	cout << endl;
}

void test01(){
	//创建list容器
	list<int>L1;//默认构造
	
	L1.push_back(10);//尾插法 
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	
	printList(L1); 
	
	list<int>L2(L1.begin(),L1.end() );//区间方式构造
	printList(L2);
		
	list<int>L3(L2);//拷贝构造
	printList(L3);
		
	list<int>L4(10,1000);//n个elem
	printList(L4);
}

//list赋值和交换
//功能描述:
//给list容器进行赋值，以及交换list容器函数原型:
//assign( beg, end );//将[beg, end)区间中的数据拷贝赋值给本身。
//assign(n,eiem);//将n个elem拷贝赋值给本身。
//list& operator=(const list &lst);//重载等号操作符
//swap(lst);//将lst与本身的元素互换。
//list赋值
void test02(){
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1); 
	
	list<int>L2;
	L2 = L1; //operator=赋值
	printList(L2);
	
	list<int>L3;
	L3.assign(L2.begin(),L2.end());
	printList(L3);
	
	list<int>L4;
	L4.assign(10,100);
	printList(L4);
}
//list交换
void test03(){
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1); 
	
	list<int>L2;
	L2.assign(10,100);
	
	printList(L1); 
	printList(L2); 	
	
	L1.swap(L2);
	printList(L1); 
	printList(L2); 	
}

//list大小操作
//功能描述:对list容器的大小进行操作
//函数原型:
//size();//返回容器中元素的个数
//empty();//判断容器是否为空
//resize( num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置//如果容器变短，则末尾超出容器长度的元素被删除。
//resize(num，elem) ;//重新指定容器的长度为num，若容器变长，则以elem值填充新位置//如果容器变短，则末尾超出容器长度的元素被删除。
void test04(){
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1); 
	
	if(L1.empty())
		cout << "YES"  << endl;
	else{
		cout << "NO" << endl; 
		cout << L1.size() << endl;
	}
	
	L1.resize(10,10000);//重新指定大小
	printList(L1); 	
	
	L1.resize(2);
	printList(L1); 
}

//list插入和删除
//功能描述:对list容器进行数据的插入和删除
//函数原型:
//push_back(elem);//在容器尾部加入一个元素
//pop_back();//删除容器中最后一个元素
//push_front(elem);//在容器开头插入一个元素
//pop_front();//从容器开头移除第一个元素
//
//insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置
//insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
//insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值
//clear();//移除容器的所有数据
//erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置
//erase(pos);//删除pos位置的数据，返回下一个数据的位置。
//remove(elem);//删除容器中所有与elem值匹配的元素。
void test05(){
	list<int>L1;
	L1.push_back(10);//尾插 
	L1.push_back(20);
	L1.push_back(30);
	
	L1.push_front(100);//头插 
	L1.push_front(200);
	L1.push_front(300);
	printList(L1); 
	
	L1.pop_back();//尾删 
	printList(L1); 	
	
	L1.pop_front();//头删 
	printList(L1); 	
	
	L1.insert(L1.begin(),1000);//insert插入 
	list<int>::iterator it = L1.begin();
	L1.insert(++it,99);//用迭代器做偏移 
	printList(L1); 	
	
	it = L1.begin();
	L1.erase(++it);//删除 
	printList(L1); 	
	
	L1.push_back(10000);
	L1.push_back(10000);
	L1.push_back(10000);
	printList(L1); 	
	L1.remove(10000);//移除 
	printList(L1); 	
	
	L1.clear();//清空 
	printList(L1); 		 
}

//list数据存取
//功能描述:对list容器中数据进行存取
//函数原型:
//front();//返回第一个元素。
// back();//返回最后一个元素。
void test06(){
	list<int>L1;
	L1.push_back(10);//尾插 
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	//L1[0] 不可以用[]访问list容器中的元素
	//L1.at(0) 不可以用at方式访问list容器中的元素
	//原因是list本质链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问的
	
	cout << L1.front() << endl;
	cout << L1.back() << endl;
	
	//验证迭代器是不支持随机访问的
	list<int> ::iterator it = L1.begin() ;
	it++;//支持双向
	it--;
	//it = it + 1;//不支持随机访问,如果能加1就是能加2了，迭代器不允许这样跳着访问 	 
}


//list反转和排序
//功能描述:
//将容器中的元素反转，以及将容器中的数据进行排序
//函数原型:
//reverse();//反转链表
//sort();//链表排序
void test07(){
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);
	cout <<"反转前:" ;
	printList(L1);		
	
	L1.reverse();
	cout <<"反转后:" ;
	printList(L1); 		
}
//list排序
bool myCompare(int v1,int v2){
	return v1 > v2;//降序就让第一个数>第二个数
}
void test08(){
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);
	cout <<"排序前:" ;
	printList(L1);	
		
	//所有不支持随机访问迭代器的容器，不可以用标准算法
	//不支持随机访问迭代器的容器，内部会提供对应一些算法
//	sort(L1.begin(),L1.end());
	L1.sort();//默认排序规则从小到大升序
	cout <<"排序后:" ;
	printList(L1); 	
	
	L1.sort(myCompare);
	printList(L1);	
}

int main(){
    test01();
    cout << endl;
 
    test02();
    test03();
    cout << endl;    
    
    test04();
    cout << endl;  
    
    test05();
    cout << endl;  
    
    test06();
    cout << endl; 
    
    test07();
    test08();
    cout << endl; 
    return 0;
}



















