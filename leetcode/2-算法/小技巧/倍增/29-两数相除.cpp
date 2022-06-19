#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


//class Solution {
//public:
//    int divide(int dividend, int divisor) {
//		if(dividend == divisor)
//			return 1;
//		if(dividend == -divisor)
//			return -1;
//		if(divisor == 1) return dividend;
//		if(divisor == -1) return -dividend;
//		
//		if(dividend < 0 && divisor < 0){
//			dividend = -dividend;
//			divisor =  -divisor;
//		}
//		bool fu_flag = false;
//		if(dividend < 0 || divisor < 0){
//			fu_flag = true;
//			if(dividend < 0)
//				dividend = -dividend;
//			if(divisor < 0)
//				divisor =  -divisor;
//		}
//		int ans = 1;
//		int tmp = divisor;
//		while(dividend >= tmp){
//			printf("%d %d\n",tmp,ans);
//			tmp += divisor;
//			ans++;
//		}
//		if(fu_flag)
//			return -(ans-1);
//		else
//			return ans-1;
//    }
//};


class Solution {
public:
    int divide(int dividend, int divisor) {
		if(dividend == divisor)
			return 1;
		if(dividend == -divisor)
			return -1;
		if(divisor == 1) return dividend;
		if(divisor == -1) return -dividend;
		
		if(dividend < 0 && divisor < 0){
			dividend = -dividend;
			divisor =  -divisor;
		}
		bool fu_flag = false;
		
		return div(dividend,divisor);
		
		
    }
    
    double div(long dividend, long divisor){
    	if(dividend < divisor)
    		return 0;
		long tmp = divisor;
		long cnt = 1;
		while(dividend > tmp + tmp){
			printf("%d %d\n",tmp,cnt);
			tmp += tmp;
			cnt += cnt;
		}
		return cnt + div(dividend - tmp, divisor);
	}
};


int main() {
	Solution solution;

	int dividend = 100;
	int divisor = 2;

	auto ans = solution.divide(dividend,divisor);
	
	cout << ans << endl;
	
	return 0;
}




