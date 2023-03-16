#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
		int total = 0;
		vector<int> dpmax(n,0);
		vector<int> dpmin(n,0);
		dpmax[0] = nums[0];
		dpmin[0] = nums[0];
		for(int i = 1;i < n;i++){
			dpmax[i] = max(nums[i] + dpmax[i-1],nums[i]);
			dpmin[i] = min(nums[i] + dpmin[i-1],nums[i]);
			total += nums[i];
		}
		PrintVector(dpmax);
		PrintVector(dpmin);
		int curMax = *max_element(dpmax.begin(),dpmax.end());
		int curMin = *min_element(dpmin.begin(),dpmin.end());
		if(curMax > 0)
			return max(curMax,total - curMin);
		else
			return curMax;
		// 最大值只会在最大和总和减去最大中出现
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



