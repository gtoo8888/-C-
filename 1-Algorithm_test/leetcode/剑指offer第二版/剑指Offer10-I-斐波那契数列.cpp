#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// class Solution {
// public:
//     int fib(int n) {
//         vector<int> dp(n+1,0);
//         if(n == 0) return 0;
//         if(n == 1) return 1;
//         dp[0] = 0;
//         dp[1] = 1;
//         for(int i = 2;i <= n;i++)
//             dp[i] = dp[i-2] + dp[i-1];
//         int ans = dp[n]%1000000007;
//         return ans;
//     }
// };


class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int a = 0,b = 0,c = 1;
        for(int i = 2;i <= n;++i){
            a = b;
            b = c;
            c = (a + b)%1000000007;
        }
        return c;
    }
};


	
int main() {
	Solution sol;

    int n = 48;

	auto ans = sol.fib(n);
	cout << ans << endl;
	
	return 0;
}



