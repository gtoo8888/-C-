#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    string removeStars(string s) {
        string ans = "";
		int n = s.size();
		for(int i = 0;i < n;i++){
			if(s[i] == '*'){
				ans.pop_back();
			}else{
				ans.push_back(s[i]);
			}
		}
		return ans;
    }
};


int main() {
	Solution solution;
	// string s = "leet**cod*e";
	string s = "erase*****";
	
    auto ans = solution.removeStars(s);

	cout << ans << endl;
	return 0;
}




