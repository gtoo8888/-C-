#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int candy(vector<int>& ratings) {
		int n = ratings.size();
		vector<int> candy_num(n,1);
		for(int i = 1;i < n;i++){
			if(ratings[i] > ratings[i-1])
				candy_num[i] = candy_num[i-1] + 1;
		}
		// PrintVector(candy_num);
		for(int i = n-1;i > 0;i--){
			if(ratings[i] < ratings[i-1])	// 需要和上一次的比较，利用上一次的信息
				candy_num[i-1] = max(candy_num[i] + 1,candy_num[i-1]);
		}
		// PrintVector(candy_num);
		return accumulate(candy_num.begin(),candy_num.end(),0);

    }
};
		
int main() {
	Solution solution;
	vector<int> ratings = {1,0,2};
	// vector<int> ratings = {1,2,2,5,4,3,2};

	auto ans = solution.candy(ratings);
	cout << ans << endl;
	return 0;
}


