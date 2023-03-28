#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
		int n = nums.size();
        int l = 0,r = 1;
		unordered_set<int> uset;
		while(r < n){
			int sum = nums[l] + nums[r];
			l++,r++;
			if(uset.find(sum) == uset.end()){
				uset.insert(sum);
			}else{
				return true;
			}
		}
		return false;
    }
};

	
int main() {
	Solution solution;
	// vector<int> nums = {4,2,4};
	vector<int> nums = {1,2,3,4,5,6};
	auto ans = solution.findSubarrays(nums);
	
	PrintBool(ans);
	return 0;
}



