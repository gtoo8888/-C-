#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n, 0));
		dp[0][0] = -prices[0];
		dp[1][0] = 0;
		dp[2][0] = 0;
		for(int i = 1; i < n; i++){
            dp[0][i] = max(dp[0][i-1],dp[2][i-1] - prices[i]);
            dp[1][i] = dp[0][i-1] + prices[i];
            dp[2][i] = max(dp[1][i-1],dp[2][i-1]);
        }
		// PrintVVector(dp);
		return max(dp[2][n-1],dp[1][n-1]);
    }
};



int main() {
	Solution solution;
	
	// vector<int> prices = {7,1,5,3,6,4};
	vector<int> prices = {1,2,3,0,2};
	
	auto ans = solution.maxProfit(prices);
	
	cout << ans << endl;
	return 0;
}



