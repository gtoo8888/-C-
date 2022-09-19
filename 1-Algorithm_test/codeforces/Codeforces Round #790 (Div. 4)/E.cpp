#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVSector(vector<string> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << endl;
	cout << endl; 
}

void PrintVVector(vector<vector<int>>& v){
	for(auto iter : v){
		auto it_tmp = iter;
		for(auto it : it_tmp)
			cout << it << " ";
		cout << endl;
	}
	cout << endl;
}


int main() {
	int t;
    scanf("%d",&t);
    while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		vector<int> a(n);
		rep(i,n)
			scanf("%d",&a[i]);
		vector<int> b = a;
		sort(b.begin(),b.end());
		sort(a.begin(),a.end(),greater<int>());
		int max_a = *max_element(a.begin(),a.end());   
		PrintVector(a);PrintVector(b);
		int can_sum = 0;
		rep(i,n)
			can_sum += a[i];
		printf("%d %d\n",can_sum,max_a);
		while(m--){
			int x;
			scanf("%d",&x);
			if(x > can_sum)
				printf("-1\n");
			else if(x > max_a){
				int can_num = 0;
				int i = 0;
				while(x > 0){
					x -= a[i++];
					can_num++;
				}
				printf("%d\n",can_num);
			}else{
				int can_num = 0;
				while(x > 0){
					auto upper = upper_bound(b.begin(),b.end(),4);
					int now_can = b[upper-b.begin()];
					printf("low:%d\n",upper-b.begin());
					x -= now_can;
					can_num++;
				}
				printf("%d\n",can_num);
			}
		}
		
    }	
	return 0;
}




