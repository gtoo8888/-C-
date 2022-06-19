#include <iostream>
#include <vector>
using namespace std;


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
	void dfs(vector<vector<char>>& board,int row,int col) {
		int row_e = board.size();
		int col_e = board[0].size();
//		cout << row << " " << col << endl;
		board[row][col] = '.';
		
		if(col + 1 < col_e && board[row][col+1] == 'X')
			dfs(board,row,col+1);
		if(col - 1 >= 0 && board[row][col-1] == 'X')
			dfs(board,row,col-1);
		if(row + 1 < row_e && board[row+1][col] == 'X')
			dfs(board,row+1,col);
		if(row - 1 >= 0 && board[row-1][col] == 'X')
			dfs(board,row-1,col);
	}

    int countBattleships(vector<vector<char>>& board) {
		int ans = 0;
		int row = board.size();
		int col = board[0].size();
		
		for(int i = 0;i < row;i++) {
			for(int j = 0;j < col;j++) {
				if(board[i][j] == 'X') { 
					ans += 1; 
					dfs(board,i,j);
				} 
			}
		}
		return ans;
    }
};



	
int main() {
	Solution solution;
	vector<vector<char>> board = {
	{'X','.','.','X'},
	{'.','.','.','X'},
	{'.','.','.','X'}}; 
	
	auto ans = solution.countBattleships(board);
	
	cout << ans << endl;
	
	return 0;
}



