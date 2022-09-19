#include <iostream>
using namespace std;


class Solution {
public:
    string toLowerCase(string s) {
//		cout << (int)'A' << endl;
//		cout << (int)'a' << endl;
		for(int i = 0;i < s.size();i++) {
			if(s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i] + ('a' - 'A');
		}
		return s;
    }
};



	
int main() {
	Solution solution;
	string rings = "LOVELY";
	
	auto ans = solution.toLowerCase(rings);
	
	cout << ans << endl;
	
	return 0;
}



