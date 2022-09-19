#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVSector(vector<string> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << endl;
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


int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,1,-1};
int main() {
	int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++){
		int n,m;
		scanf("%d %d",&n,&m);
		vector<vector<int>> grid(n,vector<int>(m,0));
		rep(i,n){
			rep(j,m)
			scanf("%d",&grid[i][j]);
		}
		int ans = 0;
		rep(i,n){
			rep(j,m){
				int sum = grid[i][j];
				for(int k = 0;k < 4;k++){
					int ndx = i + dx[k];
					int ndy = j + dy[k];
					// printf("%d %d\n",ndx,ndy);
					while(ndx >= 0 && ndy >= 0 && ndx < n && ndy < m){
						// printf("%d %d\n",ndx,ndy);
						sum += grid[ndx][ndy];
						ndx += dx[k];
					 	ndy += dy[k];
					}
				}
				ans = sum > ans ? sum : ans;
				// printf("\n%d\n",sum);
			}
			
		}
		printf("%d\n",ans);
    }	
	return 0;
}




