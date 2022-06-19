#include <iostream> 
#include <vector>
#include <queue>
using namespace std;


void PrintVector(vector<char> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void PrintVVector(vector<vector<char>> v){
	for(auto iter = v.begin();iter != v.end();iter++){		
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}


// dfs
// class Solution {
// public:
// 	void dfs(vector<vector<char>>& grid,int row,int col) {		//一定要传引用
//     	int row_e = grid.size();
//     	int col_e = grid[0].size();		
// 		grid[row][col] = '0';
// 		// PrintVVector(grid);
// 		if(row - 1 >= 0 && grid[row-1][col] == '1')		
// 			dfs(grid,row-1,col);
// 		if(row + 1 < row_e && grid[row+1][col] == '1')		
// 			dfs(grid,row+1,col);
// 		if(col - 1 >= 0 && grid[row][col-1] == '1')		
// 			dfs(grid,row,col-1);
// 		if(col + 1 <  col_e && grid[row][col+1] == '1')		
// 			dfs(grid,row,col+1);
// 	}
//     int numIslands(vector<vector<char>>& grid) {
// //    	PrintVVector(grid);
//     	int row = grid.size();
//     	int col = grid[0].size();
// //    	cout << row << " " << col << endl;
//     	int ans = 0;
//     	for(int i = 0;i < row;i++) {
//     		for(int j = 0;j < col;j++) {
//     			if(grid[i][j] == '1') {
//     				ans++;
//     				dfs(grid,i,j);
//    					PrintVVector(grid);
//     			}
//     		}
// 		}
// 		return ans;
//     }
// };


// bfs
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size();
		int ans = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(grid[i][j] == '1'){
					// printf("%d %d\n",i,j);
					ans++;
					queue<pair<int,int>> que;
					que.emplace(i,j);
					grid[i][j] = '0';
					while(!que.empty()){
						int cx = que.front().first;
						int cy = que.front().second;
						que.pop();
						for(int k = 0;k < 4;k++){
							int nx = cx + dx[k];
							int ny = cy + dy[k];
							if(nx >= 0 && ny >= 0 && nx < n && ny < m && 
												grid[nx][ny] == '1'){
								grid[nx][ny] = '0';
								que.emplace(nx,ny);
							}
						}
					}
					// PrintVVector(grid);
				}
				
			}
		}
		return ans;
    }
};

int main(){
	Solution solution;
	vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'1','0','1','0','0'},{'0','0','0','1','1'}};
	// vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'}, {'1','1','0','0','0'},{'0','0','0','0','0'}};
	PrintVVector(grid);

	auto ans = solution.numIslands(grid);
	
	cout << ans << endl;
	
	return 0;
}














