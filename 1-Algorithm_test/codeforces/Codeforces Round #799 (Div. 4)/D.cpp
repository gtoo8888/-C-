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
#ifdef LOCAL  
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++){
		string all_time;
		int x;
		cin >> all_time >> x;
		// scanf("%s %d",all_time,x);
		cout << all_time << " " << x << endl;
		int HH,MM;
		HH = (all_time[0]-'0')*10 + (all_time[1]-'0');
		MM = (all_time[3]-'0')*10 + (all_time[4]-'0');
		printf("%d %d\n",HH,MM);
		int add_HH = x/60;
		int add_MM = x%60;
		printf("%d %d\n",add_HH,add_MM);
		vector<int> HH_all;
		vector<int> MM_all;
		HH_all.push_back(HH);
		MM_all.push_back(MM);
		if(add_HH != 0 && add_MM == 0){
			int now_HH = HH,now_MM = MM;
			while(now_HH > 24){
				now_HH += add_HH;
				HH_all.push_back(now_HH);
			}
		}
		PrintVector(HH_all);
		PrintVector(MM_all);
    }	
	return 0;
}




