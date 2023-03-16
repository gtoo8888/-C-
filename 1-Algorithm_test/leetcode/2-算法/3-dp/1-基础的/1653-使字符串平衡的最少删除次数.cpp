#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// 从最后一位开始看
// dp解法
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();        
        vector<int> dp(n,0);
        int cntB = 0;
        if(s[0] == 'b')
            cntB++;
        for(int i = 1;i < n;i++){
            if(s[i] == 'b'){    
                // 如果最后一位是b,那么就不需要删除，就是右边的不需要删除，直接转移前一个状态就可以了
                cntB++;
                dp[i] = dp[i-1];
            }
            else{
                // 如果最后一位是a,需要删除掉，因为最右边是a是不合理的
                // dp[i-1]+1,删除a的总个数
                // cntB如果要把左边的b删掉的总个数，哪个操作数小，就用哪个
                dp[i] = min(dp[i-1]+1,cntB);
            }
        }
        // PrintVector(dp);
        return dp[n-1];
    }
};



int main() {
	Solution solution;

    string s = "aababbab";      // 2
    // string s = "bbaaaaabb";  // 2
    // string s = "b";  // 0
    // string s = "bbbbbbbbbbbbbb";  // 0
    

	auto ans = solution.minimumDeletions(s);
	
	cout << ans << endl;
	return 0;
}



