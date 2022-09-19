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
	void backtraing(vector<int> nums,int StartIndex) {
		ans.push_back(path);
		if(StartIndex >= nums.size()) {
			return;
		}
		
		for(int i = StartIndex;i < nums.size();i++) {
			path.push_back(nums[i]);
//			PrintVector(path) ;
			backtraing(nums,i+1);
			path.pop_back();
		}
	}
	
    vector<vector<int>> subsets(vector<int>& nums) {
    	ans.clear();
		backtraing(nums,0);
		return ans;
    }
};


	
int main() {
	Solution solution;
	vector<int> nums = {1,2,3,4};
	
	auto ans = solution.subsets(nums);
	
	printVVector(ans);
	
	return 0;
}



