#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"



// class Solution {
// public:
//     int numSquares(int n) {
//         int sqrt_n = sqrt(n); // 正常应该用doubule接收，通过int实现向下取整
//         cout << sqrt_n << endl;
//         vector<int> weight(sqrt_n,0);
//         for(int i = 0;i <= sqrt_n;i++)
//             weight[i] = (i+1) * (i+1);
//         printVector(weight);

//         vector<int> dp(n+1,INT_MAX);
//         dp[0] = 0;
//         for(int i = 0;i < weight.size();i++) {
//             for(int j = weight[i];j <= n;j++) {
//                 if(dp[j - weight[i]] != INT_MAX) 
//                     dp[j] = min(dp[j],dp[j - weight[i]]  + 1);
//                 printVector(dp);
//             }
//             cout << endl;
//         }
//         return dp[n];
//     }
// };

//优化
// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> dp(n+1,INT32_MAX);
//         dp[0] = 0;
//         for(int i = 1;i*i <= n;i++) {
//             for(int j = 1;j  <= n;j++) {
//                 if(j - i*i >= 0)
//                     dp[j] = min(dp[j],dp[j - i*i] + 1);
//                 printVector(dp);
//             }
//             cout << endl;
//         }
//         return dp[n];
//     }
// };


// 自己写出来的，思路等于零钱兑换
class Solution {
public:
    int numSquares(int n) {
        vector<int> squ;
        for(int i = 1;i*i <= n;i++){
            squ.push_back(i*i);
        }
        // PrintVector(squ);
        int m = squ.size();
        vector<int> dp(n+1,n+1);
        dp[0] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < m;j++){
                if(squ[j] <= i){
                    // printf("i:%d j:%d dp[%d]+1=%d\n",i,j,i-squ[j],dp[i-squ[j]]+1);
                    dp[i] = min(dp[i],dp[i-squ[j]]+1);
                }
            }
            // cout << endl;
        }
        // PrintVector(dp);
        // return dp[n];
        return dp[n] > n ? -1 : dp[n];
    }
};

int main() {
	Solution solution;
    int n = 12;
    // int n = 13;
	
	auto ans = solution.numSquares(n);
	
	cout << ans << endl;
	return 0;
}



