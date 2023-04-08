#include <iostream>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// class Solution {
// public:
//     int commonFactors(int a, int b) {
//         int min_ab = min(a,b);
// 		int ans = 0;
// 		for(int i = 1;i <= min_ab;i++){
// 			if(a%i == 0 && b%i == 0)
// 				ans++;
// 		}
// 		return ans;
//     }
// };


class Solution {
public:
    int commonFactors(int a, int b) {
        int gcd_ab = gcd(a,b); // 可以用最小公倍数代替
		int ans = 0;
		for(int i = 1;i <= gcd_ab;i++){
			if(a%i == 0 && b%i == 0)
				ans++;
		}
		return ans;
    }
};


	
int main() {
	Solution solution;
	// int a = 12, b = 6;
    int a = 12, b = 8;
    int a = 25, b = 30;

	auto ans = solution.commonFactors(a,b);

	cout << ans << endl;
	
	return 0;
}



