#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// 参考题解
// https://leetcode.cn/problems/maximum-sum-circular-subarray/solutions/1152143/wo-hua-yi-bian-jiu-kan-dong-de-ti-jie-ni-892u/
// 环形子数组的答案有两种情况:
// 1. 如果不在两边，那么最大子数组，一定在中间，就是转化为力扣53.最子数组和
// 2. 如何在边界出现了，那么问题可以转化为
// 先求出最小子数组和，将总和减去最小子数组和，那么就可以得到剩下的最大子数组和
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
		int total = nums[0];
		vector<int> dpmax(n,0); // 最大子数组和
		vector<int> dpmin(n,0); // 最小子数组和
		dpmax[0] = nums[0];
		dpmin[0] = nums[0];
		for(int i = 1;i < n;i++){
			dpmax[i] = max(nums[i] + dpmax[i-1],nums[i]);
			dpmin[i] = min(nums[i] + dpmin[i-1],nums[i]);
			total += nums[i];
		}
		// PrintVector(dpmax);
		// PrintVector(dpmin);
		int curMax = *max_element(dpmax.begin(),dpmax.end());
		int curMin = *min_element(dpmin.begin(),dpmin.end());
		if(curMax > 0) // 对于全负数的情况
			return max(curMax,total - curMin);
		else
			return curMax; // 对于全负数的情况，如果全负数，就需要直接返回
            // 不然total(负数)-curMax(负数)两倍的正数
        // return curMax > 0 ? max(curMax, total - curMax) : curMax; 
    }
};


// 优化后的方法，没有使用vector
// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
// 		int n = nums.size();
// 		int total = 0;
// 		int maxSum = nums[0],curMax = 0;
// 		int minSum = nums[0],curMin = 0;
// 		for(int i = 0;i < n;i++){
// 			curMax = max(curMax + nums[i],nums[i]);
// 			maxSum = max(maxSum, curMax);

// 			curMin = min(curMin + nums[i],nums[i]);
// 			minSum = min(minSum, curMin);

// 			total += nums[i];
// 			// printf("%d %d\n",curMax,maxSum);
// 			// printf("%d %d\n\n",curMin,minSum);
// 		}
// 		return curMax > 0 ? max(maxSum, total - minSum) : maxSum; 
// 		// 最大值只会在最大和总和减去最大中出现
//     }
// };


int main() {
	Solution solution;
	// vector<int> nums = {1,-2,3,-2};    // 3
	vector<int> nums = {5,-3,5};    // 10
	// vector<int> nums = {3,-2,2,-3};    
	
	auto ans = solution.maxSubarraySumCircular(nums);
	cout << ans << endl;
	return 0;
}



