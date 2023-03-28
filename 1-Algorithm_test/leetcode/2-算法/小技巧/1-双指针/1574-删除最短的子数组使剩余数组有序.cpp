#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
		int n = arr.size(),r = n-1;
		while(r > 0 && arr[r-1] <= arr[r]){
			r--;
		}
		if(r == 0)
			return n-r;
		int l = 0;
		for(l = 0;l < r || arr[l] < arr[l+1];l++){
			while(r < n && arr[l] <= arr[r])
				r++;
		}
		return r-l;
    }
};
	
int main() {
	Solution solution;
    vector<int> arr = {1,2,3,10,4,2,3,5};
	// vector<int> arr = {1,2,3,4,5,6};

	auto ans = solution.findLengthOfShortestSubarray(arr);
	cout << ans << endl;
	
	return 0;
}



