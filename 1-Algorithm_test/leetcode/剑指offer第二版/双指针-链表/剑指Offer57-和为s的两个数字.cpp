#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
// 		unordered_set<int> uset;
// 		for(auto it : nums){
// 			uset.insert(it);
// 		}
// 		int n = nums.size();
// 		for(int i = 0;i < n;i++){
// 			int two = target - nums[i];
// 			if(uset.find(two) != uset.end())
// 				return {nums[i],two};
// 		}
// 		return {};
//     }
// };

// 开数组方式不可以，10^7还是比较慢
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		int hash[10000000] = {0};
		for(auto it : nums){
			hash[it]++;
		}
		int n = nums.size();
		for(int i = 0;i < n;i++){
			int two;
			if(target - nums[i] >= 0)
				two = target - nums[i];
			else
				continue;
			if(hash[two] != 0)
				return {nums[i],two};
		}
		return {};
    }
};

int main(){
	Solution sol;
	vector<int> nums = {2,7,11,15};
	int target = 9;

	// vector<int> nums = {10,26,30,31,47,60};
	// int target = 40;

	auto ans = sol.twoSum(nums,target);
	PrintVector(ans);
	return 0;
}
