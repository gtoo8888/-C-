#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1,0);
        int p1 = 1,p2 = 1,p3 = 1;
        dp[1] = 1;
        for(int i = 2;i <= n;i++){
            int num1 = dp[p1]*2,num2 = dp[p2]*3,num3 = dp[p3]*5;
            dp[i] = min(min(num1,num2),num3);
            if(dp[i] == num1)
                p1++;
            if(dp[i] == num2)
                p2++;
            if(dp[i] == num3)
                p3++;
        }
        PrintVector(dp);
        return dp[n];
    }
};

// TODO 最小堆

int main() {
	Solution solution;
	int n = 11;
	
	auto ans = solution.nthUglyNumber(n);
	
	cout << ans << endl;
	return 0;
}


