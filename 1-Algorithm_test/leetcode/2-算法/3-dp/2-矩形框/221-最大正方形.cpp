#include <iostream>
#include <vector>
using namespace std;

#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<int>> dp(n,vector<int>(m,0));
		// PrintVVector(matrix);
		int width = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(matrix[i][j] == '1'){
					if(i == 0 || j == 0)
						dp[i][j] = 1;
					else
						dp[i][j] = min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]) + 1;
				}
				width = max(dp[i][j],width);
			}	
		}
		// PrintVVector(dp);
		return width*width;
    }
};

		
int main() {
	Solution solution;
	 
	vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	// vector<vector<char>> matrix = {{'0','1'},{'1','0'}};
	// vector<vector<char>> matrix = {{'1'}};

	auto ans = solution.maximalSquare(matrix);
	cout << ans << endl;
	return 0;
}



