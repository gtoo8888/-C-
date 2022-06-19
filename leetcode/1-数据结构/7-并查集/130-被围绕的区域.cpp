#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;

void printVector(vector<string> v){
	for(vector<string>::iterator it = v.begin();it != v.end();it++)
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

// class Solution {
// public:
// 	void dfs(vector<vector<char>> &board,int row,int col){
// 		int row_e = board.size();
// 		int col_e = board[0].size();

// 		board[row][col] = 'A';
// 		// PrintVVector(board);
// 		if(row - 1 >= 0 && board[row-1][col] == 'O')
// 			dfs(board,row-1,col);
// 		if(row + 1 < row_e && board[row+1][col] == 'O')
// 			dfs(board,row+1,col);
// 		if(col - 1 >= 0 && board[row][col-1] == 'O')
// 			dfs(board,row,col-1);
// 		if(col + 1 < col_e && board[row][col+1] == 'O')
// 			dfs(board,row,col+1);
// 	}

//     void solve(vector<vector<char>>& board) {
// 		int row = board.size();
// 		int col = board[0].size();

// 		for(int i = 0;i < row;i++) {
// 			if(board[i][0] == 'O')
// 				dfs(board,i,0);
// 			if(board[i][col-1] == 'O')
// 				dfs(board,i,col-1);
// 		}
// 		for(int i = 0;i < col;i++) {
// 			if(board[0][i] == 'O')
// 				dfs(board,0,i);	
// 			if(board[row-1][i] == 'O')
// 				dfs(board,row-1,i);	
// 		}

// 		for(int i = 0;i < row;i++) {
// 			for(int j = 0;j < col;j++) {
// 				if(board[i][j] == 'O')
// 					board[i][j] = 'X';
// 				if(board[i][j] == 'A')
// 					board[i][j] = 'O';
// 			}
// 		}
// 				// PrintVVector(board);	
//     }
// };

class Solution {
public:
	int row_e;
	int col_e;
	void dfs(vector<vector<char>> &board,int x,int y){
//		printf("%d %d\n",x,y) ;
		if(x < 0 || x >= row_e || y < 0 || y >= col_e || board[x][y] != 'O')		
			return;

		board[x][y] = 'A';
//		PrintVVector(board);
		dfs(board,x-1,y);
		dfs(board,x+1,y);
		dfs(board,x,y-1);
		dfs(board,x,y+1);
	}

    void solve(vector<vector<char>>& board) {
		row_e = board.size();  // 不要在前面加int不然会局部变量替换全局变量 
		col_e = board[0].size();

		 for(int i = 0;i < row_e;i++) {
		 	dfs(board, i, 0);
            dfs(board, i, col_e - 1);
		 }
		for(int i = 0;i < col_e;i++) {
			dfs(board, 0, i);	
			dfs(board, row_e -1 , i);	
		}
		 for(int i = 0;i < row_e;i++) {
		 	for(int j = 0;j < col_e;j++) {
		 		if(board[i][j] == 'O')
		 			board[i][j] = 'X';
		 		if(board[i][j] == 'A')
		 			board[i][j] = 'O';
		 	}
		 }
//				PrintVVector(board);	
    }
};




	
int main() {
	Solution solution;
//    vector<vector<char>> board = { 	{'X','O','X','X','X'},
//                                    {'X','X','O','O','X'},
//                                    {'X','X','O','X','X'},
//                                    {'O','X','X','X','O'},
//									{'X','O','X','X','X'}};

//	 vector<vector<char>> board ={	{'X','O','X','O','X','O'},
//	 								{'O','X','O','X','O','X'},
//	 								{'X','O','X','O','X','O'},
//	 								{'O','X','O','X','O','X'}};
	 								
	vector<vector<char>> board ={	{'O','O','O'},
									{'O','O','O'},
									{'O','O','O'}};

	PrintVVector(board);

	solution.solve(board);
	
	PrintVVector(board);
	
	return 0;
}


