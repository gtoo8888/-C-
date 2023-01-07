#include <iostream>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
		// PrintBit(x^y);
		int tmp = x ^ y;
		int ans = 0;
		while(tmp != 0){
			if(tmp&1 == 1)
				ans++;
			tmp >>= 1;
		}
		return ans;
    }
};


	
int main() {
	Solution solution;
	int x = 3, y = 1;

	auto ans = solution.hammingDistance(x,y);

	cout << ans << endl;
	
	return 0;
}



