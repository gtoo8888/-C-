#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;


void printVSector(vector<string> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << endl;
	cout << endl;
}



static const int MOUSE_TURN = 0,CAT_TURN = 1;
static const int UNKONW = 0,MOUSE_WIN = 1,CAT_WIN = 2;
static const int MAX_ITER = 1000;

void printVVV(int degrees[][64][2]){
	for(int ii = 0;ii < 64;ii++){
		for(int jj = 0;jj < 64;jj++){
			printf("%d ",degrees[ii][jj][MOUSE_TURN]);
		}
		printf("\n");
	}	
}

// void printVVV(int *degrees){
// 	for(int ii = 0;ii < 64;ii++){
// 		for(int jj = 0;jj < 64;jj++){
// 			printf("%d ",*(degrees + ii * 64 + jj * 64 + 1) );
// 		}
// 		printf("\n");
// 	}	
// }

// 没有过，还没写完
class Solution {
public:
	int n,m;
	vector<string> grid;
	int catJump,mouseJump;
	int food;
	int degrees[64][64][2];
	int results[64][64][2][2];
	vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
	int getPos(int x,int y){
		return x * n + y;
	}
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
		printVSector(grid);
		this->n = grid.size();
		this->m = grid[0].size();
		this->catJump = catJump;
		this->mouseJump = mouseJump;
		this->grid = grid;
		int startMouse = -1,startCat = -1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				char c = grid[i][j];
				if(c == 'M')
					startMouse = getPos(i,j);
				else if(c == 'M')
					startCat = getPos(i,j);
				else if(c == 'F')
					food = getPos(i,j);
			}
		}
		int total = n*m;
		memset(degrees,0,sizeof(degrees));
		memset(results,0,sizeof(results));
		queue<tuple<int,int,int>> qu;
		// 计算每个状态的度
		for(int i = 0;i < total;i++){
			int mouseX = i / n,mouseY = i % n;
			if(grid[mouseX][mouseY] == '#')
				continue;
			for(int j = 0;j < total;j++){
				int catX = j / n,catY = j % n;
				if(grid[catX][catY] == '#')
					continue;
				degrees[i][j][MOUSE_TURN]++;
				degrees[i][j][CAT_TURN]++;
// printVVV(degrees);
				for(auto dir : dirs){
					int nowX = mouseX + dir[0];
					int nowY = mouseY + dir[1];
					int jump = 1;
					printf("%d %d %d\n",nowX,nowY,getPos(nowX,nowY));
					for(;nowX >= 0 && nowX < n && nowY >= 0 && nowY < m &&
						grid[nowX][nowY] != '#' && jump <= mouseJump;
						nowX += dir[0],nowY += dir[1],jump++){
							int nextMouse = getPos(nowX,nowY);
							int nextCat = getPos(catX,catY);
							degrees[nextMouse][nextCat][MOUSE_TURN]++;
					}
					 nowX = catX + dir[0];
					 nowY = catY + dir[1];
					 jump = 1;
					for(;nowX >= 0 && nowX < n && nowY >= 0 && nowY < m &&
						grid[nowX][nowY] != '#' && jump <= catJump;
						nowX += dir[0],nowY += dir[1],jump++){
							int nextMouse = getPos(mouseX,mouseY);
							int nextCat = getPos(nowX,nowY);
							degrees[nextMouse][nextCat][CAT_TURN]++;
					}
				}
				
			}
			
		}
		
		
		return false;
    }
};


	
int main() {
	Solution solution;
	vector<string> grid = {"####F","#C...","M...."};
	int catJump = 1;
	int mouseJump = 2;

	
	auto ans = solution.canMouseWin(grid,catJump,mouseJump);
	cout << ans << endl;
	
	return 0;
}



