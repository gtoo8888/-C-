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

void PrePrint(TreeNode* root) {
	if(root == nullptr) return;
	cout << root->val << " ";
	PrePrint(root->left);
	PrePrint(root->right);
	return;
}

int main(){
	Solution solution;
	TreeNode* ans;

	vector<int> data = {4,2,7,1,3,6,9};
	TreeNode* root = NULL;
	root = CreateTree(data);
	PrePrint(root);

	ans = solution.invertTree(root);
	
	PrePrint(ans);
	
	return 0;
}














