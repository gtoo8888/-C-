#include <algorithm> 
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ans;
        n = pow(10,n);
        // cout << n << endl;
        for(int i = 1;i < n;i++)
            ans.push_back(i);
        // cout << ans[998] << endl;
        return ans;
    }
};



int main(){
	Solution sol;
	int n = 3;

	auto ans = sol.printNumbers(n);
	PrintVector(ans);
	return 0;
}
