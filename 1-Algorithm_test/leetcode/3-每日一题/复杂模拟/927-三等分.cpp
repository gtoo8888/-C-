#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"


class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
		int one_count = 0;
		for(auto n : arr){
			if(n == 1)
				one_count++;
		}
		if(one_count == 0)
			return {0,2};
		if(one_count%3 != 0)
			return {-1,-1};

		int part = one_count/3;
		int first = 0,second = 0,third = 0,cur = 0;
		int n = arr.size();
		for(int i = 0;i < n;i++){
			// printf("%d %d %d %d %d\n",arr[i],first,second,third,cur);
			if(arr[i] == 1){
				if(cur == 0)
					first = i;
				else if(cur == part)
					second = i;
				else if(cur == 2*part)
					third = i;
				cur++;
			}
		}
		// printf("%d %d %d %d\n\n",first,second,third,cur);

		int len = n - third;
		if(first + len <= second && second + len <= third){
			int i = 0;
			while(third + i < n){
				// printf("%d %d %d\n",first+i,second+i,third+i);
				if(arr[first+i] != arr[second+i] || arr[first+i] != arr[third+i])
					return {-1,-1};
				i++;
			}
			return {first + len - 1,second + len};
		}
		return {-1,-1};
    }
};


	
int main() {
	Solution solution;
	// vector<int> arr = {1,0,1,0,1,0,1,1,1,0,1,0,0,1,1};
	// vector<int> arr = {1,1,0,1,1};
	vector<int> arr = {1,1,0,0,1};
	
	auto ans = solution.threeEqualParts(arr);
	
	PrintVector(ans);	
	return 0;
}



