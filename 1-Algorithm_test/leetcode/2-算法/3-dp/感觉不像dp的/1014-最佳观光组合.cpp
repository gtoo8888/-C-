#include <iostream>
#include <vector>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
		int n = values.size();
		int ans = 0;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				ans = max(ans,values[i]+values[j]+i-j);
			}
		}
		return ans;
    }
};


// class Solution {
// public:
//     int maxScoreSightseeingPair(vector<int>& values) {
// 		int n = values.size();
// 		int ans = 0;
// 		vector<int> vj(n);
// 		for(int j = 0;j < n;j++){
// 			vj = max(ans,values[i]+values[j]+i-j);
// 		}
// 		for(int i = 0;i < n;i++){
// 			for(int j = i+1;j < n;j++){
// 				ans = max(ans,values[i]+values[j]+i-j);
// 			}
// 		}
// 		return ans;
//     }
// };



int main() {
	Solution solution;
	vector<int> values = {8,1,5,2,6};

	auto ans = solution.maxScoreSightseeingPair(values);
	
	cout << ans << endl;
	return 0;
}



