#include <iostream> 
#include <vector>
#include <queue>
using namespace std;


void PrintVector(vector<char> v){
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

// class Solution {
// public:
//    	int area = 0;
// 	void dfs(vector<vector<int>>& grid,int row,int col) {
//     	int row_e = grid.size();
//     	int col_e = grid[0].size();   		
//     	area++; 
//     	grid[row][col] = 0;
//     	if(row-1 >= 0 && grid[row-1][col] == 1) 
// 			dfs(grid,row-1,col);
// 		if(row+1 < row_e && grid[row+1][col] == 1) 
// 			dfs(grid,row+1,col);
//     	if(col-1 >= 0 && grid[row][col-1] == 1) 
// 			dfs(grid,row,col-1);
// 		if(col+1 < col_e && grid[row][col+1] == 1) 
// 			dfs(grid,row,col+1);
// 	}
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//     	int ans = INT32_MIN;
//     	int row = grid.size();
//     	int col = grid[0].size();
//     	for(int i = 0;i < row;i++) {
//     		for(int j = 0;j < col;j++) {
//     			if(grid[i][j] == 1){
//     				area = 0;
//     				dfs(grid,i,j);
// //    				PrintVVector(grid);
// //    				cout << area << endl;
//     				if(area > ans)
//     					ans = area;
//     			}
//     		}
//     	}
//     	if(ans == INT32_MIN)	
//     		ans = 0;
// 		return ans;
//     }
// };


void PrintQueue(queue<int> q){
	while(!q.empty()){
		printf("%d ",q.front());
		q.pop();
	}
	cout << endl; 
}

// bfs
// class Solution {
// public:
// 	int n,m;
// 	// int dx[4] = {1,0,-1,0};
// 	// int dy[4] = {0,1,0,-1};
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
// 		n = grid.size();
// 		m = grid[0].size();
// 		int ans = 0;
// 		for(int i = 0;i < n;i++){
// 			for(int j = 0;j < m;j++){
// 				int cur = 0; 	// 岛屿的数量
// 				queue<int> qi;
// 				queue<int> qj;
// 				qi.push(i);
// 				qj.push(j);
// 				while(!qi.empty()){
// 					// PrintQueue(qi);
// 					int cur_i = qi.front();
// 					int cur_j = qj.front();
// 					qi.pop();qj.pop();
// 					if(cur_i < 0 || cur_j < 0 || cur_i >= n || cur_j >= m || 
// 						grid[cur_i][cur_j] != 1)	// 判断条件移动到了每次栈的查找里面
// 						continue;
// 					++cur;
// 					grid[cur_i][cur_j] = 0;
// 					qi.push(cur_i + 1);qj.push(cur_j);
// 					qi.push(cur_i - 1);qj.push(cur_j);
// 					qi.push(cur_i);qj.push(cur_j + 1);
// 					qi.push(cur_i);qj.push(cur_j - 1);
// 					// printf("%d\n",cur);
// 					// PrintVVector(grid);
// 				}
// 				ans = max(ans,cur);
// 			}
// 		}
// 		return ans;
//     }
// };



// bfs写法的改进
class Solution {
public:
	int n,m;
	// int dx[4] = {1,0,-1,0};
	// int dy[4] = {0,1,0,-1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		n = grid.size();
		m = grid[0].size();
		int ans = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int cur = 0; 	// 岛屿的数量
				queue<pair<int,int>> que;	// 用一个pair结构来保存两个点的坐标
				que.push({i,j});
				while(!que.empty()){
					// auto cur_pos = que.front();
					// que.pop();
					// int cur_i = cur_pos.first;
					// int cur_j = cur_pos.second;
					int cur_i = que.front().first;
					int cur_j = que.front().second;
					que.pop();
					if(cur_i < 0 || cur_j < 0 || cur_i >= n || cur_j >= m || 
						grid[cur_i][cur_j] != 1)	// 判断条件移动到了每次栈的查找里面
						continue;
					++cur;
					grid[cur_i][cur_j] = 0;
					que.push({cur_i + 1,cur_j});
					que.push({cur_i - 1,cur_j});
					que.push({cur_i,cur_j + 1});
					que.push({cur_i,cur_j - 1});
					// printf("%d\n",cur);
					// PrintVVector(grid);
				}
				ans = max(ans,cur);
			}
		}
		return ans;
    }
};

int main(){
	Solution solution;
	// vector<vector<int>> grid =  {
	// 	{0,0,0,0,0,0,0,0}};
	vector<vector<int>> grid =  {
	{0,0,1,0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,0,0,0},
	{0,1,1,0,1,0,0,0,0,0,0,0,0},
	{0,1,0,0,1,1,0,0,1,0,1,0,0},
	{0,1,0,0,1,1,0,0,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,1,1,0,0,0,0}};

	PrintVVector(grid);
	
	auto ans = solution.maxAreaOfIsland(grid);
	
	cout << ans << endl;
	
	return 0;
}














