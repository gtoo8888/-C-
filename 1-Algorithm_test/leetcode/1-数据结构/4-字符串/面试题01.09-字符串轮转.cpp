#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
		if(s1.size() != s2.size())
			return false;
		if(s1 == "" && s1.size() == s2.size())
			return true;
		string s11 = s1 + s1;
		int j = 0;
		for(int i = 0;i < s11.size();i++){
			if(s11[i] == s2[j]){
				j++;
			}else{
				j = 0;
			}
			if(j == s2.size())
				return true;
		}
		return false;
    }
};

		
int main() {
	Solution solution;
	// string s1 = "waterbottle";
	// string s2 = "erbottlewat";

	// string s1 = "aa";
	// string s2 = "aba";

	string s1 = "abc";
	string s2 = "cab";

	auto ans = solution.isFlipedString(s1,s2);

	PrintBool(ans);
	return 0;
}


