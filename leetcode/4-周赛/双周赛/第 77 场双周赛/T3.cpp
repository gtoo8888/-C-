#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void PrintVector(vector<int> v){
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


class Solution {
public:
	void dfs(int x,int y,int m, int n, vector<vector<int>>& map){
		for(int i = x+1;i < m;i++){
			if(map[i][y] == 1 || map[i][y] == 2)
				break;
			map[i][y] = 3;
		}
		for(int i = x-1;i >= 0;i--){
			if(map[i][y] == 1 || map[i][y] == 2)
				break;
			map[i][y] = 3;
		}	
		for(int j = y+1;j < n;j++){
			if(map[x][j] == 1 || map[x][j] == 2)
				break;
			map[x][j] = 3;
		}
		for(int j = y-1;j >= 0;j--){
			if(map[x][j] == 1 || map[x][j] == 2)
				break;
			map[x][j] = 3;
		}
		return;
	}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> map(m,vector<int>(n,0));
		int g = guards.size();
		int w = walls.size();
		for(auto gi : guards){
			map[gi[0]][gi[1]] = 1;
		}
		for(auto wi : walls){
			map[wi[0]][wi[1]] = 2;
		}
		// PrintVVector(map);
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				if(map[i][j] == 1){
					dfs(i,j,m,n,map);
					// PrintVVector(map);
				}
			}
		}
		int ans = 0;
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				if(map[i][j] == 0){
					ans++;
				}
			}
		}
		return ans;
    }
};



	
int main() {
	Solution solution;
	int m = 3;
	int n = 3;
    vector<vector<int>> guards  =  {{1,1}};
    vector<vector<int>> walls  =  {{0,1},{1,0},{2,1},{1,2}};


    auto ans = solution.countUnguarded(m,n,guards,walls);

	cout << ans << endl;
	return 0;
}



