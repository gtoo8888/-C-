#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
	for(auto it : v)
		cout << it << " ";
}


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
// 		int n = numbers.size();
// 		for(int i = 0;i < n;i++){
// 			for(int j = i+1;j < n;j++){
// 				if(numbers[i] + numbers[j] == target){
// 					return {i+1,j+1};
// 				}
// 			}
// 		}
// 		return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		int n = numbers.size();
		for(int i = 0;i < n;i++){
			int target_half = target - numbers[i];
			int l = i+1,mid,r = n-1;
			while(l <= r){
				mid = l + (r - l)/2;
				// printf("%d %d %d\n",l,mid,r);
				if(numbers[mid] == target_half)
					return {i+1,mid+1};
				else if(numbers[mid] < target_half)
					l = mid + 1;	
				else
					r = mid - 1;
			}
		}
		return {};
    }
};

int main(){
	Solution sol;
	// vector<int> numbers = {2,7,11,15};
	// int target = 9;

	// vector<int> numbers = {2,3,4};
	// int target = 6;

	vector<int> numbers = {-1,0};
	int target = -1;

	auto ans = sol.twoSum(numbers,target);
	
	printVector(ans);
	return 0;
}
