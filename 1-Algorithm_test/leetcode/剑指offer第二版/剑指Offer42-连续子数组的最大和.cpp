#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        for(int i = 1;i < n;i++){   
            if(dp[i-1] >= 0)    // 如果是正的就累积下来
                dp[i] = dp[i-1]+nums[i];
            else    // 如果是负的就重新计数
                dp[i] = nums[i];
            PrintVector(dp);
        }
        // 最终得到的dp数组不能作为答案，还需要取最大值
        int max = INT32_MIN;
        for(int i = 0;i < dp.size();i++){
            max = dp[i] > max ? dp[i] : max;
        }
        return max;
    }
};


	
int main() {
	Solution sol;
	// vector<int> numbers = {-2,1,-3,4,-1,2,1,-5,4};
    // vector<int> numbers = {-10,6,2,40,-2};
    // vector<int> numbers = {-10,-1,-4,-6,-9};
    vector<int> numbers = {1,2,3,4,5};

	auto ans = sol.maxSubArray(numbers);
	cout << ans << endl;
	
	return 0;
}



