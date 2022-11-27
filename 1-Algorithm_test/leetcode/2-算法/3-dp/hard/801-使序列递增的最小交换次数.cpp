#include <iostream>
#include <vector>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(2,vector<int>(n,0));
        for (int i = 1; i < n; i++) 
            dp[0][i] = dp[1][i] = n + 10;
        dp[0][0] = 0;
        dp[1][0] = 1;
        for(int i = 1;i < n;i++){
            if(nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]){
                dp[0][i] = dp[0][i-1];
                dp[1][i] = dp[1][i-1] + 1;
            }
            if(nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]){
                dp[0][i] = min(dp[0][i],dp[1][i-1]);
                dp[1][i] = min(dp[1][i],dp[0][i-1]+1);
            }
        }
        PrintVVector(dp);
        return min(dp[0][n-1],dp[1][n-1]);
    }
};

int main() {
	Solution solution;
	vector<int> nums1 = {1,3,5,4};
    vector<int> nums2 = {1,2,3,7};
	
	auto ans = solution.minSwap(nums1,nums2);
	
	cout << ans << endl;
	return 0;
}



