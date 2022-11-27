#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
	string Bitreverse(string word){
		string ans;
		for(auto c : word){
			string key = (c == '0') ? "1" : "0";
			ans += key;
		}
		reverse(ans.begin(),ans.end());
		return ans;
	}
    char findKthBit(int n, int k) {
		string Sn_1 = "0";
		string Sn;
		for(int i = 0;i < n;i++){
			Sn = Sn_1 + "1" + Bitreverse(Sn_1);
			Sn_1 = Sn;
			// cout << Sn << endl;
		}
		return Sn[k-1];
    }
};

		
int main() {
	Solution solution;
	int n = 4;
	int k = 11;
	
	auto ans = solution.findKthBit(n,k);
	cout << ans << endl;
	return 0;
}


