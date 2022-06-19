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


class Solution {
public:
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,-1,0,1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		int n = maze.size();
		int m = maze[0].size();
		queue<pair<int,int>> que;
		int len = 0;
		que.push({entrance[0],entrance[1]});
		maze[entrance[0]][entrance[1]] = '+';
		while(!que.empty()){
			++len;
			// for(int i = 0;i < que.size();i++){
			for(int i = que.size();i > 0;i--){	// 如果不加的话，当同时有两个方向可以走的时候会出问题，会随机走
				int cx = que.front().first;
				int cy = que.front().second;
				que.pop();
				// printf("%d %d\n",len,i);
				// PrintVVector(maze);
				for(int i = 0;i < 4;i++){
					int nx = cx + dx[i];
					int ny = cy + dy[i];
					if(nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == '.'){
						if(nx == 0 || nx == n-1 || ny == 0 || ny == m-1){
							// printf("%d %d %c\n",nx,ny,maze[nx][ny]);
							return len;
						}
						// printf("%d %d %c\n",nx,ny,maze[nx][ny]);
						maze[nx][ny] = '+';
						que.emplace(nx,ny);
					}
				}
			}
		}
		return -1;
    }
};


int main(){
	Solution solution;
	// vector<vector<char>> maze =  {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
	// vector<int> entrance = {1,2};

	// vector<vector<char>> maze =  {{'+','+','+'},{'.','.','.'},{'+','+','+'}};
	// vector<int> entrance = {1,0};

	// vector<vector<char>> maze =  {{'+','.','+','+','+','+','+'},{'+','.','+','.','.','.','+'},{'+','.','+','.','+','.','+'},{'+','.','.','.','+','.','+'},{'+','+','+','+','+','.','+'}} ;
	// vector<int> entrance = {0,1};

	// vector<vector<char>> maze =  {{'+','.','+','+','+','+','+'},{'+','.','+','.','.','.','+'},{'+','.','+','.','+','.','+'},{'+','.','.','.','.','.','+'},{'+','+','+','+','.','+','.'}} ;
	// vector<int> entrance = {0,1};

	vector<vector<char>> maze =  {{'+','.','+','+','+','+','+'},{'+','.','+','.','.','.','+'},{'+','.','+','.','+','.','+'},{'+','.','.','.','+','.','+'},{'+','+','+','+','+','.','+'}}  ;
	vector<int> entrance = {3,2};
	PrintVVector(maze);

	auto ans = solution.nearestExit(maze,entrance);
	
	cout << ans << endl;
	
	return 0;
}














