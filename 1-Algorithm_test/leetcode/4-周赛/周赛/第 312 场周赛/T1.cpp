#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


bool myconpare(pair<string,int> p1,pair<string,int> p2){
	if(p1.second > p2.second)
		return true;
	// else if(p1.second < p2.second)
    else
		return false;
    return true;
}

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>> paixu;
        int n = names.size();
        for(int i = 0;i < n;i++){
            paixu.emplace_back(pair<string,int>(names[i],heights[i]));
        }
        sort(paixu.begin(),paixu.end(),myconpare);
        vector<string> ans;
        for(auto it : paixu){
            ans.emplace_back(it.first);
        }
        return ans;
    }
};
	
int main() {
	Solution solution;
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};
    int n = 5;

    auto ans = solution.sortPeople(names,heights);

	PrintVSector(ans);
	return 0;
}




