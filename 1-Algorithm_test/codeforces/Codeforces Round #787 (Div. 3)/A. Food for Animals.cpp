#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

	
int main() {
	int t;
    scanf("%d",&t);

    for(int i = 0;i < t;i++){
        ll a,b,c,x,y;
        scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&x,&y);
        ll f_dog,f_cat,f_un;
        ll t_dog,t_cat;
        if(x > a){
        	f_dog = false;
        	t_dog = x-a;
		}
		else
			f_dog = true;
			
		if(y > b){
        	f_cat = false;
        	t_cat = y-b;
		}
		else
			f_cat = true;
		ll t3 = t_dog + t_cat;
//		printf("%d %d %d%d\n",t_dog,t_cat,t3,c);	
			
		if(!f_dog || !f_cat){
			if(t3 <= c)
				printf("YES\n");
			else
				printf("NO\n");
		}else
			printf("YES\n");
			
    }	
	return 0;
}




