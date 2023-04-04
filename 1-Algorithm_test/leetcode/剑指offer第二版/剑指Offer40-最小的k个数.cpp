#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 正常排序
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
		sort(arr.begin(),arr.end());
		return vector<int>(arr.begin(),arr.begin()+k);
    }
};


// 堆排序



int main(){
	Solution sol;
	// vector<int> arr = {3,2,1};int k = 2;
	
	vector<int> arr = {0,1,2,1};int k = 1;
	auto ans = sol.getLeastNumbers(arr,k);
	
	PrintVector(ans);
	return 0;
}
