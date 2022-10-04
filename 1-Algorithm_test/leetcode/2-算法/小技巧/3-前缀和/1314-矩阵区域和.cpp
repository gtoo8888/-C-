#include <iostream>
#include <vector>
using namespace std;

#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


class Solution {
public:
	int n ;
	int m ;
	vector<vector<int>> pre;
	int sumRegion(int x1,int y1,int x2,int y2){
		x1++;x2++;y1++;y2++;
		return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
	}

	int xianzhi_n(int pos){
		if(pos < 0)
			return 0;
		else if(pos > n-1)
			return n-1;
		return pos;
	}

	int xianzhi_m(int pos){
		if(pos < 0)
			return 0;
		else if(pos > m-1)
			return m-1;
		return pos;
	}

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
		n = mat.size();
		m = mat[0].size();
		pre.resize(n+1,vector<int>(m+1,0));
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + mat[i-1][j-1];
			}
		}
		// PrintVVector(pre);
		// cout << sumRegion(0,0,1,1) << endl;
		vector<vector<int>> ans(n,vector<int>(m,0));
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				// printf("%d %d %d %d\n",xianzhi_n(i-k),xianzhi_m(j-k),xianzhi_n(i+k),xianzhi_m(j+k));
				// cout << sumRegion(xianzhi_n(i-k),xianzhi_m(j-k),xianzhi_n(i+k),xianzhi_m(j+k)) << endl;
				ans[i][j] = sumRegion(xianzhi_n(i-k),xianzhi_m(j-k),xianzhi_n(i+k),xianzhi_m(j+k));
			}
		}
		return ans;
    }
};
		
int main() {
	Solution solution;
	
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
	int k = 1;

	PrintVVector(mat);
	auto ans = solution.matrixBlockSum(mat,k);
	PrintVVector(ans);
	return 0;
}



