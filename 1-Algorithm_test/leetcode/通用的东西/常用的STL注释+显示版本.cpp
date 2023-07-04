#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <bitset>

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


void test_sqrt(int n){
	clock_t start,end; 
	start = clock();  
	for (int i = 1; i <= n; i++)
		double num = sqrt(1.0 * i);
	end = clock(); 
	cout<<"sqrt time = "<<double(end-start)/CLOCKS_PER_SEC * 1000<<"ms"<<endl;


	start = clock();  
	for (int i = 1; i <= n; i++)
		double num = __builtin_sqrt(1.0 * i);
	end = clock(); 
	cout<<"__builtin_sqrt time = "<<double(end-start)/CLOCKS_PER_SEC * 1000<<"ms"<<endl;


	start = clock();  
	for (int i = 1; i <= n; i++)
		double num = __builtin_sqrtf(1.0 * i);
	end = clock(); 
	cout<<"__builtin_sqrtf time = "<<double(end-start)/CLOCKS_PER_SEC * 1000<<"ms"<<endl;
}

void test_gcc(void){
    int t1 = __builtin_popcount(7); // x��1�ĸ���
	int t2 = __builtin_popcountl(13);
	int t3 = __builtin_popcountll(13);
	int t4 = __builtin_ctz(4); // ĩβ0�ĸ��� // 2
	int t5 = __builtin_clz(4); // ǰ��0�ĸ��� // 29
	int t6 = __builtin_parity(3); // x��1����ż�� // ż��Ϊ0 // 0
	int t7 = __builtin_ffs(4); // �������������Ķ����Ʊ�ʾ��ʽ�����һ��1�ڵڼ�λ���Ӻ���ǰ��
	double t8 = __builtin_sqrt(3); // ���ٿ�ƽ�� 8λ����double,����ٶȺ�sqrt���
	float t9 = __builtin_sqrtf(3); // ���ٿ�ƽ�� 4λ����float
	double t10 = sqrt(3); // ����double
	// float t11 = __builtin_sqrt(3);
}


void test_data(void){
    vector<int> v1;
    vector<vector<int>> v2;
    vector<pair<int,int>> v3;
    unordered_map<int,int> map;
    unordered_map<int,vector<int>> map2;

}


void test_bitset(void){
    bitset<8> bits("10101010");
    cout << bits << endl;  // 10101010
    cout << bits.to_string() << endl; // 10101010
    cout << bits.to_ulong() << endl; // 170
    cout << bits.to_ullong() << endl; // 170
    for(int i = 0; i < bits.size(); i++){
        cout << bits[i] << " ";
    }
    cout << endl;
    bits.flip(); // �Զ����������а�λȡ������
    cout << bits.to_string() << endl; // 01010101

    bitset<1> bits1("10101010");
    bitset<2> bits2("10101010");
    bitset<4> bits4("10101010");
    bitset<8> bits8("10101010");
    bitset<32> bits32("10101010");
    bitset<64> bits64("10101010");
    bitset<128> bits128("10101010");
    bitset<256> bits256("10101010");
    cout << bits1 << endl; // 1
    cout << bits2 << endl; // 10
    cout << bits4 << endl; // 1010
    cout << bits8 << endl; // 10101010
    cout << bits32 << endl; // 00000000000000000000000010101010

    // set()��������λΪ1��reset()��������λΪ0
    bitset<8> bits_test(170);
    cout << bits_test << endl; // 10101010
    bits_test.set(); // ����0λ����Ϊ1
    cout << bits_test << endl; // 11111111
    bits_test.set(0,0); // ����0λ����Ϊ0
    cout << bits_test << endl; // 11111110
    bits_test.reset(); // ������λ����Ϊ0
    cout << bits_test << endl; // 00000000
    bits_test.set();
    bits_test.reset(2); // ����0λ����Ϊ0
    cout << bits_test << endl; // 00000000
}

int main(){
    // test_vector();
    // test_algorithm_display();
    // test_algorithm_binary_search_display();
    // test_data();
    // test_gcc();
	// test_sqrt(100000000);
    test_bitset();
    return 0;
}