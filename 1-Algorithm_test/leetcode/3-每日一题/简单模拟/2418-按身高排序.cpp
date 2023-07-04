#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>> vp;
		int n = names.size();
		for(int i = 0;i < n;i++){
			vp.push_back(pair<string,int>{names[i],heights[i]});
		}
		sort(vp.begin(),vp.end(),[&](pair<string,int> p1,pair<string,int> p2){
			return p1.second > p2.second;
		});
		// PrintVP(vp);
		vector<string> ans(n);
		for(int i = 0;i < n;i++){
			ans[i] = vp[i].first;
		}
		return ans;
    }
};


	
int main() {
	Solution solution;
	vector<string> names = {"Mary","John","Emma"};
	vector<int> heights = {180,165,170};
	
	auto ans = solution.sortPeople(names,heights);
	
	PrintVector(ans);
	
	return 0;
}



