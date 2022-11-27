#include <iostream> 
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int len = prices.size();
//         vector<vector<int> > dp(len,vector<int>(2));
//         dp[0][0] -= prices[0];  //第i天持有股票所得最多现金
//         dp[0][1] = 0;           //第i天不持有股票所得最多现金
//         for(int i = 1;i < prices.size();i++) {
          
//             dp[i][0] = max(dp[i-1][0],-prices[i]);//一个一个看下来，买股票需要花的钱最少的
//             dp[i][1] = max(dp[i-1][1],dp[i-1][0] + prices[i]);//拿在手上的钱，付掉买入股票后的钱

//             PrintVVector(dp);
//         }
//         return dp[len-1][1];//肯定是买掉划算
//     }
// };


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
// 		int n = prices.size();
// 		if(n == 1)
// 			return 0;
// 		int minPrice = prices[0];
// 		vector<int> dp(n+1);
// 		dp[1] = prices[0];
// 		for(int i = 1;i < n;i++){
// 			minPrice = min(minPrice,prices[i]);
// 			dp[i] = max(dp[i-1],prices[i] - minPrice);
// 			PrintVector(dp);
// 		}	
// 		return dp[n-1];
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int low = INT32_MAX;
		int price = 0;
		for(int i = 0;i < prices.size();i++){
			low = min(prices[i],low);
			price = max(prices[i] - low,price);
		}
		return price;
    }
};

int main(){
	Solution solution;
	// vector<int> prices = {5,1,5,3,6,4};
	// vector<int> prices = {7,6,4,3,1};
	vector<int> prices = {1};
	
	auto ans = solution.maxProfit(prices);
	cout << ans << endl;
	return 0;
}
