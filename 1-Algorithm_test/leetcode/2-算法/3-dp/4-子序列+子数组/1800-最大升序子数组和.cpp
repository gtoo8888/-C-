#include <iostream> 
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> dp(n,0);
        dp[0] = nums[0];
        int ans = nums[0];
        for(int i = 1;i < n;i++){
            if(nums[i] > nums[i-1])
                dp[i] = dp[i-1] + nums[i];
            else
                dp[i] = nums[i];
            ans = dp[i] > ans ? dp[i] : ans;
        }
        // PrintVector(dp);
        return ans;
    }
};

int main(){
	Solution solution;
	// vector<int> nums = {10,20,30,5,10,50};
    // vector<int> nums = {10,20,30,40,50};
    // vector<int> nums = {12,17,15,13,10,11,12};
    // vector<int> nums = {100,10,1};
    vector<int> nums = {2};
	
	auto ans = solution.maxAscendingSum(nums);
		
	cout << ans << endl;
	return 0;
}
