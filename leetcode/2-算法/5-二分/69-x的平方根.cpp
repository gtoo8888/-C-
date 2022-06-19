#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int mySqrt(int x) {
		if(x == 1)	// 下面为了加快计算，所以用了r=x/2，写了这个需要特殊判断下1
			return 1;
		long long l = 0,mid,r = x/2;
		int ans;
		while(l <= r){
			mid = l + (r-l)/2;
			long long tmp = mid * mid;
			printf("%lld %lld %lld %lld\n",tmp,l,mid,r);
			if(tmp == x)
				return mid; 
			else if(tmp < x){
				ans = mid;
				l = mid+1;
			}
			else
				r = mid-1;
		}
		return ans;
    }
};


int main(){
	Solution sol;
	int x = 17;
	
	auto ans = sol.mySqrt(x);
	
	cout << ans <<endl;
	return 0;
}
