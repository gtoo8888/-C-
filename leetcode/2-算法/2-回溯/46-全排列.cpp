#include <iostream>
#include <vector>
using namespace std;



void PrintVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void PrintVBector(vector<bool> str)  {
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
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}



class Solution {
public:
	vector<vector<int>> ans;
	vector<int> path;
	void backtraking(vector<int> nums,vector<bool> used) {
		if(path.size() == nums.size()) {
			ans.push_back(path);
			return;
		}
		
		for(int i = 0;i < nums.size();i++) {
			if(used[i] == true) continue;
			path.push_back(nums[i]);
			used[i] = true;
//			PrintVector(path);
			backtraking(nums,used);
			used[i] = false;
			path.pop_back();
		}
	}
	
    vector<vector<int>> permute(vector<int>& nums) {
		ans.clear();
		path.clear();
		vector<bool> used(nums.size(),false);
		backtraking(nums,used);
		return ans;
    }
};

	
int main() {
	Solution solution;
	vector<int> nums = {1,2,3,4,5}; 

	
	auto ans = solution.permute(nums);
	
	
	printVVector(ans);
	
	return 0;
}



