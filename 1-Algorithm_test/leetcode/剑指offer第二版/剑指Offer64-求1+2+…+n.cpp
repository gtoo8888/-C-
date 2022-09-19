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
	int sum = 1; 
	int sum_func(int n) {
		if(n == 1)
			return 1;
		sum += n;
//		printf("%d\n",n);
		return sum_func(n-1);
	}
    int sumNums(int n) {
    	sum_func(n);
		return sum;
    }
};



int main(){
	Solution sol;
	int n = 10;
	auto ans = sol.sumNums(n);
	cout << ans << endl;
	return 0;
}
