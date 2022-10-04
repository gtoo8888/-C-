#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


int gcd(int a,int b) { return b?gcd(b,a%b):a;}

//求两个数的最小公倍数
int lcm(int m,int g)  {
     return m/gcd(m,g)*g;
}

class Solution {
public:
    int commonFactors(int a, int b) {
        int max_gcd = gcd(a,b);
        int ans = 0;
        for(int i = 1;i <= max_gcd;i++){
            if(a%i == 0 && b%i == 0){
                // printf("%d\n",i);
                ans++;
            }
        }
        return ans;
    }
};
	
int main() {
	Solution solution;
    int a = 12;
    int b = 6;

    // int a = 25;
    // int b = 30;

    auto ans = solution.commonFactors(a,b);

	cout << ans << endl;
	return 0;
}




