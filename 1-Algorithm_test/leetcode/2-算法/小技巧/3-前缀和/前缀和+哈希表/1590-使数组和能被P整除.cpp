#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 数学推导
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<int> pre(n+1,0);
        for(int i = 0;i < n;i++){
            pre[i+1] = (pre[i] + nums[i])%p;
        }
        PrintVector(pre);
        int x = pre[n];
        int ans = n;
        unordered_map<int,int> last;
        for(int i = 0;i <= n;i++){
            last[pre[i]] = i;
            auto it = last.find((pre[i] - x + p) % p);
            if(it != last.end())
                ans = min(ans,i - it->second);
        }
        return ans < n ? ans : -1;
    }
};


int main() {
	Solution solution;
	vector<int> nums = {3,1,4,2};int p = 6;
	
	auto ans = solution.minSubarray(nums,p);
	
	cout << ans << endl;
	
	return 0;
}



