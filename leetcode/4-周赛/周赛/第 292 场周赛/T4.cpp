#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
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

void PrintQueue(stack<char> st){
	while(!st.empty()){
		printf("%c ",st.top());
		st.pop();
	}
	cout << endl; 
}

class Solution {
public:
    int n,m;
    stack<char> st;
    bool flag = false;
    
    void dfs(vector<vector<char>>& grid,int x,int y,vector<vector<char>>& visit){
        if(x < 0 || y < 0 || x >= n || y >= m || visit[x][y] == '1'){
            if(x == n-1 && y == m-1 && st.empty())
                flag = true;
            return;
        }
        visit[x][y] = '1';
        PrintVVector(visit);
        if(grid[x][y] == '(')
            st.push(grid[x][y]);
        else   
            st.pop();
        printf("%d %d %c\n",x,y,grid[x][y]);
        PrintQueue(st);
        dfs(grid,x-1,y,visit);
        dfs(grid,x+1,y,visit);
        dfs(grid,x,y-1,visit);
        dfs(grid,x,y+1,visit);
    }


    bool hasValidPath(vector<vector<char>>& grid) {
        PrintVVector(grid);
        vector<vector<char>> visit = grid;
        n = grid.size();
        m = grid[0].size();
        dfs(grid,0,0,visit);
        return flag;
    }
};



	
int main() {
	Solution solution;
    vector<vector<char>> grid = {   {'(','(','('},
                                    {')','(',')'},
                                    {'(','(',')'},
                                    {'(','(',')'}};

    auto ans = solution.hasValidPath(grid);

	PrintBool(ans);
	return 0;
}




