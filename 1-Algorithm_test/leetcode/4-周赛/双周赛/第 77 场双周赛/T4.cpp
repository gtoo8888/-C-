#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVVector(vector<vector<int>>& v){
	for(auto iter : v){
		auto it_tmp = iter;
		for(auto it : it_tmp)
			cout << it << " ";
		cout << endl;
	}
	cout << endl;
}


class Solution {
public:
	int m,n;
	void dfs(int x,int y,vector<vector<int>>& grid) {
		if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2){
			return;
		}
		grid[x][y] = 1;
		PrintVVector(grid);
		dfs(x+1,y,grid);
		dfs(x-1,y,grid);
		dfs(x,y+1,grid);
		dfs(x,y-1,grid);
	}

    int maximumMinutes(vector<vector<int>>& grid) {
		PrintVVector(grid);
		m = grid.size();
		n = grid[0].size();
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				if(grid[i][j] == 1){
					dfs(i,j,grid);
					PrintVVector(grid);
				}
			}
		}

		return 0;
    }
};


	
int main() {
	Solution solution;
    vector<vector<int>> grid = {{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};


    auto ans = solution.maximumMinutes(grid);

	cout << ans << endl;
	return 0;
}



