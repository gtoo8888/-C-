#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
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

void PrintMap(unordered_map<int,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // PrintVVector(matches);
        vector<vector<int>> ans;
        unordered_map<int,int> m;
        for(int i = 0;i < matches.size();i++) {
            m[matches[i][0]] = 0;
            // m.insert(pair<int,int>(matches[i][0] ,0));
        }
        for(int i = 0;i < matches.size();i++) {
            m[matches[i][1]]--;
        }
        // PrintMap(m);
        vector<int> ans0,ans1;
        for(auto it = m.begin();it != m.end();it++){
            if(it->second == 0)
                ans0.push_back(it->first);
            if(it->second == -1)
                ans1.push_back(it->first);
        }
        sort(ans0.begin(),ans0.end());
        sort(ans1.begin(),ans1.end());
  
  
        ans.push_back(ans0);
        ans.push_back(ans1);

        return ans;
    }
};


	
int main() {
	Solution solution;

	// vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    vector<vector<int>> matches = {{2,3},{1,3},{5,4},{6,4}};

	
	vector<vector<int>> ans = solution.findWinners(matches);
	
	PrintVVector(ans);
	
	return 0;
}




