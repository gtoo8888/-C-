#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
		int n = nums.size();
		if(n == 1 && nums[0] > 0)
			return 1;
		else if(n == 1 && nums[0] <= 0)
			return 0;
		vector<int> positive(n,0);
		vector<int> nagetive(n,0);
		int max_len = 0;
		if(nums[0] > 0){
			positive[0] = 1;
		}else if(nums[0] < 0){
			nagetive[0] = 1;
		}
		for(int i = 1;i < n;i++){
			if(nums[i] > 0){
				positive[i] = positive[i-1]+1;
				if(nagetive[i-1] > 0)
					nagetive[i] = nagetive[i-1]+1;
				else if(nagetive[i-1] == 0)
					nagetive[i] = 0;
			}else if(nums[i] < 0){
				nagetive[i] = positive[i-1]+1;
				if(nagetive[i-1] > 0)
					positive[i] = nagetive[i-1]+1;
				else if(nagetive[i-1] == 0)
					positive[i] = 0;
			}else if(nums[i] == 0){
				positive[i] = 0;
				nagetive[i] = 0;
			}
			// PrintVector(positive);
			// PrintVector(nagetive);
			max_len = max(max_len,positive[i]);
			// cout << endl;
		}
		return max_len;
    }
};


int main() {
	Solution solution;
	// vector<int> nums = {1,-2,-3,4};     
	// vector<int> nums = {1,-2,-3,4,8,-1,5}; 
	// vector<int> nums = {1,-2,-3,4,0,1,-1};     
	// vector<int> nums = {123};     
	vector<int> nums = {-2};     
	
	auto ans = solution.getMaxLen(nums);
	cout << ans << endl;
	return 0;
}



