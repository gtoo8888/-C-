#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// 代码随想录
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount + 1,INT32_MAX);
//         dp[0] = 0;
//         for(int i = 0;i < coins.size();i++) {
//             for(int j = coins[i];j <= amount;j++) {
//                 cout << dp[j] << " " << dp[j - coins[i]]  + 1 << endl;
//                 if(dp[j - coins[i]] != INT32_MAX) 
//                     dp[j] = min(dp[j],dp[j - coins[i]]  + 1); 
//             }
//             PrintVector(dp);
//             cout << endl;
//         }
//         if(dp[amount] == INT32_MAX)
//             return -1;
//         return dp[amount];
//     }
// };


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i = 1;i <= amount;i++){
            for(int j = 0;j < n;j++){
                if(coins[j] <= i){
                    printf("i:%d j:%d dp[%d]+1=%d\n",i,j,i-coins[j],dp[i-coins[j]]+1);
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
            cout << endl;
        }
        PrintVector(dp);
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
	Solution solution;
	vector<int> coins = {1,2,5};
	int amount = 11;

    // vector<int> coins = {1,2,5};
	// int amount = 13;
	
    // vector<int> coins = {2};
	// int amount = 3;

    // vector<int> coins = {1};
	// int amount = 0;

	auto ans = solution.coinChange(coins,amount);
	
	cout << ans << endl;
	return 0;
}



