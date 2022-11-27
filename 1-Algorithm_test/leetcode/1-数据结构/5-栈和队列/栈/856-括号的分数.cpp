#include <iostream> 
using namespace std;
#include <vector> 
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int scoreOfParentheses(string s) {
		stack<int> st;
		st.push(0);
		for(auto c : s){
			if(c == '(')
				st.push(0);
			else{
				int v = st.top();
				st.pop();
				st.top() += max(2*v,1);
			}
			PrintStack(st);
		}
		return st.top();
    }
};


int main(){
	Solution sol;
	// string s = "()()()((((((((()))))))";
	string s = "()()()()((()(((()))((())(((((()))()()())))))))";
	
	auto ans = sol.scoreOfParentheses(s);
	cout << ans << endl;
	return 0;
}



