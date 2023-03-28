#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
// 		int n = prices.size();
// 		if(n == 0)
// 			return 0;
// 		vector<int> dp(n,0);
// 		for(int i = 1;i < n;i++){
// 			int min_cost = *min_element(prices.begin(),prices.begin()+i);
// 			dp[i] = max(dp[i-1],prices[i] - min_cost);
// 		}
// 		// PrintVector(dp);
// 		return dp[n-1];
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if(n == 0)
			return 0;
		vector<int> dp(n,0);
		int min_cost = prices[0];
		for(int i = 1;i < n;i++){
			min_cost = min(min_cost,prices[i]);
			dp[i] = max(dp[i-1],prices[i] - min_cost);
		}
		// PrintVector(dp);
		return dp[n-1];
    }
};


int main(){
	Solution sol;
	vector<int> prices = {7,1,5,3,6,4};
	auto ans = sol.maxProfit(prices);
	cout << ans << endl;
	return 0;
}
