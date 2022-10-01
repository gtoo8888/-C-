#include <iostream>
#include <vector>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    int jump(vector<int>& nums) {
		int n = nums.size();
		int maxPos = 0;
		int end = 0;
		int step = 0;
		for(int i = 0;i < n-1;i++){
			printf("%d %d %d %d\n",maxPos,i,end,step);
			if(maxPos >= i){
				maxPos = max(maxPos,i + nums[i]);
				if(i == end){	// end表示每一跳的终点
					end = maxPos;	// 每次跳到终点了，就刷新每一跳终点的位置
					step++;
				}
			}
		}
		return step;
    }
};
		
int main() {
	Solution solution;
	
	vector<int> nums = {2,3,1,1,4};
    // vector<int> nums = {2,3,1,7,0,0,0};

	auto ans = solution.jump(nums);
	
	PrintAuto(ans);
	return 0;
}



