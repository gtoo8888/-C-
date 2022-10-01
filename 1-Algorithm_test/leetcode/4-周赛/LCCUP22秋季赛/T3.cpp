#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"



int delt_dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
// 下，左，上，右

class Solution {
public:
	vector<vector<char>> map;
	vector<vector<int>> ans;
	int n;
	int m;	

	void dfs(int x,int y,int num,int dir,bool& is_ok,vector<vector<char>>& danzhu){
		// printf("%d %d now:%c\n",x,y,danzhu[x][y]);
		if(num < 0)
			return;
		if(danzhu[x][y] == 'O'){
			is_ok = true;
			return;
		}
		int now_x = x;
		int now_y = y;
		if(danzhu[x][y] == '.'){
			now_x += delt_dir[dir][0];
			now_y += delt_dir[dir][1];
		}else if(danzhu[x][y] == 'E'){
			dir += 1;
			if(dir > 3)	dir -= 4;
			now_x += delt_dir[dir][0];
			now_y += delt_dir[dir][1];
		}else if(danzhu[x][y] == 'W'){
			dir -= 1;
			if(dir < 0)	dir += 4;
			now_x += delt_dir[dir][0];
			now_y += delt_dir[dir][1];
		}
		if(now_x < n-1 && now_x >= 0 && now_y < m-1 && now_y >= 0 ){
			// printf("%d %d now:%c\n",now_x,now_y,danzhu[now_x][now_y]);
			dfs(now_x,now_y,num-1,dir,is_ok,danzhu);
		}
	}

    vector<vector<int>> ballGame(int num, vector<string>& plate) {
		// PrintVSector(plate);
		n = plate.size();
		m = plate[0].size();
		vector<vector<char>> tmp1(n,vector<char>(m,'.'));
		this->map = tmp1;

		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				map[i][j] = plate[i][j];
			}
		}
		PrintVVCector(map);
		for(int i = 1;i < n;i++){
			bool is_ok = false;
			if(map[0][i] == 'O')
				continue;
			dfs(0,i,num,0,is_ok,map);
			if(is_ok == true)
				ans.emplace_back(vector<int>{0,i});
			// cout << endl;

			is_ok = false;
			if(map[n-1][i] == 'O')
				continue;
			dfs(n-1,i,num,2,is_ok,map);
			if(is_ok == true)
				ans.emplace_back(vector<int>{n-1,i});
			// cout << endl;
		}
		for(int j = 1;j < n-1;j++){
			bool is_ok = false;
			if(map[j][0] == 'O')
				continue;
			dfs(j,0,num,3,is_ok,map);
			if(is_ok == true)
				ans.emplace_back(vector<int>{j,0});
			// cout << endl;

			is_ok = false;
			if(map[j][m-1] == 'O')
				continue;
			dfs(j,m-1,num,1,is_ok,map);
			if(is_ok == true)
				ans.emplace_back(vector<int>{j,m-1});			
			// cout << endl;
		}
		// PrintVVector(ans);
		// return vector<vector<int>>();
		return ans;
    }
};


int main() {
	Solution solution;
	// int num = 4;
	// vector<string> plate = {"..E.",".EOW","..W."};

	// int num = 5;
	// vector<string> plate = {".....","..E..",".WO..","....."};

	// int num = 3;
	// vector<string> plate = {".....","....O","....O","....."};

	int num = 69;
	vector<string> plate = {"W.W.WE..",".WWWEW..","EWW.WE.E","E.W.E.E.",".OEOO.EO","WE.WOE.W","WW...E..",".WEWO..O","E....E..",".OWE...."};

	auto ans = solution.ballGame(num,plate);
	
	PrintVVector(ans);
	return 0;
}



