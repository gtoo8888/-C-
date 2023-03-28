#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
	bool check2(string str, int i,int j){
		while(i < j && str[i] == str[j])
			i++,j--;
		return i >= j;
	}

	bool check(string a,string b){
		int l = 0,r = a.size()-1;
		while(l < r && a[l] == b[r])
			l++,r--;
		return check2(a,l,r) || check2(b,l,r);
	}

    bool checkPalindromeFormation(string a, string b) {
		return check(a,b) || check(b,a);
    }
};

		
int main() {
	Solution solution;
	string a = "pvhmupgqeltozftlmfjjde",b = "yjgpzbezspnnpszebzmhvp";
	// string a = "x",b = "y";
	// string a = "abdef",b = "fecab";
	
	auto ans = solution.checkPalindromeFormation(a,b);
	
	PrintBool(ans);
	return 0;
}


