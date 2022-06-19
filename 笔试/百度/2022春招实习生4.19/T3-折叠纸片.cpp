

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


void PrintVector(vector<int> &v) {
	for(auto it = v.begin();it != v.end();it++){
		cout << *it << " ";
	}
	cout << endl;
}


void PrintVV(vector<vector<int>> &v) {
	for(vector<vector<int>>::iterator it = v.begin();it != v.end();it++){
		vector<int> iter = *it;
		for(vector<int>::iterator iter = (*it).begin();iter != (*it).end();iter++){
			cout << *iter << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> zhezhi(n,vector<int>(n,0));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
//    		printf("[%d %d]",i,j);
        	scanf("%d",&zhezhi[i][j]);
        }
    }
    
//    PrintVV(zhezhi);    
    
    long long ans = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
			ans += zhezhi[i][j];
        }
    }
	printf("%ld",ans);

    
    return 0;
}


// ж╫ф╛╤туш
//4
//2 6 5 4
//1 5 7 6
//9 8 8 7
//1 4 7 8
//88

//2
//1 2
//3 4
//10
