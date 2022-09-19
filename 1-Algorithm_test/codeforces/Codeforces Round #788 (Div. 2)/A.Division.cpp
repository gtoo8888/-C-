#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
        PrintVector(a) ;
        int zhen = 0,fu = 0;
        
        for(int i = 0;i < n;i++){
        	if(a[i] > 0)
        		zhen++;
        	if(a[i] < 0)
        		fu++;
		}
		int zen = 0,jian = 0;
		vector<int> tmp = a;
		for(int i = 0;i < n;i++){
        	if(tmp[i] < 0)
        		tmp[i] = -tmp[i];
        	
		}
		PrintVector(tmp) ;
		for(int i = 0;i < n-1;i++){
        	if(tmp[i] > tmp[i+1])
        		jian++;
        	if(tmp[i] < tmp[i+1])
        		zen++;
		}
		printf("%d %d %d %d\n",zhen,fu,jian,zen);
        	
    }	
	return 0;
}




