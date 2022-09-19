#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
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

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
		text1 = ' ' + text1;
		text2 = ' ' + text2;
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
		for(int i = 1;i <= n1;i++){
			for(int j = 1;j <= n2;j++){
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				// printf("%c %c\n",text1[i],text2[j]);
				if(text1[i] == text2[j])
					dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
			}
			// PrintVVector(dp);
		}
		return dp[n1][n2];
    }
};



int main() {
	Solution solution;
	// string text1 = "abcde";
    // string text2 = "ace";
	string text1 = "abc";
    string text2 = "def";
	
	auto ans = solution.longestCommonSubsequence(text1,text2);
	
	cout << ans << endl;
	return 0;
}



