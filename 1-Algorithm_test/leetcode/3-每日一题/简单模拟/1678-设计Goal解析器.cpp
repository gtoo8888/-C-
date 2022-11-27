#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    string interpret(string command) {
		string ans;
		int n = command.size();
		for(int i = 0;i < n;i++){
			string str1,str2;
			if(i + 2 <= n)
				str1 = command.substr(i,2);
			if(i + 4 <= n)
				str2 = command.substr(i,4);
			// cout << str1 << endl;
			// cout << str2 << endl;
			if(command[i] == 'G')
				ans += 'G';
			if(str1 == "()")
				ans += 'o';
			if(str2 == "(al)")
				ans += "al";
		}
		return ans;
    }
};


	
int main() {
	Solution solution;
	// string command = "G()(al)";
	// string command = "G()()()()(al)";
	string command = "(al)G(al)()()G";
	
	
	auto ans = solution.interpret(command);
	
	cout << ans << endl;
	
	return 0;
}



