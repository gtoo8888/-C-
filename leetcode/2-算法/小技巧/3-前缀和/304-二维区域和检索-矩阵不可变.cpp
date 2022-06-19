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

class NumArray {
public:
    vector<int> pre;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre.resize(n+1);
        for(int i = 0;i < n;i++)
            pre[i+1] = pre[i] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return pre[right+1] - pre[left];
    }
};

class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        // PrintVVector(matrix);
        int n = matrix.size();
        int m = matrix[0].size();
        pre.resize(n+1,vector<int>(m+1,0));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++){
                // printf("%d",tmp[i-1][j]);
                pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        // PrintVVector(pre);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++,col1++,row2++,col2++;
        return pre[row2][col2] - pre[row1-1][col2] - pre[row2][col1-1] + pre[row1-1][col1-1];
    }
};

int main() {
    vector<vector<int>> matrix = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    NumMatrix *obj = new NumMatrix(matrix);
    int param_1 = obj->sumRegion(2,1,4,3);
    cout << param_1 << endl;
    param_1 = obj->sumRegion(1,1,2,2);
    cout << param_1 << endl;
    param_1 = obj->sumRegion(1,2,2,4);
    cout << param_1 << endl;
	return 0;
}



