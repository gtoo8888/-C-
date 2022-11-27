#include <iostream>
#include <vector>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i < n-1;i++){
            int len = 1;
            for(int j = i;j < n-1;j++){
                printf("%d %d %d\n",nums[j], nums[j+1],len);
                if(nums[j+1] > nums[j])
                    len++;
                else
                    break;
                if(len >= 3)
                    ans++;
            }
            cout << endl;
        }
        return ans;
    }
};

int main() {
	Solution solution;
	vector<int> nums = {1,2,3,4,5};
	
	auto ans = solution.numberOfArithmeticSlices(nums);
	
	cout << ans << endl;
	return 0;
}



