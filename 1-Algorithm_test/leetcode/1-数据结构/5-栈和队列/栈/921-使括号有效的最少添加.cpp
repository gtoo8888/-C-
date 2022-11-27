#include <iostream>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int minAddToMakeValid(string s) {
		int l = 0;
		int n = s.size();
		int ans = 0;
		for(int i = 0;i < n;i++){
			if(s[i] == '(')
				l++;
			else if(s[i] == ')'){
				if(l > 0)	//如果碰到右括号，优先消解掉左括号
					l--;
				else
					ans++;				
			}
			// printf("%d %d\n",ans,l);
		}
		ans += l;
		return ans;
    }
};

		
int main() {
	Solution solution;
	// string s = "(((";
	// string s = ")))";
	// string s = "(()";
	// string s = "()))";
	// string s = "(()())";	// (()()) 这样是可以的
	// string s = "()))((";
	// string s = "()))(()()))))";	
	string s = "()))(((()(((()))))))))";
	
	
	auto ans = solution.minAddToMakeValid(s);

	cout << ans << endl;
	
	return 0;
}


