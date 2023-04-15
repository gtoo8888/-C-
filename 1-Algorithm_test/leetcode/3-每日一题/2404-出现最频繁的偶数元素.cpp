#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
		int n = nums.size();
		unordered_map<int,int> mp;
		for(auto it : nums){
			if(it%2 == 0)
				mp[it]++;
		}
		int max_odd = 0;
		for(auto it : mp){
			max_odd = max(max_odd,it.second);
		}
		int ans = INT32_MAX;
		for(auto it : mp){
			if(it.second == max_odd)
				ans = min(ans,it.first);
		}
		if(ans == INT32_MAX)
			return -1;
		return ans;
    }
};

	
int main() {
	Solution solution;
	vector<int> nums;
	nums = vector<int>{0,1,2,2,4,4,1};
	cout << solution.mostFrequentEven(nums) << endl;

	nums = vector<int>{4,4,4,9,2,4};
	cout << solution.mostFrequentEven(nums) << endl;

	nums = vector<int>{29,47,21,41,13,37,25,7};
	cout << solution.mostFrequentEven(nums) << endl;

	nums = vector<int>{0,0,0,0};
	cout << solution.mostFrequentEven(nums) << endl;

	return 0;
}



