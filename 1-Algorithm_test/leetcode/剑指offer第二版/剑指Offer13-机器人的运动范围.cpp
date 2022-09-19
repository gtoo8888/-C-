#include <iostream>
#include <vector>
using namespace std;

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
    bool is_go(int i, int j, int k) {
        int sum = 0;
        while(i != 0) {sum += i%10;i /= 10;}
        while(j != 0) {sum += j%10;j /= 10;}
        if (sum <= k)           return true;
        else                    return false;
    }

    // int ans = 0;
    // void dfs(vector<vector<int>>& grid,int row,int col) {    //dfs一定要传引用
    //     int row_e = grid.size();
    //     int col_e = grid.size();

    //     ans++;
    //     grid[row][col] = 0;
    //     PrintVVector(grid);
    //     if(row - 1 >= 0 && grid[row-1][col] == 1)
    //         dfs(grid,row-1,col);
    //     if(row + 1 <= row_e && grid[row+1][col] == 1)
    //         dfs(grid,row+1,col);
    //     if(col - 1 >= 0 && grid[row][col-1] == 1)
    //         dfs(grid,row,col-1);
    //     if(col + 1 <= col_e && grid[row][col+1] == 1)
    //         dfs(grid,row,col+1);
    // }

    int ans = 0;
    void dfs(vector<vector<int>> &grid,int row,int col) {   //dfs的另外一种写法
        int row_e = grid.size();
        int col_e = grid[0].size();
        // cout << row << " " << col << endl;
        if(row < 0 || row >= row_e ||  col < 0 ||col >= col_e || grid[row][col] == 0)
            return;
        ans++;
        grid[row][col] = 0;
        PrintVVector(grid);
        dfs(grid,row-1,col);
        dfs(grid,row+1,col);
        dfs(grid,row,col-1);
        dfs(grid,row,col+1);
    }

    int movingCount(int m, int n, int k) {
        vector<vector<int>> map(m,vector<int>(n,0));
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(is_go(i,j,k) == true){
                    // printf("[%d,%d]\n",i,j);
                    map[i][j] = 1;
                }
                else   
                    map[i][j] = 0;
            }
        }
        // PrintVVector(map);
        dfs(map,0,0);
        cout << ans << endl;
        return ans;
    }
};


	
int main() {
	Solution sol;
	int m = 16,n = 8,k = 4;

	auto ans = sol.movingCount(m,n,k);
	cout << ans << endl;
	
	return 0;
}



