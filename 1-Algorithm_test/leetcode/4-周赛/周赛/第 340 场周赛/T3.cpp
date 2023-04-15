#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// O(n2) 穷举了所有下标对的情况
// 并不是所有的下标对都是可以被枚举的，会有占用情况
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        if(p == 0)
            return 0;
		vector<int> chazhi;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				chazhi.push_back(abs(nums[i]-nums[j]));
			}
		}
        sort(chazhi.begin(),chazhi.end());
        int ans = INT32_MIN;
        for(int i = 0;i < p;i++){
            ans = max(ans,chazhi[i]);
        }
		return ans;
    }
};


int main() {
	Solution solution;
	// vector<int> nums = {10,1,2,7,1,3};int p = 2; // 1
    // vector<int> nums = {4,2,1,2};int p = 1;  // 0
    // vector<int> nums = {0,5,3,4};int p = 0; // 0
    vector<int> nums = {3,4,2,3,2,1,2};int p = 3; // 1

    auto ans = solution.minimizeMax(nums,p);

	cout << ans << endl;
	return 0;
}




