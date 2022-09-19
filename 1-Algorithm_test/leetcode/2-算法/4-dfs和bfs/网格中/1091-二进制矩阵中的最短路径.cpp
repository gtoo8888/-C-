#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
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


static const int dx[8] = {1,1,0,-1,-1,-1,0,1};
static const int dy[8] = {0,1,1,1,0,-1,-1,-1};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		if(grid[0][0] == 1)
			return -1;
		int n = grid.size();
		int m = grid[0].size();
		if(n == 1 && m == 1 && grid[0][0] == 0)
			return 1;
		queue<pair<int,int>> que;
		que.emplace(0,0);
		grid[0][0] = 1;
		int len = 1;
		while(!que.empty()){
			len++;
			// PrintVVector(grid);
			for(int i = que.size();i > 0;i--){
				int cx = que.front().first;
				int cy = que.front().second;
				que.pop();
				for(int j = 0;j < 8;j++){
					int nx = cx + dx[j];
					int ny = cy + dy[j];
					if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0){
						if(nx == n-1 && ny == m-1)
							return len;
						grid[nx][ny] = 1;
						que.emplace(nx,ny);
					}	
				}
			}
		}
		return -1;
    }
};


	
int main() {
	Solution solution;
	// vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
	// vector<vector<int>> grid = {{1,0,0},{1,1,0},{1,1,0}};
	// vector<vector<int>> grid =  {{0,1},{1,0}};
	// vector<vector<int>> grid =  {	{0,0,0,1},
	// 								{1,1,0,1},
	// 								{1,1,0,0}};
	vector<vector<int>> grid =  {{0}};
	PrintVVector(grid);
	
	auto ans = solution.shortestPathBinaryMatrix(grid);
	
	cout << ans << endl;
	
	return 0;
}



