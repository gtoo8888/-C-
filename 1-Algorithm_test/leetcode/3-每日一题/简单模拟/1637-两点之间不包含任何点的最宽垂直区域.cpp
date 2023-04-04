#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		// PrintVVector(points);
		int n = points.size();
		vector<int> x_index(n,0);
		for(int i = 0;i < n;i++){
			x_index[i] = points[i][0];
		}
		// PrintVector(x_index);
		sort(x_index.begin(),x_index.end());
		// PrintVector(x_index);
		int ans = 0;
		for(int i = 1;i < n;i++){
			ans = max(ans,x_index[i]-x_index[i-1]);
		}
		return ans;
    }
};


int main() {
	Solution solution;
	// vector<vector<int>> points = {{8,7},{9,9},{7,4},{9,7}};
	vector<vector<int>> points = {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};
	auto ans = solution.maxWidthOfVerticalArea(points);
	
	cout << ans << endl;
	return 0;
}



