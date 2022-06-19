#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#include <unordered_set>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << endl;
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

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}


class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
		int n = positions.size();
		vector<int> ans(n);
		for(int i = 0;i < n;i++){
			int l1 = positions[i][0];
			int r1 = positions[i][0] + positions[i][1] - 1;
			ans[i] = positions[i][1];
			for(int j = 0;j < i;j++){
				int new_l = positions[j][0];
				int new_r = positions[j][0] + positions[j][1] - 1;
				// printf("%d %d %d %d\n",r1,l2,r2,l1);
				if(new_l <= r1 && new_r >= l1){	// 新的左边大于老的右边 && 不能整个都在老的左边，限制一下
					ans[i] = max(ans[i],ans[j] + positions[i][1]);
				}
			}
		}
		for(int i = 1;i < n;i++){
			ans[i] = max(ans[i],ans[i-1]);
		}
		return ans;
    }
};

// class Solution {
// public:
//     vector<int> fallingSquares(vector<vector<int>>& positions) {
//         int n = positions.size();
//         vector<int> heights(n);
//         for (int i = 0; i < n; i++) {
//             int left1 = positions[i][0], right1 = positions[i][0] + positions[i][1] - 1;
//             heights[i] = positions[i][1];
//             for (int j = 0; j < i; j++) {
//                 int left2 = positions[j][0], right2 = positions[j][0] + positions[j][1] - 1;
//                 if (right1 >= left2 && right2 >= left1) {
//                     heights[i] = max(heights[i], heights[j] + positions[i][1]);
//                 }
//             }
//         }
//         for (int i = 1; i < n; i++) {
//             heights[i] = max(heights[i], heights[i - 1]);
//         }
//         return heights;
//     }
// };


int main() {

	// freopen("out.out","w",stdout);
	Solution solution;
	// vector<vector<int>> positions = {{1,2},{2,3},{6,1}};
	vector<vector<int>> positions = {{2,1},{2,9},{1,8}};
	PrintVVector(positions);

	auto ans = solution.fallingSquares(positions);
	printVector(ans);
	
	return 0;
}



