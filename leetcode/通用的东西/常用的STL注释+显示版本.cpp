#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>


#include <list>

#include <typeinfo>
using namespace std;
#define OUTPUT(f)	cout << typeid(f).name() << endl;
// OUTPUT(it4);   // 测试类型



void PrintVector(vector<int>& v){
    for(auto n : v)
        printf("%d ",n);
    cout << endl;
}

void test_vector(void){
    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v2 = {1,2,3};
    // 构造
    vector<int> v3(v1.begin(),v2.end());            // 官方1 官方提供的三种拷贝构造
    vector<int> v4(4,100);                          // 官方2
    vector<int> v5(v1);                             // 官方3
    vector<int> v6 = v1;                            // 4.重载等号运算符
    vector<int> v7;
    v7 = vector<int>(4,12);                         // 5.构造匿名变量
    int a1[] = {6,7,8,9,10};                        
    vector<int> v8(a1,a1+sizeof(a1)/sizeof(int));   // 6.数组转vector构造，官方2的变种
    vector<int> v9 = {1,2,3};                       // 7.C++11提供的构造方法
    vector<int> v10;                              
    v10 = vector<int>{1,2,4,5,6,7};                 // 8.直接将想要的内容构造进vector
    // PrintVector(v10);
    // 迭代器
    vector<int>::iterator it1 = v1.begin();
    vector<int>::iterator it2 = v1.end();                       // 所有的end()迭代器都无法显示
    vector<int>::reverse_iterator it3 = v1.rbegin();
    vector<int>::reverse_iterator it4 = v1.rend();
    vector<int>::const_iterator it5 = v1.cbegin();              // const_iterator 
    vector<int>::const_iterator it6 = v1.cend();
    vector<int>::const_reverse_iterator it7 = v1.crbegin();     // const_reverse_iterator
    vector<int>::const_reverse_iterator it8 = v1.crend();
    // 容量
    cout << v1.size() << endl;
    cout << v1.max_size() << endl;              // 可以开的最大容量，和系统有关，我的是1073741823
    v1.resize(15);                              // resize既修改capacity大小，也修改size大小。
    v1.resize(20,100);                          // 重载版本，是对扩容后的大小赋值，也就是对15-20之间赋值
    cout << v1.capacity() << endl;
    cout << v1.empty() << endl;
    v1.reserve(40);                             // reserve只修改capacity大小
    // 访问元素
    cout << v1[0] << endl;
    cout << v1.at(0) << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;
    cout << v1.data() << endl;                  // 显示一个地址
    int *p = v1.data();                         // C++11 返回容器的第一个地址的指针
    cout << *(p+1) << endl;
    // 移动
    v1.push_back(11);
    v1.pop_back();
    v1.insert(v1.begin(),20);
    v1.insert(v1.begin() + 3,20);               // 插入元素
    v1.insert(v1.begin(),3,20);
    v1.erase(v1.begin());                       // 删除这位置的元素
    v1.erase(v1.begin() + 3);
    v1.swap(v2);                                // 将两个vector交换
    v1.emplace(v1.begin(),12);                  //C++11 指定位置，构造并且插入
    v1.emplace(v1.begin() + 3,12);
    v1.emplace_back(12);                        // C++11 元素在末尾，构造并且插入
    v1.clear();
}

void test_vector_display(void){
    sort(v.begin(),v.end(),less<int>())
}


void test_algorithm_display(void){
    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    int a1[] = {11,12,13,14,15,16,17,18,19,20};

    // 最大最小值
    // cout << min(v1.begin(),v1.end()) << endl;
    // cout << min(1,2) << endl;
    // cout << min('a','z') << endl;
    // cout << min(3.14,2.72) << endl;

    // cout << max(1,2) << endl;
    pair<int,int> r1 = minmax({1,2,3,4,5,6});
    printf("%d %d\n",r1.first,r1.second);
    pair<int,int> r2 = minmax(32,56);
    printf("%d %d\n",r2.first,r2.second);


    vector<int>::iterator it1 = min_element(v1.begin(),v1.end());   // 第一种写法
    cout << *it1 << endl;
    int it2 = *min_element(v1.begin(),v1.end());                    // 第二种写法
    cout << it2 << endl;
    int it3 = *min_element(a1,a1+sizeof(a1)/sizeof(int));                   
    cout << it3 << endl;
    auto it4 = min_element(a1,a1+sizeof(a1)/sizeof(int));            // 这个返回值就是一个指向int类型的指针，所以一定得用上面的写法，加个*                
    cout << *it4 << endl;


    int it5 = *max_element(v1.begin(),v1.end());                    // 第二种写法
    cout << it5 << endl;
    int it6 = *max_element(a1,a1+sizeof(a1)/sizeof(int));                   
    cout << it6 << endl;

    // pair<int,int> it7 = minmax_element(v1.begin(),v1.end());                   
    // printf("%d %d\n",*it7.first,*it7.second);  
    // auto it8 = minmax_element(a1,a1+sizeof(a1)/sizeof(int));                   
    // printf("%d %d\n",*it8.first,*it8.second); 
}

// 二分查找
void test_algorithm_binary_search_display(void){
    // vector<int> v1 = {1,3,5,7,7,9,9,9,11,12,15,17,30};
    vector<int> v1 = {1,3,5,7,7,8,8,8,8,8,8,9,9,9,11,12,15,17,30};

    sort(v1.begin(),v1.end());  // 二分之前一定要排序
    vector<int>::iterator low = lower_bound(v1.begin(),v1.end(),8);   // 如果数字会重复出现，返回第一个出现的位置的迭代器
    vector<int>::iterator up = upper_bound(v1.begin(),v1.end(),8);    // 
    cout << low - v1.begin() << endl;
    cout << up - v1.begin() << endl;
    
}


void test_data(void){
    vector<int> v1;
    vector<vector<int>> v2;
    vector<pair<int,int>> v3;
    unordered_map<int,int> map;
    unordered_map<int,vector<int>> map2;

}
int main(){
    test_vector();
    // test_algorithm_display();
    test_algorithm_binary_search_display();
    test_data();
    return 0;
}