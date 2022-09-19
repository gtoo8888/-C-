#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


// 朴素的思想，直接乘 复杂度O(n)
// class Solution {
// public:
//     double myPow(double x, int n) {
// 		if(n == 0)
// 			return 1;
// 		double ans = x;
// 		int tmp = n;
// 		if (n < 0)
// 			tmp = -n;
// 		for(int i = 1;i < tmp;i++)
// 			ans *= x;
// 		// printf("%f %d\n",ans,tmp);
// 		if (n < 0)
// 			ans = 1.0 / ans;
// 		// return pow(x,n);
// 		return ans;
//     }
// };


// class Solution {
// public:
//     double myPow(double x, int n) {
// 		if(n == 0)
// 			return 1;
// 		if(x == 0)	
// 			return 0;
// 		double ans = 1;
// 		int tmp = n;
// 		if(n < 0){
// 			x = 1 / x;
// 			n = -n;
// 		}
// 		while(n > 0){
// 			printf("%f %f %d\n",ans,x,n);
// 			if((n & 1) == 1)
// 				ans *= x;
// 			x *= x;
// 			n >>= 1;	
// 		}
// 		return ans;
//     }
// };

// 递归方法实现快速幂
// class Solution {
// public:
// 	double quickpow(double x, long long N){
// 		if(N == 0)
// 			return 1;
// 		double y = quickpow(x, N / 2);
// 		printf("%f\n",y);
// 		if(N % 2 == 0) 	// 每次中间商，如果是奇数，需要多乘一个
// 			return y * y;
// 		else
// 			return y * y * x;
// 	}
//     double myPow(double x, int n) {
// 		long long N = n;
// 		double ans;
// 		if(n > 0)
// 			ans = quickpow(x,N);
// 		else{
// 			ans = 1.0 / quickpow(x,-N);
// 		}
// 		return ans;
//     }
// };


// 迭代方法实现快速幂
// 77 = (1001101)2
class Solution {
public:
	double quickpow(double x, long long N){
		double ans = 1;
		while(N > 0){
			printf("%f %f %d\n",ans,x,N);
			if((N & 1) == 1)	// 但是要不要把这个数字乘进来，看这一个二进制位是不是1
				ans *= x;
			x *= x;  	// 每次都是以 1,2,4,8,16,32这样去倍增
			N >>= 1;
		}
		return ans;
	}
    double myPow(double x, int n) {
		long long N = n;
		double ans;
		if(n > 0)
			ans = quickpow(x,N);
		else{//负数次方在这里处理
			ans = 1.0 / quickpow(x,-N);
		}
		return ans;
    }
};

int main() {
	Solution solution;

	double x = 8;
	int n = 77;

	auto ans = solution.myPow(x,n);
	
	cout << ans << endl;
	
	return 0;
}




