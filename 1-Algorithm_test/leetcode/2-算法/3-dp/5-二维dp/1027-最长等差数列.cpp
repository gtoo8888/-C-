#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(1001,0));
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < i; ++k) {
                int j = nums[i] - nums[k] + 500;
                dp[i][j] = max(dp[i][j], dp[k][j] + 1);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans + 1;
    }
};




int main() {
	Solution solution;
	vector<int> nums = {3,6,9,12};    
	
	auto ans = solution.longestArithSeqLength(nums);
	
	cout << ans << endl;
	return 0;
}



