#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
		int ans = INT32_MIN;
		for(int i = 0;i < n ;i++){
			int size = 1;
			int pos = i;
			while(s[pos+1] == s[pos]+1 ){
				pos++;size++;
			}
			ans = size > ans ? size : ans;
		}
		return ans;
    }
};
	
int main() {
	Solution solution;
    string s = "abcde";

    auto ans = solution.longestContinuousSubstring(s);

	cout << ans << endl;
	return 0;
}




