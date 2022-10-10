#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++){ 
		cout << *it << " ";
	} 
	cout << endl; 
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
		
		int sum = 0;
		for(int i = 0;i < stones.size();i++) {
			sum += stones[i];
		}
		int target = sum/2;

		// cout << target << endl;
		
		vector<int> dp(target+1,0);
		for(int i = 0;i < stones.size();i++) {
			for(int j = target;j >= stones[i];j--) {
				// cout << dp[j] << " " << dp[j - stones[i]] + stones[i] << endl;
				dp[j] = max(dp[j],dp[j - stones[i]] + stones[i]);
				// printVector(dp);
			}
		}
		// cout << dp[target] << endl;

		return sum - dp[target] - dp[target];
    }
};
		
int main() {
	Solution solution;
	
	vector<int> nums = {31,26,33,21,40};
	
	auto ans = solution.lastStoneWeightII(nums);
	
	cout << ans << endl;
	return 0;
}



