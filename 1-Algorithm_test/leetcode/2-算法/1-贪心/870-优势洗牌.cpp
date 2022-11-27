#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // iota() ????
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


void PrintVTector(vector<int> ids,vector<int>& nums2){
	int n = nums2.size();
	for(int i = 0;i < n;i++)
		cout << nums2[ids[i]] << " ";
	cout << endl;
}


class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		vector<int> ids(n);
		vector<int> ans(n);
		sort(nums1.begin(),nums1.end());
		iota(ids.begin(),ids.end(),0);
		sort(ids.begin(),ids.end(),[&](int i ,int j){
			return nums2[i] < nums2[j];
		});	// nums2?????ids???ids[0]?????????
		// PrintVTector(ids,nums2);
		// PrintVector(ids);
		int left = 0,right = n-1;
		for(int x : nums1){
			ans[x > nums2[ids[left]] ? ids[left++] : ids[right--]] = x;
		}
		return ans;
    }
};

		
int main() {
	Solution solution;
	// vector<int> nums1 = {1,2,7,10};
	// vector<int> nums2 = {1,3,5,9};
	
	vector<int> nums1 = {12,24,8,32};
	vector<int> nums2 = {13,25,32,11};	
	auto ans = solution.advantageCount(nums1,nums2);
	
	PrintVector(ans);
	return 0;
}


