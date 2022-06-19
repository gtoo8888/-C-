#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
		if(arr[0] > k)
			return k;
		int n = arr.size();
		int l = 0,mid,r = n;
		while(l < r){
			mid = l + (r - l) / 2;
			int x = mid < n ? arr[mid] : INT_MAX;
			printf("%d %d %d %d %d\n",arr[mid],l,mid,r,x);
			if(x - mid - 1 >= k){
				r = mid;
			}else
				l = mid + 1;
		}
		printf("%d %d %d %d\n",k,arr[l-1],(l -1) -1,arr[l-1]);
		int ans = k - (arr[l-1]- (l -1) -1) + arr[l-1];
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> arr = {2,3,4,7,11};
	int k = 5;

	// vector<int> arr = {1,2,3,4};
	// int k = 2;	

	// vector<int> arr = {3,4,5};
	// int k = 1;

	auto ans = sol.findKthPositive(arr,k);
	
	cout << ans <<endl;
	return 0;
}
