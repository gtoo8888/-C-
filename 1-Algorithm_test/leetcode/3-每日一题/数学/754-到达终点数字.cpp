#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
		int n = 0,s = 0;
		while(s < target || (s - target)%2 ){
			printf("%d %d %d\n",s,n,s - target);
			s += ++n;
		}
		return n;
    }
};


int main() {
	Solution sol;
	// int target = 3;
	int target = 15;

	auto ans = sol.reachNumber(target);

	cout << ans << endl;
	return 0;
}

