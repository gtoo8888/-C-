#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;



// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int bad = 1;
	bool isBadVersion(int version){
		if(version >= bad)
			return true;
		else
			return false;
	}
    int firstBadVersion(int n) {
        int l = 1,mid,r = n;
		while(l <= r){
			mid = l + (r - l)/2;
			printf("%d %d %d\n",l,mid,r);
			if(isBadVersion(mid))
				r = mid - 1;
			else
				l = mid + 1;		
		}
		return l;
    }
};

int main(){
	Solution sol;
	int n = 1;
	
	auto ans = sol.firstBadVersion(n);
	
	cout << ans <<endl;
	return 0;
}
