#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int len = n-1;
		while(len){
			for(int i = 0;i < 4;i++){
				
			}
			len -= 2;
		}
    }
};

int main(){
	Solution sol;

	vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

	auto ans = sol.spiralOrder(matrix);
	PrintVector(ans);
	return 0;
}
