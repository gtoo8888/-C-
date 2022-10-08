#include <iostream>
#include <vector>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	int row = obstacleGrid.size();
    	int line = obstacleGrid[0].size();
    	vector<vector<int>> dp(row,vector<int>(line,0));
		for(int i = 0;i < row;i++){
			if(obstacleGrid[i][0] == 1)
				break;
			dp[i][0] = 1;
		}
		for(int i = 0;i < line;i++){
			if(obstacleGrid[0][i] == 1)
				break;
			dp[0][i] = 1;
		}
		for(int i = 1;i < row;i++){
			for(int j = 1;j < line;j++){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				if(obstacleGrid[i][j] == 1)
					dp[i][j] = 0;
			}
		}			
		// PrintVVector(dp);
		return dp[row-1][line-1];
    }
};
		
int main() {
	Solution solution;
	vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};

	auto ans = solution.uniquePathsWithObstacles(obstacleGrid);	
	cout << ans << endl;
	return 0;
}



