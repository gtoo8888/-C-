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
    string replaceSpace(string s) {
    	if(s == "")
    		return "";
    	int len = s.size();
		int num = 0;
		string ans;
		for(int i = 0;i < s.size();i++) 
			if(s[i] == ' ')
				num++;
		s.resize(s.size() + num*2);
		int new_len = s.size();
		int j = len - 1;
		
		for(int i = new_len - 1;i >= 0;i--,j--) {
			if(s[j] == ' ') {
				i -= 2;
				s[i] = '%';
				s[i + 1] = '2';
				s[i + 2] = '0';
			}
			else
				s[i] = s[j];
			cout << s << endl;
		}
		return s;
    }
};


		
int main() {
	Solution solution;
	string str = "   ";
	string ans;
	
	ans = solution.replaceSpace(str);
	
	printStirng(ans);
	return 0;
}


