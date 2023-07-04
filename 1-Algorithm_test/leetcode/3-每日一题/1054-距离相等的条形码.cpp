#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int max_ele = *max_element(barcodes.begin(),barcodes.end());
        vector<int> hash(max_ele+1,0);
        for(auto it : barcodes){
            hash[it]++;
        }
        // PrintVector(hash);
        sort(barcodes.begin(), barcodes.end(), [&](int a, int b) {
            return hash[a] > hash[b] || (hash[a] == hash[b] && a < b);
        });
        // PrintVector(barcodes);
        int n = barcodes.size();
        vector<int> ans(n,0);
        for(int k = 0,j = 0;k < 2;++k){
            for(int i = k;i < n;i+=2){
                ans[i] = barcodes[j++];
            }
        }
        return ans;
    }
};

	
int main() {
	Solution solution;
	// vector<int> barcodes = {1,1,1,2,2,2};
    vector<int> barcodes = {1,2,1};

	auto ans = solution.rearrangeBarcodes(barcodes);
	
	PrintVector(ans);
	
	return 0;
}



