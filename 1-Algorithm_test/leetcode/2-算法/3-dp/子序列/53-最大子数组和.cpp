#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n+1);
		dp[0] = nums[0];
		for(int i = 1;i < n;i++){
			dp[i] = max(dp[i-1] + nums[i],dp[i-1]);
			PrintVector(dp);
		}
		return dp[n-1];
    }
};


int main() {
	Solution solution;
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};    
	
	auto ans = solution.maxSubArray(nums);
	cout << ans << endl;
	return 0;
}



