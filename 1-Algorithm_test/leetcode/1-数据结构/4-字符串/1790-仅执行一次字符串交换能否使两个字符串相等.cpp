#include <iostream>
#include <algorithm>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
		vector<pair<char,char>> save;
		int n = s1.size();
		for(int i = 0;i < n;i++){
			if(s1[i] != s2[i])
				save.push_back(pair<char,char>(s1[i],s2[i]));
		}
		if(save.size() == 0)
			return true;
		if(save.size() != 2)
			return false;
		
		if((save[0].first != save[0].second && save[0].first != save[1].second) || 
		(save[1].first != save[0].second && save[1].first != save[1].second) )
			return false;
		return true;
    }
};

		
int main() {
	Solution solution;
	// string s1 = "bank";
	// string s2 = "kanb";

	// string s1 = "attack";
	// string s2 = "defend";	

	string s1 = "kelb";
	string s2 = "kelb";

	// string s1 = "abcd";
	// string s2 = "dcba";

	// string s1 = "abcd";
	// string s2 = "fbce";

	// string s1 = "abcd";
	// string s2 = "abce";

	auto ans = solution.areAlmostEqual(s1,s2);

	PrintBool(ans);
	
	return 0;
}


