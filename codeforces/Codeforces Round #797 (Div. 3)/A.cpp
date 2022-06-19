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
#ifdef LOCAL  // 这LOCAL已经在vscode配置里面定义了
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++){
		int n;
		scanf("%d",&n);
		int h2;
		int h1 = n/3+1;
		int h3 = n/3-1;
		// printf("%d\n",n%3);
		if(n%3 == 0)
			h2 = h1-1;	// 做中间的平衡值
		else if(n%3 == 1)
			h2 = h1-1,h1++;	// 因为多了1，所以最大的可以加一个
		else if(n%3 == 2)
			h2 = h1,h1++;	// 多了2，最大的最大，第二大都加一
		printf("%d %d %d\n",h2,h1,h3);

    }	
	return 0;
}




