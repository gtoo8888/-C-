#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1,0);
        dp[0] = 1; //�ճ��ܽ��0�Ļ��������Ϊ1
        for(int i = 0;i < coins.size();i++) {    // ������Ʒ
            for(int j = coins[i];j <= amount;j++) {  //������������
                dp[j] += dp[j - coins[i]]; //������ܷ�����,����Ҫ��ͣ������ǱȽϴ�С
                // dp[j] = max(dp[j],dp[j - coins[i]] + coins[i]);
                PrintVector(dp);
            }
            cout << endl;
        }
        return dp[amount];
    }
};

//ȫ��������µ�д��
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<int> dp(amount + 1,0);

//         dp[0] = 1; //�ճ��ܽ��0�Ļ��������Ϊ1
//         for(int j = 0;j <= amount;j++) {    //������������
//             for(int i = 0;i < coins.size();i++) {   // ������Ʒ
//                 if(j - coins[i] >= 0)   //��֤���ݲ�Խ�磬��˼�����������װ���������Ʒ
//                     dp[j] += dp[j - coins[i]];  //ÿ�ζ��Ǵ���ǰ���������ݣ����ڵ�ǰ������ÿ�ζ�������Ʒ�ܲ���װ��ȥ 
//             }
//         }   
//         printVector(dp);    
//         return dp[amount];
//     }
// };



int main() {
	Solution solution;
	vector<int> coins = {1,2,5};
	int amount = 5;
	
	auto ans = solution.change(amount,coins);
	
	cout << ans << endl;
	return 0;
}



