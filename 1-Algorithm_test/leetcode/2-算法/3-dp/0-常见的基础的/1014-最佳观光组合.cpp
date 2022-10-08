#include <iostream>
#include <vector>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

// class Solution {
// public:
//     int maxScoreSightseeingPair(vector<int>& values) {
// 		int n = values.size();
// 		int ans = 0;
// 		for(int i = 0;i < n;i++){
// 			for(int j = i+1;j < n;j++){
// 				ans = max(ans,values[i]+values[j]+i-j);
// 			}
// 		}
// 		return ans;
//     }
// };


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
		int n = values.size();
		int ans = 0;
		vector<int> vi(n);		
		int mx = values[0] + 0;
		// printf("mx:%d v[j]:%d j:%d\n",mx , values[0] , 0);
		for(int j = 1;j < n;j++){
			// printf("mx:%d v[j]:%d j:%d\n",mx , values[j] , j);
			ans = max(ans,mx + values[j] - j);
			mx = max(mx,values[j] + j);	// 每次大循环里面这个值都不会变
			// printf("%d %d\n",ans,mx);
		}
		return ans;
    }
};



int main() {
	Solution solution;
	// vector<int> values = {8,1,5,2,6};
	vector<int> values = {1,1,5,2,6,5,6,0,0,8,8,65,45};

	auto ans = solution.maxScoreSightseeingPair(values);
	
	cout << ans << endl;
	return 0;
}



