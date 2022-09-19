#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void printBool(bool val){
	if(val == true)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cout << endl;
}

class Solution {
public:
	vector<int> NumSeparate(int n) {//将每个数拆开并且求和 
		vector<int> ans;
		int temp = n;
		while(temp != 0){
			ans.push_back(temp%10);
			temp = temp / 10;			
		}
		return ans;
	}
	
    bool isHappy(int n) {
    	vector<int> nums;
    	unordered_set<int> sign;//用来标记 重复元素的哈希表 
    	int SumSquare = n;
    	while(SumSquare != 1){
    		nums = NumSeparate(SumSquare);//将每个数拆开返回一个向量 
    		SumSquare = 0;//为了之后的赋值 
    		for(vector<int>::iterator it = nums.begin();it != nums.end();it++)//快乐数的运算方式 
    			SumSquare += (*it) * (*it);
//    		auto ptr = sign.insert(SumSquare);//将算出来的和插入哈希表 
    		pair<unordered_set<int>::iterator,bool> ptr = sign.insert(SumSquare);//返回的是一个对组，迭代器+bool 
    		cout << SumSquare << " " << ptr.second <<endl;
    		if(ptr.second == 0)//insert的返回pair会表示插入成功或者失败，如果失败就结束循环 
    			return false;
//    		printVector(nums);
		}
		return true;
    }
};


int main() {
	Solution solution;
	bool ans;
	int n = 7;
	
	ans = solution.isHappy(n);

	
	printBool(ans);
	
	return 0;
}



