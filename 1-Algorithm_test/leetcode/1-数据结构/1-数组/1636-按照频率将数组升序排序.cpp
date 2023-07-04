#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

bool mycompare(pair<int,int> p1,pair<int,int> p2){
	if(p1.second > p2.second)
		return false;
	else if(p1.second < p2.second)
		return true;
	else{
		if(p1.first > p2.first)
			return true;
		else
			return false;
	}
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
		map<int,int> map1;
		int n = nums.size();
		for(int i = 0;i < n;i++){
			map1[nums[i]]++;
		}
		// PrintMap(map1);
		vector<pair<int,int>> vp;
		for(auto it : map1){
			vp.emplace_back(pair<int,int>(it.first,it.second));
		}
		// PrintVP(vp);
		sort(vp.begin(),vp.end(),mycompare);
		// PrintVP(vp);
		vector<int> ans;
		for(auto it : vp){
			for(int i = 0;i < it.second;i++){
				ans.push_back(it.first);
			}
		}
		return ans;
    }
};


int main() {
	Solution sol;
	// vector<int> nums = {1,1,2,2,2,3};	
	// vector<int> nums = {2,3,1,3,2};	
	// vector<int> nums = {-1,1,-6,4,5,-6,1,4,1,3,3};	
	vector<int> nums = {14,32,24,27,1,32,-16,29,46,40,21,9,-18,29,40,7,-16,-43,9,19,24,-32,32,-35};	

	auto ans = sol.frequencySort(nums);
	PrintVector(ans);
	return 0;
}

