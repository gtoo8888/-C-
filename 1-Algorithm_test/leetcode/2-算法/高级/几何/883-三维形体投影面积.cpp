#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVVector(vector<vector<int>> v){
	for(auto iter = v.begin();iter != v.end();iter++){
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}


class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        // PrintVVector(grid);
        int xy=0,yz=0,xz=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++) {
                if(grid[i][j] != 0)
                    xz++;
            }
        }
        for(int i = 0;i < n;i++){
            int max_l = INT32_MIN;
            for(int j = 0;j < m;j++) {
                max_l = max_l < grid[i][j] ? grid[i][j] : max_l;
            }
            yz += max_l;
        }
        for(int i = 0;i < m;i++){
            int max_d = INT32_MIN;
            for(int j = 0;j < n;j++) {
                max_d = max_d < grid[j][i] ? grid[j][i] : max_d;
            }
            xy += max_d;
        }
        // printf("%d %d\n",yz,xy);

        return xz+xy+yz;
    }
};


int main() {
	Solution solution;
	// vector<vector<int>> grid = {{1,2},{3,4}};
    // vector<vector<int>> grid = {{2}};
    vector<vector<int>> grid = {{1,0},{0,2}};
	
	auto ans = solution.projectionArea(grid);
	
	cout << ans << endl;
	
	return 0;
}



