#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

// O(n)��ֱ������
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
// 		int n = nums.size();
// 		for(int i = 0;i < n;i++)
// 			if(nums[i] == target)
// 				return i;
// 		return -1;
//     }
// };

//O(logn),���ֲ���
// ����ȡrr
class Solution {
public:
    int search(vector<int>& nums, int target) {
		int n = nums.size();
		int l = 0,r = n;
		int mid;
		if(target < nums.front() || target > nums.back())
			return -1;
		while(l <= r){
			mid = l + (r - l)/2;	// ��ֹ���
			printf("%d %d %d %d\n",nums[mid],l,mid,r);
			
			if(nums[mid] == target)
				return mid;
			else if(nums[mid] < target)	// Ŀ�������ұ�
				l = mid + 1;
			else						// Ŀ���������
				r = mid - 1;
		}
		return -1;
    }
};


int main(){
	Solution sol;
	vector<int> nums = {-1,0,3,5,9,12};
	// vector<int> nums = {12,9,5,3,0,-1};
	int target = 9;
	
	auto ans = sol.search(nums,target);
	
	cout << ans <<endl;
	return 0;
}
