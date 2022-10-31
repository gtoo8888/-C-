#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


int gcd_t(int a,int b) { return b?gcd_t(b,a%b):a;}

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> gcd(n);
        for(int i = 0;i < n;i++){
            if(gcd_t(nums[i],k) == k)
                gcd[i] = 1;
            else 
                gcd[i] = 0;
        }
        // printf("%d\n",gcd_t(27,3));
        // PrintVector(gcd);
        vector<int> dp(n);
        if(n == 1){
            if(gcd[0] == 1)
                return 1;
            else
                return 0;
        }

        if(gcd[0] == 1)
            dp[0] = 1;
        else
            dp[0] = 0;
        for(int i = 1;i < n;i++){
            if(gcd[i] == 1)
                dp[i] += dp[i-1] + 1;
            else
                dp[i] = dp[i-1];
        }
        // PrintVector(dp);
        return dp[n-1];
    }
};
	
int main() {
	Solution solution;
    // vector<int> nums = {9,3,1,2,6,3};
    // int k = 3;

    vector<int> nums = {4};
    int k = 7;


    auto ans = solution.subarrayGCD(nums,k);

	cout << ans << endl;
	return 0;
}




