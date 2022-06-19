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
    int climbStairs(int n) {
    	if(n == 1)
    		return 1;
		vector<int> dp(n+1);
		dp[1] = 1;
		dp[2] = 2;
		for(int i = 3;i <= n;i++){
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		printVector(dp);
		return dp[n];
    }
};

int main(){
	Solution solution;
	int n = 10;
	int ans;
	
	ans = solution.climbStairs(n);
		
	cout << ans << endl;
	return 0;
}
