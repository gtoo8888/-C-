#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;




class Solution {
public:
    int search(vector<int>& nums, int target) {
		int n = nums.size();
		int l = 0,mid,r = n-1;
		if(n == 1)
			return target == nums[0] ? 0 : -1;
		while(l <= r){
			mid = l + (r - l)/2;
			printf("%d %d %d %d\n",nums[mid],l,mid,r);
			if(nums[mid] == target)
				return mid;
			if(nums[0] <= nums[mid]){	// 没有旋转的部分一定是有序的，满足的话说明左边一定有序
				if(nums[0] <= target && target < nums[mid]){	// 目标值是不是在有序的左边
					r = mid - 1;
				}else	// 如果不在有序的左边，就得去右边搜索了
					l = mid + 1;
			}
			else{	// 左边无序
				if(nums[mid] < target && target <= nums[n-1])	// 测一下是不是在有序的右边
					l = mid + 1;
				else
					r = mid - 1;
			}
		}
		return -1;
    }
};



int main(){
	Solution sol;
	// vector<int> nums = {4,5,6,7,0,1,2};
	// int target = 0;

	// vector<int> nums = {6,7,0,1,2,4,5};
	// int target = 0;

	// vector<int> nums = {4,5,6,7,0,1,2};
	// int target = 3;

	// vector<int> nums = {1};
	// int target = 1;

	vector<int> nums = {3,1};
	int target = 1;

	auto ans = sol.search(nums,target);
	
	cout << ans <<endl;
	return 0;
}
