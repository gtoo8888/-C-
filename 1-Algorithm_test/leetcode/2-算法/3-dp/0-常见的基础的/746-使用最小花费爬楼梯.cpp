#include <iostream> 
#include <vector>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//     	int n = cost.size();
// 		vector<int> dp(n+1);
// 		dp[0] = cost[0];
// 		dp[1] = cost[1];
// 		for(int i = 2;i < n;i++){
// 			dp[i] = min(dp[i - 1],dp[i - 2]) + cost[i];
//  		}
//  		PrintVector(dp);
//  		return min(dp[n - 1],dp[n - 2]);
//     }
// };


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		vector<int> dp(n+1,0);
		dp[0] = cost[0];dp[1] = cost[1];
		for(int i = 2;i < n;i++){
			dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
		}
		dp[n] = min(dp[n-1],dp[n-2]);
		PrintVector(dp);
		return dp[n];
    }
};

int main(){
	Solution sol;
	// vector<int> cost = {1,2};
	vector<int> cost = {10,15,20};
	// vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
	
	auto ans = sol.minCostClimbingStairs(cost);
	cout << ans << endl;
	return 0;
}
