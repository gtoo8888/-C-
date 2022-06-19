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


#define LOCAL

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
		vector<int> a(n);
		vector<int> b(n);
		vector<int> c(n);
		for(int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		for(int i = 0;i < n;i++)
			scanf("%d",&b[i]);
		rep(i,0,n){
			c[i] = a[i] - b[i];
		}
		// PrintVector(c);
		int flag_num = -1;
		rep(i,0,n){
			if(c[i] != 0){
				flag_num = c[i];
				break;
			}
		}
		bool yes = true;
		rep(i,0,n){
			if(c[i] < 0){
				printf("NO\n");yes = false;
				break;
			}
			if(c[i] != flag_num){
				// printf("%d %d %d\n",c[i],flag_num,b[i]);
				if(b[i] == 0){
					if(c[i] == a[i])
						break;
				}
				else{
					printf("NO\n");yes = false;
					break;
				}
			}
			
		}
		if(yes)
			printf("YES\n");
    }	
	return 0;
}




