#include <iostream>
#include <vector>
#include <algorithm>
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

class Solution {
public:
	double clc_area(int x1,int y1,int x2,int y2,int x3,int y3){
		 return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
	}
    double largestTriangleArea(vector<vector<int>>& points) {
		int n = points.size();
		double area = 0.0;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int k = j+1;k < n;k++){
					double tmp = clc_area(	points[i][0],points[i][1],
											points[j][0],points[j][1],
											points[k][0],points[k][1]);
					area = tmp > area ? tmp : area;
				}
			}
		}
		return area;
    }
};


	
int main() {
	Solution solution;
	vector<vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
	
	auto ans = solution.largestTriangleArea(points);
	
	cout << ans << endl;
	
	return 0;
}



