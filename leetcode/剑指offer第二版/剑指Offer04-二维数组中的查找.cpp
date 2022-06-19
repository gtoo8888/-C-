#include <iostream>
#include <vector>
using namespace std;


void printBool(bool val){
	if(val == true)		cout << "YES" << endl;
	else				cout << "NO" << endl;
	cout << endl;
}


void printvector(vector<vector<int>> matrix){
	
	for(vector<vector<int>>::iterator iter = matrix.begin();iter != matrix.end();iter++) {
		vector<int> temp = *iter;
		for(vector<int>::iterator it = temp.begin();it != temp.end();it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
}



//class Solution {
//public:
//    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//    	if(matrix.empty() == true)
//    		return false;
//    	
//    	int col = matrix.size();
//		vector<int> temp = matrix[0];
//		int row = temp.size();
//		
//		
//		for(int i = 0;i < matrix.size() - 1;i++) {
//			if(matrix[i][0] == target) 
//				return true;
//			else if	(matrix[i][0] < target) {			
//				for(int j = 0;j < row;j++) {
////					cout << matrix[i][j] << endl;
//					if(matrix[i][j] == target) 
//						return true;
//					else if	(matrix[i][j] < target)
//						continue;
//					else if (matrix[i][j] > target && matrix[i+1][0] > target)
//						continue;
//					else
//						break;
//				}
//			}
//			else
//				return false;
//		}
//		for(int j = 0;j < row;j++) {
////			cout << matrix[col - 1][j] << endl;
//			if(matrix[col - 1][j] == target) 
//				return true;
//			else if	(matrix[col - 1][j] < target)
//				continue;
//			else
//				break;	
//		}
//		return false;
//    }
//};

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    	if(matrix.empty() == true)
    		return false;
    		
    	int col = matrix.size();
		vector<int> temp = matrix[0];
		int row = temp.size();

		for(int i = 0;i < matrix.size();i++) {			
			for(int j = 0;j < row;j++) {
				if(matrix[i][j] == target) 
					return true;
			}
		}
		return false;
    }
};
	
int main() {
	Solution sol;
	int target = 23;
	vector<vector<int>> matrix = {
						  {1,   4,  7, 11, 15},
						  {2,   5,  8, 12, 19},
						  {3,   6,  9, 16, 22},
						  {10, 13, 14, 17, 24},
						  {18, 21, 23, 26, 30}
						};
//	printvector(matrix);
	auto ans = sol.findNumberIn2DArray(matrix,target);
	printBool(ans);
	
	return 0;
}



