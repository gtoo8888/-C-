#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
		int n = nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
		// PrintVector(nums);
		unordered_set<float> set;
		int l = n;
		while(l>0){
			float n_min = nums[l-1];
			float n_max = nums[0];
			// printf("float%f %f\n",n_min,n_max);
			nums.erase(nums.begin());
			l--;
			nums.erase(nums.begin()+l-1);
			l--;
			
			// PrintVector(nums);
			set.insert((n_min+n_max)/2);
		}
		// PrintUnorder_Set(set);
		return set.size();
    }
};
	
int main() {
	Solution solution;
	vector<int> words = {4,1,4,0,3,5};
	// vector<int> words = {1,100};
    auto ans = solution.distinctAverages(words);

	cout << ans << endl;
	return 0;
}




