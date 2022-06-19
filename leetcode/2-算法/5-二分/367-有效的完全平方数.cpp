#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isPerfectSquare(int num) {
		if(num == 1)
			return true;
		long long n = num/2;
		long long l = 0,mid,r = n;
		while(l <= r){
			mid = l + (r-l)/2;
			long long tmp = mid*mid;
			printf("%lld %d %d %d\n",tmp,l,mid,r);
			if(tmp == num)
				return true;
			else if(tmp < num)
				l = mid+1;
			else
				r = mid-1;		
		}
		printf("%d %d %d\n",l,mid,r);
		return false;
    }
};


int main(){
	Solution sol;
	int num = 16;
	
	auto ans = sol.isPerfectSquare(num);
	
	cout << ans <<endl;
	return 0;
}
