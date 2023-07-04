#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// O(n2)
// class Solution {
// public:
//     int numPairsDivisibleBy60(vector<int>& time) {
// 		vector<int> vec;
// 		int n = time.size();
// 		for(int i = 0;i < n;i++){
// 			for(int j = i+1;j < n;j++){
// 				vec.push_back(time[i]+time[j]);
// 			}
// 		}
// 		// PrintVector(vec);
// 		int ans = 0;
// 		for(auto it : vec){
// 			if(it%60 == 0)
// 				ans++;
// 		}
// 		return ans;
//     }
// };


// 30,20,150,100,40
// 20,30,40 ,40 ,30
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
		vector<int> cnt(60,0);
		int n = time.size();
		int ans = 0;
		for(auto it : time){
			int mod_num = it%60;
			// printf("%d\n",mod_num);
			// 20,30,40,40,30 
			// 比如统计40前面有几个20
			ans += cnt[(60-mod_num)%60]; // 只能一边计算一边统计
			cnt[mod_num]++;
		}
		// PrintVector(cnt);
		return ans;
    }
};

int main() {
	Solution solution;
	vector<int> time;
	time = vector<int>{30,20,150,100,40};
	cout << solution.numPairsDivisibleBy60(time) << endl;
	
	time = vector<int>{60,60,60};
	cout << solution.numPairsDivisibleBy60(time) << endl;
	return 0;
}



;