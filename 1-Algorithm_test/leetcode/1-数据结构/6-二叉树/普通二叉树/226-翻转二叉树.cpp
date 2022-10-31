#include <iostream> 
#include <vector>
#include <queue>
#include <string>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
		queue<TreeNode*> que;	
		if(root != nullptr)
			que.push(root);
		while(!que.empty()) {
			int size = que.size();
			
			for(int i = 0;i < size;i++) {
				TreeNode* temp = que.front();que.pop();
				cout << temp->val << endl;
				swap(temp->left,temp->right);
				if(temp->left != nullptr) que.push(temp->left);
				if(temp->right != nullptr) que.push(temp->right);
			}
		}
		return root;
    }
};


int main(){
	Solution solution;
	TreeNode* ans;

	vector<int> data = {4,2,7,1,3,6,9};
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);
	PrePrint(root);

	ans = solution.invertTree(root);
	
	PrePrint(ans);
	
	return 0;
}














