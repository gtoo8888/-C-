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
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> xi(n);
	vector<int> yi(n);
    for(int i = 0;i < n;i++){
        scanf("%d %d",&xi[i],&yi[i]);
	}
	unordered_map<int,int> map;
    for(int i = 0;i < n;i++){
        map[xi[i]] = yi[i];
	}

	PrintVector(xi);
	PrintVector(yi);
	
	PrintMap(map);

	

	return 0;
}



