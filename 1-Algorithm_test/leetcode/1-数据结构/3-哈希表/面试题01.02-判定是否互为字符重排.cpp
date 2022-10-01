#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

// class Solution {
// public:
//     bool CheckPermutation(string s1, string s2) {
// 		unordered_map<char,int> map;
// 		for(auto c : s1){
// 			map[c]++;
// 		}
// 		PrintUnorder_Map(map);
// 		for(auto c : s2){
// 			map[c]--;
// 		}
// 		PrintUnorder_Map(map);
// 		for(auto it : map){
// 			if(it.second != 0)
// 				return false;
// 		}
// 		return true;
//     }
// };

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
		int zidian[26] = {0};
		for(auto c : s1){
			zidian[c-'a']++;
		}
		for(auto c : s2){
			zidian[c-'a']--;
		}
		for(int i = 0;i < 26;i++){
			if(zidian[i] != 0)
				return false;
		}
		return true;
    }
};


int main() {
	Solution solution;
	// string s1 = "abc";
	// string s2 = "bca";
	
	string s1 = "abc";
	string s2 = "bad";	
	auto ans = solution.CheckPermutation(s1,s2);

	PrintBool(ans);

	return 0;
}



