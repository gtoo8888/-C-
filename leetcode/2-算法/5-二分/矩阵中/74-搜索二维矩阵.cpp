#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVVector(vector<vector<int>>& v){
	for(auto iter : v){
		auto it_tmp = iter;
		for(auto it : it_tmp)
			cout << it << " ";
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size(),m = matrix[0].size();
		int l = 0,mid,r = m*n - 1;
		while(l <= r){
			mid = l + (r - l)/2;
			// printf("%d %d %d\n",mid/m,mid%m,matrix[mid/m][mid%m]);
			// printf("%d %d %d\n\n",l,mid,r);
			if(matrix[mid/m][mid%m] == target)
				return true;
			else if(matrix[mid/m][mid%m] > target)
				r = mid - 1;
			else	
				l = mid + 1;
		}
		return false;
    }
};

int main(){
	Solution sol;
	vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	int target = 10;
	
	PrintVVector(matrix);

	auto ans = sol.searchMatrix(matrix,target);
	
	cout << ans <<endl;
	return 0;
}
