#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n);
		dp[0] = nums[0];
		for(int i = 1;i < n;i++){
			if(dp[i-1] > 0)
				dp[i] = max(dp[i-1]+nums[i],nums[i]);
			else
				dp[i] = nums[i];
		}
		// PrintVector(dp);
		return *max_element(dp.begin(),dp.end());
    }
};


int main() {
	Solution solution;
	// vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};    
	vector<int> nums = {5,4,-1,7,8};    
	
	auto ans = solution.maxSubArray(nums);
	cout << ans << endl;
	return 0;
}



