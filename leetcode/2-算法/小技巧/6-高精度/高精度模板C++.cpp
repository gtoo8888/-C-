#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


const int L=100005;
string add(string a,string b)//只限两个非负整数相加
{
    string ans;
    int na[L]={0},nb[L]={0};
    int la=a.size(),lb=b.size();
    for(int i=0;i<la;i++) na[la-1-i]=a[i]-'0';
    for(int i=0;i<lb;i++) nb[lb-1-i]=b[i]-'0';
    int lmax=la>lb?la:lb;
    for(int i=0;i<lmax;i++) na[i]+=nb[i],na[i+1]+=na[i]/10,na[i]%=10;
    if(na[lmax]) lmax++;
    for(int i=lmax-1;i>=0;i--) ans+=na[i]+'0';
    return ans;
}


string sub(string a,string b)//只限大的非负整数减小的非负整数
{
    string ans;
    int na[L]={0},nb[L]={0};
    int la=a.size(),lb=b.size();
    for(int i=0;i<la;i++) na[la-1-i]=a[i]-'0';
    for(int i=0;i<lb;i++) nb[lb-1-i]=b[i]-'0';
    int lmax=la>lb?la:lb;
    for(int i=0;i<lmax;i++)
    {
        na[i]-=nb[i];
        if(na[i]<0) na[i]+=10,na[i+1]--;
    }
    while(!na[--lmax]&&lmax>0)  ;lmax++;
    for(int i=lmax-1;i>=0;i--) ans+=na[i]+'0';
    return ans;
}


int a[L];
string fac(int n)
{
    string ans;
    if(n==0) return "1";
    fill(a,a+L,0);
    int s=0,m=n;
    while(m) a[++s]=m%10,m/=10;
    for(int i=n-1;i>=2;i--)
    {
        int w=0;
        for(int j=1;j<=s;j++) a[j]=a[j]*i+w,w=a[j]/10,a[j]=a[j]%10;
        while(w) a[++s]=w%10,w/=10;
    }
    while(!a[s]) s--;
    while(s>=1) ans+=a[s--]+'0';
    return ans;
}


string mul(string a,string b)//高精度乘法a,b,均为非负整数
{
    string s;
    int na[L],nb[L],nc[L],La=a.size(),Lb=b.size();//na存储被乘数，nb存储乘数，nc存储积
    fill(na,na+L,0);fill(nb,nb+L,0);fill(nc,nc+L,0);//将na,nb,nc都置为0
    for(int i=La-1;i>=0;i--) na[La-i]=a[i]-'0';//将字符串表示的大整形数转成i整形数组表示的大整形数
    for(int i=Lb-1;i>=0;i--) nb[Lb-i]=b[i]-'0';
    for(int i=1;i<=La;i++)
        for(int j=1;j<=Lb;j++)
        nc[i+j-1]+=na[i]*nb[j];//a的第i位乘以b的第j位为积的第i+j-1位（先不考虑进位）
    for(int i=1;i<=La+Lb;i++)
        nc[i+1]+=nc[i]/10,nc[i]%=10;//统一处理进位
    if(nc[La+Lb]) s+=nc[La+Lb]+'0';//判断第i+j位上的数字是不是0
    for(int i=La+Lb-1;i>=1;i--)
        s+=nc[i]+'0';//将整形数组转成字符串
    return s;
}


// 5.高精度取模
// 1）高精度对高精度取模(以在高精度除高精度中实现，此处不再赘述)
// 2）高精度对单精度取模
// 传入参数约定：传入第一参数为string类型，第二个为int型，返回值为string类型
// 算法思想：利用(a+b)%c=a%c+b%c。
// 算法复杂度：o(n)
int mod(string a,int b)//高精度a除以单精度b
{
    int d=0;
    for(int i=0;i<a.size();i++) d=(d*10+(a[i]-'0'))%b;//求出余数
    return d;
}


// 9.高精度进制转换
// 传入参数约定：传入第一个参数为string类型，第二第三均为int型，返回值为string类型

// 算法思想：模拟手工进制转换。

// 算法复杂度：o(n^2)。
bool judge(string s)//判断串是否为全零串
{
    for(int i=0;i<s.size();i++)
        if(s[i]!='0') return 1;
    return 0;
}
string solve(string s,int n,int m)//n进制转m进制只限0-9进制，若涉及带字母的进制，稍作修改即可
{
    string r,ans;
    int d=0;
    if(!judge(s)) return "0";//特判
    while(judge(s))//被除数不为0则继续
    {
        for(int i=0;i<s.size();i++)
        {
            r+=(d*n+s[i]-'0')/m+'0';//求出商
            d=(d*n+(s[i]-'0'))%m;//求出余数
        }
       s=r;//把商赋给下一次的被除数
       r="";//把商清空
        ans+=d+'0';//加上进制转换后数字
        d=0;//清空余数
    }
    reverse(ans.begin(),ans.end());//倒置下
    return ans;
}


int main() {

    string a = "213151543563";
    string b = "23";

    string addstring = add(a,b);
    cout << addstring << endl;

    string substring = sub(a,b);
    cout << substring << endl;

    string mulstring = mul(a,b);
    cout << mulstring << endl;

    string facstring = fac(100);
    cout << facstring << endl;

    string aa = "12314";
    int bb = 10;
    int modstring = mod(aa,bb);
    cout<< modstring <<endl;

    string solvestring = "10000000000";
    cout<< solve(solvestring,10,2) <<endl;
	
	return 0;
}



