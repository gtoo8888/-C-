#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
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

void PrintSet(multiset<int> s) {
	for(auto it : s)
		printf("%d ",it);
	cout << endl;	
}


int main() {
#ifdef LOCAL  // 这LOCAL已经在vscode配置里面定义了
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n,k;
    scanf("%d %d",&n,&k);
	vector<int> a(n);
	int b[k];
    rep(i,0,n){
		scanf("%d",&a[i]);
	}
	rep(i,0,k){
		scanf("%d",&b[i]);
	}
	int a_max = *max_element(a.begin(),a.end()); 
	multiset<int> s;
	rep(i,0,n){
		if(a[i] == a_max)
			s.insert(i+1);
	}
	// PrintSet(s);
	rep(i,0,k){
		if(s.find(b[i]) != s.end()){
			printf("Yes\n");
			return 0;
		}
	}
   	printf("No\n");
	return 0;
}




