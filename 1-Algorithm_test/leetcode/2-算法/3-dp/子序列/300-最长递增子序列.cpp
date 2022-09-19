#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for(int i = 0;i < n;i++){
            dp[i] = 1;
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i],dp[j]+1);
            }
            printVector(dp);
        }
        int ans = 0;
        for(int n : dp){
            ans = n > ans ? n : ans;
        }
        return ans;
    }
};



int main() {
	Solution solution;
	// vector<int> nums = {10,9,2,5,3,7,101,18};
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
	
	auto ans = solution.lengthOfLIS(nums);
	
	cout << ans << endl;
	return 0;
}



