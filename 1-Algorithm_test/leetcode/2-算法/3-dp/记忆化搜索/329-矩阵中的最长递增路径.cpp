#include <iostream>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 仅仅使用dfs还不会写


// dfs+记忆化搜索
static const int dis[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
class Solution {
    int cols,rows;
    vector<vector<int>> memo;
public:
    int dfs(int x,int y,vector<vector<int>>& matrix){
        if(memo[x][y] != 0)
            return memo[x][y];
        memo[x][y]++;
        for(int i = 0;i < 4;i++){
            int x_now = x + dis[i][0];
            int y_now = y + dis[i][1];
            if(x_now >= 0 && x_now < rows && y_now >= 0 && y_now < cols && matrix[x_now][y_now] > matrix[x][y]){
                memo[x][y] = max(memo[x][y],dfs(x_now,y_now,matrix)+1);
            }
        }
        return memo[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // PrintVVector(matrix);
        rows = matrix.size();
        cols = matrix[0].size();
        this->memo = vector<vector<int>>(rows,vector<int>(cols,0));
        int ans = -1;
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                ans = max(ans,dfs(i,j,matrix));
            }
        }
        // PrintVVector(memo);
        return ans;
    }
};


	
int main() {
	Solution solution;
	// vector<vector<int>> matrix  = {{9,9,4},{6,6,8},{2,1,1}};
    // vector<vector<int>> matrix  = {{3,4,5},{3,2,6},{2,2,1}};
    // vector<vector<int>> matrix  = {{1}};
    vector<vector<int>> matrix  = {{1,2}};
	
	auto ans = solution.longestIncreasingPath(matrix);
	
	cout << ans << endl;
	
	return 0;
}



