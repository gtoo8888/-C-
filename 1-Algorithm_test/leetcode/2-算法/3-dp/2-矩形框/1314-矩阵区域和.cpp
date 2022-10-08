#include <iostream>
#include <vector>
using namespace std;

#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<int>> ans(n,vector<int>(m,0));
		for(int i = 0;i < m;i++){
			ans[0][i] = matrix[0][i];
		}
		for(int i = 1;i < n;i++){
			for(int j = 0;j < m;j++){
				// printf("%d %d %d\n",ans[i-1][j-1],ans[i-1][j],ans[i-1][j+1]);
				if(j == 0 )
					ans[i][j] = min(ans[i-1][j],ans[i-1][j+1]) + matrix[i][j];
				else if(j == m-1)
					ans[i][j] = min(ans[i-1][j],ans[i-1][j-1]) + matrix[i][j];
				else
					ans[i][j] = min(min(ans[i-1][j-1],ans[i-1][j]),ans[i-1][j+1]) + matrix[i][j];
			}
		}
		PrintVVector(ans);
		int out = INT32_MAX;
		for(int i = 0;i < m;i++){
			out = ans[n-1][i] < out ? ans[n-1][i] : out;
		}
		return out;
    }
};
		
int main() {
	Solution solution;
	 
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
	// vector<vector<int>> matrix = {{-19,57},{-40,-5}};

	auto ans = solution.minFallingPathSum(matrix);
	cout << ans << endl;
	return 0;
}



