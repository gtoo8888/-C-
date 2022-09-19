#include<bits/stdc++.h>
using namespace std;
long long n,a,b; 
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n*a;i++)
    {
        if(((i-1)/a)%2)
        {
            for(int j=1;j<=n*b;j++)
            {
                if(((j-1)/b)%2)
                {
                    cout<<'.';
                }
                else
                {
                    cout<<"#";
                }
            }
        }
        else
        {
            for(int j=1;j<=n*b;j++)
            {
                if(((j-1)/b)%2)
                {
                    cout<<'#';
                }
                else
                {
                    cout<<".";
                }
            }
        }
        cout<<endl;
    }
}