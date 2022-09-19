#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;


void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

// 暴力O(n2)
// class Solution {
// public:
//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
// 		int n1 = nums1.size(),n2 = nums2.size();
// 		int ans = 0;
// 		for(int i = 0;i < n1;i++){
// 			for(int j = i;j < n2;j++){
// 				if(i <= j && nums1[i] <= nums2[j]){
// 					int len = j - i;
// 					ans = len > ans ? len : ans;
// 				}
// 			}
// 		}
// 		return ans;
//     }
// };

// 二分解法O(nlogn) TLE
// class Solution {
// public:
//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
// 		int n1 = nums1.size(),n2 = nums2.size();
// 		int res = 0;
// 		for(int i = 0;i < n1;i++){
// 			int i_num = nums1[i];
// 			int l = i,mid,r = n2-1;
// 			int ans = -1;
// 			if(nums1[i] >  nums2[i])
// 				continue;
// 			while(l <= r){
// 				mid = l + (r - l)/2;
// 				// printf("%d %d %d %d %d\n",nums2[mid],l,mid,r,ans);
// 				if(nums2[mid] >= i_num){
// 					ans = mid;
// 					l = mid + 1;
// 				}else
// 					r = mid - 1;
// 			}
// 			// printf("%d %d\n\n",nums2[ans],ans);
// 			if(ans == -1)
// 				continue;
// 			else{
// 				for(int j = i;j <= ans;j++){
// 					int len = j - i;
// 					res = len > res ? len : res;
// 				}
// 			}
// 		}
// 		return res;
//     }
// };


// 二分解法
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size(),n2 = nums2.size();
		int res = 0;
		for(int i = 0;i < n1;i++){
			int i_num = nums1[i];
			int l = i,mid,r = n2-1;
			int ans = -1;
			while(l <= r){
				mid = l + (r - l)/2;
				// printf("%d %d %d %d %d\n",nums2[mid],l,mid,r,ans);
				if(nums2[mid] >= i_num){
					ans = mid;
					l = mid + 1;
				}else
					r = mid - 1;
			}
			// printf("%d %d\n\n",nums2[ans],ans);
			// 求出来的右边界就是距离的最大值，直接相减就可以了
			if(ans >= i)	
				res = max(res,ans - i);
		}
		return res;
    }
};


int main(){
	Solution sol;
	vector<int> nums1 = {55,30,5,4,2};
	vector<int> nums2 = {100,20,10,10,5};

	// vector<int> nums1 = {2,2,2};
	// vector<int> nums2 = {10,10,1};

	// vector<int> nums1 = {30,29,19,5};
	// vector<int> nums2 = {25,25,25,25,25};

	auto ans = sol.maxDistance(nums1,nums2);
	
	cout << ans <<endl;
	return 0;
}
