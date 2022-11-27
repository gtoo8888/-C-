#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
		int n = nums.size();
        if(n < 2)
            return n;
        vector<int> up(n),down(n);
        up[0] = down[0] = 1;
        for(int i = 1;i < n;i++){
            if(nums[i] > nums[i-1]){
                up[i] = max(up[i-1],down[i-1] + 1);
                down[i] = down[i-1];
            }else if(nums[i] < nums[i-1]){
                up[i] = up[i-1];
                down[i] = max(up[i-1]+1,down[i-1]);
            }else{
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        PrintVector(up);
        PrintVector(down);
        return max(up[n-1],down[n-1]);
    }
};

int main() {
	Solution solution;
	vector<int> nums = {1,7,4,9,2,5};
    // vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    // vector<int> nums = {1,2,3,4,5,6,7,8,9};
	
	auto ans = solution.wiggleMaxLength(nums);
	
	cout << ans << endl;
	return 0;
}



