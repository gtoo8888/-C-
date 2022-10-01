#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

int AndOperator(int a, int b){
    return a & b;
}


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
		int n = nums.size();

		int min_anweiyu = INT32_MIN;
		int ans = 0;
		for(int i = 0;i < nums.size();i++){
			int start = nums[i];
			if(start > min_anweiyu){
				// printf("!!!%d \n",i);
				ans = ans > 1 ? ans : 1;
				min_anweiyu = start;
			}
			for(int j = i+1;j < nums.size();j++){
				printf("%d %d min:%d\n",nums[j]  ,start,min_anweiyu);
				start = nums[j] & start;
				if(start > min_anweiyu){
					printf("!!!%d %d\n",i,j);
					ans = ans < j-i+1 ? j-i+1 : ans;
					// ans = j-i+1;
					min_anweiyu = start;
				}
			}
			cout << endl;
		}
		return ans;
    }
};
	
int main() {
	Solution solution;
    vector<int> nums = {1,2,3,3,2,2};
	// vector<int> nums = {1,2,3,4};
	// vector<int> nums = {100,5,5};

    auto ans = solution.longestSubarray(nums);

	cout << ans << endl;
	return 0;
}




