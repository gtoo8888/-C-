#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printStirng(string str){
	for(int i = 0;i < str.size();i++)
		cout << str[i] << " ";
	cout << endl; 
}

class Solution {
public:
    string reverseStr(string s, int k) {
		for(int i = 0;i < s.size();i += (2 * k)) {
			if(i + k <= s.size()){//2k能整除完的，就在if里面解决，通过continue来跳过 
//				cout << s[i] << " " << s[i+k] << endl;
				reverse(s.begin() + i, s.begin() + i + k );
//				cout << s << endl;
				continue;
			}
//			cout << s[i] << " " << s[s.size()-1] << endl;
			reverse(s.begin() + i, s.begin() + s.size());
//			cout << s << endl;
		}
		return s;
    }
};

		
int main() {
	Solution solution;
	string str = "abcdefghijklmn";
	string ans;
	int k = 3;
	
	ans = solution.reverseStr(str,k);
	
	printStirng(ans);
	return 0;
}


