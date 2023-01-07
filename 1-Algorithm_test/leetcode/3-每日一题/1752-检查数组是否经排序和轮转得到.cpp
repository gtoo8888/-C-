#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    bool check(vector<int>& nums) {
		PrintVector(nums);
		return false;
    }
};


	
int main() {
	Solution solution;
	vector<int> nums = {3,4,5,1,2};

	auto ans = solution.check(nums);
	
	PrintBool(ans);
	return 0;
}



