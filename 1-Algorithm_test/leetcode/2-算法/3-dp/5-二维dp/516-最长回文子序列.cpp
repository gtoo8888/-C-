#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 动态规划法
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
				// printf("%c %c\n",s[i],s[j]);
				// printf("%d\n",dp[i + 1][j - 1]);
				// printf("%d %d\n",dp[i + 1][j], dp[i][j - 1]);
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
				// PrintVVector(dp);
            }
        }
		
        return dp[0][n - 1];		
    }
};



int main() {
	Solution solution;
	string s = "bbbab";

	auto ans = solution.longestPalindromeSubseq(s);
	
	cout << ans << endl;
	return 0;
}



