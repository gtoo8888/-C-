#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(auto it : v)
		cout << it << " ";
}

// class Solution {
// public:
//     int specialArray(vector<int>& nums) {
// 		sort(nums.begin(),nums.end());
// 		int n = nums.size();
// 		int l = 0,mid,r = n-1;
// 		int ans = -1;
// 		int iter = 0;
// 		while(l <= r){
// 			mid = l + (r - l)/2;
// 			printf("%d %d %d %d %d\n",nums[mid],n - mid + 1,l,mid,r);
// 			if(nums[mid] >= n - mid + 1){
// 				ans = mid;
// 				r = mid - 1;
// 			}
// 			else if(nums[mid] < n - mid + 1) 
// 				l = mid + 1;
				
// 			if(iter++ == 50) break;
// 		}
// 		return ans;
//     }
// };


// 暴力做法，二分想不明白
class Solution {
public:
    int specialArray(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		int nums_max = *max_element(nums.begin(),nums.end());
		int n = nums.size();
		for(int i = 1;i <= nums_max;i++){
			int count = 0;
			for(int j = 0;j < n;j++){
				if(nums[j] >= i)
					count++;
			}
			if(count == i)
				return i;
		}
		return -1;
    }
};



int main(){
	Solution sol;
	// vector<int> nums = {3,5};
	// vector<int> nums = {0,0};
	// vector<int> nums = {0,4,3,0,4};
	// vector<int> nums = {3,6,7,7,0};
	vector<int> nums = {7,7,7,7,7,7,7};
	
	auto ans = sol.specialArray(nums);
	
	cout << ans <<endl;
	return 0;
}
