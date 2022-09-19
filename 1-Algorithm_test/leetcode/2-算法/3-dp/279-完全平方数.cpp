#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


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
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i*i <= n;i++) {
            for(int j = 1;j  <= n;j++) {
                if(j - i*i >= 0)
                    dp[j] = min(dp[j],dp[j - i*i] + 1);
                printVector(dp);
            }
            cout << endl;
        }
        return dp[n];
    }
};



int main() {
	Solution solution;
    int n = 13;
	
	auto ans = solution.numSquares(n);
	
	cout << ans << endl;
	return 0;
}



