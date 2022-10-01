#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


void PrintVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void printVVector(vector<vector<int>> v){
	vector<vector<int>>::iterator iter;
	vector<int>::iterator it;
	vector<int> it_temp;
	
	for(iter = v.begin();iter != v.end();iter++){
		it_temp = *iter;
		for(it = it_temp.begin();it != it_temp.end();it++)
			cout << setw(5) << *it << " ";
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> path;
	void backtraing(vector<int> nums,int StartIndex,vector<bool> used) {
		ans.push_back(path);
		if(StartIndex >= nums.size()) {
			return;
		}
		
		for(int i = StartIndex;i < nums.size();i++) {
			if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
				continue;
			path.push_back(nums[i]);
			used[i] = true;
//			PrintVector(path) ;
			backtraing(nums,i+1,used);
			path.pop_back();
			used[i] = false;
		}
	}
	
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
    	ans.clear();
    	vector<bool> used(nums.size(),false);
		backtraing(nums,0,used);
		return ans;
    }
};


	
int main() {
	Solution solution;
	vector<int> nums = {1,2,3,3};
	
	auto ans = solution.subsetsWithDup(nums);
	
	printVVector(ans);
	
	return 0;
}



