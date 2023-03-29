#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
		int n = haystack.size();
		int m = needle.size();
		for(int i = 0;i < n;i++){
			int j = 0;
			for(;j < m;j++){
				if(haystack[i+j] != needle[j]){
					break;
				}
			}
			if(j == m)
				return i;
		}
		return -1;
    }
};


	
int main() {
	Solution solution;
	string haystack = "low";
	string needle = "low";

	auto ans = solution.strStr(haystack,needle);
	
	cout << ans << endl;
	
	return 0;
}



