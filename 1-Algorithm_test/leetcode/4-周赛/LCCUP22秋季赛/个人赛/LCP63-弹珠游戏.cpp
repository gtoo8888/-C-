#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"



// int delt_dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
// 下，左，上，右

// class Solution {
// public:
// 	vector<vector<char>> map;
// 	vector<vector<int>> ans;
// 	int n;
// 	int m;	

// 	void dfs(int x,int y,int num,int dir,bool& is_ok,vector<vector<char>>& danzhu){
// 		// printf("%d %d now:%c\n",x,y,danzhu[x][y]);
// 		if(num < 0)
// 			return;
// 		if(danzhu[x][y] == 'O'){
// 			is_ok = true;
// 			return;
// 		}
// 		int now_x = x;
// 		int now_y = y;
// 		if(danzhu[x][y] == '.'){
// 			now_x += delt_dir[dir][0];
// 			now_y += delt_dir[dir][1];
// 		}else if(danzhu[x][y] == 'E'){
// 			dir += 1;
// 			if(dir > 3)	dir -= 4;
// 			now_x += delt_dir[dir][0];
// 			now_y += delt_dir[dir][1];
// 		}else if(danzhu[x][y] == 'W'){
// 			dir -= 1;
// 			if(dir < 0)	dir += 4;
// 			now_x += delt_dir[dir][0];
// 			now_y += delt_dir[dir][1];
// 		}
// 		if(now_x < n-1 && now_x >= 0 && now_y < m-1 && now_y >= 0 ){
// 			// printf("%d %d now:%c\n",now_x,now_y,danzhu[now_x][now_y]);
// 			dfs(now_x,now_y,num-1,dir,is_ok,danzhu);
// 		}
// 	}

//     vector<vector<int>> ballGame(int num, vector<string>& plate) {
// 		// PrintVSector(plate);
// 		n = plate.size();
// 		m = plate[0].size();
// 		vector<vector<char>> tmp1(n,vector<char>(m,'.'));
// 		this->map = tmp1;

// 		for(int i = 0;i < n;i++){
// 			for(int j = 0;j < m;j++){
// 				map[i][j] = plate[i][j];
// 			}
// 		}
// 		PrintVVector(map);
// 		for(int i = 1;i < n;i++){
// 			bool is_ok = false;
// 			if(map[0][i] == 'O')
// 				continue;
// 			dfs(0,i,num,0,is_ok,map);
// 			if(is_ok == true)
// 				ans.emplace_back(vector<int>{0,i});
// 			// cout << endl;

// 			is_ok = false;
// 			if(map[n-1][i] == 'O')
// 				continue;
// 			dfs(n-1,i,num,2,is_ok,map);
// 			if(is_ok == true)
// 				ans.emplace_back(vector<int>{n-1,i});
// 			// cout << endl;
// 		}
// 		for(int j = 1;j < n-1;j++){
// 			bool is_ok = false;
// 			if(map[j][0] == 'O')
// 				continue;
// 			dfs(j,0,num,3,is_ok,map);
// 			if(is_ok == true)
// 				ans.emplace_back(vector<int>{j,0});
// 			// cout << endl;

// 			is_ok = false;
// 			if(map[j][m-1] == 'O')
// 				continue;
// 			dfs(j,m-1,num,1,is_ok,map);
// 			if(is_ok == true)
// 				ans.emplace_back(vector<int>{j,m-1});			
// 			// cout << endl;
// 		}
// 		// PrintVVector(ans);
// 		// return vector<vector<int>>();
// 		return ans;
//     }
// };

vector<vector<int>> dir = {{1,0},{0,-1},{-1,0},{0,1}};
// 下，左，上，右

class Solution {
public:
	vector<vector<char>> map;
	vector<vector<int>> ans;
	int n; // x和n，y和m的关系不要搞错
	int m;	

	// 只是一个简单的模拟，每次遇到E,W时候改变下一步走的方向
	bool dfs(int x,int y,int bushu,int now_dir){ 
		int left = bushu;
		while(map[x][y] != 'O'){
			if(left == 0)
				return false;
			else if(map[x][y] == 'E'){
				now_dir = (now_dir+1)%4;
			}else if(map[x][y] == 'W'){
				// int now_dir = now_dir+1 >= 0 ? (now_dir-1)%4 : (1-now_dir)%4;
				now_dir = (now_dir+3)%4;
			}
			x = x + dir[now_dir][0];
			y = y + dir[now_dir][1]; 
			if(x < 0 || x > n-1 || y < 0 || y > m-1)
				return false;
			left--;
		}
		return true;
	}

    vector<vector<int>> ballGame(int num, vector<string>& plate) {
		n = plate.size();
		m = plate[0].size();
		vector<vector<char>> tmp1(n,vector<char>(m,'.'));
		this->map = tmp1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				map[i][j] = plate[i][j];
			}
		}
		// PrintVVector(map);
		vector<vector<int>> ans;
		for(int j = 1;j < m-1;j++){
			if(map[0][j] == '.' && dfs(0,j,num,0)) // 需要排除掉，只有.能开始走
				ans.push_back({0,j});
			if(map[n-1][j] == '.' && dfs(n-1,j,num,2)) // 改变起始方向就可以了
				ans.push_back({n-1,j});		
		}
		for(int i = 1;i < n-1;i++){
			if(map[i][0] == '.' && dfs(i,0,num,3))
				ans.push_back({i,0});
			if(map[i][m-1] == '.' && dfs(i,m-1,num,1))
				ans.push_back({i,m-1});		
		}
		return ans;
    }
};

int main() {
	Solution solution;
	// int num = 4;
	// vector<string> plate = {"..E.",".EOW","..W."};

	int num = 5;
	vector<string> plate = {".....","..E..",".WO..","....."};

	// int num = 3;
	// vector<string> plate = {".....","....O","....O","....."};

	// int num = 69;
	// vector<string> plate = {"W.W.WE..",".WWWEW..","EWW.WE.E","E.W.E.E.",".OEOO.EO","WE.WOE.W","WW...E..",".WEWO..O","E....E..",".OWE...."};

	auto ans = solution.ballGame(num,plate);
	
	PrintVVector(ans);
	return 0;
}



