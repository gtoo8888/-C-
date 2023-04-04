#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
		int n = reward1.size();
        int m1 = k,m2 = n-k;
		sort(reward1.begin(),reward1.end());
		return -1;
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




