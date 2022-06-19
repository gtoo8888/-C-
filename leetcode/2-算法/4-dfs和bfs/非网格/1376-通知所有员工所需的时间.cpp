#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

void printVector(vector<string> v){
	for(vector<string>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVVector(vector<vector<int>> v){
	for(auto iter = v.begin();iter != v.end();iter++){		
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}



class Solution {
public:
	void dfs(vector<vector<int>>& vec, vector<int>& informTime,int id,int time,int &ans){
		if(vec[id].empty()){
			ans = max(ans,time);
			return;
		}
		time += informTime[id];
		for(auto& next : vec[id]){
			dfs(vec,informTime,next,time,ans);
		}
	}
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		vector<vector<int>> vec(n,vector<int>());
		for(int i = 0;i < n;i++){
			if(manager[i] == -1)
				continue;
			vec[manager[i]].emplace_back(i);
		}
		// PrintVVector(vec);
		int ans = 0;
		dfs(vec,informTime,headID,0,ans);
		return ans;
    }
};



	
int main() {
	Solution solution;	 								
	vector<int> manager = {2,2,-1,2,2,2};
	vector<int> informTime = {0,0,1,0,0,0};
	int n = 6,headID = 2;


	auto ans = solution.numOfMinutes(n,headID,manager,informTime);
	
	cout << ans << endl;
	
	return 0;
}


