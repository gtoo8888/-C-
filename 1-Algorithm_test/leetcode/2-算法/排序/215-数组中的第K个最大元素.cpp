#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(),nums.end());
		// printVector(nums);
		return nums[nums.size() - k];
    }
};

	
int main() {
	Solution solution;
	// vector<int> nums = {3,2,1,5,6,4};
	// int k = 2;

	vector<int> nums = {3,2,3,1,2,4,5,5,6};
	int k = 4;

	auto ans = solution.findKthLargest(nums,k);
	
	cout << ans << endl;
	
	return 0;
}



