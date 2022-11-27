#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
// 		if(grid[0][0] == 1)
// 			return -1;
// 		int n = grid.size();
// 		int m = grid[0].size();
// 		if(n == 1 && m == 1 && grid[0][0] == 0)
// 			return 1;
// 		queue<pair<int,int>> que;
// 		que.emplace(0,0);
// 		grid[0][0] = 1;
// 		int len = 1;
// 		while(!que.empty()){
// 			len++;
// 			// PrintVVector(grid);
// 			for(int i = que.size();i > 0;i--){
// 				int cx = que.front().first;
// 				int cy = que.front().second;
// 				que.pop();
// 				for(int j = 0;j < 8;j++){
// 					int nx = cx + dx[j];
// 					int ny = cy + dy[j];
// 					if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0){
// 						if(nx == n-1 && ny == m-1)
// 							return len;
// 						grid[nx][ny] = 1;
// 						que.emplace(nx,ny);
// 					}	
// 				}
// 			}
// 		}
// 		return -1;
//     }
// };

static const int dx[4] = {1,-1,0,0};
static const int dy[4] = {0,0,1,-1};
class Solution {
public:
	int n,m;
    int shortestBridge(vector<vector<int>>& grid) {
		PrintVVector(grid);
		n = grid.size();
		m = grid[0].size();
		queue<pair<int,int>> que;
		vector<pair<int,int>> island;
		

		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(grid[i][j] == 1){
					que.emplace(i,j);
					grid[i][j] = -1;
					while(!que.empty()){
						for(int i = que.size();i > 0;i--){
							auto [x,y] = que.front();
							que.pop();
							island.emplace_back(x,y);
							for(int j = 0;j < 4;j++){
								int nx = x + dx[j];
								int ny = y + dy[j];
								if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
									grid[nx][ny] = -1;
									que.emplace(nx,ny);
								}	
							}
						}
					}
					PrintVVector(grid);
					for(auto it : island){
						que.emplace(it.first,it.second);
					}					
					int step = 0;
					while(!que.empty()){
						PrintVVector(grid);
						printf("%d\n",que.size());
						for(int i = que.size();i > 0;i--){
							auto [x,y] = que.front();
							que.pop();
							for(int j = 0;j < 4;j++){
								int nx = x + dx[j];
								int ny = y + dy[j];
								if(nx >= 0 && ny >= 0 && nx < n && ny < m){
									if(grid[i][j] == 0){
										grid[nx][ny] = -1;
										que.emplace(nx,ny);
									}else if(grid[i][j] == 1)
										return step;									
								}	
							}
						}
						step++;
						PrintVVector(grid);
					}

				}
			}
		}

		return 0;
    }
};



	
int main() {
	Solution solution;
	// vector<vector<int>> grid = {{0,1,0},{0,0,0},{0,0,1}};
	vector<vector<int>> grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};	
	auto ans = solution.shortestBridge(grid);
	
	cout << ans << endl;
	
	return 0;
}



