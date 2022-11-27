#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		// if(n == 0 && m == 0)
		// 	return 0;
		vector<vector<int>> dp(n,vector<int>(m,0));
		dp[0][0] = grid[0][0];
		for(int i = 1;i < m;i++){
			dp[0][i] = dp[0][i-1] + grid[0][i];
		}
		for(int i = 1;i < n;i++){
			dp[i][0] = dp[i-1][0] + grid[i][0];
		}
		for(int i = 1;i < n;i++){
			for(int j = 1;j < m;j++){
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j];
			}
		}
		PrintVVector(dp);
		return dp[n-1][m-1];
    }
};
		
int main() {
	Solution solution;
	// vector<vector<int>> grid ={  {1,3,1},  {1,5,1},  {4,2,1}};
	// vector<vector<int>> grid ={  {1,3,1}};
	// vector<vector<int>> grid ={{1},{3},{4}};
	// vector<vector<int>> grid ={{1}};
	// vector<vector<int>> grid ={{}};
	vector<vector<int>> grid ={{1,2,5},{3,2,1}};

	PrintVVector(grid);

	auto ans = solution.maxValue(grid);

	cout << ans << endl;

	
	return 0;
}


