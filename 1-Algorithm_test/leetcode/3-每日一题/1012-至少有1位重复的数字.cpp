#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
		int ans = 0;
		for(int i = 1 ;i <= n;i++){
			vector<int> wei(10,0);
			int num = i;
			while(num >= 0){
				wei[num%10]++;
				if(wei[num%10] > 1){
					ans++;
					break;
				}
				num /= 10;
			}
		}
		return ans;
    }
};

	
int main() {
	Solution solution;
	
	auto ans = solution.numDupDigitsAtMostN(100);
	
	cout << ans << endl;
	
	return 0;
}



