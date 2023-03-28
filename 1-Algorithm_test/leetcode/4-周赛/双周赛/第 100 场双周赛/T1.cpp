#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int captureForts(vector<int>& forts) {
		int n = forts.size();
		int ans = -1;
		int len = 0;
		bool flag;
		if(forts[0] == 1)
			flag = 1;
		else if(forts[0] == -1)
			flag = 0;
        for(int i = 1;i < n;i++){
		}
		return 0;
    }
};
	
int main() {
	Solution solution;
	vector<int> forts = {1,0,0,-1,0,0,0,0,1};	// 4

    auto ans = solution.captureForts(forts);

	cout << ans << endl;
	return 0;
}




