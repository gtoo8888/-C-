#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// class Solution {
// public:
//     vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
// 		int n = queries.size();
//         vector<int> ans(n,0);
// 		for(int i = 0;i < n;i++){
// 			int biaozhun = queries[i];
// 			int m = nums.size();
// 			vector<int> dp(m,0);
// 			int sum = nums[0];
// 			if(sum > biaozhun){
// 				sum -= nums[0];
// 				dp[0] = 0;
// 			}else{
// 				dp[0] = 1;
// 			}
// 			for(int j = 1;j < m;j++){
// 				sum += nums[j];
// 				if(sum > biaozhun){
// 					sum -= nums[j];
// 					dp[j] = dp[j-1];
// 				}else{
// 					dp[j] = dp[j-1] + 1;
// 				}
// 			}
// 			PrintVector(dp);
// 			ans[i] = dp[m-1];
// 		}
// 		return ans;
//     }
// };

// 排序+前缀和+二分查找
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
		int queries_n = queries.size();
		int nums_n = nums.size();
        vector<int> ans(queries_n,0);
		sort(nums.begin(),nums.end());
		// PrintVector(nums);
		vector<int> pre(nums_n,0);
		pre[0] = nums[0];
		for(int i = 1;i < nums_n;i++){
			pre[i] = nums[i] + pre[i-1];
		}
		// PrintVector(pre);
		for(int i = 0;i < queries_n;i++){
			int find_num = queries[i];
			int index = upper_bound(pre.begin(),pre.end(),find_num) - pre.begin();
			ans[i] = index;
		}
		return ans;
    }
};

	
int main() {
	Solution solution;
	vector<int> nums = {4,5,2,1};
	vector<int> queries = {3,10,21};

	// vector<int> nums = {469781,45635,628818,324948,343772,713803,452081};
	// vector<int> queries = {816646,929491};

	auto ans = solution.answerQueries(nums,queries);
	
	PrintVector(ans);
	
	return 0;
}



