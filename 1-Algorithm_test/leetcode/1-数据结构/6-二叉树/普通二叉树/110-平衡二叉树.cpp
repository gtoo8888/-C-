#include <iostream> 
#include <vector>
#include <queue>
#include <string>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
	int getHeight(TreeNode* node) {
		if(node == nullptr) return 0;
		
		int leftHeight = getHeight(node->left);
		if(leftHeight == -1)	return -1;
		int RightHeight = getHeight(node->right);
		if(RightHeight == -1)	return -1;
		
//		int ans = 0;
//		if(abs(leftHeight - RightHeight) > 1)
//			return -1;
//		else
//			ans = 1 + max(leftHeight,RightHeight);
//		return ans;

		return abs(leftHeight - RightHeight) > 1 ? -1 :
									 1 + max(leftHeight,RightHeight);
	}
	
    bool isBalanced(TreeNode* root) {
//		if(getHeight(root) == -1)
//			return false;
//		else
//			return true;
		return getHeight(root) == -1 ? false : true;
    }
};


int main(){
	Solution solution;

	vector<int> data = {1,2,2,3,3,null,null,4,4};
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);
//	PrePrint(root);
	
	auto ans = solution.isBalanced(root);
	
	PrintBool(ans);
	
	return 0;
}














