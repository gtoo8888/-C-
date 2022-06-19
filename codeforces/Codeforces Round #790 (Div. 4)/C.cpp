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


int check(string a,string b){
	vector<string> v{a,b};
	int n = a.size();
	int ans = 0;
	
	rep(i,n){
		int char_min = INT_MAX,char_max = INT_MIN;
		rep(j,2){
			// cout << v[j][i] << endl;
			if(v[j][i] > char_max)
				char_max = v[j][i];
			if(v[j][i] < char_min)
				char_min = v[j][i];
		}
		int tmp = char_max - char_min;
		ans += tmp;
		// printf("%c %c %d %d\n",char_max,char_min,tmp,ans);
	}

	return ans;
}

int main() {
	int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++){
		int n,m;
		scanf("%d %d",&n,&m);
		vector<string> a(n);
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		// PrintVSector(a);
		int ans_min = INT_MAX;
		rep(i,n){
			for(int j = i+1; j < (n); j++){
				// cout << a[i] << " " << a[j] << endl;
				int tmp = check(a[i],a[j]);
				ans_min = tmp < ans_min ? tmp : ans_min;
			}
		}
		printf("%d\n",ans_min);
    }	
	return 0;
}




