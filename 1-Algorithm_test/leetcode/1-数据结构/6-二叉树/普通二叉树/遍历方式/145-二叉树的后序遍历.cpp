#include <iostream> 
#include <vector>
#include <queue>
#include <string>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"



class Solution {
public:
	void PostOrder(TreeNode* root,vector<int> &ans) {
		if(root == nullptr)
			return;	
		PostOrder(root->left,ans);
		PostOrder(root->right,ans);
		ans.push_back(root->val);
	}
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		PostOrder(root,ans);
		return ans;
    }
};

int main(){
	Solution solution;
	vector<int> ans;

	vector<int> data = {1,null,2,3,null };
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);
			
	ans = solution.postorderTraversal(root);
	PrintVector(ans);
	
	return 0;
}



