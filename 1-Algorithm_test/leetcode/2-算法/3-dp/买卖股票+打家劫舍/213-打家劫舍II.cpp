#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         if(nums.size() == 1)    return nums[0];
//         if(nums.size() == 2)    return max(nums[0],nums[1]);
//         vector<int> dp1(nums.size(),0);
//         dp1[0] = nums[0];
//         dp1[1] = max(nums[0],nums[1]);
//         for(int i = 2;i < nums.size() - 1;i++){ //处理前半段
//             dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i]);
//             printVector(dp1);
//         }

//         vector<int> dp2(nums.size(),0);
//         dp2[1] = nums[1];
//         dp2[2] = max(nums[1],nums[2]);
//         for(int i = 3;i < nums.size();i++){//后半段
//             dp2[i] = max(dp2[i-1],dp2[i-2]+nums[i]);
//             printVector(dp2);
//         }
//         int ans = max(dp1[nums.size()-2],dp2[nums.size()-1]);
// 		int a=0,b=1;
// 		int c = max(a,b);
//         return ans;
//     }
// };


// 第一段[0,n-2]
// 第二段[1,n-1]
// 就可以简化为打家劫舍1处理
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0],nums[1]);
        int n = nums.size();
        vector<int> dp1(n,0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0],nums[1]);
        for(int i = 2;i <= n-2;i++){
            dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i]);
            // PrintVector(dp1);
        }
        vector<int> dp2(n,0);
        dp2[1] = nums[1];
        dp2[2] = max(nums[1],nums[2]);
        for(int i = 3;i <= n-1;i++){
            dp2[i] = max(dp2[i-1],dp2[i-2]+nums[i]);
            // PrintVector(dp2);
        }
        return max(dp1[n-2],dp2[n-1]);
    }
};



int main() {
	Solution solution;
	vector<int> nums = {12,12};
	
	auto ans = solution.rob(nums);
	cout << ans << endl;
	return 0;
}



