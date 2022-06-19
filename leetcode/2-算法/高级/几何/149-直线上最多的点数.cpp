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

void PrintVVector(vector<vector<int>> v){
	for(auto iter = v.begin();iter != v.end();iter++){
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

void PrintUnorder_Map(unordered_map<double,int> m) {
	for(auto it : m)
		printf("%f %d\n",it.first,it.second);
	cout << endl;	
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double,int> map;
        int n = points.size();
        printf("%d\n",n);
        double save_k = 0;
        int ans =  0;
        for(int i = 0;i < n-1;i++){
            double yy = points[i+1][1] - points[i][1];
            double xx = points[i+1][0] - points[i][0];
            double kk = yy / xx;
			printf("%f %f %f\n",kk,yy,xx);
			map[kk]++;           
        }
		// PrintUnorder_Map(map);
        return ans;
    }
};



	
int main() {
	Solution solution;
	// vector<vector<int>> points =  {{1,1},{2,2},{3,3}};
	vector<vector<int>> points =  {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
	
	auto ans = solution.maxPoints(points);
	
	cout << ans << endl;
	
	return 0;
}



