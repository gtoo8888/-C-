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


// 不可以用dfs
// class Solution {
// public:
// 	int n,m;
// 	int len;
// 	void dfs(vector<vector<int>>& mat,int x,int y){
// 		if(x < 0 || y < 0 || x >= n || y >= m || mat[x][y] != 0){
// 			return;
// 		}
// 		len++;
// 		mat[x][y] = 0;
// 		printf("%d %d\n",x,y);
// 		PrintVVector(mat);
// 		dfs(mat,x-1,y);
// 		dfs(mat,x+1,y);
// 		dfs(mat,x,y-1);
// 		dfs(mat,x,y+1);
// 	}
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
// 		this->n = mat.size();
// 		this->m = mat[0].size();
// 		for(int i = 0;i < n;i++){
// 			for(int j = 0;j < m;j++){
// 				if(mat[i][j] == 0)
// 					continue;
// 				len = 1;
// 				dfs(mat,i,j);
// 				mat[i][j] = len;
// 			}
// 		}
// 		return mat;
//     }
// };


// 多源bfs，从多个点开始扩散
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		int n = mat.size();
		int m = mat[0].size();
		vector<vector<int>> vistied(n,vector<int>(m,0));
		vector<vector<int>> ans(n,vector<int>(m,0));
		queue<pair<int,int>> que;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(mat[i][j] == 0){
					que.emplace(i,j);
					vistied[i][j] = 1;
				}
			}
		}
		while(!que.empty()){
			int cx = que.front().first;
			int cy = que.front().second;
			que.pop();
			// PrintVVector(mat);
			for(int i = 0;i < 4;i++){
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if(nx >= 0 && ny >= 0 && nx < n && ny < m && vistied[nx][ny] == 0){
					ans[nx][ny] = ans[cx][cy] + 1;
					que.emplace(nx,ny);
					vistied[nx][ny] = 1;
				}
			}
		}
		return ans;
    }
};

	
int main() {
	Solution solution;
	// vector<vector<int>> mat  =  {{0,0,0},{0,1,0},{0,0,0}};
	vector<vector<int>> mat  =   {{0,0,0},{0,1,0},{1,1,1}};
	PrintVVector(mat);

	auto ans = solution.updateMatrix(mat);
	
	PrintVVector(ans);
	
	return 0;
}



