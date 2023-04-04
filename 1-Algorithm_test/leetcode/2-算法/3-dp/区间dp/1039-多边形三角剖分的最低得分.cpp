#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
    vector<vector<int>> dp;
public:
    int dfs(int i,int j,vector<int> values){
        if(i+1 == j)
            return 0;
        int &res = dp[i][j];
        if(res != -1)
            return res;
        res = INT32_MAX;
        for(int k = i+1;k < j;k++){
            res = min(res, dfs(i,k,values) + dfs(k,j,values) + values[i]*values[j]*values[k]);
        }
        return res;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp = vector<vector<int>>(n,vector<int>(n,-1));
        return dfs(0,n-1,values);
    }
};

int main() {
	Solution solution;
	vector<int> nums = {3,7,4,5};
	
	auto ans = solution.minScoreTriangulation(nums);
	
	cout << ans << endl;
	return 0;
}



