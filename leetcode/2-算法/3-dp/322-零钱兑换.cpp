#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1,INT_MAX);
        dp[0] = 0;
        for(int i = 0;i < coins.size();i++) {
            for(int j = coins[i];j <= amount;j++) {
                cout << dp[j] << " " << dp[j - coins[i]]  + 1 << endl;
                if(dp[j - coins[i]] != INT_MAX) 
                    dp[j] = min(dp[j],dp[j - coins[i]]  + 1);
                
                printVector(dp);
            }
            cout << endl;
        }
        if(dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};



int main() {
	Solution solution;
	vector<int> coins = {1};
	int amount = 0;
	
	auto ans = solution.coinChange(coins,amount);
	
	cout << ans << endl;
	return 0;
}



