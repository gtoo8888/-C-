#include <algorithm> 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// class Solution {
// public:
//     string reverseWords(string s) {
// 		int n = s.size();
// 		if(n == 0)
// 			return "";
// 		int l=0,r=n-1;
		
// 		while(s[l] == ' ' && l < n) 
// 			l++;
// 		while(s[r] == ' ' && r > 0) 
// 			r--;
// 		if(r <= l)
// 			return "";
// 		vector<string> keys;
// 		while(l <= r){
// 			int length = 0;
// 			int start = l;
// 			while(s[l] != ' ' && l < n){
// 				length++;
// 				l++;
// 			}
// 			while(s[l] == ' ' && l < n){
// 				l++;
// 			}
// 			string tmp = s.substr(start,length);
// 			keys.push_back(tmp);
// 		}
// 		// PrintVector(keys);
// 		reverse(keys.begin(),keys.end());
// 		// PrintVector(keys);
// 		string ans;
// 		for(int i = 0;i < keys.size();i++){
// 			if(i < keys.size()-1)
// 				ans += keys[i] + " ";
// 			else
// 				ans += keys[i];
// 		}
// 		return ans;
//     }
// };

// 只需要简单的将空格排除掉就可以了
class Solution {
public:
    string reverseWords(string s) {
		int n = s.size();
		vector<string> keys;
		for(int i = 0;i < n;i++){
			if(s[i] != ' '){
				int length = 0;
				int start = i;
				while(s[i] != ' ' && i < n){
					length++;
					i++;
				}
				string tmp = s.substr(start,length);
				keys.push_back(tmp);
			}
		}
		// PrintVector(keys);
		reverse(keys.begin(),keys.end());
		// PrintVector(keys);
		string ans;
		for(int i = 0;i < keys.size();i++){
			if(i < keys.size()-1)
				ans += keys[i] + " ";
			else
				ans += keys[i];
		}
		return ans;
    }
};



int main(){
	Solution sol;
	// string s = "the sky is blue";
	// string s = "  hello world!  ";
	// string s = 	"a good   example";
	// string s = "";
	// string s = " ";
	// string s = "    ";
	string s = "a";



	auto ans = sol.reverseWords(s);
	
	cout << ans << endl;
	return 0;
}
