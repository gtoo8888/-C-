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
    	int amax = INT32_MIN;
    	int amax_in = 0;
     	for(int j = 0;j < n;j++){
     		scanf("%d",&a[j]);
     		if(a[j] > amax){
     			amax = a[j];
     			amax_in = j;
     		}
		}
		PrintVector(a);
		printf("%d %d\n",amax,amax_in);
		a[amax_in] /=  2;
		
			
    }	
	return 0;
}




