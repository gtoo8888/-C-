#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
		int n = nums.size();
        vector<int> sub(n-1,0);
        for(int i = 0;i < n-1;i++)
            sub[i] = nums[i+1] - nums[i];
        PrintVector(sub);
		vector<int> dp(n,0);
        return -1;
    }
};

int main() {
	Solution solution;
	// vector<int> nums = {1,7,4,9,2,5};
    // vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
	
	auto ans = solution.wiggleMaxLength(nums);
	
	cout << ans << endl;
	return 0;
}



