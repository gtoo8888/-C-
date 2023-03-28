#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int countSubstrings(string s, string t) {
		int ans = 0;
		int n = s.size(),m = t.size();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(s[i] != t[j]){
					int l=0,r=0;
					while(i-l>0 && j-l>0 && s[i-l-1]==t[j-l-1]){
						++l;}
					while(i+r+1<n && j+r+1<m && s[i+r+1]==t[j+r+1]){
						++r;}
					ans += (l+1)*(r+1);
					// printf("i:%d j:%d l:%d r:%d\n",i,j,l,r);
				}
			}
		}
		return ans;
    }
};


// class Solution {
// public:
//     int countSubstrings(string s, string t) {
//         int ans = 0;
//         int m = s.size(), n = t.size();
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (s[i] != t[j]) {
//                     int l = 0, r = 0;
//                     while (i - l > 0 && j - l > 0 && s[i - l - 1] == t[j - l - 1]) {
//                         ++l;
//                     }
//                     while (i + r + 1 < m && j + r + 1 < n && s[i + r + 1] == t[j + r + 1]) {
//                         ++r;
//                     }
//                     ans += (l + 1) * (r + 1);
//                 }
//             }
//         }
//         return ans;
//     }
// };


int main() {
	Solution solution;
	// string s = "aba",t = "baba";
	// string s = "abe",t = "bbc";
	string s = "abbab",t = "bbbbb";
	
	auto ans = solution.countSubstrings(s,t);
	
	cout << ans <<endl;
	return 0;
}


