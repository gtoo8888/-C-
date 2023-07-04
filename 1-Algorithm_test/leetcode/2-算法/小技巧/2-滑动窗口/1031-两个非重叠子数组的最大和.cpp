#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
	int f(int a,int b,vector<int>& pre,int& n){
		int ans = 0;
		for (int i = a, t = 0; i + b - 1 < n; ++i) {
			t = max(t, pre[i] - pre[i - a]);
			ans = max(ans, t + pre[i + b] - pre[i]);
		}
		return ans;
	}

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
		int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }
		return max(f(firstLen,secondLen,pre,n), f(secondLen,firstLen,pre,n));
    }
};
		
int main() {
	Solution solution;
	vector<int> nums = {2,3,1,2,4,3};int firstLen = 1;int secondLen = 2;
	
	auto ans = solution.maxSumTwoNoOverlap(nums,firstLen,secondLen);
	
	cout << ans <<endl;
	return 0;
}



