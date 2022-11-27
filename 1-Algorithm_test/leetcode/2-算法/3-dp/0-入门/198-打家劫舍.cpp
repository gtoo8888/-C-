#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0],nums[1]);
        vector<int> dp(n+1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);   // 如果有多余2个的时候，不可能就只偷第一个，选取最大值
        for(int i = 2;i < n;i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);   // dp[i-1]如果上一个偷法是对的，那就保留
            PrintVector(dp);
        }
        // return max(dp[n-1],dp[n-2]);
        return dp[n-1];
    }
};



int main() {
	Solution solution;
    // vector<int> nums = {1};      // 只有一个
    // vector<int> nums = {1,2};
    // vector<int> nums = {2,1};
    // vector<int> nums = {2,14,3};

	vector<int> nums = {1,2,3,1};    // 常规
    // vector<int> nums = {1,2,3,1,9,7};
    // vector<int> nums = {2,7,9,3,1};

    // vector<int> nums = {2,1,1,2}; // 间隔多个房间
    // vector<int> nums = {1,3,1,3,100}; // 后面的也间隔2个

	
	auto ans = solution.rob(nums);
	cout << ans << endl;
	return 0;
}



