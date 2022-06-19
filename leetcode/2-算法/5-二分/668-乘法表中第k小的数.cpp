#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;


void PrintVVector(vector<vector<int>>& v){
	for(auto iter : v){
		auto it_tmp = iter;
		for(auto it : it_tmp)
			printf("%2d ",it);
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
		int l = 1,r = m*n;
		while(l < r){
			int mid = l + (r - l)/2;
			int count = mid / n*n;
			// printf("count:%d l:%d mid:%d r:%d\n",count,l,mid,r);
			// printf("mid/n+1:%d m:%d n:%d\n", mid/n+1,m,n);
			for(int i = mid/n + 1;i <= m;i++){
				count += mid/i;
			}
			// printf("count:%d\n\n",count);
			if(count >= k)
				r = mid;
			else	
				l = mid + 1;
		}
		return l;
    }
};

void create_table(int m,int n){
	vector<vector<int>> vec(m+1,vector<int>(n+1,0));
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			vec[i][j] = i*j;
		}
	}
	PrintVVector(vec);
}

int main(){
	Solution sol;
	int m = 6,n = 5,k = 15;

	// create_table(m,n);
	
	auto ans = sol.findKthNumber(m,n,k);
	
	cout << ans <<endl;
	return 0;
}
