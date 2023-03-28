#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
		int n = a.size();
		if(n == 0)
			return {};
		vector<int> pre_l(n+2,1);
		vector<int> pre_r(n+2,1);
		vector<int> ans(n,1);
		pre_l[1] = a[0];
		pre_r[n-1] = a[n-1];
		for(int i = 2;i <= n;i++){
			pre_l[i] = pre_l[i-1]*a[i-1];
		}
		for(int i = n;i > 0;i--){
			pre_r[i] = pre_r[i+1]*a[i-1];
		}
		// PrintVector(pre_l);
		// PrintVector(pre_r);
		for(int i = 0;i < n;i++){
			ans[i] = pre_l[i]*pre_r[i+2];
		}
		return ans;
    }
};


int main(){
	Solution sol;
	// vector<int> a = {1,2,3,4,5};
	vector<int> a = {};
	auto ans = sol.constructArr(a);
	PrintVector(ans);
	return 0;
}
