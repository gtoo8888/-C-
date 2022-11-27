#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int averageValue(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        for(int i = 0;i < n;i++){
            if(nums[i]%3 == 0 && nums[i]%2 == 0){
                sum += nums[i];
                count++;
            }
        }
        if(count == 0)
            return 0;
        return sum/count;
    }
};
	
int main() {
	Solution solution;
    // vector<int> nums = {1,3,6,10,12,15};
    //  vector<int> nums = {1,2,4,7,10};
     vector<int> nums = {6};


    auto ans = solution.averageValue(nums);

	cout << ans << endl;
	return 0;
}




