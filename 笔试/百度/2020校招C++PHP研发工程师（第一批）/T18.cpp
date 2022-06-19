#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

	
void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintMap(unordered_map<int,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> a(n);
    for(int i = 0;i < n;i++)
        scanf("%d ",&a[i]);

//    PrintVector(a);
	unordered_map<int,int>  m;
	for(int a_i : a){
		m[a_i]++;
	}
	
	int ans = 0;
	for(auto it = m.begin();it != m.end();it++) {
		int m1 = it->first,m2 = it->second;
		if(m2 % 2 == 1)
			ans += m2/2 + 1;
		else
			ans += m2/2;
	}
//	PrintMap(m);

	cout << ans << endl;
	return 0;
}



