#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 看代码随想录时候写的
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.size();
//         int n2 = text2.size();
// 		text1 = ' ' + text1;
// 		text2 = ' ' + text2;
//         vector<vector<int>> dp(n1+1,vector<int>(n2+1));
// 		for(int i = 1;i <= n1;i++){
// 			for(int j = 1;j <= n2;j++){
// 				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
// 				// printf("%c %c\n",text1[i],text2[j]);
// 				if(text1[i] == text2[j])
// 					dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
// 			}
// 			// PrintVVector(dp);
// 		}
// 		return dp[n1][n2];
//     }
// };


// 错误的做法，只有一维的思路
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
// 		int n = text1.size(),m = text2.size();
// 		if(m > n){
// 			string tmp = text2;
// 			text2 = text1;
// 			text1 = tmp;
// 		}
// 		n = text1.size(),m = text2.size();
// 		vector<int> dp(n,0);
// 		int j = 0;
// 		if(text1[0] == text2[0])
// 			dp[0] = 1,j++;

// 		for(int i = 1;i < n;i++){
// 			if(text2[j] == text1[i]){
// 				dp[i] = dp[i-1] + 1;
// 				j++;
// 			}else
// 				dp[i] = dp[i-1];
// 		}
// 		PrintVector(dp);
// 		return dp[n-1];
//     }
// };


// 二维dp
// 为什么要用二维？
// 因为是子序列之间的对比，先把一个字符串拆开来，text1的每个字符都a,b,c，a就可以对整个text2进行动态规划的转移
// 同时在用b,c来转移的时候，可以接受a动态规划后的结果，所以使用二维
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size(),m = text2.size();
		vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(text1[i-1] == text2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		// PrintVVector(dp);
		return dp[n][m];
    }
};



int main() {
	Solution solution;
	// string text1 = "abcde";
    // string text2 = "ace";

	// string text1 = "ace";
    // string text2 = "abcde";

	// string text1 = "abc";
    // string text2 = "abc";

	// string text1 = "abc";
    // string text2 = "def";

	// string text1 = "psnw";
    // string text2 = "vozsh";

	string text1 = "psnh";
    string text2 = "vozsh";
	
	auto ans = solution.longestCommonSubsequence(text1,text2);
	
	cout << ans << endl;
	return 0;
}



