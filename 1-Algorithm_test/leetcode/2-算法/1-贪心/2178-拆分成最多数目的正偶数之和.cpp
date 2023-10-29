#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
		if(finalSum%2 > 0){
			return ans;
		}
		for(int i = 2;i <= finalSum;i += 2){
			printf("%d %d\n",i,finalSum);
			ans.push_back(i);
			finalSum -= i;
		}
		ans.back() += finalSum;
		return ans;
    }
};

		
int main() {
	Solution solution;
	long long finalSum = 28;
	
	
	auto ans = solution.maximumEvenSplit(finalSum);
	
	PrintVector(ans);
	return 0;
}


