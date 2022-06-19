#include <iostream> 
#include <vector> 
#include <pri>
using namespace std;




int main(){
	Solution solution;
	vector<vector<char>> grid = {
								  {'1','1','0','0','0'},
								  {'1','1','0','0','0'},
								  {'1','0','1','0','0'},
								  {'0','0','0','1','1'}
								};

	auto ans = solution.numIslands(grid);
	
	cout << ans << endl;


	return 0;
}



