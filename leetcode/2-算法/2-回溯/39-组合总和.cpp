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
	
	void backtraining(vector<int> candidates,int target,int sum,int StartIndex) {
		if(sum > target)	return;
		if(sum == target) {
			ans.push_back(path);
			return;
		}

		for(int i = StartIndex;i < candidates.size();i++) {		
//		for(int i = StartIndex;i < candidates.size() && sum + candidates[i] <= target;i++) {
			sum += candidates[i];
			path.push_back(candidates[i]);
			PrintVector(path);
			backtraining(candidates,target,sum,i);
			sum -= candidates[i];
			path.pop_back();
		}
	}
		
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//    	PrintVector(candidates);
		sort(candidates.begin(),candidates.end());
		backtraining(candidates,target,0,0);
		return ans;
    }
};

	
int main() {
	Solution solution;
	vector<int> candidates = {2,7,6,3,5,1}; 
	int target = 9;
	
	auto ans = solution.combinationSum(candidates,target);
	
	printVVector(ans);
	
	return 0;
}



