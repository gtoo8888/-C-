#include <iostream>
#include <vector>
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

static const int dis[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};//搜索的时候需要对比，所以先取出来了方向
class Solution {
public:
	vector<vector<int>> o_height;
	int n;
	int m;	
	void dfs(int x,int y,vector<vector<int>>& ocean){
		if(ocean[x][y] == 1)
			return;
		ocean[x][y] = 1;
		// PrintVVector(ocean);
		for(int i = 0;i < 4;i++){
			int now_x = x + dis[i][0];
			int now_y = y + dis[i][1];
			if(now_x < n && now_x >= 0 && now_y < m && now_y >= 0 
				&& o_height[now_x][now_y] >= o_height[x][y]){
				// printf("%d %d now:%d old:%d\n",now_x,now_y,o_height[now_x][now_y],o_height[x][y]);
				dfs(now_x,now_y,ocean);
			}
		}
	}

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		// PrintVVector(heights);
		this->o_height = heights;
		n = heights.size();
		m = heights[0].size();	
		vector<vector<int>> pacific(n,vector<int>(m,0));
		vector<vector<int>> atiantic(n,vector<int>(m,0));
		for(int i = 0;i < n;i++){
			dfs(i,0,pacific);
			dfs(i,m-1,atiantic);
		}
		for(int j = 0;j < m;j++){
			dfs(0,j,pacific);
			dfs(n-1,j,atiantic);
		}
		PrintVVector(pacific);	
		PrintVVector(atiantic);	

		vector<vector<int>> ans;
		for(int i = 0 ;i < n;i++){
			for(int j = 0;j < m;j++){
				if(pacific[i][j] == 1 && atiantic[i][j] == 1){
					vector<int> tmp = {i,j};
					ans.push_back(tmp);
				}
			}
		}
		return ans;
    }
};


	
int main() {
	Solution solution;
	vector<vector<int>> heights  = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
	
	auto ans = solution.pacificAtlantic(heights);
	
	PrintVVector(ans);
	
	return 0;
}



