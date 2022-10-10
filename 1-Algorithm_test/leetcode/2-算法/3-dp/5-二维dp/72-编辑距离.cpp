#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
		int n = word1.size(),m = word2.size();
		vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		for(int i = 0;i <= n;i++)
			dp[i][0] = i;
		for(int j = 0;j <= m;j++)
			dp[0][j] = j;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]) + 1;
			}
		}	
		PrintVVector(dp);
		return dp[n][m];
    }
};



int main() {
	Solution solution;
	string word1 = "horse";
    string word2 = "ros";

	
	auto ans = solution.minDistance(word1,word2);
	
	cout << ans << endl;
	return 0;
}



