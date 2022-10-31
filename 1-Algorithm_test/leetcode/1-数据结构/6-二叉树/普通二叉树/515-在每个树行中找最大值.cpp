#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include <queue>
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
		queue<TreeNode*> que;
		vector<int> ans;
		
		if(root != nullptr)	que.push(root);
		while(!que.empty()) {
			int size = que.size();
			int max = INT32_MIN;
			
			for(int i = 0;i < size;i++) {
				TreeNode* temp = que.front();que.pop();
				max = temp->val > max ? temp->val : max;
				if(temp->left)	que.push(temp->left);
				if(temp->right)	que.push(temp->right);
			}
			ans.push_back(max);
		}
		return ans;
    }
};


int main() {
	Solution solution;
	vector<int> ans;
	vector<int> data = {1,2,3};
	TreeNode* root = CreateBinaryTree(data);
	
//	PrePrint(root);
	ans = solution.largestValues(root);
	
	PrintVector(ans);
	
	return 0;
}



