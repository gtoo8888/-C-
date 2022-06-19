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
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
//		printf("%d %d %d %d",a,b,c,d);
		int ans = 0;
		if(b > a) ans++;
		if(c > a) ans++;
		if(d > a) ans++;
		printf("%d\n",ans);
    }	
	return 0;
}




