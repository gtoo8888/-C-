#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}



// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         // int sum = 0;
//         // for(int i = 0;i < coins.size();i++) 
//         //     sum += coins[i];
//         // if(sum < amount)
//         //     return 0;
//         vector<int> dp(amount + 1,0);

//         dp[0] = 1; //凑成总金额0的货币组合数为1
//         for(int i = 0;i < coins.size();i++) {    // 遍历物品
//             for(int j = coins[i];j <= amount;j++) {  //遍历背包容量
//                 dp[j] += dp[j - coins[i]]; //求的是总方案数,所以要求和，而不是比较大小
//                 // dp[j] = max(dp[j],dp[j - coins[i]] + coins[i]);
//                 printVector(dp);
//             }
//             cout << endl;
//         }
//         return dp[amount];
//     }
// };

//全排列情况下的写法
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1,0);

        dp[0] = 1; //凑成总金额0的货币组合数为1
        for(int j = 0;j <= amount;j++) {    //遍历背包容量
            for(int i = 0;i < coins.size();i++) {   // 遍历物品
                if(j - coins[i] >= 0)   //保证数据不越界，意思是这个容量下装不下这个物品
                    dp[j] += dp[j - coins[i]];  //每次都是处理当前容量的数据，对于当前容量，每次都看看物品能不能装进去
                printVector(dp);
            }
            cout << endl;
        }       
        return dp[amount];
    }
};



int main() {
	Solution solution;
	vector<int> coins = {1,2,5};
	int amount = 5;
	
	auto ans = solution.change(amount,coins);
	
	cout << ans << endl;
	return 0;
}



