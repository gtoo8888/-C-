#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


const long long mod = 1000000007;
class Solution {
public:
    int numTilings(int n) {
		vector<vector<long long>> dp(n+1,vector<long long>(4,0));
		PrintVVector(dp);
		dp[0][3] = 1;
		for(int i = 1;i <= n;i++){
			dp[i][0] = dp[i-1][3];
			dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
			dp[i][2] = (dp[i-1][0] + dp[i-1][1])%mod;
			dp[i][3] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3])%mod;
		}
		// PrintVVector(dp);
		return dp[n][3];
    }
};


int main() {
	Solution solution;
	int n = 3;

	auto ans = solution.numTilings(n);
	
	cout << ans << endl;
	return 0;
}



