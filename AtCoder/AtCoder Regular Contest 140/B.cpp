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
	int n;
    scanf("%d",&n);
	string s;
	cin >> s;
    int ans = 0;
	int change_num = 1;
	int i = 0;
	while(i < n-2){
		string str_tmp = s.substr(i,3);
		// cout << str_tmp << endl;
		if(str_tmp == "ARC"){
			ans++;
			if(change_num%2 == 1){
				s.erase(i,3);
				s.insert(i,"R");
				i = 0;
				n = s.size();
				change_num++;
			}
			else{
				s.erase(i,3);
				s.insert(i,"AC");
				i = 0;
				n = s.size();
				change_num++;
			}	
		}else
			i++;
		// printf("%d %d %d\n",i,n,change_num);
		cout << s << endl;
	}
	// cout << s << endl;
	printf("%d\n",ans);		
	

	return 0;
}




