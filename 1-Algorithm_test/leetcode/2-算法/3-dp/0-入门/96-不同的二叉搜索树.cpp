#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

// ��ʵ��쳲���������һ����˼��
// �����ǲ����뵽����ѧ��ʽ
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i <= n;i++){
            for(int j = 1;j <= i;j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        PrintVector(dp);
        return dp[n];
    }
};



int main() {
	Solution solution;
    int n = 10;

	
	auto ans = solution.numTrees(n);
	cout << ans << endl;
	return 0;
}



