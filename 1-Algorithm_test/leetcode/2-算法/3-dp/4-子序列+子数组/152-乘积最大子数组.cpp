#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 错误的思路
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
// 		int n = nums.size();
// 		vector<int> dp(n,1);
// 		dp[0] = nums[0];
// 		for(int i = 1;i < n;i++){
// 			// printf("%d %d %d\n",dp[i],dp[i-1],nums[i]);
// 			if(nums[i] > 0 && dp[i-1] > 0 || nums[i] < 0 && dp[i-1] < 0)
// 				dp[i] = dp[i-1] * nums[i];
// 			// else if(nums[i] > 0)
// 			else
// 				dp[i] = nums[i];
// 			PrintVector(dp);
// 		}
// 		int ans = INT32_MIN;
// 		for(int i = 0;i < n;i++){
// 			ans = dp[i] > ans ? dp[i] : ans;
// 		}
// 		return ans;
//     }
// };

// 同时维护最大最小值
class Solution {
public:
    int maxProduct(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n,1);
		dp[0] = nums[0];
		int dp_min=1,dp_max=1;
		int ans = INT32_MIN;
		for(int i = 0;i < n;i++){
			if(nums[i] < 0){
				int tmp = dp_min;
				dp_min = dp_max;
				dp_max = tmp;
			}
			dp_max = max(nums[i],nums[i]*dp_max);	// 要么是自己，要么自己乘上当前的数字
			dp_min = min(nums[i],nums[i]*dp_min);
			ans = max(ans,dp_max);

			printf("%d %d %d\n",dp_max,dp_min,ans);
		}
		return ans;
    }
};


int main() {
	Solution solution;
	vector<int> nums = {2,3,-2,4};    
	// vector<int> nums = {-2,0,-1};  
	// vector<int> nums = {-3,-1,-1};   // 相乘为正
	// vector<int> nums = {-2,3,-4};   	// 跨过来相乘  

	vector<int> nums = {2,3,-2,4,-2};    
	// vector<int> nums = {2,3,-2,4,9,95,4,3,-2,-4,5,6};    
	// vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};    
	
	auto ans = solution.maxProduct(nums);
	cout << ans << endl;
	return 0;
}



