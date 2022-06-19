#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <bits/stdc++.h>>
using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;


/*
    |��������|
    |Ҫ��������|
    |16/11/05ztx, thanks to wangxiaocai|
*/

//  leftΪ�ʼԪ��, right��ĩβԪ�ص���һ������x��Ҫ�ҵ���
int bsearch(int *A, int left, int right, int x){
    int m;
    while (left < right){
        m = left + (right - left) / 2;
        if (A[m] >= x)  right = m;   else left = m + 1;    
        // ���Ҫ�滻Ϊ upper_bound, ��Ϊ:if (A[m] <= v) x = m+1; else y = m;     
    }
    return left;
}

/*
    ���left == right  

    ���û���ҵ�135577��6������7  

    ������ж��ٵ�x��������lower_bound����һ�飬upper_bound����һ�飬�±����  

    C++�Դ���lower_bound(a,a+n,x)�������������һ��x����һ�����ĵ�ַ 

    upper_bound(a,a+n,x)���������е�һ��x�ĵ�ַ

    ���a+n��û���ҵ�x��x����һ����ַ������a+n�ĵ�ַ  

    lower_bound(a,a+n,x��-upper_bound(a,a+n,x)����������x�ĸ���
*/ 




// ���ݽṹ
// ���鼯
// 8.���鼯


/*
    |�ϲ��ڵ����|
    |16/11/05ztx, thanks to chaixiaojun|
*/

int father[maxn];   //  ����i��father���ڵ�  

void makeSet() {  
    for (int i = 0; i < maxn; i++)   
        father[i] = i;  
}  

int findRoot(int x) {   //  �����Ҹ��ڵ�
    int root = x; // ���ڵ�  
    while (root != father[root]) { // Ѱ�Ҹ��ڵ�  
        root = father[root];  
    }  
    while (x != root) {  
        int tmp = father[x];  
        father[x] = root; // ���ڵ㸳ֵ  
        x = tmp;  
    }  
    return root;  
}  

void Union(int x, int y) {  //  ��x���ڵļ��Ϻ�y���ڵļ������������γ�һ�����ϡ�  
    int a, b;  
    a = findRoot(x);  
    b = findRoot(y);  
    father[a] = b;  // y����x�ĸ��ڵ���   ��father[b] = aΪx����y�ĸ��ڵ��ϣ�  
}  

/*
    ��findRoot(x)�У�
    ·��ѹ�� ���� ���Ű�
    �ؼ�������·���ϵ�ÿ���ڵ㶼����ֱ�����ӵ�����
*/



/*
    |Kruskal�㷨|
    |������ ϡ��ͼ ����С������|
    |16/11/05ztx thanks to wangqiqi|
*/

/*
    ��һ�����㡢�ߡ�����vector�������б߰���С��������
    �ڶ��������鼯���� + �����code
*/

void Kruskal() {    
    ans = 0;    
    for (int i = 0; i<len; i++) {    
        if (Find(edge[i].a) != Find(edge[i].b)) {    
            Union(edge[i].a, edge[i].b);    
            ans += edge[i].len;    
        }    
    }    
}    



/*
    |Prim�㷨|
    |������ ����ͼ ����С������|
    |���Ż��棬ʱ�临�Ӷȣ�O(elgn)|
    |16/11/05ztx, thanks to chaixiaojun|
*/

struct node {  
    int v, len;  
    node(int v = 0, int len = 0) :v(v), len(len) {}  
    bool operator < (const node &a)const {  // ������е�Ԫ���Զ��������С��������  
        return len> a.len;  
    }  
};

vector<node> G[maxn];
int vis[maxn];
int dis[maxn];

void init() {  
    for (int i = 0; i<maxn; i++) {  
        G[i].clear();  
        dis[i] = INF;  
        vis[i] = false;  
    }  
}  
int Prim(int s) {  
    priority_queue<node>Q; // �������ȶ���  
    int ans = 0;  
    Q.push(node(s,0));  // ���������  
    while (!Q.empty()) {   
        node now = Q.top(); Q.pop();  // ȡ��������С�ĵ�  
        int v = now.v;  
        if (vis[v]) continue;  // ͬһ���ڵ㣬���ܻ�����2�λ�2�����϶��У�������һ������Ǻ�ʣ�µ���Ҫֱ��������  
        vis[v] = true;  // ���һ��  
        ans += now.len;  
        for (int i = 0; i<G[v].size(); i++) {  // ��ʼ����  
            int v2 = G[v][i].v;  
            int len = G[v][i].len;  
            if (!vis[v2] && dis[v2] > len) {   
                dis[v2] = len;  
                Q.push(node(v2, dis[v2]));  // ���µĵ������в�����  
            }  
        }  
    }  
    return ans; 
}  





