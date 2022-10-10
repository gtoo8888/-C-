#include <iostream>
#include <vector>
using namespace std;

#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

// TODO
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<int>> dp(n,vector<int>(m,0));
		// PrintVVector(matrix);
		int width = 0;
		
		return width*width;
    }
};

		
int main() {
	Solution solution;
	 
	vector<vector<int>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	// vector<vector<char>> matrix = {{'0','1'},{'1','0'}};
	// vector<vector<char>> matrix = {{'1'}};

	auto ans = solution.countSquares(matrix);
	cout << ans << endl;
	return 0;
}



