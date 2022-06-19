#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

//+1+1+1+1-1=3
//数组的元素和(不论正负)为sum
//负数元素和neg
//正数元素和sum-neg，就是去掉了负数部分
//表达式和target
//+(sum-neg)-neg=target
//得到neg=(sum-target)/2

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for(int i = 0;i < nums.size();i++) 
            sum += nums[i];
        int bagsize = (target + sum) / 2;

        if(abs(target) > sum) //全都加起来也没有目标大，必然没有方法
            return 0;
        if((target + sum) % 2 == 1)
            return 0;

        vector<int> dp(bagsize + 1,0);
        dp[0] = 1;
	    
        for(int i = 0;i < nums.size();i++) {
            for(int j = bagsize;j >= nums[i];j--) {
                dp[j] += dp[j - nums[i]]; //累加的动态规划的方法
                printVector(dp);  
            }
            cout << endl;
        }
        return dp[bagsize];
    }
};



int main() {
	Solution solution;
	vector<int> nums = {1,1,1,1,1,1,1,3,4,6};
	int target = 16;
	
	auto ans = solution.findTargetSumWays(nums,target);
	
	cout << ans << endl;
	return 0;
}



