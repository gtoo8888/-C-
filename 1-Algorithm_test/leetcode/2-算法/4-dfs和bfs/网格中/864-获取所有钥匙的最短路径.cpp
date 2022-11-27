#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// bfs
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
		PrintVector(grid);
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> grid_num(n,vector<int>(m,0));
		int key_num = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(grid[i][j] == '#') grid_num[i][j] = -1;
				if(grid[i][j] == '@') grid_num[i][j] = 0;
				// if(grid[i][j] >= 'a' && grid[i][j] <= 'z') {
				// 	grid_num[i][j] = -2;
				// 	key_num++;
				// }
				// if(grid[i][j] >= 'A' && grid[i][j] <= 'Z') 
				// 	grid_num[i][j] = -3;
			}
		}
		PrintVVector(grid_num);

		int cur = 1;
		queue<pair<int,int>> que;	// 用一个pair结构来保存两个点的坐标
        stack<char> st;
		que.push({0,0});
        grid_num[0][0] = 0;
		while(!que.empty()){
			int cur_i = que.front().first;
			int cur_j = que.front().second;
			que.pop();
            // if(grid_num[cur_i][cur_j] == -2){
            //     key_num--;
            //     st.push(grid[cur_i][cur_j]);
            // }
			// if(cur_i < 0 || cur_j < 0 || cur_i >= n || cur_j >= m || 
			// 	grid_num[cur_i][cur_j] == -1 ||grid_num[cur_i][cur_j] > 0)	// 判断条件移动到了每次栈的查找里面
			// 	continue;
			// grid_num[cur_i][cur_j] = cur;
            for(int k = 0;k < 4;k++){
				int nx = cur_i + dx[k];
				int ny = cur_j + dy[k];
				if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid_num[nx][ny] == 0){
					grid_num[nx][ny] = cur++;
					que.emplace(nx,ny);
				}
			}

			// que.push({cur_i + 1,cur_j});
			// que.push({cur_i - 1,cur_j});
			// que.push({cur_i,cur_j + 1});
			// que.push({cur_i,cur_j - 1});
			// printf("%d\n",cur);
			PrintVVector(grid_num);
            // cur++;

            if(cur > 10 )
                return 0;
		}
		return 0;
    }
};


	
int main() {
	Solution solution;
	vector<string> grid = {"@.a..","###.#","b.A.B"};
	auto ans = solution.shortestPathAllKeys(grid);
	
	cout << ans << endl;
	
	return 0;
}



