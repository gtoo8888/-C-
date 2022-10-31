#include <iostream> 
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// 方法一：偷鸡解法，得到以后翻转
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
// 		vector<vector<int>> ans;
// 		queue<TreeNode*> que;
// 		if(root != nullptr)
// 			que.push(root);

// 		while(!que.empty()){
// 			int size = que.size();
// 			vector<int> ans_t;
// 			for(int i = 0;i < size;i++){
// 				TreeNode* tmp = que.front();que.pop();
// 				ans_t.push_back(tmp->val);
// 				if(tmp->left != nullptr) 
// 					que.push(tmp->left);
// 				if(tmp->right != nullptr) 
// 					que.push(tmp->right);
// 			}
// 			ans.push_back(ans_t);
// 		}
// 		for(int i = 0;i < ans.size();i++){
// 			if(i%2 == 1)
// 				reverse(ans[i].begin(),ans[i].end());
// 		}
// 		return ans;
//     }
// };

// 方法二：使用双端队列
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> que;
		if(root != nullptr)
			que.push(root);
		int depth = 1;
		while(!que.empty()){
			int size = que.size();
			deque<int> ans_t;
			for(int i = 0;i < size;i++){
				TreeNode* tmp = que.front();que.pop();
				if(depth%2 == 1){
					ans_t.push_back(tmp->val);
				}else{
					ans_t.push_front(tmp->val);
				}
				if(tmp->left != nullptr) 
					que.push(tmp->left);
				if(tmp->right != nullptr) 
					que.push(tmp->right);
			}
			ans.emplace_back(vector<int>(ans_t.begin(),ans_t.end()));
			depth++;
		}
		return ans;
    }
};


int main(){
	Solution solution;
	// vector<int> data = {3,9,20,null,null,15,7};
	vector<int> data = {3,9,20,1,2,15,7};
	TreeNode* root = NULL;
	root = CreateBinaryTree(data);
			
	auto ans = solution.levelOrder(root);
	PrintVVector(ans);

	return 0;
}



