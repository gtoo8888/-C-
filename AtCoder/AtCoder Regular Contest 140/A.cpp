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

int func_string(string str){
    string tmp = str;
    int n = str.size();
    char s1 = tmp[0];
    tmp.erase(0,1);
    tmp += s1;
    cout << tmp << endl;
    int change = 1;
    while(tmp != str){
        char s1 = tmp[0];
        tmp.erase(0,1);
        tmp += s1;
        cout << tmp << endl;
        change++;
    }
    return change;
}

int main() {

#ifdef LOCAL  // 这LOCAL已经在vscode配置里面定义了
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n,k;
    scanf("%d %d",&n,&k);
    string s;
    cin >> s;
    vector<int> hash_map(26);
    int n1 = s.size();
    rep(i,0,n1){
        hash_map[s[i] - 'a']++;
    }
    PrintVector(hash_map);
    func_string(s);
    // for(int i = 0;i < t;i++){

    // }	
	return 0;
}




