#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int longestValidParentheses(string s) {
		int ans = 0;
		stack<int> st;
		st.push(-1);
		for(int i = 0;i < s.size();i++){
			if(s[i] == '(')
				st.push(i);
			else{
				st.pop();
				if(st.empty())	// ���ǰ��û����ĸ��ʱ�򣬵ð�)Ҳ���Ž�ȥ
					st.push(i);
				else
					ans = max(ans,i - st.top());
			}
			// PrintStack(st);
		}
		return ans;
    }
};
		
int main() {
	Solution solution;
	// string s = "(()()";
	string s = ")()())";
	
	auto ans = solution.longestValidParentheses(s);
	
	cout << ans << endl;
	return 0;
}


