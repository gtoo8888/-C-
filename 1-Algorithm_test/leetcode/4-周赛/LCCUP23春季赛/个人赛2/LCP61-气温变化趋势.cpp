#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"



class Solution {
public:
    vector<int> supplyWagon(vector<int>& supplies) {
		int n = supplies.size();
		int ori_n = n/2;
		int sub = n-n/2;
		vector<int> sub_num = supplies;
		while(sub--){
			unordered_map<int,int> umap;
			int nt = sub_num.size();
			int min_t = INT32_MAX;
			for(int i = 0;i < nt-1;i++){
				int tmp = sub_num[i]+sub_num[i+1];
				umap[tmp]=i;
				min_t = min(min_t,tmp);
			}
			int index = umap[min_t];
			vector<int> change(nt-1,0);
			for(int i = 0;i < nt-1;i++){
				change[i] = 
			}
		}

    }
};


int main() {
	Solution solution;
	vector<int> supplies  = {7,3,6,1,8};

	auto ans = solution.supplyWagon(supplies);
	
	PrintVector(ans);
	
	return 0;
}



