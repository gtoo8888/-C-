#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n,-1);
		int l = 0,r = n-1;
		int index = 0;
		while(l<=r){
			if(nums[index]%2 == 1)
				ans[l] = nums[index],l++;
			else
				ans[r] = nums[index],r--;
			index++;
		}
		return ans;
    }
};








int main(){
	Solution sol;
	
	vector<int> data = {1,2,3,4};
	// q:data有什么作用？
	// a:用来存储数据
	PrintVector(sol.exchange(data));
	data = vector<int>{24,51,75,78,84};
	PrintVector(sol.exchange(data));
	data = vector<int>{24,51,75,78,84};
	PrintVector(sol.exchange(data));

	
	return 0;
}
