#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
		int n = arr.size();
		int l = 0,mid,r = n-1;
		while(l <= r){
			mid = l + (r - l) / 2;
			printf("%d %d %d %d\n",arr[mid],l,mid,r);
			if(arr[mid] > arr[mid + 1])	// 如果是递减的，说明偏右，山峰顶在左边区间内
				r = mid - 1;
			else
				l = mid + 1;
		}
		return l;
    }
};



int main(){
	Solution sol;
	// vector<int> arr = {0,1,0};
	vector<int> arr = {24,69,89,99,100,99,79,78,67,36,26,19};
	
	auto ans = sol.peakIndexInMountainArray(arr);
	
	cout << ans <<endl;
	return 0;
}