/*
    |Dijkstra�㷨|
    |�����ڱ�ȨΪ��������ͼ��������ͼ|
    |��ӵ���Դ������������нڵ�����·|
    |�Ż��棺ʱ�临�Ӷ� O(elbn)|
    |16/11/05ztx, thanks to chaixiaojun|
*/

struct node {  
    int v, len;  
    node(int v = 0, int len = 0) :v(v), len(len) {}  
    bool operator < (const node &a)const {  //  �����С��������  
        return len > a.len;  
    }  
};  

vector<node>G[maxn];  
bool vis[maxn];  
int dis[maxn];

void init() {  
    for (int i = 0; i<maxn; i++) {  
        G[i].clear();  
        vis[i] = false;  
        dis[i] = INF;  
    }  
}  
int dijkstra(int s, int e) {  
    priority_queue<node>Q;  
    Q.push(node(s, 0)); //  ������в�����  
    dis[s] = 0;  
    while (!Q.empty()) {  
        node now = Q.top();     //  ȡ����ǰ��С��  
        Q.pop();  
        int v = now.v;  
        if (vis[v]) continue;   //  �����ǹ���, ֱ��continue  
        vis[v] = true;  
        for (int i = 0; i<G[v].size(); i++) {   //  ����  
            int v2 = G[v][i].v;  
            int len = G[v][i].len;  
            if (!vis[v2] && dis[v2] > dis[v] + len) {  
                dis[v2] = dis[v] + len;  
                Q.push(node(v2, dis[v2]));  
            }  
        }  
    }  
    return dis[e];  
}  





/*
    |SPFA�㷨|
    |�����Ż�|
    |�ɴ�����|
*/

vector<node> G[maxn];
bool inqueue[maxn];
int dist[maxn];

void Init()  
{  
    for(int i = 0 ; i < maxn ; ++i){  
        G[i].clear();  
        dist[i] = INF;  
    }  
}  
int SPFA(int s,int e)  
{  
    int v1,v2,weight;  
    queue<int> Q;  
    memset(inqueue,false,sizeof(inqueue)); // ����Ƿ��ڶ�����  
    memset(cnt,0,sizeof(cnt)); // ������еĴ���  
    dist[s] = 0;  
    Q.push(s); // ���������  
    inqueue[s] = true; // ���  
    while(!Q.empty()){  
        v1 = Q.front();  
        Q.pop();  
        inqueue[v1] = false; // ȡ�����  
        for(int i = 0 ; i < G[v1].size() ; ++i){ // ����v1������  
            v2 = G[v1][i].vex;  
            weight = G[v1][i].weight;  
            if(dist[v2] > dist[v1] + weight){ // �ɳڲ���  
                dist[v2] = dist[v1] + weight;  
                if(inqueue[v2] == false){  // �ٴμ������  
                    inqueue[v2] = true;  
                    //cnt[v2]++;  // �и���  
                    //if(cnt[v2] > n) return -1;  
                    Q.push(v2);  
                } } }  
    }  
    return dist[e];  
}

/*
    ���ϵĽ�s���ڽӵ������У�ȡ�����ϵĽ����ɳڲ�����ֱ������Ϊ��  

    ���һ����㱻������г���n-1�Σ���ô��Ȼͼ���и���  
*/


/*
    |SPFA�㷨|
    |�����Ż�|
    |�ɴ�����|
*/

vector<node> G[maxn];
bool inqueue[maxn];
int dist[maxn];

