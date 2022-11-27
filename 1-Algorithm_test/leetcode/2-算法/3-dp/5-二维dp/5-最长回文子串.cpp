#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 中心法
class Solution {
public:
    string longestPalindrome(string s) {
		int n = s.size();
		int start = 0,end = 0;
		for(int i = 0;i < n;i++){
			int len1 = gethuiwen(s,i,i);
			int len2 = gethuiwen(s,i,i+1);
			int max_len = max(len1,len2);
			if(max_len > end - start){
				start = i-(max_len-1)/2;
				end = i+max_len/2;

			}
			
		}
		return s.substr(start,end-start+1);
    }

	int gethuiwen(string s,int l,int r){
		while(l >= 0 && r < s.size() && s[l] == s[r]){
			l--;r++;
		}
		return r-l-1;
	}
};

// TODO 动态规划法


int main() {
	Solution solution;
	string s = "babad";

	auto ans = solution.longestPalindrome(s);
	
	cout << ans << endl;
	return 0;
}



