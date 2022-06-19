#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

void PrintVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void printVVector(vector<vector<int>> v){
	vector<vector<int>>::iterator iter;
	vector<int>::iterator it;
	vector<int> it_temp;
	
	for(iter = v.begin();iter != v.end();iter++){
		it_temp = *iter;
		for(it = it_temp.begin();it != it_temp.end();it++)
			cout << setw(5) << *it << " ";
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
    	int oCout = 0;
    	int xCout = 0;
    	for(auto it = board.begin();it != board.end();it++) {
    		string str = *it;
    		for(int i = 0;i < str.size();i++) {
    			if(str[i] == 'X')
    				xCout++;
    			if(str[i] == 'O')
    				oCout++;
			}
		}
//		cout << xCout << endl;
//		cout << oCout << endl;
//		PrintBool(win(board,'O'));
		if(xCout < oCout) 
			return false;
		if(xCout - oCout > 1) 
			return false;
		
		if(win(board,'X') && xCout != (oCout + 1) )
			return false;
		if(win(board,'O') && xCout != oCout)
			return false;
		return true;
    }
    
    bool win(vector<string>& board,char p) {
//    	cout << board[0][2] << endl;
//    	cout << board[1][1] << endl;
//    	cout << board[2][0] << endl;
    	for(int i = 0;i < 3;i++)
    		if(board[i][0] == p && board[i][1] == p && board[i][2] == p)
    			return true;
    	for(int j = 0;j < 3;j++)
    		if(board[0][j] == p && board[1][j] == p && board[2][j] == p)
    			return true;
    	if(board[0][0] == p && board[1][1] == p && board[2][2] == p)
    		return true;
    	if(board[0][2] == p && board[1][1] == p && board[2][0] == p)
    		return true;
    	
    	return false;
	}
};


	
int main() {
	Solution solution;
	vector<string> board = {"XXO","XOX","OXO"};
	
	auto ans = solution.validTicTacToe(board);
	
	PrintBool(ans);
	
	return 0;
}



