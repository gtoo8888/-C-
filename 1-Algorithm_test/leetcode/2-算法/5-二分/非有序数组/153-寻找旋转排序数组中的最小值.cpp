#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;




class Solution {
public:
    int findMin(vector<int>& nums) {
		int n = nums.size();
		int l = 0,mid,r = n-1;
		while(l < r){
			mid = l + (r - l)/2;
			printf("%d %d %d %d\n",nums[mid],l,mid,r);
			if(nums[mid] < nums[r]){	// ���ұߵĵ�����ת�ķָ��ߣ�������������¶���
				r = mid;	// ��������ģ�ÿ�ζ��ұ߽�����������С�ļ�����
			}else
				l = mid + 1;
		}
		return nums[l];
    }
};



int main(){
	Solution sol;
	// vector<int> nums = {3,4,5,1,2};
	// vector<int> nums = {4,5,6,7,0,1,2};
	// vector<int> nums = {11,13,15,17};
	// vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,13,15,17,20,21,22,23,24,25,26,27,28};
	vector<int> nums = {26,27,28,1,2,3,4,5,6,7,8,9,10,11,13,15,17,20,21,22,23,24,25};
	// vector<int> nums = {1};
	// vector<int> nums = {3,1};


	auto ans = sol.findMin(nums);
	
	cout << ans <<endl;
	return 0;
}
