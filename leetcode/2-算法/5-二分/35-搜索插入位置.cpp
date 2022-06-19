#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;



//O(logn),二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int l = 0,mid,r = nums.size()-1;
		while(l <= r){
			mid = l + (r - l)/2 ;
			printf("%d %d %d %d\n",nums[mid],l,mid,r);
			if(target == nums[mid])	// 如果找到这个数，直接返回
				return mid;
			else if(target < nums[mid]){	
				// 如果不存在这个数，返回第一个大于等于target的下标
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		return l;
    }
};



int main(){
	Solution sol;
	// vector<int> nums = {1,3};
	vector<int> nums = {1,3,5,6};
	int target = 7;
	
	auto ans = sol.searchInsert(nums,target);
	
	cout << ans <<endl;
	return 0;
}
