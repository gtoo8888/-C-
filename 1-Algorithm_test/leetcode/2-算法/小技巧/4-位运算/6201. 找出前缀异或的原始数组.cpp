#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        if(n == 1)
            return vector<int> {pref[0]};
        vector<int> ans(n,0);
        ans[0] = pref[0];
        for(int i = 1;i < n;i++){
            printf("%d %d\n",ans[i-1] , pref[i]);
            ans[i] = pref[i-1] ^ pref[i];
        }
        return ans;
    }
};
	
int main() {
	Solution solution;
    // vector<int> pref = {5,2,0,3,1};
    // vector<int> pref = {13};
    vector<int> pref = {3,4,5,6,2,9};
     printf("%d\n",5^7);

    auto ans = solution.findArray(pref);

	PrintVector(ans);
	return 0;
}




