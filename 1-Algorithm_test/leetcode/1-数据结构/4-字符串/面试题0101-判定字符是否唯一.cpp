#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    bool isUnique(string astr) {
		if(astr.size() == 0)
			return true;
		unordered_set<char> uset;
		uset.insert(astr[0]);
		for(int i = 1;i < astr.size();i++){
			if(uset.find(astr[i]) == uset.end())
				uset.insert(astr[i]);
			else
				return false;
		}
		return true;
    }
};

		
int main() {
	Solution solution;
	// string s1 = "leetcode";
	string s1 = "abc";

	auto ans = solution.isUnique(s1);

	PrintBool(ans);
	return 0;
}


