#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> grid;
    int dfs(int x,int y,int len){
        if(x < 0 || x >= rows || y < 0 || y >= cols){
            return 0;
        }
        if(x == rows-1 && y == cols-1){
            return len;
        }

        len++;    
        int run = grid[x][y];
        if(run == 0)
            return 0;
        for(int i = 1;i < run;i++){
            dfs(x,y+i,len);
            len--;
            dfs(x+i,y,len);
            len--;
        }
    }
    int minimumVisitedCells(vector<vector<int>>& grid) {
        PrintVVector(grid);
        this->rows = grid.size();
        this->cols = grid[0].size();
        this->grid = grid;
        int ans = dfs(0,0,0);
        return ans;
    }
};


int main() {
	Solution solution;
	vector<vector<int>> grid = {{3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0}};

    auto ans = solution.minimumVisitedCells(grid);

	cout << ans << endl;
	return 0;
}




