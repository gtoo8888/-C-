#include <iostream>
#include <vector>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		int m = triangle[n-1].size();
		vector<vector<int>> ans(n,vector<int>(m,0));
		ans[0][0] = triangle[0][0];
		for(int i = 1;i < n;i++){
			for(int j = 0;j <= i;j++){
				// printf("%d %d %d\n",ans[i-1][j-1],ans[i-1][j],ans[i-1][j+1]);
				if(j == 0)
					ans[i][j] = ans[i-1][j] + triangle[i][j];
				else if(j == i)
					ans[i][j] = ans[i-1][j-1] + triangle[i][j];
				else
					ans[i][j] = min(ans[i-1][j-1],ans[i-1][j]) + triangle[i][j];
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

// TODO 可以做空间优化
		
int main() {
	Solution solution;
	 
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
	// vector<vector<int>> triangle = {{-10}};

	auto ans = solution.minimumTotal(triangle);
	cout << ans << endl;
	return 0;
}



