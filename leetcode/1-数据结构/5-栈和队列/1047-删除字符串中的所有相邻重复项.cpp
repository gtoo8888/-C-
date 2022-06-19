#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
		stack<char> sta;
		for(int i = 0;i < s.size();i++){
			cout << s[i] << endl; 
			if(!sta.empty() && sta.top() == s[i])
				sta.pop();
			else
				sta.push(s[i]);
		}
		string ans;
		while(!sta.empty()){
			ans.push_back(sta.top());
			sta.pop();
		}
		reverse(ans.begin(),ans.end());
//		cout << ans << endl;
		return ans;
    }
};

		
int main() {
	Solution solution;
	int k = 2;
	string str = "azxxzy";
	string ans;
	
	ans = solution.removeDuplicates(str);
	
	cout << "\"" << ans << "\"" << endl;
	return 0;
}


