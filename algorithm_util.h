#ifndef _ALGORITHM_UTIL_
#define _ALGORITHM_UTIL_

// #include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
//#include <iomanip>//<< setw(5)
using namespace std;

class PrintVector{
public:
	void operator ()(int val) {
		cout << val << " ";
	}
};
//	for_each(temp.begin(),temp.end(),printVector());

void PrintAuto(int it){
	cout << it << endl;
}

// ����ķ���
// void PrintVector(vector<int> v){
// 	for(auto it = v.begin();it != v.end();it++)
// 		cout << *it << " ";
// 	cout << endl; 
// }

void PrintVector(vector<int> v){
	for(auto it : v)
		cout << it << " ";
	cout << endl;
}

void PrintVCector(vector<char> v){
	for(auto it : v)
		cout << it << " ";
	cout << endl;
}

void PrintVSector(vector<string> v){
	for(auto it : v)
		// cout << it << " ";
		cout << it << endl;
}

void PrintVBector(vector<bool> v){
	for(auto it : v)
		cout << it << " ";
	cout << endl;
}

void PrintSet(set<int> s) {
	// for(set<int>::iterator it = s.begin();it != s.end();it++)
	// 	printf("%d ",*it);
	for(auto it : s)
		printf("%d ",it);
	cout << endl;	
}

void PrintMap(map<int,int> m) {
// 	for(auto it = m.begin();it != m.end();it++)
// 		cout << (*it).first << " " << it->second << endl;
	for(auto it : m)
		printf("%d %d\n",it.first,it.second);
	cout << endl;	
}

void PrintUnorder_Map(unordered_map<char,int> m) {
	for(auto it : m)
		printf("%d %d\n",it.first,it.second);
	cout << endl;	
}

vector<int> NumSeparate(int n) {//ÿ��λ��
	vector<int> ans;
	int temp = n;
	while(temp != 0){
		ans.push_back(temp%10);
		temp = temp / 10;			
	}
	return ans;
}

void PrintQueue(queue<int> q){
	while(!q.empty()){
		printf("%d ",q.front());
		q.pop();
	}
	cout << endl; 
}
	
void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

// void PrintVVector(vector<vector<int>>& v){
// 	for(auto iter = v.begin();iter != v.end();iter++){
// 		auto it_temp = *iter;
// 		for(auto it = it_temp.begin();it != it_temp.end();it++)
// 			cout << *it << " ";
// 		cout << endl;
// 	}
// 	cout << endl;
// }

void PrintVVector(vector<vector<int>>& v){
	for(auto iter : v){
		auto it_tmp = iter;
		for(auto it : it_tmp)
			cout << it << " ";
		cout << endl;
	}
	cout << endl;
}

void PrintVVCector(vector<vector<char>>& v){
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

//�ͷ�new���ٵĿռ䣬�����лᵼ���ڴ�й©
void releaseNode(ListNode* node)
{
    ListNode* temp = NULL;
    if (node == NULL)
        cout << "����ڵ��ڴ�Ϊ��\n";
    else
	    while (node != NULL){
	        temp = node;
	        node = node->next;
	        delete temp;
	        cout << "�ڵ��ڴ�����ɹ�\n";
	    }
}

//������� 
void PrintListNode(ListNode* head){
	while(head != nullptr){
		cout << head -> val << " ";
		head = head -> next;
	}
	cout << endl;
}

//n & 1 == 1�ж���һλ�ǲ���1
//n | 0 == 0�ж���һλ�ǲ���0
//���������
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
    cout << endl;
}

		
int test_util() {
	//�������� 
	vector<int> temp;
	for(int i = 0;i < 10;i++)
		temp.push_back(i);
	PrintVector(temp);
	
	//����������� 
	bool temp2 = false;
	PrintBool(temp2);
	
	//������� 
	vector<int> temp3;
	temp3 = NumSeparate(123456);
	PrintVector(temp3);
	
	//����ת����vector 
	int nums_t[]  = {1,2,3,4,5,6}; 
//	vector<int> temp4(nums_t,nums_t + sizeof(nums_t) / sizeof(int));
	vector<int> temp4 = {1,2,3,4,5,6};//C++11 ���� 
	PrintVector(temp4);
	
	cout << INT32_MAX << endl;
	cout << INT32_MIN << endl;
	cout << endl;
	
	//�����ά���� 
	int n1 = 3;
	vector<vector<int>> temp5(n1,vector<int>(n1,123));
	PrintVVector(temp5);
	
	//������ʼ������ 
	vector<int> value = {1,2,3,4};
   	int len = value.size();
    ListNode* head = new ListNode(value[len-1]);
    for (int i = 1; i < len; i++) {
        head = new ListNode(value[len-1-i], head);
    }
    
    //��������ͷ����� 
    PrintListNode(head);
    releaseNode(head);
    
    ListNode* dummyhead = new ListNode(0,head);//����ͷ���
    
    int temp6 = 1;
    cout << temp6 << " " << temp6 << endl;
    
    
    //��ȡ��ά�����к��� 
    int temp7[][3] = { {0,0,0},
					  {0,1,0},
					  {0,0,0},};
	int row = (sizeof(temp7) / sizeof(int)) / (sizeof(temp7[0]) / sizeof(int));//���� 
	int line = sizeof(temp7[0]) / sizeof(int);//����
	//��ά�����ʼ����ά���� 
	vector<vector<int>> temp8(row,vector<int>(line,0));
	for(int i = 0;i < row;i++)
		for(int j = 0;j < line;j++)
			temp8[i][j] = temp7[i][j];
	//�����ά���� 
	PrintVVector(temp8);

	vector<vector<char>> temp9 = { 	{'X','X','X','X','X'},
								{'X','O','O','O','X'},
								{'X','X','O','X','X'},
								{'O','O','X','X','X'},
								{'X','O','X','X','X'}};
	PrintVVector(temp8);

	
	PrintBit(11);
//	auto temp = max_element(grid[0].begin(),grid[0].end());
//	cout << *temp << " " << temp-grid[0].begin() << endl;
	
	return 0;
}


#endif /* _ALGORITHM_UTIL_ */

