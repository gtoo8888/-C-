#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// vector<int> NumSeparate(int n) {//每个位拆开
// 	vector<int> ans;
// 	int temp = n;
// 	while(temp != 0){
// 		ans.push_back(temp%10);
// 		temp = temp / 10;			
// 	}
// 	return ans;
// }


class Solution {
public:
    int rotatedDigits(int n) {
						// 1,2,3,4,5,6,7,8,9
		int youxiao[10] = {0,0,1,-1,-1,1,1,-1,0,1};
		int ans = 0;
		for(int i = 0;i <= n;i++){
			vector<int> tmp = NumSeparate(i);
			// PrintVector(tmp);
			bool vail = true;
			bool diff = false;
			for(int j = 0;j < tmp.size();j++){
				if(youxiao[tmp[j]] == -1){
					vail = false;
				}else if(youxiao[tmp[j]] == 1){
					diff = true;
				}
			}
			if(vail && diff){
				ans++;
			}
		}
		return ans;
    }
};


	
int main() {
	Solution solution;
	int n = 100;
	auto ans = solution.rotatedDigits(n);
	
	cout << ans << endl;
	return 0;
}



