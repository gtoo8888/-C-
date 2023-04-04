#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
	vector<vector<vector<int>>> dp;
	vector<int> pre;
	int k;
public:
	int dfs(int i,int j,int p){
		// PrintVVVector(this->dp);
		int &res = dp[i][j][p];
		if(res != -1)
			return res;
		if(p == 1){
			return res = i == j ? 0 : dfs(i,j,k) + pre[j+1]-pre[i];
		}
		res = INT32_MAX;
		for(int m = i;m < j;m += k-1){
			res = min(res,dfs(i,m,1) + dfs(m+1,j,p-1));
		}
		return res;
	}

    int mergeStones(vector<int>& stones, int k) {
		int n = stones.size();
		if((n-1)%(k-1) != 0)
			return -1;

		this->k = k;
		this->pre = vector<int>(n+1,0);
		pre[0] = 0;
		for(int i = 0;i < n;i++)
			pre[i+1] = stones[i] + pre[i];

		this->dp = vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        // this->dp = vector(n, vector(n, vector<int>(k + 1, -1)));

		int ans = dfs(0,n-1,1);
		return ans;
    }
};

int main() {
	Solution solution;
	vector<int> stones = {3,2,4,1};int k = 2;

	auto ans = solution.mergeStones(stones,k);
	
	cout << ans << endl;
	return 0;
}


