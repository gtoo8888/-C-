#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> uset;
		int n = nums.size();
		for(int i = 0;i < n;i++){
			uset.insert(nums[i]);
		}
		int ans = 0;
		for(int i = 0;i < n;i++){
			int i_num = nums[i],j_num = nums[i] + diff,k_num = nums[i] + 2*diff;
			if(uset.find(j_num) != uset.end() && uset.find(k_num) != uset.end())
				ans++;
		}
		return ans;
    }
};


int main(){
	Solution sol;
	// vector<int> nums = {0,1,4,6,7,10};int diff = 3;
	vector<int> nums = {4,5,6,7,8,9};int diff = 2;

	auto ans = sol.arithmeticTriplets(nums,diff);
	cout << ans << endl;
    return 0;
}


