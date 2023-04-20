#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin(),arr2.end());
        vector<int>::iterator ip = unique(arr2.begin(),arr2.end()); // 找到相同的元素去掉
        arr2.erase(ip,arr2.end());
        vector<vector<int>> dp(n+1,vector<int>(min(m,n)+1,INT32_MAX));
        dp[0][0] = -1;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= min(i,m);j++){
                if(arr1[i-1] > dp[i-1][j]){
                    dp[i][j] = arr1[i-1];
                }
                if(j > 0 && dp[i-1][j-1] != INT32_MAX){
                    auto it = upper_bound(arr2.begin()+j-1,arr2.end(),dp[i-1][j-1]);
                    if(it != arr2.end())
                        dp[i][j] = min(dp[i][j],*it);
                }
                if(i == n && dp[i][j] != INT32_MAX)
                    return j;
            }
            // PrintVVector(dp);
        }
        return -1;
    }
};

int main() {
	Solution solution;
    vector<int> arr1 = {1,5,3,6,7};
    vector<int> arr2 = {1,3,2,4};

	auto ans = solution.makeArrayIncreasing(arr1,arr2);
	
	cout << ans << endl;
	return 0;
}



