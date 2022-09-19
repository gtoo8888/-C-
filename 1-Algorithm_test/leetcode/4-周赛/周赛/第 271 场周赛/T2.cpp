#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void PrintVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void PrintVVector(vector<vector<int>> v){
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
	void backtraing(vector<int> nums,int StartIndex,int jishu) {
		ans.push_back(path);
		if(StartIndex >= nums.size()) {
			jishu++;
//			cout << "--retuen--" << StartIndex << endl;
			StartIndex = jishu;
			return;
		}
		
		for(int i = StartIndex;i < nums.size();i++) {
//			cout << "             " << i << " " << StartIndex << endl;
			path.push_back(nums[i]);
			PrintVector(path) ;
			backtraing(nums,i+1,jishu);
			cout << "--retuen--" << i << " " << StartIndex << endl;
			path.pop_back();
		}
	}
	
    long long subArrayRanges(vector<int>& nums) {
    	ans.clear();
		backtraing(nums,0,0);
		long long return_ans;
//		PrintVVector(ans);
		return return_ans;
    }
};



	
int main() {
	Solution solution;
	vector<int> nums = {1,2,3,4};
	
	long long temp = 1;
	
	auto ans = solution.subArrayRanges(nums);
	
	cout << ans << endl;
	
	return 0;
}



