#include <iostream>
#include <vector>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 每次计算最大值时候需要用for循环遍历要查找的数组
// 复杂度O(n3)
// class Solution {
// public:
//     int dp_max(vector<int>& arr, int l,int r){
//         int max_num = -1;
//         for(int i = l;i <= r;i++){
//             max_num = max(max_num,arr[i]);
//         }
//         return max_num;
//     }
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<int> dp(n+1,-1);
//         for(int i = 1;i <= k;i++){
//             dp[i-1] = dp_max(arr,0,i-1)*i; // 提前一格放，就不会越界了
//         }
//         for(int i = k;i < n;i++){
//             for(int j = 1;j <= k;j++){
//                 // 每往前一个数，就会向前回溯K个数
//                 // 如果往前k个数，形成的子数组能比当前位置的数大，那么就更新现在的
//                 // 比如递归到arr[3]=9时
//                 // dp[3] = max(dp[3],dp_max([9])*1)
//                 // dp[2] = max(dp[3],dp_max([7,9])*2)
//                 // dp[1] = max(dp[3],dp_max([15,7,9])*3)
//                 int qian_max = dp[i-j]+dp_max(arr,i-j+1,i)*j;
//                 dp[i] = max(dp[i],qian_max);
//             }
//         }
//         // PrintVector(dp);
//         return dp[n-1];
//     }
// };


// 每次递推计算区间内最大值
// 复杂度O(n2)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        int tmpMax = arr[0];
        for(int i = 1;i <= k;i++){
            tmpMax = max(tmpMax,arr[i-1]); // 每次递推计算当前区间内的最大值
            dp[i-1] = tmpMax*i; // 提前一格放，就不会越界了
        }
        for(int i = k;i < n;i++){
            tmpMax = arr[i]; // 初始化为区间的开头
            for(int j = 1;j <= k;j++){
                tmpMax = max(arr[i-j+1],tmpMax); // 每次递推计算当前区间内的最大值
                int qian_max = dp[i-j]+tmpMax*j;
                dp[i] = max(dp[i],qian_max);
            }
        }
        // PrintVector(dp);
        return dp[n-1];
    }
};


int main() {
	Solution solution;
	vector<int> arr;int k = 0;
    arr = vector<int>{1,15,7,9,2,5,10},k = 3;
	cout << solution.maxSumAfterPartitioning(arr,k) << endl;cout << "-----------------" << endl;
	return 0;
}



