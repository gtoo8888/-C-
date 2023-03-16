#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 最大质因数
int gcd_t(int a,int b) { return b?gcd_t(b,a%b):a;}


class Solution {
public:
    int findValidSplit(vector<int>& nums) {
		int n = nums.size();
        vector<long long> pre(n-1,1);
		vector<long long> last(n-1,1);
		pre[0] = nums[0];
		last[n-2] = nums[n-1];
		for(int i = 1;i < n-1;i++){
			pre[i] = pre[i-1]*nums[i];
		}
		for(int i = n-2;i >= 1;i--){
            int t1 = last[i];
            int t2 = nums[i];
			last[i-1] = last[i]*nums[i];
		}
		// PrintVector(pre);
		// PrintVector(last);
        int n_pre = pre.size();
        for(int i = 0;i < n_pre;i++){
            int res = gcd_t(pre[i],last[i]);
            if(res == 1)
                return i;
        }
		return -1;
    }
};

int main() {
	Solution solution;
	vector<int> nums = {4,7,8,15,3,5};

    auto ans = solution.findValidSplit(nums);

	cout << ans << endl;
	return 0;
}




