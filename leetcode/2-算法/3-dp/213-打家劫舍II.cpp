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
        vector<int> dp1(nums.size(),0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0],nums[1]);
        for(int i = 2;i < nums.size() - 1;i++){ //处理前半段
            dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i]);
            printVector(dp1);
        }

        vector<int> dp2(nums.size(),0);
        dp2[1] = nums[1];
        dp2[2] = max(nums[1],nums[2]);
        for(int i = 3;i < nums.size();i++){//后半段
            dp2[i] = max(dp2[i-1],dp2[i-2]+nums[i]);
            printVector(dp2);
        }
        int ans = max(dp1[nums.size()-2],dp2[nums.size()-1]);
		int a=0,b=1;
		int c = max(a,b);
        return ans;
    }
};



int main() {
	Solution solution;
	vector<int> nums = {12,12};
	
	auto ans = solution.rob(nums);
	cout << ans << endl;
	return 0;
}



