#include <iostream> 
#include <vector> 
#include <stack> 
using namespace std;


void printVector(vector<int> v){
	for(auto it : v)
		cout << it << " ";
}

class Solution {
public:
    string removeOuterParentheses(string s) {
		int len = s.size();
		stack<char> st;
		string ans;
		for(int i = 0;i < len;i++){
			if(s[i] == ')')
				st.pop();
			if(!st.empty())	//????????????????(??
				ans.push_back(s[i]);
			if(s[i] == '(')
				st.emplace(s[i]);
		}
		return ans;
    }
};



int main(){
	Solution sol;
	string s = "(()())(())";
	
	auto ans = sol.removeOuterParentheses(s);
	
	cout << ans << endl;
	return 0;
}



