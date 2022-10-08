#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
		dp[0] = dp[1] = 0;
		for(int i = 2;i < n;i++){
			if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
				dp[i] += 1;
				if(dp[i-1] != 0)	// 如果上一位不为0那么可以继承上一位已有的个数
					dp[i] += dp[i-1];
			}
			// PrintVector(dp);
		}
		int sum = 0;
		for(auto num : dp){
			sum += num;
		}
		return sum;
    }
};


int main() {
	Solution solution;
	vector<int> nums = {1,2,3};    
	// vector<int> nums = {1,2,3,4};    
	// vector<int> nums = {1,2,3,4,5,6};    
	// vector<int> nums = {1,2,3,4,1,5,6,7};   

	
	auto ans = solution.numberOfArithmeticSlices(nums);
	cout << ans << endl;
	return 0;
}



