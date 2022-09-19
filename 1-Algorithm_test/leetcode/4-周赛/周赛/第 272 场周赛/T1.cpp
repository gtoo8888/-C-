#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

class Solution {
public:
	bool ishuiwen(string s) {
		int i = 0;
		int j = s.size() - 1;
		for(;i < j;i++,j--) {
			if(s[i] != s[j])
				return false;
		}
		return true;
	}
	
    string firstPalindrome(vector<string>& words) {
    	for(int i = 0;i < words.size();i++) {
//    		cout << words[i] << endl;
    		if(ishuiwen(words[i]))
    			return words[i];
		}
        return "";
    }
};


	
int main() {
	Solution solution;
	vector<string> words = {"abc","car","ada","racecar","cool"};
	string ans;
	
	ans = solution.firstPalindrome(words);
	
	cout << ans << endl;
	
	return 0;
}



