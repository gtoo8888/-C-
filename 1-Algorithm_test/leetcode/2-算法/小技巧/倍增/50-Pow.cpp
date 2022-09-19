#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


// ���ص�˼�룬ֱ�ӳ� ���Ӷ�O(n)
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

// �ݹ鷽��ʵ�ֿ�����
// class Solution {
// public:
// 	double quickpow(double x, long long N){
// 		if(N == 0)
// 			return 1;
// 		double y = quickpow(x, N / 2);
// 		printf("%f\n",y);
// 		if(N % 2 == 0) 	// ÿ���м��̣��������������Ҫ���һ��
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


// ��������ʵ�ֿ�����
// 77 = (1001101)2
class Solution {
public:
	double quickpow(double x, long long N){
		double ans = 1;
		while(N > 0){
			printf("%f %f %d\n",ans,x,N);
			if((N & 1) == 1)	// ����Ҫ��Ҫ��������ֳ˽���������һ��������λ�ǲ���1
				ans *= x;
			x *= x;  	// ÿ�ζ����� 1,2,4,8,16,32����ȥ����
			N >>= 1;
		}
		return ans;
	}
    double myPow(double x, int n) {
		long long N = n;
		double ans;
		if(n > 0)
			ans = quickpow(x,N);
		else{//�����η������ﴦ��
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




