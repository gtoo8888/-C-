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
string add(string a,string b)//ֻ�������Ǹ��������
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


string sub(string a,string b)//ֻ�޴�ķǸ�������С�ķǸ�����
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


string mul(string a,string b)//�߾��ȳ˷�a,b,��Ϊ�Ǹ�����
{
    string s;
    int na[L],nb[L],nc[L],La=a.size(),Lb=b.size();//na�洢��������nb�洢������nc�洢��
    fill(na,na+L,0);fill(nb,nb+L,0);fill(nc,nc+L,0);//��na,nb,nc����Ϊ0
    for(int i=La-1;i>=0;i--) na[La-i]=a[i]-'0';//���ַ�����ʾ�Ĵ�������ת��i���������ʾ�Ĵ�������
    for(int i=Lb-1;i>=0;i--) nb[Lb-i]=b[i]-'0';
    for(int i=1;i<=La;i++)
        for(int j=1;j<=Lb;j++)
        nc[i+j-1]+=na[i]*nb[j];//a�ĵ�iλ����b�ĵ�jλΪ���ĵ�i+j-1λ���Ȳ����ǽ�λ��
    for(int i=1;i<=La+Lb;i++)
        nc[i+1]+=nc[i]/10,nc[i]%=10;//ͳһ�����λ
    if(nc[La+Lb]) s+=nc[La+Lb]+'0';//�жϵ�i+jλ�ϵ������ǲ���0
    for(int i=La+Lb-1;i>=1;i--)
        s+=nc[i]+'0';//����������ת���ַ���
    return s;
}


// 5.�߾���ȡģ
// 1���߾��ȶԸ߾���ȡģ(���ڸ߾��ȳ��߾�����ʵ�֣��˴�����׸��)
// 2���߾��ȶԵ�����ȡģ
// �������Լ���������һ����Ϊstring���ͣ��ڶ���Ϊint�ͣ�����ֵΪstring����
// �㷨˼�룺����(a+b)%c=a%c+b%c��
// �㷨���Ӷȣ�o(n)
int mod(string a,int b)//�߾���a���Ե�����b
{
    int d=0;
    for(int i=0;i<a.size();i++) d=(d*10+(a[i]-'0'))%b;//�������
    return d;
}


// 9.�߾��Ƚ���ת��
// �������Լ���������һ������Ϊstring���ͣ��ڶ�������Ϊint�ͣ�����ֵΪstring����

// �㷨˼�룺ģ���ֹ�����ת����

// �㷨���Ӷȣ�o(n^2)��
bool judge(string s)//�жϴ��Ƿ�Ϊȫ�㴮
{
    for(int i=0;i<s.size();i++)
        if(s[i]!='0') return 1;
    return 0;
}
string solve(string s,int n,int m)//n����תm����ֻ��0-9���ƣ����漰����ĸ�Ľ��ƣ������޸ļ���
{
    string r,ans;
    int d=0;
    if(!judge(s)) return "0";//����
    while(judge(s))//��������Ϊ0�����
    {
        for(int i=0;i<s.size();i++)
        {
            r+=(d*n+s[i]-'0')/m+'0';//�����
            d=(d*n+(s[i]-'0'))%m;//�������
        }
       s=r;//���̸�����һ�εı�����
       r="";//�������
        ans+=d+'0';//���Ͻ���ת��������
        d=0;//�������
    }
    reverse(ans.begin(),ans.end());//������
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



