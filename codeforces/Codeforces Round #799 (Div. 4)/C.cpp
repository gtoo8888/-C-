#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define test_cout  cout << "!!!" << endl 
#define SZ(x) ((int)(x).size())
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef double db;
const ll mod=1000000007;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

void PrintVector(vector<int> v){for(auto it : v) cout << it << " ";cout << endl;}
void PrintVSector(vector<string> v){for(auto it : v)cout << it << endl;cout << endl;}
void PrintVVector(vector<vector<int>>& v){for(auto iter : v){auto it_tmp = iter;for(auto it : it_tmp)cout << it << " ";cout << endl;}cout << endl;}


// #define LOCAL

int main() {
#ifdef LOCAL  
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++){
		// char chessborad[8][8];
		// rep(i,0,8){
		// 	rep(j,0,8){
		// 		scanf("%c",&chessborad[i][j]);
		// 	}
		// }
		string chess[8];
		rep(i,0,8){
			cin >> chess[i];
		}
		// rep(i,0,8){
		// 	cout << chess[i] << endl;
		// }
		
		int col=0,row=0;
		vector<int> col_save(8);
		rep(i,0,8){
			int jinghao_num = 0;
			rep(j,0,8){
				if(chess[i][j] == '#')
					jinghao_num++;
			}
			col_save[i] = jinghao_num;
		}
		// PrintVector(col_save);
		rep(i,1,7){
			if(col_save[i-1] == 2 && col_save[i] == 1 && col_save[i+1] == 2)
				col = i;
		}
		vector<int> row_save(8);
		rep(i,0,8){
			int jinghao_num = 0;
			rep(j,0,8){
				if(chess[j][i] == '#')
					jinghao_num++;
			}
			row_save[i] = jinghao_num;
		}
		// PrintVector(row_save);
		rep(i,1,7){
			if(row_save[i-1] == 2 && row_save[i] == 1 && row_save[i+1] == 2)
				row = i;
		}
		printf("%d %d\n",col+1,row+1);
    }	
	return 0;
}




