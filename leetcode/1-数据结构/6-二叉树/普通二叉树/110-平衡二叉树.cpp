#include <iostream> 
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define null 0xffff

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void PrintVector(vector<string> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

TreeNode* CreateTree(vector<int> data) {
	vector<string> str_data(data.size());
	for(int i = 0;i < data.size();i++) {
		if(data[i] != null)
			str_data[i] = to_string(data[i]);
		else
			str_data[i] = "null";
	}
	
	queue<TreeNode*> que;
	TreeNode* root = new TreeNode(stoi(str_data[0]));
	que.push(root);
	int i = 1;
	while(i < str_data.size()) {
		TreeNode* temp =  que.front();que.pop();
		if(str_data[i] != "null") {
			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
			temp->left = new_node;
			que.push(new_node);
		}
		i++;
		if(str_data[i] != "null") {
			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
			temp->right = new_node;
			que.push(new_node);
		}
		i++;
	}
	return root;
}


class Solution {
public:
	int getHeight(TreeNode* node) {
		if(node == nullptr) return 0;
		
		int leftHeight = getHeight(node->left);
		if(leftHeight == -1)	return -1;
		int RightHeight = getHeight(node->right);
		if(RightHeight == -1)	return -1;
		
//		int ans = 0;
//		if(abs(leftHeight - RightHeight) > 1)
//			return -1;
//		else
//			ans = 1 + max(leftHeight,RightHeight);
//		return ans;

		return abs(leftHeight - RightHeight) > 1 ? -1 :
									 1 + max(leftHeight,RightHeight);
	}
	
    bool isBalanced(TreeNode* root) {
//		if(getHeight(root) == -1)
//			return false;
//		else
//			return true;
		return getHeight(root) == -1 ? false : true;
    }
};

void PrePrint(TreeNode* root) {
	if(root == nullptr) return;
	cout << root->val << " ";
	PrePrint(root->left);
	PrePrint(root->right);
	return;
}

int main(){
	Solution solution;

	vector<int> data = {1,2,2,3,3,null,null,4,4};
	TreeNode* root = NULL;
	root = CreateTree(data);
//	PrePrint(root);
	
	auto ans = solution.isBalanced(root);
	
	PrintBool(ans);
	
	return 0;
}














