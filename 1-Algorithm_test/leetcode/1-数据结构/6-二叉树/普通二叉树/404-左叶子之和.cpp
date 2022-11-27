#include <iostream> 
#include <vector>
#include <queue>
#include <string>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
		queue<TreeNode*> que;
		que.push(root);
		int ans = 0;
		while(!que.empty()) {
			int size = que.size();
			for(int i = 0;i < size;i++) {
				TreeNode* temp = que.front();que.pop();
				
				if(temp->left != nullptr && temp->left->left == nullptr 
										&& temp->left->right == nullptr) {
					ans += temp->left->val;
				}
				if(temp->left)  que.push(temp->left);
				if(temp->right) que.push(temp->right);
			}
		}
		return ans;
    }
};

int main(){
	Solution solution;

	vector<int> data = {3,9,20,null,null,15,7};
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);
//	PrePrint(root);
	
	auto ans = solution.sumOfLeftLeaves(root);
	
	cout << ans << endl;
	
	return 0;
}














