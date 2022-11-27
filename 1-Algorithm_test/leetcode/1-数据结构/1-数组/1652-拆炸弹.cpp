#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
		vector<int> ans;
		int n = code.size();
		if(k == 0)
			return vector<int>(n,0);
		else if(k > 0){
			for(int i = 0;i < n;i++){
				int sum = 0;
				for(int j = i+1;j <= i+k;j++){
					sum += code[j%n];
				}
				ans.emplace_back(sum);
			}
		}else if(k < 0){
			for(int i = n-1;i >= 0;i--){
				int sum = 0;
				for(int j = i-1;j >= i+k ;j--){
					if(j < 0)
						sum += code[j+n];
					else
						sum += code[j];
				}
				ans.push_back(sum);
			}
			reverse(ans.begin(),ans.end());
		}
		return ans;
    }
};

int main() {
	Solution sol;
	// vector<int> code = {5,7,1,4};
	// int k = 0;

	vector<int> code = {2,4,9,3};
	int k = -2;

	auto ans = sol.decrypt(code,k);
	PrintVector(ans);
	return 0;
}

