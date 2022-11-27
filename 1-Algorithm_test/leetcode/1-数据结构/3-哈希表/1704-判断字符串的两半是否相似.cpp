#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
	vector<char> yuan = {'a','e','i','o','u','A','E','I','O','U'};
    bool halvesAreAlike(string s) {
		unordered_set<char> set;
		for(auto c : yuan){
			set.emplace(c);
		}
		int n = s.size();
		int ll=0,rr=0;
		for(int i = 0;i < n/2;i++){
			// printf("%c %c\n",s[i],s[n-i-1]);
			if(set.find(s[i]) != set.end())
				ll++;
			if(set.find(s[n-i-1]) != set.end())
				rr++;
		}
		// printf("%d %d\n",ll,rr);
		if(ll == rr)
			return true;
		else
			return false;
    }
};
		
int main() {
	Solution solution;
	// string s = "book";
	string s = "textbook";
	
	auto ans = solution.halvesAreAlike(s);
	
	PrintBool(ans);
	return 0;
}



