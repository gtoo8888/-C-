#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
		int n = strs.size(),m = strs[0].size();
		int ans = 0;
		for(int i = 0;i < m;i++){
			for(int j = 1;j < n;j++){
				if(strs[j-1][i] > strs[j][i]){
					ans++;
					break;
				}
			}
		}
		return ans;
    }
};


	
int main() {
	Solution solution;
	vector<string> strs = {"zyx","wvu","tsr"};
	
	auto ans = solution.minDeletionSize(strs);
	
	cout << ans << endl;
	
	return 0;
}



