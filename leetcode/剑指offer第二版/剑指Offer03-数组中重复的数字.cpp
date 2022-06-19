#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {	
		unordered_set<int> set;
		for(int i = 0;i < nums.size();i++) {
			pair<unordered_set<int>::iterator,bool> res = set.insert(nums[i]);
//			cout << res.second << endl;
			if(res.second == false)
				return nums[i];
		}
		return 0;	
    }
};


	
int main() {
	Solution sol;
	vector<int> nums = {2, 3, 1, 0, 2, 5, 3};	
	auto ans = sol.findRepeatNumber(nums);
	cout << ans << endl;
	
	return 0;
}



