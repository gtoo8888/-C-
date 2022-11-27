#include <iostream>
#include <vector>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		if(numRows == 1)
			return {{1}};
		else if(numRows == 2)
			return {{1},{1,1}};
		vector<vector<int>> ans = {{1},{1,1}};
		for(int i = 2;i < numRows;i++){
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
		return ans;
    }
};

	
int main() {
	Solution solution;
	 
	int numRows = 2;

	auto ans = solution.generate(numRows);
	PrintVVector(ans);
	return 0;
}



