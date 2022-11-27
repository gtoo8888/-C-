#include <algorithm> 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// 错误思路
// class Solution {
// public:
//     bool isStraight(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n = nums.size();
//         for(int i = 0;i < n-1;i++){
//             if( !(nums[i] == nums[i+1] - 1 || nums[i] == nums[i+1] ))
//                 return false;
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool isStraight(vector<int>& nums) {
		if(nums.size() == 0)
			return false;
		int king = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i < n-1;i++){
            if(nums[i] == 0)
				king++;
			else if(nums[i] == nums[i+1])
				return false;
        }
        return nums[4] - nums[king] < 5;
    }
};



int main(){
	Solution sol;
	// vector<int> nums = {1,2,3,4,5};	// 功能测试
	// vector<int> nums = {0,0,1,2,5};
	// vector<int> nums = {0,0,1,2,6};

	vector<int> nums = {};	// 特殊输入测试

	auto ans = sol.isStraight(nums);
	PrintBool(ans);
	return 0;
}
