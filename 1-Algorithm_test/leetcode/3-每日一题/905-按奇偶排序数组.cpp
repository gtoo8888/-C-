#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}



// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums) {
// 		int n = nums.size();
// 		vector<int> ans(n);
// 		int ans_i = 0;
// 		for(int i = 0;i < n;i++){
// 			if(nums[i] % 2 == 0)
// 				ans[ans_i++] = nums[i];
// 		}
// 		for(int i = 0;i < n;i++){
// 			if(nums[i] % 2 == 1)
// 				ans[ans_i++] = nums[i];
// 		}
// 		return ans;
//     }
// };

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n);
		int left = 0,right = n-1;
		for(int i = 0;i < n;i++){
			if(nums[i] % 2 == 0)
				ans[left++] = nums[i];
			else
				ans[right--] = nums[i];
		}
		return ans;
    }
};

// ½â·¨´íÎóµÄ
// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums) {
// 		int n = nums.size();
// 		for(int left = 0,right = n-1;left < right , right;left++){
// 			if(nums[left] % 2 == 1){
// 				int c = nums[right];
// 				nums[right--] = nums[left];
// 				nums[left--] = c;
// 			}
// 		}
// 		return nums;
//     }
// };
	
int main() {
	Solution solution;
	vector<int> nums = {3,1,2,4};
	
	
	auto ans = solution.sortArrayByParity(nums);
	
	printVector(ans);
	
	return 0;
}



