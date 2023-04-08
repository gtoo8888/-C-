#include <iostream>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

// 1300 real 1607
// 如果是最深叶子节点的公共祖先，那么左右子树高度一定相等
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
		if(root == nullptr)
			return nullptr;
		queue<TreeNode*> que;
		que.emplace(root);
		int height = 0;
		while(!que.empty()){
			height++;
			int len = que.size();
			for(int i = 0;i < len;i++){
				TreeNode* tmp = que.front();que.pop();
				if(tmp->left != nullptr) que.emplace(tmp->left);
				if(tmp->right != nullptr) que.emplace(tmp->right);
			}
		}

		return root;
    }
};



	
int main() {
	Solution solution;
	vector<int> nums = {3,5,1,6,2,0,8,null,null,7,4};
	TreeNode* root = CreateBinaryTree(nums);
	
	auto ans = solution.lcaDeepestLeaves(root);
	
	PrintTreeLevelOrder(ans);	
	return 0;
}



