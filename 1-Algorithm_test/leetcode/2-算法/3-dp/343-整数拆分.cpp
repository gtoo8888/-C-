#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


class Solution {
public:
    int integerBreak(int n) {
		vector<int> dp(n+1,0);
		dp[2] = 1;
		for(int i = 3;i <= n;i++){
			for(int j = 1;j < i-1;j++){
				int sum_2 = (i - j) * j;//两数相乘的值 
				int sum_all = dp[i - j] * j;//更多相乘的都在这里，因为dp[]包含了很多子问题 
				int dangqian = max(sum_2,sum_all);//选取两数还是更多数的最大值 
				dp[i] = max(dp[i],dangqian);//需要找出遍历所有的i的最大值 
			}
		}
		printVector(dp);
		return dp[n];
    }
};
		
int main() {
	Solution solution;
	
	int n = 10;
	int ans = 0;
	
	ans = solution.integerBreak(n);
	
	cout << ans << endl;
	return 0;
}



