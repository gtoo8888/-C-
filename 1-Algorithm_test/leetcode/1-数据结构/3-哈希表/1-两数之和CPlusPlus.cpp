#include<iostream>
#include<malloc.h>
#include <vector>
#include <algorithm>
using namespace std;


class printVector{//打印输出的仿函数 
public:
	void operator ()(int val){
		cout << val << " ";		
	}
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		int n = nums.size();
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j++){
				if((nums.at(i) + nums.at(j)) == target){
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		return result;	
    }
};


int main() {
	Solution sol;
	int nums[] = {3,2,4};
	vector<int> test_num(nums,nums + sizeof(nums)/sizeof(int));
	vector<int> returnSize;
	int target = 6;
	
	returnSize = sol.twoSum(test_num,target);
		
	for_each(returnSize.begin(),returnSize.end(),printVector());

	return 0;
}

