#include <algorithm> 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int r=-1;
		int ans = 0;
		int n = s.size();
		unordered_map<char,int> map;
		for(int i = 0;i < n;i++){
			// r = i;
			if(i != 0){
				map.erase(s[i-1]);
			}
			while(r+1 < n && map.find(s[r+1]) == map.end()){
				map[s[r+1]]++;
				r++;
			}
			// PrintUnorder_Map(map);
			// printf("%d %d %d\n",i,r,ans);
			ans = ans < r-i+1 ? r-i+1 : ans;
		}
		return ans;
    }
};



int main(){
	Solution sol;
	// string s = "abcabcbb";
	
	// string s = "bbbbb";
	// string s = "abcaaaa";
	string s = "pwwkew";

	auto ans = sol.lengthOfLongestSubstring(s);
	
	cout << ans << endl;
	return 0;
}
