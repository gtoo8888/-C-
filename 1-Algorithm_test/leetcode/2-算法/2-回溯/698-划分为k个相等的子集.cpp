#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

void PrintVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void PrintVBector(vector<bool> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void printVVector(vector<vector<int>> v){
	vector<vector<int>>::iterator iter;
	vector<int>::iterator it;
	vector<int> it_temp;
	
	for(iter = v.begin();iter != v.end();iter++){
		it_temp = *iter;
		for(it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}


class Solution {
public:
	int back_count = 0;
	bool backtraining(vector<int>& nums,int k,int index,vector<int>& bucket,int target){
		// if(back_count++ > 30)
		// 	return false;
		// PrintVector(bucket);
		if(index == nums.size()){
			// 有人提出，其实这个地方不需要判断，因为当 index == num.length 时，所有球已经按要求装入所有桶，所以肯定是一个满足要求的解
    		// 即：每个桶内球的和一定为 target
			// for(int i = 0;i < k;i++){
			// 	if(bucket[i] != target)
			// 		return false;
			// }
			return true;
		}

		for(int i = 0;i < k;i++){
			// 如果当前桶和上一个桶内的元素和相等，则跳过
			// 原因：如果元素和相等，那么 nums[index] 选择上一个桶和选择当前桶可以得到的结果是一致的
			// 没怎么看懂
			if(i > 0 && bucket[i] == bucket[i-1])	// 最重要的剪枝，效果最好
				continue;
			if(bucket[i] + nums[index] > target)
				continue;
			bucket[i] += nums[index];
			if(backtraining(nums,k,index+1,bucket,target))
				return true;
			bucket[i] -= nums[index];
		}
		return false;
	}

    bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = accumulate(nums.rbegin(),nums.rend(),0);
		
		if(sum%k != 0)
			return false;
		int target = sum/k;
		printf("%d %d\n",sum,target);
		vector<int> bucket(k);
		sort(nums.begin(),nums.end(),greater<int>());
		PrintVector(nums);
		return backtraining(nums,k,0,bucket,target);
    }
};

	
int main() {
	Solution solution;
	// vector<int> nums = {4, 3, 2, 3, 5, 2, 1}; 
	// int k = 4;

	vector<int> nums = {10,5,5,4,3,6,6,7,6,8,6,3,4,5,3,7}; 
	int k = 8;
	
	auto ans = solution.canPartitionKSubsets(nums,k);
	
	
	PrintBool(ans);
	
	return 0;
}



