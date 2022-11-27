#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
	void test(vector<int>& nums, int space){
		int n = nums.size();
		for(int i = 0;i < n;i++){
			vector<int> tmp;
			for(int c = 0;c < 10;c++){
				tmp.emplace_back(nums[i]+c*space);
			}
			PrintVector(tmp);
		}	
	}

    int destroyTargets(vector<int>& nums, int space) {
		vector<int> tmp = nums;
		sort(tmp.begin(),tmp.end());
		PrintVector(tmp);
		return -1;
    }
};

	
int main() {
	Solution sol;
	vector<int> nums = {3,7,8,1,1,5};
	int space = 2;

	sol.test(nums,space);
    auto ans = sol.destroyTargets(nums,space);

	cout << ans << endl;
	return 0;
}




