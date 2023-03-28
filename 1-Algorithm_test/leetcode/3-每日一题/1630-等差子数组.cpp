#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
		int n = l.size();
		vector<bool> ans(n,true);
		for(int i = 0;i < n;i++){
			vector<int> tmp(nums.begin()+l[i],nums.begin()+r[i]+1);
			sort(tmp.begin(),tmp.end(),less<int>());
            for(int j = 0;j < tmp.size()-2;j++){
                if(tmp[j+1]-tmp[j] != tmp[j+2]-tmp[j+1]){
                    ans[i] = false;
                    break;
                }
                
            }
			// PrintVector(tmp);
		}
		return ans;
    }
};

	
int main() {
	Solution solution;
	// vector<int> nums = {4,6,5,9,3,7};
	// vector<int> l = {0,0,2};
	// vector<int> r = {2,3,5};
	vector<int> nums = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
	vector<int> l = {0,1,6,4,8,7};
	vector<int> r = {4,4,9,7,9,10};
	auto ans = solution.checkArithmeticSubarrays(nums,l,r);
	
	PrintVector(ans);
	return 0;
}



