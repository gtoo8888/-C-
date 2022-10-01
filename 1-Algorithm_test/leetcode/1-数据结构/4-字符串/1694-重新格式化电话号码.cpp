#include <iostream>
#include <algorithm>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    string reformatNumber(string number) {
		vector<char> tmp;
		for(auto c : number){
			if(c == ' ' || c == '-')
				continue;
			tmp.emplace_back(c);
		}
		PrintVCector(tmp);
		string ans;
		int new_len = tmp.size();
		for(int i = 0;i < tmp.size();i += 3){
			if(new_len - i == 4){
				ans.push_back(tmp[i]);
				ans.push_back(tmp[i+1]);
				ans.push_back('-');
				ans.push_back(tmp[i+2]);
				ans.push_back(tmp[i+3]);
				break;
			}else if(new_len - i == 3){
				ans.push_back(tmp[i]);
				ans.push_back(tmp[i+1]);
				ans.push_back(tmp[i+2]);
				break;
			}else if(new_len - i == 2){
				ans.push_back(tmp[i]);
				ans.push_back(tmp[i+1]);
				break;
			}else {
				ans.push_back(tmp[i]);
				ans.push_back(tmp[i+1]);
				ans.push_back(tmp[i+2]);
				ans.push_back('-');
			}

		}
		return ans;

    }
};

		
int main() {
	Solution solution;
	// string number = "1-23-45 6";
	// string number = "123 4-567";
	// string number = "123 4-5678";
	// string number = "12";
	// string number = "123";
	string number = "--17-5 229 35-39475 ";
	string ans;
	
	ans = solution.reformatNumber(number);

	cout <<  ans << endl;
	
	return 0;
}


