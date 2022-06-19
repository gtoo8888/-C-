#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

int main() {
	int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++){
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		for(int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		int it2 = *min_element(a.begin(),a.end());  
		int ans = 0;
		for(int i = 0;i < n;i++)
			ans += abs(a[i] - it2);
		printf("%d\n",ans);
    }	
	return 0;
}




