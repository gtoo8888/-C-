#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 1300 real 1188

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		sort(arr1.begin(),arr1.end());
		unordered_map<int,int> umap;
		int n1 = arr1.size(),n2 = arr2.size();
		for(int i = 0;i < n1;i++){
			umap[arr1[i]]++;
		}
		// PrintVector(arr1);
		
		vector<int> ans;
		for(int i = 0;i < n2;i++){
			if(umap[arr2[i]] != 1){
				int t = umap[arr2[i]];
				while(t--)
					ans.push_back(arr2[i]);
				umap.erase(arr2[i]);
			}else{
				ans.push_back(arr2[i]);
				umap.erase(arr2[i]);
			}
		}
		// PrintUnorder_Map(umap);
		
		// 剩下的，大于一个的数
		if(!umap.empty()){
			vector<int> tmp;
			for(auto it : umap){
				if(it.second == 1)
					tmp.push_back(it.first);
				else{
					int t = it.second;
					while(t--)
						tmp.push_back(it.first);
				}
			}
			sort(tmp.begin(),tmp.end());
			for(auto it : tmp){
				ans.push_back(it);
			}
		}
		return ans;
    }
};


int main() {
	Solution solution;
	// vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
	// vector<int> arr2 = {2,1,4,3,9,6};

	// vector<int> arr1 = {28,6,22,8,44,17};
	// vector<int> arr2 = {22,28,8,6};

	vector<int> arr1 = {2,21,43,38,0,42,33,7,24,13,12,27,12,24,5,23,29,48,30,31};
	vector<int> arr2 = {2,42,38,0,43,21};

	auto ans = solution.relativeSortArray(arr1,arr2);
	
	PrintVector(ans);
	return 0;
}



