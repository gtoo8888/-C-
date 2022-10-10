#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"




class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        int n = s.size();
        vector<bool> dp(n,false);
        dp[0] = true;
        for(int i = 0;i <= n;i++) {  //从s的第一个字母开始做切分
            for(int j = 0;j < i;j++) { // 
                string word = s.substr(j,i-j);
                // cout << word << endl;
                if(wordset.find(word) != wordset.end() && dp[j]) {// 如果抽出来的单词，在字典中找到了
                    dp[i] = true;
                }   
            }
        }
        // PrintVector(dp);
        return dp[n];
    }
};



int main() {
	Solution solution;
    // string s = "applepenapple";
	// vector<string> wordDict = {"apple", "pen"};

    string s = "leetcode";
	vector<string> wordDict = {"leet", "code"};	
	auto ans = solution.wordBreak(s,wordDict);
	
	PrintBool(ans);
	return 0;
}



