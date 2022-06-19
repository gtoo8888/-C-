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
    int n,m;
    scanf("%d %d",&m,&n);
    vector<int> shuzi(n);
    for(int i = 0;i < n;i++){
        scanf("%d ",&shuzi[i]);
	}
	vector<int> huochai = {0,2,5,5,4,5,6,3,7,6};
	PrintVector(shuzi);

	vector<int> ans_num;
	while(m > 0){
		
	}

	

	return 0;
}



