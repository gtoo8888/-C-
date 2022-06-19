#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void printBool(bool val){
	if(val == true)		cout << "YES" << endl;
	else				cout << "NO" << endl;
	cout << endl;
}

void printmap(unordered_map<char,char> m)  {
	for(unordered_map<char,char>::iterator it = m.begin();it !=  m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;
}

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		unordered_map<char,char>  m1;
		unordered_map<char,char>  m2;
		for(int i = 0;i < s.size();i++) {
//			cout << s[i] << " " << t[i] << endl;
			m1[s[i]] = t[i];
		}
//		cout << endl;
		for(int i = 0;i < t.size();i++) {
//			cout << m1[s[i]] << " " << t[i] << endl;
			m2[t[i]] = s[i];
			if(m1[s[i]] != t[i])
				return false;
		}
		printmap(m1);
//		cout << endl;
		for(int i = 0;i < s.size();i++) {
//			cout << m2[t[i]] << " " << t[i] << endl;
			if(m2[t[i]] != s[i])
				return false;
		}
//		cout << endl;	
		return true;
    }
};


	
int main() {
	Solution solution;
	string s = "baaaaaaaaaaaaaaaaaaar";
	string t = "foooooooooooooooooooo";
	bool ans;
	
	ans = solution.isIsomorphic(s,t);
	
	printBool(ans);
	
	return 0;
}



