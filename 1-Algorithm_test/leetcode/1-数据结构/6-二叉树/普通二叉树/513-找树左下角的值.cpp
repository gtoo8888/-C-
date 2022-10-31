#include <iostream> 
#include <vector>
#include <queue>
#include <string>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> que;
		que.push(root);
		int ans = 0;
		while(!que.empty()) {
			int size = que.size();
			for(int i = 0;i < size;i++) {
				TreeNode* temp = que.front();que.pop();
				if(i == 0 && temp->left == nullptr && temp->right == nullptr) {
					ans = temp->val;
				}
				if(temp->left) que.push(temp->left);
				if(temp->right) que.push(temp->right);
			}
		}
		return ans;
    }
};

int main(){
	Solution solution;

	vector<int> data = {1,2,3,4,null,5,6,null,null,7,null};
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);
//	PrePrint(root);
	
	auto ans = solution.findBottomLeftValue(root);
	
	cout << ans << endl;
	
	return 0;
}














