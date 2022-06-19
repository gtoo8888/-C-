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

void printBool(bool val){
	if(val == true)		cout << "YES" << endl;
	else				cout << "NO" << endl;
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
    bool isSymmetric(TreeNode* root) {
		queue<TreeNode*> que;
		
		if(root != nullptr) {
			que.push(root->left);
			que.push(root->right);
		}
		while(!que.empty()) {
			TreeNode* left_node = que.front();que.pop();
			TreeNode* right_node = que.front();que.pop();
//			cout << left_node->val << " "  << right_node->val << endl;
			if((left_node == nullptr) && (right_node == nullptr))
				continue;	
				
			if(left_node == nullptr)
				return false;
			if(right_node == nullptr)
				return false;
			if(left_node->val != right_node->val)
				return false;
	
			que.push(left_node->left);
			que.push(right_node->right);
			
			que.push(left_node->right);
			que.push(right_node->left);
		}
		return true;
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
	bool ans;

	vector<int> data = {1,2,2,null,4,null,4};
	TreeNode* root = NULL;
	root = CreateTree(data);
//	PrePrint(root);

	ans = solution.isSymmetric(root);
	
	printBool(ans);
	
	return 0;
}














