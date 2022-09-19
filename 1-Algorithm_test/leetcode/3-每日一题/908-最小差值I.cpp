#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}


class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int nums_min = INT32_MAX;
        int nums_max = INT32_MIN;
        for(auto n : nums){
            nums_min = nums_min > n ? n : nums_min;
            nums_max = nums_max < n ? n : nums_max;
        }
        printf("%d %d\n",nums_min,nums_max);
        if(nums_max - nums_min > 2*k)
            return nums_max - nums_min - 2*k;
        else   
            return 0;
        // return 0;
    }
};


	
int main() {
	Solution solution;
	vector<int> nums = {0,10};
	int k = 2;
	
	auto ans = solution.smallestRangeI(nums,k);
	
	cout << ans << endl;
	
	return 0;
}



