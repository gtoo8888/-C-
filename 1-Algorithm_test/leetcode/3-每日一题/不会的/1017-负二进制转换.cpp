#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    string baseNeg2(int n) {
		if(n == 0)
			return "0";
		string ans;
		int k = 1;
		while(n>0){
			int tmp = n%2;
			if(tmp == 1){
				ans.push_back('1');
				n -= k; // 在奇数的二进制变化是和偶数不一样的
			}else{
				ans.push_back('0');
			}
			k *= -1;
			n /= 2;
		}
		reverse(ans.begin(),ans.end());
		return ans;
    }
};

	
int main() {
	Solution solution;
	int n = 2;
	auto ans = solution.baseNeg2(n);
	
	cout << ans << endl;
	return 0;
}



