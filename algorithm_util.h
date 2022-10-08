#ifndef _ALGORITHM_UTIL_
#define _ALGORITHM_UTIL_

// #include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <numeric> // iota() 批量递增
//#include <iomanip>//<< setw(5)
using namespace std;

class PrintVector{
public:
	void operator ()(int val) {
		cout << val << " ";
	}
};
//	for_each(temp.begin(),temp.end(),printVector());

// 最早的方法
// void PrintVector(vector<int> v){
// 	for(auto it = v.begin();it != v.end();it++)
// 		cout << *it << " ";
// 	cout << endl; 
// }

// 常用的方法
void PrintVector(vector<int> v){
	for(auto it : v)
		cout << it << " ";
	cout << endl;
}

// 使用模板来简化
template<typename T>
void PrintVector(vector<T> v){
	for(auto it : v)
		cout << it << " ";
	cout << endl;
}
// 模板偏特化
// 对于string有特殊处理
// template<typename T>
void PrintVector(vector<string> v){
	for(auto it : v)
		cout << it << endl;
}

// void PrintSet(set<int> s) {
// 	for(set<int>::iterator it = s.begin();it != s.end();it++)
// 		printf("%d ",*it);
// 	cout << endl;	
// }

// void PrintSet(set<int> s) {
// 	for(auto it : s)
// 		cout << it << endl;
// 	cout << endl;	
// }

template<typename T>
void PrintSet(set<T> s) {
	for(auto it : s)
		cout << it << endl;
	cout << endl;	
}

// void PrintMap(map<int,int> m) {
// // 	for(auto it = m.begin();it != m.end();it++)
// // 		cout << (*it).first << " " << it->second << endl;
// 	for(auto it : m)
// 		printf("%d %d\n",it.first,it.second);
// 	cout << endl;	
// }

template<typename T,typename N>
void PrintMap(map<T,T> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

template<typename T>
void PrintUnorder_Set(unordered_set<T> m) {
	for(auto it : m)
		cout << it << endl;
	cout << endl;	
}

// void PrintUnorder_Map(unordered_map<char,int> m) {
// 	for(auto it : m)
// 		cout << it.first << " " << it.second << endl;
// 		// printf("%d %d\n",it.first,it.second);
// 	cout << endl;	
// }

template<typename T,typename N>
void PrintUnorder_Map(unordered_map<T,N> m) {
	for(auto it : m)
		cout << it.first << " " << it.second << endl;
	cout << endl;	
}


vector<int> NumSeparate(int n) {//每个位拆开
	vector<int> ans;
	int temp = n;
	while(temp != 0){
		ans.push_back(temp%10);
		temp = temp / 10;			
	}
	return ans;
}

template<typename T>
void PrintStack(stack<T> st){
	while(!st.empty()){
		cout << st.top() << endl;
		st.pop();
	}
	cout << endl; 
}

template<typename T>
void PrintQueue(queue<T> q){
	while(!q.empty()){
		cout << q.front() << endl;
		q.pop();
	}
	cout << endl; 
}
	
void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

// 最原始的方法
// void PrintVVector(vector<vector<int>>& v){
// 	for(auto iter = v.begin();iter != v.end();iter++){
// 		auto it_temp = *iter;
// 		for(auto it = it_temp.begin();it != it_temp.end();it++)
// 			cout << *it << " ";
// 		cout << endl;
// 	}
// 	cout << endl;
// }

// 常用的方法
// void PrintVVector(vector<vector<int>>& v){
// 	for(auto iter : v){
// 		auto it_tmp = iter;
// 		for(auto it : it_tmp)
// 			cout << it << " ";
// 		cout << endl;
// 	}
// 	cout << endl;
// }

// 使用模板简化函数
template<typename T>
void PrintVVector(vector<vector<T>> v){
	for(auto iter : v){
		auto it_tmp = iter;
		for(auto it : it_tmp)
			cout << it << " ";
		cout << endl;
	}
	cout << endl;
}

void PrintPriQueue(priority_queue<long,vector<int>,greater<long>> pri){
	while(!pri.empty()){
		cout << pri.top() << endl;
		pri.pop();
	}
}

struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x,ListNode *next) : val(x), next(next){}
};

//释放new开辟的空间，不进行会导致内存泄漏
void releaseNode(ListNode* node)
{
    ListNode* temp = NULL;
    if (node == NULL)
        cout << "链表节点内存为空\n";
    else
	    while (node != NULL){
	        temp = node;
	        node = node->next;
	        delete temp;
	        cout << "节点内存清除成功\n";
	    }
}

// 创建列表节点
ListNode* CreateListNode(vector<int> value){
	int len = value.size();
	ListNode* head = new ListNode(value[len -1]);
	for(int i = 1;i < len;i++)
		head = new ListNode(value[len-1-i],head);
	return head;
}

//输出链表 
void PrintListNode(ListNode* head){
	while(head != nullptr){
		cout << head -> val << " ";
		head = head -> next;
	}
	cout << endl;
}

