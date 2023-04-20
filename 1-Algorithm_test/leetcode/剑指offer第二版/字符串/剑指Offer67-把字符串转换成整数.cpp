#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"



class Solution {
public:
    int strToInt(string str) {
		int start = 0;
		int n = str.size();
		bool fu_flag = false;
		for(int i = 0;i < n;i++){
			if(str[i] == ' ')
				continue;
			if(str[i] == '-' || (str[i] >= '0' && str[i] <= '9')){
				start = i;
				if(str[i] == '-'){
					start = i+1;
					fu_flag = true;
				}
				break;
			}
		}
		string num_str(str.begin()+start,str.end());
		
		return -1;
    }
};


int main(){
	Solution sol;
	// string str = "42";
	string str = "  42";
	auto ans = sol.strToInt(str);
	cout << ans << endl;
	return 0;
}
