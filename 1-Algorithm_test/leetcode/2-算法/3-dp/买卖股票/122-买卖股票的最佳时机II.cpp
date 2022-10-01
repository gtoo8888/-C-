#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVVector(vector<vector<int>> v){
	for(auto iter = v.begin();iter != v.end();iter++){
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int len = prices.size();
//         vector<vector<int> > dp(len,vector<int>(2));
//         dp[0][0] -= prices[0];  //第i天持有股票所得最多现金
//         dp[0][1] = 0;           //第i天不持有股票所得最多现金
// 		int sum = 0;
//         for(int i = 1;i < prices.size();i++) {

//             dp[i][0] = max(dp[i-1][0],dp[i-1][1] - prices[i]);
//             dp[i][1] = max(dp[i-1][1],dp[i-1][0] + prices[i]);
//           	// printf("   %d     = max(   %d ,  %d - %d);\n",dp[i][0],dp[i-1][0],dp[i-1][1],prices[i]);
// 			// printf("dp[%d][0] = max(dp[%d][0],dp[%d][1] - prices[%d]);\n",i,i-1,i-1,i);
// 			// printf("   %d     = max(   %d ,  %d + %d);\n",dp[i][1],dp[i-1][1],dp[i-1][0],prices[i]);
// 			// printf("dp[%d][1] = max(dp[%d][1],dp[%d][0] + prices[%d]);\n",i,i-1,i-1,i);
//             // PrintVVector(dp);
//         }
//         return dp[len-1][1];//肯定是买掉划算
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
		for(int i = 0;i < n-1;i++){
			if(prices[i+1] > prices[i])
				ans += prices[i+1] - prices[i];
		}
        return ans;
    }
};



int main() {
	Solution solution;
	// vector<int> prices = {7,1,5,3,6,4};
	vector<int> prices = {1,2,3,4,5};
	
	auto ans = solution.maxProfit(prices);
	
	cout << ans << endl;
	return 0;
}



