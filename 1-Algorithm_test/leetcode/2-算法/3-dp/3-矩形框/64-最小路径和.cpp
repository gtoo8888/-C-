#include <iostream>
#include <vector>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> ans(n,vector<int>(m,0));
		ans[0][0] = grid[0][0];
		for(int i = 1;i < m;i++){
			ans[0][i] = grid[0][i] + ans[0][i-1];
		}
		for(int i = 1;i < n;i++){
			ans[i][0] = grid[i][0] + ans[i-1][0];
		}
		for(int i = 1;i < n;i++){
			for(int j = 1;j < m;j++){
				// printf("%d %d %d\n",ans[i-1][j-1],ans[i-1][j],ans[i-1][j+1]);
				ans[i][j] = grid[i][j] + min(ans[i-1][j],ans[i][j-1]);
			}
		}
		// PrintVVector(ans);
		return ans[n-1][m-1];
    }
};

// TODO 可以做空间优化
		
int main() {
	Solution solution;
	 
    // vector<vector<int>> grid =  {{1,3,1},{1,5,1},{4,2,1}};
	vector<vector<int>> grid = {{1,2,3},{4,5,6}};

	auto ans = solution.minPathSum(grid);
	cout << ans << endl;
	return 0;
}



