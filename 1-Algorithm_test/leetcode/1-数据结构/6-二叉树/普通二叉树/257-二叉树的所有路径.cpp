#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
		PrintTreeLevelOrder(root);
		return vector<string>();
    }	
};


int main() {
	Solution solution;
	vector<int> data = {1,2,3,null,5};
	TreeNode* root = CreateBinaryTree(data);
	
	auto ans = solution.binaryTreePaths(root);
	
	PrintVector(ans);
	
	return 0;
}



