#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


// 垃圾方法，需要移动l 和mid适配
// l = mid+1;mid = l + (r - l) / 2;
// l = mid;mid = l + (r - l + 1) / 2;
// 如果左边不加1,mid加一
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
// 		if(nums.empty())
// 			return vector<int>{-1,-1};
// 		int n = nums.size();
// 		int l = 0,mid,r = n - 1;
// 		while(l < r){
// 			mid = l + (r - l) / 2;
// 			// printf("%d %d %d %d \n",nums[mid],l,mid,r);
// 			if(nums[mid] >= target){
// 				r = mid;
// 			}else{
// 				l = mid+1;
// 			}
// 		}
// 		// printf("%d %d %d %d\n",nums[r],target,r,nums[r] != target);
// 		if(nums[r] != target)	// nums[r]才代表当前实际找到的元素,不要用nums[mid]
// 			return vector<int>{-1,-1};
// 		// printf("!!!\n");
// 		int L = r;
// 		l = 0;r = n - 1;
// 		while(l < r){
// 			mid = l + (r - l + 1) / 2;
// 			// printf("%d %d %d %d \n",nums[mid],l,mid,r);
// 			if(nums[mid] <= target){
// 				l = mid;
// 			}else{
// 				r = mid-1;
// 			}
// 		}
// 		return vector<int>{L,r};
//     }
// };

class Solution {
public:
	int n;
	int binary_search_upper(vector<int>& nums, int target){
		int l = 0,mid,r = n - 1;
		int ans = -1;
		while(l <= r){
			mid = l + (r - l) / 2;
			// printf("%d %d %d %d \n",nums[mid],l,mid,r);
			if (nums[mid] > target || (0 && nums[mid] >= target)){
				ans = mid;
				r = mid-1;
			}else{
				l = mid+1;
			}
		}
		return ans;
	}

	int binary_search_lower(vector<int>& nums, int target){
		int l = 0,mid,r = n - 1;
		int ans = -1;
		while(l < r){
			mid = l + (r - l) / 2;
			// printf("%d %d %d %d \n",nums[mid],l,mid,r);
			if(nums[mid] > target || (1 && nums[mid] >= target)){
				ans = mid;
				r = mid-1;
			}else{
				l = mid+1;
			}
		}
		return ans;
	}

    vector<int> searchRange(vector<int>& nums, int target) {
		this->n = nums.size();
		int num_lower = binary_search_lower(nums,target);
		int num_upper = binary_search_upper(nums,target)-1;
		printf("%d %d %d %d\n",num_lower,num_upper,nums[num_lower],nums[num_upper]);
		if(num_lower <= num_upper && num_upper < n && 
			nums[num_lower] == target && nums[num_upper] == target){
				return {num_lower,num_upper};
			}
		return {-1,-1};
    }
};


int main(){
	Solution sol;
	vector<int> nums = {5,7,7,8,8,10};
	int target = 8;
	
	auto ans = sol.searchRange(nums,target);
	
	PrintVector(ans);
	return 0;
}
