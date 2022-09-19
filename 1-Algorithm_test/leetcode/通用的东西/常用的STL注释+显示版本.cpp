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
// OUTPUT(it4);   // ��������



void PrintVector(vector<int>& v){
    for(auto n : v)
        printf("%d ",n);
    cout << endl;
}

void test_vector(void){
    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v2 = {1,2,3};
    // ����
    vector<int> v3(v1.begin(),v2.end());            // �ٷ�1 �ٷ��ṩ�����ֿ�������
    vector<int> v4(4,100);                          // �ٷ�2
    vector<int> v5(v1);                             // �ٷ�3
    vector<int> v6 = v1;                            // 4.���صȺ������
    vector<int> v7;
    v7 = vector<int>(4,12);                         // 5.������������
    int a1[] = {6,7,8,9,10};                        
    vector<int> v8(a1,a1+sizeof(a1)/sizeof(int));   // 6.����תvector���죬�ٷ�2�ı���
    vector<int> v9 = {1,2,3};                       // 7.C++11�ṩ�Ĺ��췽��
    vector<int> v10;                              
    v10 = vector<int>{1,2,4,5,6,7};                 // 8.ֱ�ӽ���Ҫ�����ݹ����vector
    // PrintVector(v10);
    // ������
    vector<int>::iterator it1 = v1.begin();
    vector<int>::iterator it2 = v1.end();                       // ���е�end()���������޷���ʾ
    vector<int>::reverse_iterator it3 = v1.rbegin();
    vector<int>::reverse_iterator it4 = v1.rend();
    vector<int>::const_iterator it5 = v1.cbegin();              // const_iterator 
    vector<int>::const_iterator it6 = v1.cend();
    vector<int>::const_reverse_iterator it7 = v1.crbegin();     // const_reverse_iterator
    vector<int>::const_reverse_iterator it8 = v1.crend();
    // ����
    cout << v1.size() << endl;
    cout << v1.max_size() << endl;              // ���Կ��������������ϵͳ�йأ��ҵ���1073741823
    v1.resize(15);                              // resize���޸�capacity��С��Ҳ�޸�size��С��
    v1.resize(20,100);                          // ���ذ汾���Ƕ����ݺ�Ĵ�С��ֵ��Ҳ���Ƕ�15-20֮�丳ֵ
    cout << v1.capacity() << endl;
    cout << v1.empty() << endl;
    v1.reserve(40);                             // reserveֻ�޸�capacity��С
    // ����Ԫ��
    cout << v1[0] << endl;
    cout << v1.at(0) << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;
    cout << v1.data() << endl;                  // ��ʾһ����ַ
    int *p = v1.data();                         // C++11 ���������ĵ�һ����ַ��ָ��
    cout << *(p+1) << endl;
    // �ƶ�
    v1.push_back(11);
    v1.pop_back();
    v1.insert(v1.begin(),20);
    v1.insert(v1.begin() + 3,20);               // ����Ԫ��
    v1.insert(v1.begin(),3,20);
    v1.erase(v1.begin());                       // ɾ����λ�õ�Ԫ��
    v1.erase(v1.begin() + 3);
    v1.swap(v2);                                // ������vector����
    v1.emplace(v1.begin(),12);                  //C++11 ָ��λ�ã����첢�Ҳ���
    v1.emplace(v1.begin() + 3,12);
    v1.emplace_back(12);                        // C++11 Ԫ����ĩβ�����첢�Ҳ���
    v1.clear();
}

void test_vector_display(void){
    sort(v.begin(),v.end(),less<int>())
}


void test_algorithm_display(void){
    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    int a1[] = {11,12,13,14,15,16,17,18,19,20};

    // �����Сֵ
    // cout << min(v1.begin(),v1.end()) << endl;
    // cout << min(1,2) << endl;
    // cout << min('a','z') << endl;
    // cout << min(3.14,2.72) << endl;

    // cout << max(1,2) << endl;
    pair<int,int> r1 = minmax({1,2,3,4,5,6});
    printf("%d %d\n",r1.first,r1.second);
    pair<int,int> r2 = minmax(32,56);
    printf("%d %d\n",r2.first,r2.second);


    vector<int>::iterator it1 = min_element(v1.begin(),v1.end());   // ��һ��д��
    cout << *it1 << endl;
    int it2 = *min_element(v1.begin(),v1.end());                    // �ڶ���д��
    cout << it2 << endl;
    int it3 = *min_element(a1,a1+sizeof(a1)/sizeof(int));                   
    cout << it3 << endl;
    auto it4 = min_element(a1,a1+sizeof(a1)/sizeof(int));            // �������ֵ����һ��ָ��int���͵�ָ�룬����һ�����������д�����Ӹ�*                
    cout << *it4 << endl;


    int it5 = *max_element(v1.begin(),v1.end());                    // �ڶ���д��
    cout << it5 << endl;
    int it6 = *max_element(a1,a1+sizeof(a1)/sizeof(int));                   
    cout << it6 << endl;

    // pair<int,int> it7 = minmax_element(v1.begin(),v1.end());                   
    // printf("%d %d\n",*it7.first,*it7.second);  
    // auto it8 = minmax_element(a1,a1+sizeof(a1)/sizeof(int));                   
    // printf("%d %d\n",*it8.first,*it8.second); 
}

// ���ֲ���
void test_algorithm_binary_search_display(void){
    // vector<int> v1 = {1,3,5,7,7,9,9,9,11,12,15,17,30};
    vector<int> v1 = {1,3,5,7,7,8,8,8,8,8,8,9,9,9,11,12,15,17,30};

    sort(v1.begin(),v1.end());  // ����֮ǰһ��Ҫ����
    vector<int>::iterator low = lower_bound(v1.begin(),v1.end(),8);   // ������ֻ��ظ����֣����ص�һ�����ֵ�λ�õĵ�����
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