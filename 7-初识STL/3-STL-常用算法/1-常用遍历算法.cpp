#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//算法主要是由头文件<algorithm><functional> <numeric>组成。
//<algorithm>是所有STL头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等等
//<numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
//<functional>定义了一些模板类,用以声明函数对象。

void print01(int val){//普通函数 
	cout << val << " ";
}

class print02{//仿函数 
public:
	void operator() (int val){
		cout << val << " ";
	}
};
//常用遍历算法for_each
void test01(){
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);
		
	for_each(v.begin(),v.end(),print01);//普通函数放函数名 
	cout << endl;

	for_each(v.begin(),v.end(),print02());//仿函数放函数对象 
	cout << endl;
}

class Transform{
public:
	int operator() (int v){
		return v + 100;
	}
};
class myprint{
public:
	void operator() (int val){
		cout << val << " ";
	}
};
//常用遍历算法transform
void test02(){
	vector<int>v;
	for(int i = 0;i < 10;i++)
		v.push_back(i);
		
	vector<int>vTarget;;//目标容器
	vTarget.resize(v.size());//目标容器需要提前开辟空间
	
	transform(v.begin(),v.end(),vTarget.begin(),Transform());
	for_each(vTarget.begin(),vTarget.end(),myprint());
	cout << endl;
}







int main(){
    test01();
    cout << endl;
 
    test02();
    cout << endl;    
    return 0;
}



















