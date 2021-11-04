#include <iostream>
using namespace std;
#include <list>
#include <map>

//map/multimap容器
//简介:
//map中所有元素都是pair
//pair中第一个元素为key(键值)，起到索引作用，第二个元素为value(实值)，
//高效性 
//所有元素都会根据元素的键值自动排序
//本质:
//map/multimap属于关联式容器，底层结构是用二叉树实现。
//优点:
//可以根据key值快速找到value值
//map和multimap区别:
//map不允许容器中有重复key值元素
//multimap允许容器中有重复key值元素

void printMap(map<int,int> &m){
	for(map<int,int>::iterator it = m.begin();it != m.end();it++)
		cout << (*it).first <<" " << it -> second << endl;
	cout << endl; 
}
//map的构造和赋值 
void test01(){
	map<int,int> m;
	
	m.insert(pair<int,int>(1,10));//对组 
	m.insert(pair<int,int>(3,30));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(4,40));//插入的时候会按照key排序 
	
	printMap(m);
	
	map<int,int>m2(m) ;//拷贝构造 
	printMap(m2);
	
	map<int,int>m3;//赋值 
	m3 = m2;
	printMap(m3); 
}

//map容器大小和交换
//size();//返回容器中元素的数目
//empty();//判断容器是否为空
//swap(st);//交换两个集合容器

//大小
void test02(){
	map<int,int> m;
	m.insert(pair<int,int>(1,10));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(3,30));	
	
	if(m.empty())
		cout << "YES" << endl;
	else{
		cout << "NO" << endl;
		cout << m.size() << endl;
	}
}
//交换
void test03(){
	map<int,int> m1;
	m1.insert(pair<int,int>(1,10));
	m1.insert(pair<int,int>(2,20));
	m1.insert(pair<int,int>(3,30));		

	map<int,int> m2;
	m2.insert(pair<int,int>(4,100));
	m2.insert(pair<int,int>(5,200));
	m2.insert(pair<int,int>(6,300));	
	
	cout << "after" << endl;
	printMap(m1); 	
	printMap(m2); 
	
	m1.swap(m2);
	cout << "before" << endl;
	printMap(m1); 	
	printMap(m2); 	
}


//map插入和删除
//insert( qlem);//在容器中插入元素。
//clear();//清除所有元素
//erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
//erase(beg, end);//删除区间[beg,end)的所有元素，返回下一个元素的迭代器。
//erase(key ) ;//删除容器中值为key的元素。
void test04(){
	map<int,int> m;
	//插入 
	m.insert(pair<int,int>(1,10));//第一种 
	m.insert(make_pair(2,20));//第二种
	m.insert(map<int,int>::value_type(3,30));//第三种
	m[4] = 40;//第四种
	
	cout << m[4] << endl;//[]不建议插入，用途 可以利用key访问到value
	cout << m[5] << endl;//错误的使用方法，想要打印，但是创建了一个pair 
	printMap(m); 	
	//删除
	m.erase(m.begin()) ;
	printMap(m); 

	m.erase(3) ;//按照key删除
	printMap(m); 
	
	m.erase(m.begin(),m.end());
//	m.clear();
	printMap(m); 		
}

//map查找和统计
//find(key);//查找key是否存在,若存在，返回该键的元素的迭代器;若不存在，返回set.end();
//count(Fey);//统计key的元素个数
void test05(){
	map<int,int> m;
	m.insert(pair<int,int>(1,10));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(3,30));	
	
	//查找 
	map<int,int>::iterator pos = m.find(3)	;	
	if(pos != m.end())
		cout << (*pos).first << " " << pos -> second << endl;
	else
		cout << "NO" << endl;
		
	//统计
	//map不允许插入重复key元素，count统计而言结果要么是0要么是1 
	//multimap的count统计可能大于1
	int num = m.count(3);
	cout << num << endl;	
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
    return 0;
}



















