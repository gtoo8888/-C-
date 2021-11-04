#include <iostream>
using namespace std;
#include <vector>

// vector基本概念:vector数据结构和数组非常相似，也称为单端数组
// vector与普通数组区别:不同之处在于数组是静态空间，而vector可以动态扩展
// 动态扩展:并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间
// vector容器的失代器具支持随机访问的迭代器

// vector<T> V;//采用模板实现类实现，默认构造函数
// vector(v. begin()，v.end());//将v[pegin(), end())区间中的元素拷贝给本身。
// //前闭，后开
// vector(n, elem);//构造函数将n个elem拷贝给本身。
// vector(const vector &vec);//拷贝构造函数。

// vector容器的遍历
void printVector(vector<int> &v){
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
        cout << *it << " ";
    cout << endl;
}

// vector容器构造
void test01(){
    vector<int>v1;//默认构造 无参构造
    for(int i = 0;i < 10;i++)
        v1.push_back(i);
    printVector(v1);

    vector<int>v2(v1.begin(),v1.end());//通过区间的方式构造
    printVector(v2);

    vector<int>v3(10,100);//n个elem方式构造，前面个数，后面元素
    printVector(v3);

    vector<int>v4(v3);
    printVector(v4);
}

// vector& operator=(const vector &vec); //重载等号操作符
// assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
// assign(n, elem);//将n个elem拷贝赋值给本身。

//vector容器的赋值
void test02(){
    vector<int>v1;
    for(int i = 0;i < 10;i++)
        v1.push_back(i);
    printVector(v1);

    vector<int>v2;//赋值 operator=
    v2 = v1;
    printVector(v2);

    vector<int>v3;//assign
    v3.assign(v1.begin(),v1.end());
    printVector(v3);

    vector<int>v4;//n个elem方式赋值
    v4.assign(10,99);
    printVector(v4);
}

// empty();//判断容器是否为空
// capacity();//容器的容量
// size();//返回容器中元素的个数
// resize(int num);//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
// //如果容器变短，则末尾超出容器长度的元素被删除。
// resize(int num，elem); | //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
// //如果容器变短，则末尾超出容器长度的元素被删除

// vector容量和大小
//容量永远大于大小
void test03(){
    vector<int>v1;
    for(int i = 0;i < 10;i++)
        v1.push_back(i);

    if(v1.empty())
        cout << "empty YES" << endl;
    else{
        cout << "empty NO" << endl;
        cout << v1.capacity() << endl;
        cout << v1.size() << endl;
    }
    //重新指定大小
    v1.resize(15,95) ;//利用重载版本，可以指定默认填充值，参数2
    printVector(v1);//如果重新指定的比原来长了，默认用0填充新的位置

    v1.resize(5);
    printVector(v1);//如果重新指定的比原来短了，超出部分会删除掉
}

// push_ back(ele);//尾部插入元素ele
// pop_ back();//删除最后一个元素
// insert(const_ iterator pos, ele);//迭代器指向位置pos插入元素ele
// insert(const_ iterator pos, int count, ele); //迭代器指向位置pos插入count个元素ele
// erase(const_ iterator pos);//删除迭代器指向的元素
// erase(const_ iterator start, const_ iterator end); //删除迭代器从start到end之间的元素

// clear();//删除容器中所有元素
// vector插入和删除
void test04(){
    vector<int>v1;
    v1.push_back(10);//尾插
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);

    v1.pop_back();//尾删
    printVector(v1);

    v1.insert(v1.begin(),55);//插入，第一个参数是迭代器
    //实现了从头部插入
    printVector(v1);

    v1.insert(v1.begin(),2,56);//重载版本插入，可以插入n个数据
    printVector(v1);

    v1.erase(v1.begin());//删除，第一个参数是迭代器
    printVector(v1);

    // v1.erase(v1.begin(),v1.end());//删除，前后参数都是迭代器
    v1.clear();//清空
    printVector(v1);
}

// at(int idx);//返回索引idx所指的数据
// operator[I];//返回索引idx所指的数据
// front();//返回容器中第一个数据元素
// back();//返回容器中最后一个数据元素
//vector容器数据存取
void test05(){
    vector<int>v1;
    for(int i = 0;i < 10;i++)
        v1.push_back(i);
    
    for(int i = 0;i < v1.size();i++)//利用[]方式访问数组中元素
        cout << v1[i] << " ";
    cout << endl;
    
    for(int i = 0;i < v1.size();i++)//利用at方式访问元素
        cout << v1.at(i) << " ";
    cout << endl;

    cout << v1.front() << endl;//获取第一个元素
    cout << v1.back() << endl;//获取最后一个元素
}

// swap(vec); //将vec与本身的元素互换
//vector容器互换：基本使用
void test06(){
    vector<int>v1;
    for(int i = 0;i < 10;i++)
        v1.push_back(i);
    
    vector<int>v2;
    for(int i = 10;i > 0;i--)
        v2.push_back(i);

    cout << "swap before:" << endl;
    printVector(v1);
    printVector(v2);
    
    cout << "swap after:" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
//vector容器互换：实际用途
//巧用swap可以收缩内存空间
void test07(){
    vector<int>v1;
    for(int i = 0;i < 100000;i++)
        v1.push_back(i);

    cout << v1.capacity() << endl;
    cout << v1.size() << endl;

    v1.resize(3);
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;  

    vector<int>(v1).swap(v1);
    //实际情况：创建了一个vector<int>(v1)的匿名对象
    //在交换完之后，匿名对象就被释放掉了
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;   
}

// reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问。
// vector预留空间：减少vector在动态扩展容量时的扩展次数
void test08(){
    vector<int>v1;
    int num = 0;
    int *p = NULL;
    for(int i = 0;i < 100000;i++){//在进行大范围数据存储的时候，系统是不断在扩充内部空间的
        v1.push_back(i);
        if(p != &v1[0]){//如果指针指向的不是首地址
            p = &v1[0];//那么将指针的指向指向首地址
            num++;//看看重新的指向，这样的操作重复了多少次
        }
    }
    cout << num << endl;

    vector<int>v2;
    v2.reserve(100000);
    num = 0;
    *p = NULL;
    for(int i = 0;i < 100000;i++){
        v2.push_back(i);
        if(p != &v2[0]){
            p = &v2[0];
            num++;
        }
    }
    cout << num << endl;
}

int main(){
    test01();//vector容器构造
    cout << endl;

    test02();//vector容器的赋值
    cout << endl;

    test03();// vector容量和大小
    cout << endl;

    test04();// vector插入和删除
    cout << endl;

    test05();//vector容器数据存取
    cout << endl;

    test06();//vector容器互换：基本使用
    test07();//vector容器互换：实际用途,巧用swap可以收缩内存空间
    cout << endl;

    test08();// vector预留空间
    cout << endl;
    return 0;
}






