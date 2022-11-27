#include <iostream>
#include <vector>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"
class Solution {
public:
    vector<int> getRow(int rowIndex) {
		rowIndex++;
		if(rowIndex == 1)
			return {{1}};
		else if(rowIndex == 2)
			return {{1,1}};
		vector<vector<int>> ans = {{1},{1,1}};
		for(int i = 2;i < rowIndex;i++){
			vector<int> tmp;
			for(int j = 0;j <= i;j++){
				if(j == 0)
					tmp.push_back(1);
				else if(j == i)
					tmp.push_back(1);
				else
					tmp.push_back(ans[i-1][j]+ans[i-1][j-1]);
			}
			ans.push_back(tmp);
		}
		return ans[rowIndex-1];
    }
};

	
int main() {
	Solution solution;
	 
	int rowIndex = 3;

	auto ans = solution.getRow(rowIndex);
	PrintVector(ans);
	return 0;
}



