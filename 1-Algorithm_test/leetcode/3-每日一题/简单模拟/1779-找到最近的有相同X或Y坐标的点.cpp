#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		int len_max = INT32_MAX;
		int index = 0;
		int ans = -1;
		for(auto pos : points){
			int px = pos[0],py = pos[1];
			if(px == x || py == y){
				int len = abs(px-x) + abs(py-y);
				if(len < len_max){
					len_max = len;
					ans = index;
				}
			}
			index++;
		}
		if(len_max == INT32_MAX){
			return -1;
		}else{
			return ans;
		}
    }
};


	
int main() {
	Solution solution;
	// int x = 3, y = 4;
	// vector<vector<int>> points = {{1,2},{3,1},{2,4},{2,3},{4,4}};

	// int x = 3, y = 4;
	// vector<vector<int>> points = {{3,4}};	

	int x = 3, y = 4;
	vector<vector<int>> points = {{2,5}};	
	auto ans = solution.nearestValidPoint(x,y,points);
	
	cout << ans << endl;
	
	return 0;
}



