#include <iostream> 
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> que;
		if(root != nullptr)
			que.push(root);

		while(!que.empty()){
			int size = que.size();
			vector<int> ans_t;
			for(int i = 0;i < size;i++){
				TreeNode* tmp = que.front();que.pop();
				ans_t.push_back(tmp->val);
				if(tmp->left != nullptr) 
					que.push(tmp->left);
				if(tmp->right != nullptr) 
					que.push(tmp->right);
			}
			ans.push_back(ans_t);
		}
		return ans;
    }
};


int main(){
	Solution solution;
	vector<int> data = {3,9,20,null,null,15,7};
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);
			
	auto ans = solution.levelOrder(root);
	PrintVVector(ans);

	return 0;
}



