#include <iostream> 
using namespace std;
#include <vector> 
#include <typeinfo> 
#include <queue>
#include <iomanip>
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
		queue<TreeNode*> que;
		vector<double> ans;
		
		if(root != nullptr)	que.push(root);	
		while(!que.empty()) {
			int size = que.size();	
			vector<int> vec;
			long sum = 0;
			for(int i = 0;i < size;i++) {
				TreeNode* temp = que.front();que.pop();
				sum += temp->val;
				if(temp->left != nullptr)	que.push(temp->left);
				if(temp->right != nullptr)	que.push(temp->right);
			}
			ans.push_back((double)sum / (double)size);
		}
		return ans;
    }
};

int main() {
	Solution solution;
	vector<double> ans;
	
	vector<int> date = {2147483647,2147483647,2147483647};
	TreeNode* root = NULL;
	root = CreateBinaryTree(date);
	
//	PrePrint(root);	

	ans = solution.averageOfLevels(root);

	PrintVector(ans);
	
	return 0;
}



