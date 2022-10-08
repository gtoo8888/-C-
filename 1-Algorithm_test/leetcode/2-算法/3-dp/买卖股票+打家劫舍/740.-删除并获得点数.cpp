#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0],nums[1]);
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i < nums.size();i++){
            //因为i-1不能偷，所以直接用
            //i-2可以偷，所以加上可以偷的货物的价值
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            PrintVector(dp);
        }
        return dp[nums.size()-1];
    }

    int deleteAndEarn(vector<int>& nums){   // 转化以后就成了打家劫舍
        int n = nums.size();
        int max_nums = 0;
        for(int i = 0;i < n;i++){
            max_nums = max(max_nums,nums[i]);
        }
        vector<int> djjs(max_nums+1,0);
        for(int i = 0;i < n;i++){
            djjs[nums[i]] += nums[i];
        }
        PrintVector(djjs);
        return rob(djjs);
    }
};



int main() {
	Solution solution;
	// vector<int> nums = {3,4,2};
    vector<int> nums = {2,2,3,3,3,4};
	
	auto ans = solution.deleteAndEarn(nums);
	cout << ans << endl;
	return 0;
}



