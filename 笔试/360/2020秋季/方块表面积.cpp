#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


//leetcode 892. 三维形体的表面积
void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVVector(vector<vector<int>> v){
	for(auto iter = v.begin();iter != v.end();iter++){
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> res(n,vector<int>(m,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) {
            cin >> res[i][j] ;
        }
    }
	PrintVVector(res);
	int up_to_down = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) {
            if(res[i][j] != 0)
            	up_to_down++;
        }
    }
    up_to_down *= 2;
	
 	int front_to_back = 0;
    for(int i = 0;i < m;i++){
    	int max = INT32_MIN;
        for(int j = 0;j < n;j++) {
            if(res[j][i] > max)
            	max = res[j][i];
        }
        front_to_back += max;
    }

	front_to_back *= 2;
	
  
  	int left_to_right = 0;
    for(int i = 0;i < n;i++){
    	int max = INT32_MIN;
        for(int j = 0;j < m;j++) {
            if(res[i][j] > max)
            	max = res[i][j];
        }
        left_to_right += max;
    }
	left_to_right *= 2;
	
	
	printf("%d,%d,%d\n",up_to_down,front_to_back,left_to_right);
	
	int ans = up_to_down + front_to_back + left_to_right;
	printf("%d",ans);
	
	
	
	

    
	return 0;
}