void Init()  
{  
    for(int i = 0 ; i < maxn ; ++i){  
        G[i].clear();  
        dist[i] = INF;  
    }  
}  
int SPFA(int s,int e)  
{  
    int v1,v2,weight;  
    queue<int> Q;  
    memset(inqueue,false,sizeof(inqueue)); // ����Ƿ��ڶ�����  
    memset(cnt,0,sizeof(cnt)); // ������еĴ���  
    dist[s] = 0;  
    Q.push(s); // ���������  
    inqueue[s] = true; // ���  
    while(!Q.empty()){  
        v1 = Q.front();  
        Q.pop();  
        inqueue[v1] = false; // ȡ�����  
        for(int i = 0 ; i < G[v1].size() ; ++i){ // ����v1������  
            v2 = G[v1][i].vex;  
            weight = G[v1][i].weight;  
            if(dist[v2] > dist[v1] + weight){ // �ɳڲ���  
                dist[v2] = dist[v1] + weight;  
                if(inqueue[v2] == false){  // �ٴμ������  
                    inqueue[v2] = true;  
                    //cnt[v2]++;  // �и���  
                    //if(cnt[v2] > n) return -1;  
                    Q.push(v2);  
                } } }  
    }  
    return dist[e];  
}

/*
    ���ϵĽ�s���ڽӵ������У�ȡ�����ϵĽ����ɳڲ�����ֱ������Ϊ��  

    ���һ����㱻������г���n-1�Σ���ô��Ȼͼ���и���  
*/



/*
    |01����|
    |��ȫ����|
    |���ر���|
    |16/11/05ztx|
*/

//  01������  

void bag01(int cost,int weight)  {  
    for(i = v; i >= cost; --i)  
    dp[i] = max(dp[i], dp[i-cost]+weight);  
}  

//  ��ȫ������  

void complete(int cost, int weight)  {  
    for(i = cost ; i <= v; ++i)  
    dp[i] = max(dp[i], dp[i - cost] + weight);  
}  

//  ���ر�����  

void multiply(int cost, int weight, int amount)  {  
    if(cost * amount >= v)  
        complete(cost, weight);  
    else{  
        k = 1;  
        while (k < amount){  
            bag01(k * cost, k * weight);  
            amount -= k;  
            k += k;  
        }  
        bag01(cost * amount, weight * amount);  
    }  
}  


// other

int dp[1000000];
int c[55], m[110];
int sum;

void CompletePack(int c) {
    for (int v = c; v <= sum / 2; ++v){
        dp[v] = max(dp[v], dp[v - c] + c);
    }
}

void ZeroOnePack(int c) {
    for (int v = sum / 2; v >= c; --v) {
        dp[v] = max(dp[v], dp[v - c] + c);
    }
}

