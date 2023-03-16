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
		int n = grid.size(),m = grid[0].size();
		vector<vector<int>> dp(n,vector<int>(m,0));
		dp[0][0] = grid[0][0];
		for(int i = 1;i < n;i++)
			dp[i][0] = grid[i][0] + dp[i-1][0];
		for(int j = 1;j < m;j++)
			dp[0][j] = grid[0][j] + dp[0][j-1];
		for(int i = 1;i < n;i++){
			for(int j = 1;j < m;j++){
				dp[i][j] = grid[i][j] + max(dp[i-1][j],dp[i][j-1]);
			}
		}
		// PrintVVector(dp);
		return dp[n-1][m-1];
    }
};
		
int main() {
	Solution solution;
	// vector<vector<int>> grid ={  {1,3,1},  {1,5,1},  {4,2,1}};
	// vector<vector<int>> grid ={  {1,3,1}};
	// vector<vector<int>> grid ={{1},{3},{4}};
	// vector<vector<int>> grid ={{1}};
	vector<vector<int>> grid ={{1,2,5},{3,2,1}};

	PrintVVector(grid);

	auto ans = solution.maxValue(grid);

	cout << ans << endl;

	
	return 0;
}


