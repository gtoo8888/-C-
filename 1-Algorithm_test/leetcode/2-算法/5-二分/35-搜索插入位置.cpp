#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;



//O(logn),���ֲ���
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int l = 0,mid,r = nums.size()-1;
		while(l <= r){
			mid = l + (r - l)/2 ;
			printf("%d %d %d %d\n",nums[mid],l,mid,r);
			if(target == nums[mid])	// ����ҵ��������ֱ�ӷ���
				return mid;
			else if(target < nums[mid]){	
				// �������������������ص�һ�����ڵ���target���±�
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
