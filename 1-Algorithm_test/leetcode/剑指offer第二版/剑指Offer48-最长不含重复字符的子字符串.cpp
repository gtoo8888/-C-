#include <algorithm> 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int n = s.size();
		if(n == 0)
			return 0;
		vector<int> dp(n,0);
		unordered_set<char> uset;
		dp[0] = 1;
		int j = 0;
		for(int i = 0;i < n;i++){
			if(i != 0)
				uset.erase(s[i-1]);
			while(j < n && uset.find(s[j]) == uset.end()){
				uset.insert(s[j]);
				j++;
			}
			dp[i] = j-i;
		}	
		PrintVector(dp);
		return *max_element(dp.begin(),dp.end());
    }
};




int main(){
	Solution sol;
	string s = "abcabcbb";
	
	// string s = "bbbbb";
	// string s = "abcaaaa";
	// string s = "pwwkew";

	auto ans = sol.lengthOfLongestSubstring(s);
	
	cout << ans << endl;
	return 0;
}
