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

#define LOCAL

void PrintSet(multiset<int> s) {
	for(auto it : s)
		printf("%d ",it);
	cout << endl;	
}

void PrintUnorder_Map(unordered_map<int,int> m) {
	for(auto it : m)
		printf("%d %d\n",it.first,it.second);
	cout << endl;	
}

int main() {
#ifdef LOCAL  // 这LOCAL已经在vscode配置里面定义了
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
    scanf("%d",&n);
	vector<int> a(n);
    rep(i,0,n){
		scanf("%d",&a[i]);
	}
	PrintVector(a);
	unordered_map<int,int> map;
	int ans = 0;
	rep(i,0,n){
		map[a[i]]++;
		if(map[a[i]] > 1){
			map[a[i]]--;
			continue;
		}
		rep(j,i+1,n){
			map[a[j]]++;
			if(map[a[j]] > 1){
				map[a[j]]--;
				continue;
			}
			rep(k,j+1,n){
				map[a[k]]++;
				// PrintUnorder_Map(map);
				if(map[a[k]] > 1){
					map[a[k]]--;
					continue;
				}
				
				printf("%d %d %d\n",i,j,k);
				ans++;
				map.clear();
			}
		}
		
	}
	printf("%d\n",ans);
	return 0;
}




