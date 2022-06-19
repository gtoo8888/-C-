#include <algorithm> 
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
    	unordered_map<char,int> count;
    	int ans = 0;
    	for(auto c: s){
//    		cout << count[c] << endl;
    		++count[c];
    	}
//    	for(unordered_map<char,int>::iterator it = count.begin();it != count.end();it++){//±éÀú¹şÏ£±í 
//    		cout << it->first << " " << it->second << endl;
//		}
		for(unordered_map<char,int>::iterator it = count.begin();it != count.end();it++) {
//		for(auto it:count){
			int v = it->second;
			ans += v/2*2;
			if(ans%2 == 0 && v % 2 == 1)
				ans++;
		}
		return ans;
    }
};


int main(){
	Solution sol;
	int ans;
    string str;
    str = "abccccdd";

	ans = sol.longestPalindrome(str);
	cout << ans << endl;
    return 0;
}


