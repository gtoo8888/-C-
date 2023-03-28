#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// 最朴素思路，O（n2）
// class Solution {
// public:
//     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
// 		int n = nums.size(),m = queries.size();
//         vector<long long> ans(m,0);
// 		for(int i = 0;i < m;i++){
// 			long long tmp_sum = 0;
// 			for(int j = 0;j < n;j++){
// 				tmp_sum += abs(nums[j] - queries[i]);
// 			}
// 			ans[i] = tmp_sum;
// 		}
// 		return ans;
//     }
// };


// 排序+前缀和+二分 优化
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
		sort(nums.begin(),nums.end()); // 排序为了后面的二分作准备
		int n = nums.size(),m = queries.size();
		vector<long long> pre(n+1,0);
		pre[1] = nums[0];
		for(int i = 1;i < n;i++){
			pre[i+1] = pre[i] + nums[i]; // 前缀和为了相加更加方便
		}
		// PrintVector(pre);
        vector<long long> ans(m,0);
		for(int i = 0;i < m;i++){
			long long tmp_sum = 0;
			int index = lower_bound(nums.begin(),nums.end(),queries[i]) - nums.begin();
			
			long long l_sum = (long long)(index - 0)*queries[i] - (pre[index] - pre[0]);
			long long r_sum = (pre[n] - pre[index]) - (long long)(n - index)*queries[i];
			ans[i] =  l_sum + r_sum; // 可以拆分成前后两段，之后相加，记得转化成long long
		}
		return ans;
    }
};


int main() {
	Solution solution;
	// vector<int> nums = {3,1,6,8};
	// vector<int> queries = {1,5};
	// vector<int> queries = {5,1};

	vector<int> nums = {2,9,6,3};
	vector<int> queries = {10};

    auto ans = solution.minOperations(nums,queries);

	PrintVector(ans);
	return 0;
}




