#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

// 不可以使用平均数
// class Solution {
// public:
//     int minMoves2(vector<int>& nums) {
// 		int sum = 0;
// 		int n = nums.size();
// 		for(int i = 0;i < n;i++)
// 			sum += nums[i];
// 		int average = sum/n;
// 		int ans = 0;
// 		printf("%d %d\n",average,sum);
// 		for(int i = 0;i < n;i++){
// 			ans += abs(nums[i] - average);
// 		}
// 		return ans;
//     }
// };


// 最左和最右一起切割，可以得到选取中位数的结论
class Solution {
public:
    int minMoves2(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(),nums.end());
		int target = nums[n/2];
		int ans = 0;
		// printf("%d\n",target);
		for(int i = 0;i < n;i++){
			ans += abs(nums[i] - target);
		}
		return ans;
    }
};


	
int main() {
	Solution solution;
	// vector<int> nums = {1,10,2,9};
	// vector<int> nums = {1,2,3};
	vector<int> nums = {1,0,0,8,6};
	
	auto ans = solution.minMoves2(nums);
	
	cout << ans << endl;
	
	return 0;
}



