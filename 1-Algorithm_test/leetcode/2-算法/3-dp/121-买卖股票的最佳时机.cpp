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
        dp[0][0] -= prices[0];  //��i����й�Ʊ��������ֽ�
        dp[0][1] = 0;           //��i�첻���й�Ʊ��������ֽ�
        for(int i = 1;i < prices.size();i++) {
          
            dp[i][0] = max(dp[i-1][0],-prices[i]);//һ��һ�������������Ʊ��Ҫ����Ǯ���ٵ�
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] + prices[i]);//�������ϵ�Ǯ�����������Ʊ���Ǯ

            PrintVVector(dp);
        }
        return dp[len-1][1];//�϶����������
    }
};



int main() {
	Solution solution;
	vector<int> prices = {7,1,5,3,6,4};
	
	auto ans = solution.maxProfit(prices);
	
	cout << ans << endl;
	return 0;
}



