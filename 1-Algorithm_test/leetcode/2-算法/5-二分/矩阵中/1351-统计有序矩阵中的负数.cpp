#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVVector(vector<vector<int>>& v){
	for(auto iter : v){
		auto it_tmp = iter;
		for(auto it : it_tmp)
			cout << it << " ";
		cout << endl;
	}
	cout << endl;
}

// class Solution {
// public:
// 	int n,m;
// 	int binay_search(vector<vector<int>>& grid){
// 		int l = 0,mid,r = n-1;
// 		while(l <= r){
// 			mid = l + (r - l)/2;
// 			// printf("%d %d %d %d\n",grid[mid][0],l,mid,r);
// 			if(grid[mid][0] == 0)
// 				return mid;
// 			else if(grid[mid][0] > 0)
// 				l = mid + 1;
// 			else
// 				r = mid - 1;
// 		}
// 		return r;
// 	}

// 	int binay_search2(vector<vector<int>>& grid,int i){
// 		int l = 0,mid,r = m-1;
// 		while(l <= r){
// 			mid = l + (r - l)/2;
// 			// printf("%d %d %d %d\n",grid[i][mid],l,mid,r);
// 			if(grid[i][mid] == 0)
// 				return mid;
// 			else if(grid[i][mid] > 0)
// 				l = mid + 1;
// 			else
// 				r = mid - 1;
// 		}
// 		return r;
// 	}

//     int countNegatives(vector<vector<int>>& grid) {
// 		n = grid.size();
// 		m = grid[0].size();
// 		int up = binay_search(grid);
// 		int ans = 0;
// 		// printf("\n");
// 		int hen;
// 		for(int i = 0;i <= up;i++){
// 			hen = binay_search2(grid,i);
// 			ans += hen + 1;
// 			// printf("%d %d\n",hen,ans);
// 		}
// 		return m*n - ans;
//     }
// };



// class Solution {
// public:
// 	int n,m;
// 	int binay_search2(vector<vector<int>>& grid,int i){
// 		int l = 0,mid,r = m-1;
// 		int pos = -1;
// 		while(l <= r){
// 			mid = l + (r - l)/2;
// 			// printf("%d %d %d %d\n",grid[i][mid],l,mid,r);
// 			if(grid[i][mid] < 0){
// 				pos = mid;
// 				r = mid - 1;
// 			}
// 			else
// 				l = mid + 1;
// 		}
// 		return pos;
// 	}

//     int countNegatives(vector<vector<int>>& grid) {
// 		n = grid.size();
// 		m = grid[0].size();
// 		int ans = 0;
// 		// printf("\n");
// 		int hen;
// 		for(int i = 0;i < n;i++){
// 			hen = binay_search2(grid,i);
// 			if(hen > 0)
// 				ans += hen;
// 			else if(hen == -1)
// 				ans += m;
// 			// printf("%d %d\n",hen,ans);
// 		}
// 		return m*n - ans;
//     }
// };



class Solution {
public:
	int n,m;
	int binay_search(vector<vector<int>>& grid){
		int l = 0,mid,r = n-1;
		while(l <= r){
			mid = l + (r - l)/2;
			// printf("%d %d %d %d\n",grid[mid][0],l,mid,r);
			if(grid[mid][0] == 0)
				return mid;
			else if(grid[mid][0] > 0)
				l = mid + 1;
			else
				r = mid - 1;
		}
		return r;
	}
	int binay_search2(vector<vector<int>>& grid,int i){
		int l = 0,mid,r = m-1;
		int pos = -1;
		while(l <= r){
			mid = l + (r - l)/2;
			// printf("%d %d %d %d\n",grid[i][mid],l,mid,r);
			if(grid[i][mid] < 0){
				pos = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		return pos;
	}

    int countNegatives(vector<vector<int>>& grid) {
		n = grid.size();
		m = grid[0].size();
		int ans = 0;
		int up = binay_search(grid);
		// printf("\n");
		int hen;
		for(int i = 0;i <= up;i++){
			hen = binay_search2(grid,i);
			if(hen > 0)
				ans += hen;
			else if(hen == -1)
				ans += m;
			// printf("%d %d\n",hen,ans);
		}
		return m*n - ans;
    }
};



int main(){
	Solution sol;
	// vector<vector<int>> grid = {	{4,3,2,-1},
	// 								{3,2,1,-1},
	// 								{1,1,-1,-2},
	// 								{-1,-1,-2,-3}};
	vector<vector<int>> grid = {	{3,2},
									{1,0}};								
	// vector<vector<int>> grid = {	{4,3,2,-1},
	// 								{3,2,1,-1},
	// 								{1,1,-1,-2},
	// 								{-1,-1,-2,-3},
	// 								{-1,-3,-4,-5}};
	
	PrintVVector(grid);

	auto ans = sol.countNegatives(grid);
	
	cout << ans <<endl;
	return 0;
}
