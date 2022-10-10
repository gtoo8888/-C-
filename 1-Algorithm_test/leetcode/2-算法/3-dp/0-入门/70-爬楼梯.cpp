#include <iostream> 
#include <vector>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        vector<int> dp(n+1);
        dp[0] = 1;dp[1] = 1;
        for(int i = 2;i <= n;i++){
            dp[i] = dp[i-1] + dp[i-2];
			// PrintVector(dp);
        }
        return dp[n];
    }
};

int main(){
	Solution solution;
	int n = 10;
	
	auto ans = solution.climbStairs(n);
		
	cout << ans << endl;
	return 0;
}
