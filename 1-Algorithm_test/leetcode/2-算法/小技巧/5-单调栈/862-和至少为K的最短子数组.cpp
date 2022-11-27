#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
		int n = nums.size();
		vector<long> pre(n+1,0);	
		for(int i = 0;i < n;i++){
			pre[i+1] = pre[i] + nums[i];		
		}
		PrintVector(pre);
		int res = n+1;
		deque<int> q;
		int ans = n+1;
		for(int i = 0;i <= n;i++){
			long cur_s = pre[i];
			while(!q.empty() && cur_s - pre[q.front()] >= k){
				ans = min(ans,i-q.front());
				q.pop_front();
			}
			while(!q.empty() && pre[q.back()] >= cur_s){
				q.pop_back();
			}
			q.push_back(i);
		}
		return ans > n ? -1:ans;
    }
};


	
int main() {
	Solution solution;
	vector<int> nums = {2,-1,2};
	int k = 3;
	
	auto ans = solution.shortestSubarray(nums,k);
	
	cout << ans << endl;
	
	return 0;
}



