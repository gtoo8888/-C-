#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"



class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1;i <= n;i++){
            if(s[i-1] != '0')
                dp[i] += dp[i-1];
            if(i > 1 && s[i-2] != '0' && ( (s[i-2]-'0')*10 + s[i-1]-'0') <= 26)
                dp[i] += dp[i-2];
        }
        PrintVector(dp);
        return dp[n];
    }
};



int main() {
	Solution solution;

    string s = "06";

	auto ans = solution.numDecodings(s);
	
	cout << ans << endl;
	return 0;
}



