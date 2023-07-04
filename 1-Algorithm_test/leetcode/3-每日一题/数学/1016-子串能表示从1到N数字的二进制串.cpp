#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    bool queryString(string s, int n) {
		for(int i = 1;i <= n;i++){
			string bin = bitset<32>(i).to_string();
			string binsub = bin.substr(bin.find('1')); // 就是去掉前置0
			// cout << bin << endl;
			// cout << binsub << endl;
			if(s.find(binsub) == string::npos)
				return false;
		}
		return true;
    }
};


int main() {
	Solution sol;
	string s;int n;
	s = "0110", n = 3;
	PrintBool(sol.queryString(s,n));cout << "---------------------" << endl;

	s = "0110", n = 4;
	PrintBool(sol.queryString(s,n));cout << "---------------------" << endl;

	return 0;
}

