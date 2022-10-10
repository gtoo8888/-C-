#include <iostream>
#include <vector>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"



class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
		vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0] = 0;
		dp[1][0] = -prices[0];
		for(int i = 1;i < n;i++){
			dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i] - fee);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]);
		}
		// PrintVVector(dp);
        return dp[0][n - 1];
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2));
//         dp[0][0] = 0, dp[0][1] = -prices[0];
//         for (int i = 1; i < n; ++i) {
//             dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
//             dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
//         }
// 		PrintVVector(dp);
//         return dp[n - 1][0];
//     }
// };


int main() {
	Solution solution;
	vector<int> prices = {1, 3, 2, 8, 4, 9};
	int free = 2;


	// vector<int> prices = {1,2,3,4,5};
	
	auto ans = solution.maxProfit(prices,free);
	
	cout << ans << endl;
	return 0;
}



