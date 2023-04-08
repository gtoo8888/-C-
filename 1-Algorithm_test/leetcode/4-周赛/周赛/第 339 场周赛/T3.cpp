#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
		int n = reward1.size();
		int ans = accumulate(reward2.begin(),reward2.end(),0);
		vector<int> sub(n,0);
		for(int i = 0;i < n;i++){
			sub[i] = reward1[i]-reward2[i];
		}
		sort(sub.begin(),sub.end(),greater<int>());
		for(int i = 0;i < k;i++){
			ans += sub[i];
		}
		// PrintVector(sub);
		return ans;
    }
};

int main() {
	Solution solution;
	vector<int> reward1 = {1,1,3,4};
	vector<int> reward2 = {4,4,1,1};int k = 2;

    auto ans = solution.miceAndCheese(reward1,reward2,k);

	cout << ans << endl;
	return 0;
}




