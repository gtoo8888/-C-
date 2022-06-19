#include <iostream> 
#include <vector>
using namespace std;


void PrintVector(vector<char> v){
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
	int n,m;
	void dfs(vector<vector<int>>& image,int x,int y,int oldcolor,int newColor){
		if(x < 0 || y < 0 || x >= n || y >= m || image[x][y] != oldcolor || image[x][y] == newColor){
			return;
		}
		image[x][y] = newColor;
		// PrintVVector(image);
		dfs(image,x-1,y,oldcolor,newColor);
		dfs(image,x+1,y,oldcolor,newColor);
		dfs(image,x,y-1,oldcolor,newColor);
		dfs(image,x,y+1,oldcolor,newColor);
		return;
	}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		// PrintVVector(image);
		n = image.size();
		m = image[0].size();
		int oldcolor = image[sr][sc];
		if(oldcolor != newColor) 	// 就从当前的点dfs就可以了
			dfs(image,sr,sc,oldcolor,newColor);
		return image;
    }
};

int main(){
	Solution solution;
	vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
	int sr = 1;
	int sc = 1;
	int newColor = 2;	

	auto ans = solution.floodFill(image,sr,sc,newColor);
	
	PrintVVector(ans);
	
	return 0;
}














