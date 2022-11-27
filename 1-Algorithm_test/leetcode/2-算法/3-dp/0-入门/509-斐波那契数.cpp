#include <iostream> 
#include <vector>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// class Solution {
// public:
//     int fib(int n) {
//     	if(n == 0)
//     		return 0;
// 		vector<int> dp(n+1);
// 		dp[0] = 0;
// 		dp[1] = 1;
// 		for(int i = 2;i <= n;i++){
// 			dp[i] = dp[i - 1] + dp[i - 2];
// 		}
// 		PrintVector(dp);
// 		return dp[n];
//     }
// };


class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        vector<int> dp(n+1);
        dp[0] = 0;dp[1] = 1;
        for(int i = 2;i <= n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main(){
	Solution solution;
	int n = 10;
	
	auto ans = solution.fib(n);
		
	cout << ans << endl;
	return 0;
}
