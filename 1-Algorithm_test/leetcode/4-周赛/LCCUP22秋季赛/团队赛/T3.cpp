#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


class Solution {
public:
	vector<vector<int>> ans;
	vector<int> path;
	void backtraking(vector<int> nums,vector<bool> used) {
		if(path.size() == nums.size()) {
			ans.push_back(path);
			return;
		}
		
		for(int i = 0;i < nums.size();i++) {
			if(used[i] == true) continue;
			path.push_back(nums[i]);
			used[i] = true;
//			PrintVector(path);
			backtraking(nums,used);
			used[i] = false;
			path.pop_back();
		}
	}
	
    vector<vector<int>> permute(vector<int>& nums) {
		ans.clear();
		path.clear();
		vector<bool> used(nums.size(),false);
		backtraking(nums,used);
		return ans;
    }
};

	
int main() {
	Solution solution;
	vector<int> nums = {1,2,3,4,5}; 

	
	auto ans = solution.permute(nums);
	
	
	PrintVVector(ans);
	
	return 0;
}

