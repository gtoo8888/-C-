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
    int minCostClimbingStairs(vector<int>& cost) {
    	int n = cost.size();
		vector<int> dp(n+1);
		dp[0] = cost[0];
		dp[1] = cost[1];
		for(int i = 2;i < n;i++){
			dp[i] = min(dp[i - 1],dp[i - 2]) + cost[i];
 		}
 		printVector(dp);
 		return min(dp[n - 1],dp[n - 2]);
    }
};

int main(){
	Solution solution;
	int nums[]  = {0,0,0,0};
	vector<int> cost(nums,nums + sizeof(nums) / sizeof(int));
	printVector(cost);
	int ans;
	
	ans = solution.minCostClimbingStairs(cost);
		
	cout << ans << endl;
	return 0;
}
