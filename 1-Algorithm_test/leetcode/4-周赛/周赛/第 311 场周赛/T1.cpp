#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


int gcd(int a,int b) { return b?gcd(b,a%b):a;}

//求两个数的最小公倍数
int lcm(int m,int g)  {
     return m/gcd(m,g)*g;
}


class Solution {
public:
    int smallestEvenMultiple(int n) {
        return lcm(2,n);
    }
};
	
int main() {
	Solution solution;
    int n = 5;

    auto ans = solution.smallestEvenMultiple(n);

	cout << ans << endl;
	return 0;
}




