#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
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
    vector<int> intersection(vector<vector<int>>& nums) {
 	    // PrintVVector(nums);      
        unordered_map<int,int> m;
        for(int i = 0;i < nums.size();i++) {
            for(int j = 0;j < nums[i].size();j++) {
                m[nums[i][j]]++;
            }
        }
        vector<int> ans;
        int len = nums.size();
        for(auto it = m.begin();it != m.end();it++) {
            int m1 = it->first,m2 = it->second;
            if(m2 == len) 
                ans.push_back(m1);
        }
        sort(ans.begin(),ans.end());
        // PrintMap(m);
        return ans;
    }
};



	
int main() {
	Solution solution;
    vector<vector<int>> nums = {{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};

    auto ans = solution.intersection(nums);

	PrintVector(ans);
	return 0;
}




