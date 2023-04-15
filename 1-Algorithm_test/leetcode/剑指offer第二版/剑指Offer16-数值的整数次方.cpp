#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// O(n) 计算平方
// class Solution {
// public:
//     double myPow(double x, int n) {
// 		if(x == 1)
// 			return 1;
// 		if(n == 0)
// 			return 1;
// 		double ans = 1;
// 		double cheng = x;
// 		if(n < 0){
// 			n = -n;
// 			cheng = 1.0/x;
// 		}
// 		for(int i = 0;i < n;i++){
// 			ans *= cheng;
// 		}
// 		return ans;
// 		// return pow(x,n);
//     }
// };



class Solution {
public:
	double cal_pow(double x, long long n){
		if(n == 0)
			return 1.0;
		double y = cal_pow(x,n/2);
		return n%2 == 0 ? y*y : y*y*x;
	}

    double myPow(double x, int n) {
		long long N = n;
		if(x == 1)
			return 1;
		if(n == 0)
			return 1;
		else if(n > 0)
			return cal_pow(x,N);
		else
			return 1.0/cal_pow(x,-N);
    }
};




int main(){
	Solution sol;
	// double x = 2;int n = 10;
	
	double x = 2;int n = 3;
	cout << sol.myPow(x,n) << endl;
	x = 2; n = 1;
	cout << sol.myPow(x,n) << endl;
	x = 2; n = 0;
	cout << sol.myPow(x,n) << endl;
	x = 2; n = 10;
	cout << sol.myPow(x,n) << endl;
	x = 2; n = -1;
	cout << sol.myPow(x,n) << endl;
	x = 2; n = -2;
	cout << sol.myPow(x,n) << endl;
	x = 1; n = 2147483647;
	cout << sol.myPow(x,n) << endl;

	return 0;
}