//n & 1 == 1判断这一位是不是1
//n | 0 == 0判断这一位是不是0
//二进制输出
void PrintBit(int n) {
	string str;
    while(n != 0 ) {
        if(n & 1 == 1)  
            str.push_back('1');
        else   
            str.push_back('0');
        n >>= 1;
    }
	reverse(str.begin(),str.end());
	cout << str << endl;
}

int str_to_num(string str){
	reverse(str.begin(),str.end());
	// cout << str << endl;
	int num = 0;
	for(int i = 0;i < str.size();i++){	
		// 返回浮点数，如果不向上取整就有精度问题,9*100.00会变成999
		num += (str[i]-'0')*ceil(pow(10,i));
		// printf("%d %d %f\n",num,i,ceil(pow(10,i));
	}
	return num;
}

string num_to_str(int num){
	string str;
	while(num != 0){
		int tmp = num%10;
		str.push_back('0'+tmp);
		num /= 10;
	}
	reverse(str.begin(),str.end());
	return str;
}
		
void turnVVector(string str1){
	for(int i = 0;i < str1.size();i++){
		if(str1[i] == '[')
			str1[i] = '{';
		if(str1[i] == ']')
			str1[i] = '}';
		if(str1[i] == '\"')
			str1[i] = '\'';
	}
	cout << str1 << endl;
}

bool myconpare(pair<string,int> p1,pair<string,int> p2){
	if(p1.second > p2.second)
		return true;
	// else if(p1.second < p2.second)
    else
		return false;
    return true;
}

int test_util() {
	vector<int> example1 = {1,2,3,4,5};
	vector<string> example2 = {"aa","bb","cc","dd"};
	//单个输入 
	vector<int> temp;
	for(int i = 0;i < 10;i++)
		temp.push_back(i);
	PrintVector(temp);
	
	//输出布尔类型 
	bool temp2 = false;
	PrintBool(temp2);
	
	//拆分数据 
	vector<int> temp3;
	temp3 = NumSeparate(123456);
	PrintVector(temp3);
	
	//数组转化成vector 
	int nums_t[]  = {1,2,3,4,5,6}; 
//	vector<int> temp4(nums_t,nums_t + sizeof(nums_t) / sizeof(int));
	vector<int> temp4 = {1,2,3,4,5,6};//C++11 特性 
	PrintVector(temp4);
	
	cout << INT32_MAX << endl;
	cout << INT32_MIN << endl;
	cout << endl;
	
	//输出二维数组 
	int n1 = 3;
	vector<vector<int>> temp5(n1,vector<int>(n1,123));
	PrintVVector(temp5);
	
	//向量初始化链表 
	vector<int> value = {1,2,3,4};
   	int len = value.size();
    ListNode* head = new ListNode(value[len-1]);
    for (int i = 1; i < len; i++) {
        head = new ListNode(value[len-1-i], head);
    }
    
    //输出链表、释放链表 
    PrintListNode(head);
    releaseNode(head);
    
    ListNode* dummyhead = new ListNode(0,head);//虚拟头结点
    
    int temp6 = 1;
    cout << temp6 << " " << temp6 << endl;
    
    
    //读取二维数组行和列 
    int temp7[][3] = { {0,0,0},
					  {0,1,0},
					  {0,0,0},};
	int row = (sizeof(temp7) / sizeof(int)) / (sizeof(temp7[0]) / sizeof(int));//行数 
	int line = sizeof(temp7[0]) / sizeof(int);//列数
	//二维数组初始化二维向量 
	vector<vector<int>> temp8(row,vector<int>(line,0));
	for(int i = 0;i < row;i++)
		for(int j = 0;j < line;j++)
			temp8[i][j] = temp7[i][j];
	//输出二维数组 
	PrintVVector(temp8);

    vector<vector<int>> temp12 = {{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<char>> temp9 = { 	{'X','X','X','X','X'},
								{'X','O','O','O','X'},
								{'X','X','O','X','X'},
								{'O','O','X','X','X'},
								{'X','O','X','X','X'}};
	PrintVVector(temp8);
	PrintVVector(temp12);


	vector<int> example_vector1 = {1,2,3,4};
	vector<char> example_vector2 = {'4','5','6'};
	vector<bool> example_vector3 = {false,true,false,true};
	vector<string> example_vector4 = {"XSW","CDE","VFR"};
	PrintVector(example_vector1);
	PrintVector(example_vector2);
	PrintVector(example_vector3);
	PrintVector(example_vector4);
	

	
	PrintBit(11);
//	auto temp = max_element(grid[0].begin(),grid[0].end());
//	cout << *temp << " " << temp-grid[0].begin() << endl;

	string temp10 = "[  [1,3,1],  [1,5,1],  [4,2,1]]";
	turnVVector(temp10);

	vector<pair<string,int>> temp11;
	sort(temp11.begin(),temp11.end(),myconpare);	// 使用后面一个排序
	
	return 0;
}


#endif /* _ALGORITHM_UTIL_ */

