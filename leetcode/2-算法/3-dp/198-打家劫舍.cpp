#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0],nums[1]);
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i < nums.size();i++){
            //因为i-1不能偷，所以直接用
            //i-2可以偷，所以加上可以偷的货物的价值
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            // printVector(dp);
        }
        return dp[nums.size()-1];
    }
};



int main() {
	Solution solution;
	vector<int> nums = {1,2,3,1};
	
	auto ans = solution.rob(nums);
	cout << ans << endl;
	return 0;
}



