#include <algorithm> 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


set<char> num_set = {'1','2'};
class Solution {
public:
    bool isNumber(string s) {
		for(auto c : s){
			if(c == 'E' || c == 'e'){
				
			}
		}

		return false;
    }
};

int main(){
	Solution sol;
	
	PrintBool(sol.isNumber("0"));;cout << "------------------------" << endl;
	PrintBool(sol.isNumber("e"));;cout << "------------------------" << endl;
	PrintBool(sol.isNumber("."));;cout << "------------------------" << endl;
	PrintBool(sol.isNumber("   .1  "));;cout << "------------------------" << endl;

	return 0;
}
