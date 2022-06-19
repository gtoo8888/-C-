#include <algorithm> 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void PrintMap(unordered_map<int,int> m) {
	for(auto it : m)
		printf("%d %d\n",it.first,it.second);
	cout << endl;	
}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		unordered_map<int,int> m;
		for(auto n : nums){
			m[n]++;
		}
		// PrintMap(m);
		for(auto it : m){
			int fi = it.first;
			int se = it.second;
			if(se == 1)
				return fi;
		}
		// return 0;
    }
};



int main(){
	Solution sol;
	vector<int> nums = {3,4,3,3};
	auto ans = sol.singleNumber(nums);
	cout << ans << endl;
	return 0;
}
