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

void PrintVBector(vector<vector<bool>> v){
	
	for(auto iter = v.begin();iter != v.end();iter++){		
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

class Solution {
public:
	int row_e,col_e;
	int w_flag = false;
	void dfs(vector<vector<char>>& board ,int x,int y, string word,int w_len,
			vector<vector<bool>>& w_true) {
		
		 if (x < 0 || x >= row_e || y < 0 || y >= col_e || board[x][y] != word[w_len]
		 			|| w_len > word.size() || w_flag == true || w_true[x][y] == true){
		 	if(w_len == word.size())
		 		w_flag = true;
		 	if ( !(x < 0 || x >= row_e || y < 0 || y >= col_e || w_len > word.size()))
		 		w_true[x][y] = false;
		 	return;
		 }
		 printf("%d %d %c %d %d\n\n",x,y,board[x][y],w_len,word.size());
		 w_true[x][y] = true;
		 PrintVBector(w_true);
		
		dfs(board,x-1,y,word,w_len+1,w_true);
		dfs(board,x+1,y,word,w_len+1,w_true);
		dfs(board,x,y-1,word,w_len+1,w_true);
		dfs(board,x,y+1,word,w_len+1,w_true);
	}
    bool exist(vector<vector<char>>& board, string word) {
		row_e = board.size();
		col_e = board[0].size();
		
		printf("%d %d\n",row_e,col_e);
		if(row_e == 1 && col_e < word.size()){
//			printf("%d %d\n",row_e,col_e);
			return false;
		}

		for(int i = 0;i < row_e ;i++){
			for(int j = 0;j < col_e ;j++){
				if(board[i][j] == word[0]){
					vector<vector<bool>> w_true(row_e,vector<bool>(col_e,false));
					dfs(board,i,j,word,0,w_true);
				}
			}
		}
		return w_flag;
    }	
};

		
int main() {
	Solution solution;
//	vector<vector<char>> board ={	{'A','B','C','E'},
//									{'S','F','C','S'},
//									{'A','D','E','E'}};
//	vector<vector<char>> board ={	{'a','b'},
//									{'c','d'}};
//	vector<vector<char>> board ={	{'a','a'}};
//	vector<vector<char>> board ={	{'A','B','C','E'},
//									{'S','F','C','S'},
//									{'A','D','E','E'}};
//	vector<vector<char>> board ={	{'C','A','A'},
//									{'A','A','A'},
//									{'B','C','D'}};	
	vector<vector<char>> board ={	{'A','B','C','E'},
									{'S','F','E','S'},
									{'A','D','E','E'}};
	
	string word = "ABCESEEEFS";

	PrintVVector(board);

	auto ans = solution.exist(board,word);

	PrintBool(ans);

	
	return 0;
}


