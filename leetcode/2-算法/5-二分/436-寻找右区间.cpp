#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;



void printVector(vector<int> v){
	for(auto it : v)
		cout << it << " ";
}

void PrintVVector(vector<vector<int>>& v){
	for(auto iter : v){
		auto it_tmp = iter;
		for(auto it : it_tmp)
			cout << it << " ";
		cout << endl;
	}
	cout << endl;
}

void printVIIector(vector<pair<int,int>> v){
	for(auto it : v)
		printf("%d %d\n",it.first,it.second);
	cout << endl;
}

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
		vector<pair<int,int>> vec;
		int n = intervals.size();
		for(int i = 0;i < n;i++){
			vec.emplace_back(intervals[i][0],i);
		}
		printVIIector(vec);
		sort(vec.begin(),vec.end());
		printVIIector(vec);
		vector<int> ans(n,-1);
		for(int i = 0;i < n;i++){
			auto it = lower_bound(vec.begin(),vec.end(),make_pair(intervals[i][1],0));
			if(it != vec.end())
				ans[i] = it->second;
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<vector<int>> intervals = {{3,4},{2,3},{1,2}};
	
	auto ans = sol.findRightInterval(intervals);
	
	printVector(ans);
	return 0;
}
