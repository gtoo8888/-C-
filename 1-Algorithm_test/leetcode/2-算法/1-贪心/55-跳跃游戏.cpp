#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
		int n = nums.size();
		vector<int> max_len(n);
		int max_jump = 0;
		for(int i = 0;i < n;i++){
			if(i > max_jump){
				// printf("%d %d\n",i,max_jump);
				return false;
			}
			max_jump = max(max_jump, i + nums[i]);	// 当前坐标+能跳的距离，就是能跳的最远距离
			max_len[i] = max_jump;
			// PrintVector(max_len);
		}
		return true;
    }
};
		
int main() {
	Solution solution;
	
	vector<int> nums = {0,0};
    // vector<int> nums = {2,3,1,7,0,0,0};

	auto ans = solution.canJump(nums);
	
	PrintBool(ans);
	return 0;
}



