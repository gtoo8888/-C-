#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
		cout << "\"" << s << "\"" << endl;
		reverse(s.begin(),s.begin() + n);
		cout << "\"" << s << "\"" << endl;
		reverse(s.begin() + n,s.end());
		cout << "\"" << s << "\"" << endl;
		reverse(s.begin(),s.end());
		return s;
    }
};

		
int main() {
	Solution solution;
	int k = 2;
	string str = "abcdefg";
	string ans;
	
	ans = solution.reverseLeftWords(str,k);
	
	cout << "\"" << ans << "\"" << endl;
	
	return 0;
}


