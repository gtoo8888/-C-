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
    
    void backtraining(vector<int> candidates,int target,int sum,int StartIndex,vector<bool> used) {
    	if(sum > target) return;
    	if(sum == target) {
    		ans.push_back(path);
    		return;
		}
		
		for(int i = StartIndex;i < candidates.size();i++) {
			if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) 
				continue;
			sum += candidates[i];
			path.push_back(candidates[i]);
			used[i] = true;
			PrintVector(path);
			backtraining(candidates,target,sum,i+1,used);
			sum -= candidates[i];
			path.pop_back();
			used[i] = false;
		}
	}  
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(),candidates.end());
		vector<bool> used(candidates.size(),false);
		ans.clear();
		path.clear();
		backtraining(candidates,target,0,0,used);
		return ans;
    }
};

	
int main() {
	Solution solution;
	vector<int> candidates = {10,1,2,7,6,1,5}; 
	int target = 8;
	
	auto ans = solution.combinationSum2(candidates,target);
	
	printVVector(ans);
	
	return 0;
}



