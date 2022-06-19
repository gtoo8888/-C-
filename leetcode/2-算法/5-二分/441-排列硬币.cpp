#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;



// class Solution {
// public:
//     int arrangeCoins(int n) {
// 		if(n == 1)
// 			return 1;
// 		long long ans = 0,sum = 0;
// 		for(long long i = 1;i < n;i++){
// 			sum += i;
// 			if(sum > n)
// 				break;
// 			ans++;
// 			printf("%lld %lld %d\n",sum,ans,n);
// 		}
// 		return ans;
//     }
// };

class Solution {
public:
    int arrangeCoins(int n) {
		if(n == 1)
			return 1;
		long long l = 0,mid,r = n;
		while(l <= r){
			mid = l + (r - l)/2;
			// printf("%lld %lld %lld\n",l,mid,r);
			if(mid * (1 + mid) / 2 < n)
				l = mid + 1;
			else if(mid * (1 + mid) / 2 > n)
				r = mid - 1;
			else 
				return mid;
		}
		return r;
    }
};

int main(){
	Solution sol;
	int n = 2147483647;
	
	auto ans = sol.arrangeCoins(n);
	
	cout << ans <<endl;
	return 0;
}
