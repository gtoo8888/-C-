#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


// 超时做法
// class Solution {
// public:
//     int numberOfPaths(vector<vector<int>>& grid, int k) {
//     	int n = grid.size();
//     	int m = grid[0].size();
//     	vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(0,0)));
//         dp[0][0] = vector<int>(1,grid[0][0]);
// 		for(int i = 1;i < n;i++){
// 			// printf("%d %d\n",grid[i][0] , dp[i-1][0][0]);
// 			dp[i][0] = vector<int>(1,grid[i][0] + dp[i-1][0][0]);
// 		}
// 		for(int i = 1;i < m;i++){
// 			dp[0][i] = vector<int>(1,grid[0][i] + dp[0][i-1][0]);
// 		}
// 		for(int i = 1;i < n;i++){
// 			for(int j = 1;j < m;j++){
// 				vector<int> tmp;
// 				for(int l = 0;l < dp[i - 1][j].size();l++)
// 					tmp.push_back(dp[i - 1][j][l] + grid[i][j]);
// 				for(int l = 0;l < dp[i][j - 1].size();l++)
// 					tmp.push_back(dp[i][j - 1][l] + grid[i][j]);
// 				dp[i][j] = tmp;
// 			}
// 		}		
// 		PrintVector(dp[n-1][m-1]);	
// 		int ans = 0;
// 		for(int l = 0;l < dp[n-1][m-1].size();l++){
// 			// printf("%d ",dp[n-1][m-1][l]);
// 			if(dp[n-1][m-1][l] % k == 0)
// 				ans++;
// 			ans %= 1000000008;
// 		}	
// 		// return dp[n-1][m-1];
// 		return ans;
//     }
// };


class Solution {
public:
	const int MOD = 1000000007;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
    	int n = grid.size();
    	int m = grid[0].size();
    	vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,0)));
        dp[0][0][grid[0][0] % k] = 1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				for(int l = 0;l < k;l++){
					printf("%d %d %d\n",grid[i][j],(l+grid[i][j])%k,l+grid[i][j]);
					if(i >= 1)  dp[i][j][(l+grid[i][j])%k] = ( dp[i-1][j][l] + dp[i][j][(l+grid[i][j])%k] ) % MOD;
					if(j >= 1)  dp[i][j][(l+grid[i][j])%k] = ( dp[i][j-1][l] + dp[i][j][(l+grid[i][j])%k] ) % MOD;
				}	
				cout << endl;
			}
		}		
		PrintVVVector(dp);
		return dp[n-1][m-1][0];
    }
};
		
int main() {
	Solution solution;
	vector<vector<int>> grid = {{5,2,4},{3,0,5},{0,7,2}};
    int k = 3;

	// vector<vector<int>> grid = {{7,3,4,9},{2,3,6,2},{2,3,7,0}};
    // int k = 1;

	auto ans = solution.numberOfPaths(grid,k);	
	cout << ans << endl;
	return 0;
}



