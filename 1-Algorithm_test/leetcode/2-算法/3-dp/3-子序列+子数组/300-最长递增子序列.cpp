#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n,0);
        for(int i = 0;i < n;i++){
            dp[i] = 1;
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i])   // 找个比自己小的
                    dp[i] = max(dp[i] , dp[j] + 1);
            }
        }
        PrintVector(dp);
        return *max_element(dp.begin(),dp.end());
    }
};

int main() {
	Solution solution;
	// vector<int> nums = {10,9,2,5,3,7,101,18};
    // vector<int> nums = {0,1,0,3,2,3};
    // vector<int> nums = {7,7,7,7,7,7,7};
    vector<int> nums = {7,6,5,4,9,8,7};
    // vector<int> nums = {4,10,4,3,8,9};
    // vector<int> nums = {1,3,6,7,9,4,10,5,6};    // 最长连续子串不在最后
	
	auto ans = solution.lengthOfLIS(nums);
	
	cout << ans << endl;
	return 0;
}



