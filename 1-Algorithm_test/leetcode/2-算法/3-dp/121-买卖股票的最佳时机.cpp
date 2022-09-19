#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVVector(vector<vector<int>> v){
	for(auto iter = v.begin();iter != v.end();iter++){
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int> > dp(len,vector<int>(2));
        dp[0][0] -= prices[0];  //第i天持有股票所得最多现金
        dp[0][1] = 0;           //第i天不持有股票所得最多现金
        for(int i = 1;i < prices.size();i++) {
          
            dp[i][0] = max(dp[i-1][0],-prices[i]);//一个一个看下来，买股票需要花的钱最少的
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] + prices[i]);//拿在手上的钱，付掉买入股票后的钱

            PrintVVector(dp);
        }
        return dp[len-1][1];//肯定是买掉划算
    }
};



int main() {
	Solution solution;
	vector<int> prices = {7,1,5,3,6,4};
	
	auto ans = solution.maxProfit(prices);
	
	cout << ans << endl;
	return 0;
}



