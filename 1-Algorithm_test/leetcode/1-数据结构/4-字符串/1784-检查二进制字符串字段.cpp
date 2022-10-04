#include <iostream>
#include <algorithm>
using namespace std;

#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    bool checkOnesSegment(string s) {
		// 如果有01，1....01 必定有分开的
		// 如果有10, 1....10 必定有连续的
		return s.find("01") == string::npos;
    }
};

		
int main() {
	Solution solution;
	string s = "1001";
	
	auto ans = solution.checkOnesSegment(s);

	PrintBool(ans);
	
	return 0;
}


