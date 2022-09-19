#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
//谓词概念
//返回bool类型的仿函数称为谓词
//如果operator()接受一个参数，那么叫做一元谓词
//如果operator()接受两个参数，那么叫做二元谓词


//仿函数返回值类型是bool数据类型，称为谓词
//一元谓词
class GreaterFive{
public:
	bool operator()(int val){
		return val > 5;
	}
};

void test01(){
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);

	//查找容器中 有没有大于5的数字
	//GreaterFive()匿名函数对象
	vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());
	if(it == v.end())
		cout << "NO" << endl;
	else
		cout << *it << endl;
}

//二元谓词
class MyCompare{
public:
	bool operator()(int val1,int val2){
		//bool体现谓词，两个参数体现二元 
		return val1 > val2;
	}
};

void test02(){
	vector<int>v;
	
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);
	
	sort(v.begin(),v.end());
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl;
	
	sort(v.begin(),v.end(),MyCompare());//提供一个仿函数，改变排序策略 
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl;
}

int main(){
    test01();
    cout << endl;
 
    test02();
    cout << endl; 
    return 0;
}



















