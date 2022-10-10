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
				int sum_2 = (i - j) * j;//������˵�ֵ 
				int sum_all = dp[i - j] * j;//������˵Ķ��������Ϊdp[]�����˺ܶ������� 
				int dangqian = max(sum_2,sum_all);//ѡȡ�������Ǹ����������ֵ 
				dp[i] = max(dp[i],dangqian);//��Ҫ�ҳ��������е�i�����ֵ 
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