void multiplePack(int c, int m�� {
    if (m * c > sum / 2)
        CompletePack(c);
    else{
        int k = 1;
        while (k < m){
            ZeroOnePack(k * c);
            m -= k;
            k <<= 1;
        }
        if (m != 0){
            ZeroOnePack(m * c);
        }
    }
}


/*
    |kmp�㷨|
    |�ַ���ƥ��|
    |17/1/21ztx|
*/

void getnext(char str[maxn], int nextt[maxn]) {
    int j = 0, k = -1;
    nextt[0] = -1;
    while (j < m) {
        if (k == -1 || str[j] == str[k]) {
            j++;
            k++;
            nextt[j] = k;
        }
        else
            k = nextt[k];
    }
}

void kmp(int a[maxn], int b[maxn]) {    
    int nextt[maxm];    
    int i = 0, j = 0;    
    getnext(b, nextt);    
    while (i < n) {    
        if (j == -1 || a[i] == b[j]) { // ĸ���������Ӵ��ƶ�    
            j++;    
            i++;    
        }    
        else {    
            // i����Ҫ������    
            // i = i - j + 1;    
            j = nextt[j];    
        }    
        if (j == m) {    
            printf("%d\n", i - m + 1); // ĸ����λ�ü�ȥ�Ӵ��ĳ���+1    
            return;    
        }    
    }    
    printf("-1\n");
}    






/*
    |��ʽɸ��|
    |����ɸѡ����|
    |16/11/05ztx|
*/

int prime[maxn];  
bool is_prime[maxn];

int sieve(int n){
    int p = 0;
    for(int i = 0; i <= n; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i){   //  ע�������С��n
        if(is_prime[i]){
            prime[p++] = i;
            for(int j = i + i; j <= n; j += i)  //  ���֦��j�ض���i�ı���
                is_prime[j] = false;
        }
    }
    return p;   //  ������������
}




/*
    |������|
    |16/11/05ztx|
*/

typedef long long LL;   //  �����ݴ�С���������

LL powerMod(LL x, LL n, LL m)
{
    LL res = 1;
    while (n > 0){
        if  (n & 1) //  �ж��Ƿ�Ϊ������������true
            res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;    //  �൱��n /= 2;
    }
    return res;
}


/*
    |����ģ��ӷ�|
    |��stringģ��|
    |16/11/05ztx, thanks to caojiji|
*/

string add1(string s1, string s2)
{
    if (s1 == "" && s2 == "")   return "0";
    if (s1 == "")   return s2;
    if (s2 == "")   return s1;
    string maxx = s1, minn = s2;
    if (s1.length() < s2.length()){
        maxx = s2;
        minn = s1;
    }
    int a = maxx.length() - 1, b = minn.length() - 1;
    for (int i = b; i >= 0; --i){
        maxx[a--] += minn[i] - '0'; //  aһֱ�ڼ� �� ���⻹Ҫ����'0'
    }
    for (int i = maxx.length()-1; i > 0;--i){
        if (maxx[i] > '9'){
            maxx[i] -= 10;//ע������Ǽ�10
            maxx[i - 1]++;
        }
    }
    if (maxx[0] > '9'){
        maxx[0] -= 10;
        maxx = '1' + maxx;
    }
    return maxx;
}



/*
    |����ģ��׳�|
    |������ģ��|
    |16/12/02ztx|
*/

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int maxn = 100010;

int num[maxn], len;

/*
    ��mult�����У��ββ��֣�lenÿ�ε��ú������ᷢ���ı䣬n��ʾÿ��Ҫ���Ե��������շ��ص��ǽ���ĳ���
    tip: �׳˶�������֮ǰ��(n-1)!����n!
    ��ʼ��Init��������Ҫ����Ҫ����
*/

void Init() {
    len = 1;
    num[0] = 1;
}

int mult(int num[], int len, int n) {
    LL tmp = 0;
    for(LL i = 0; i < len; ++i) {
         tmp = tmp + num[i] * n;    //�����λ��ʼ���Ⱥ���ߵ�tmp��ʾ��ǰλ���ұߵ�tmp��ʾ��λ��֮ǰ����λ��
         num[i] = tmp % 10; //  �����ڶ�Ӧ������λ�ã���ȥ����λ���һλ��
         tmp = tmp / 10;    //  ȡ�������ٴ�ѭ��,��n����һ��λ�õĳ˻����
    }
    while(tmp) {    //  ֮��Ľ�λ����
         num[len++] = tmp % 10;
         tmp = tmp / 10;
    }
    return len;
}

int main() {
    Init();
    int n;
    n = 1977; // ��Ľ׳���
    for(int i = 2; i <= n; ++i) {
        len = mult(num, len, i);
    }
    for(int i = len - 1; i >= 0; --i)
        printf("%d",num[i]);    //  �����λ�������,���ݱȽ϶����printf���
    printf("\n");
    return 0;
}




/*
    |շת�����|
    |ŷ������㷨|
    |�����Լ��|
    |16/11/05ztx|
*/

int gcd(int big, int small)
{
    if (small > big) swap(big, small);
    int temp;
    while (small != 0){ //  շת�����
        if (small > big) swap(big, small);
        temp = big % small;
        big = small;
        small = temp;
    }
    return(big);
}


/*
    |շת�����|
    |ŷ������㷨|
    |����С������|
    |16/11/05ztx|
*/

int gcd(int big, int small)
{
    if (small > big) swap(big, small);
    int temp;
    while (small != 0){ //  շת�����
        if (small > big) swap(big, small);
        temp = big % small;
        big = small;
        small = temp;
    }
    return(big);
}



/*
    |��1��n��ȫ����, ������|
    |16/11/05ztx, thanks to wangqiqi|
*/

void Pern(int list[], int k, int n) {   //  k��ʾǰk�����������ƶ�����n-kλ��
    if (k == n - 1) {
        for (int i = 0; i < n; i++) {
            printf("%d", list[i]);
        }
        printf("\n");
    }else {
        for (int i = k; i < n; i++) {   //  ������������ƶ���������ȫ����
            swap(list[k], list[i]);
            Pern(list, k + 1, n);
            swap(list[k], list[i]);
        }
    }
}




































































































































































