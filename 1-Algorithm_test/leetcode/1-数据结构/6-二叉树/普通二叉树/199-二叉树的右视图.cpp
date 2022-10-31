#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> que;
		vector<int> ans;
		
		if(root != nullptr)
			que.push(root);
		while(!que.empty()) {
			int size = que.size();

			ans.push_back(que.back()->val);
			for(int i = 0;i < size;i++) {
				TreeNode* temp = que.front();
				
				que.pop();	
				if(temp->left != nullptr)
					que.push(temp->left);
				if(temp->right != nullptr)
					que.push(temp->right);
			}
		}
		PrintVector(ans);
		return ans;
    }
};	

int main() {
	Solution solution;
	vector<int> ans;
	
	vector<int> date = {1,2,3,null,5,null,4,null,6};
	TreeNode* root = NULL;
	root = CreateBinaryTree(date);
	
//	PrePrint(root);	

	ans = solution.rightSideView(root);

	return 0;
}



