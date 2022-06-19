#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}



class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1,0);
        dp[0] = 1;
        for(int j = 0;j <= target;j++) {
            for(int i = 0;i < nums.size();i++) {
                if(j - nums[i] >= 0 && dp[j] < INT_MAX - dp[j - nums[i]])
                  dp[j] += dp[j - nums[i]];
                printVector(dp);
            }
            cout << endl;
        }
        return dp[target];
    }
};



int main() {
	Solution solution;
	vector<int> nums = {1,2,3};
	int target = 4;
	
	auto ans = solution.combinationSum4(nums,target);
	
	cout << ans << endl;
	return 0;
}



