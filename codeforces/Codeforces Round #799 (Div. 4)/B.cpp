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
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		rep(i,0,n){
			scanf("%d ",&a[i]);
		}
		int hash_map[10100] = {0};
		rep(i,0,n){
			hash_map[a[i]]++;
		}
		
		int now_len = 0;
		rep(i,0,10100){
			if(hash_map[i] != 0){
				now_len++;
			}
		}
		int sub_len = a.size() - now_len;
		// printf("%d %d %d\n",now_len,sub_len,a.size());
		if(sub_len%2 == 0)
			printf("%d\n",now_len);
		else
			printf("%d\n",now_len-1);
    }	
	return 0;
}




