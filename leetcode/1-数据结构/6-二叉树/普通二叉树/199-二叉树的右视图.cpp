#include <iostream>
#include <vector>
#include <queue>
#define null 0xffff
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


TreeNode* CreateTree(vector<int> date) {
	vector<string> str_date(date.size()," ");
	
	for(int i = 0;i < date.size();i++) {
		if(date[i] != null)
			str_date[i] = to_string(date[i]);
		else
			str_date[i] = "null";
	}
	
	queue<TreeNode*> que;
	TreeNode* root = new TreeNode(stoi(str_date[0]));
	que.push(root);
	int i = 1;
	while(i < str_date.size()) {
		TreeNode* temp = que.front();
		que.pop();
		if(str_date[i] != "null") {
			TreeNode* new_node = new TreeNode(stoi(str_date[i]));
			temp->left = new_node;
			que.push(new_node);
		}
		i++;
		if(str_date[i] != "null") {
			TreeNode* new_node = new TreeNode(stoi(str_date[i]));
			temp->right = new_node;
			que.push(new_node);
		}
		i++;
	} 
	return root;
}

void PrePrint(TreeNode* root) {
	if(root == nullptr)	return;
	cout << root->val << " ";
	PrePrint(root->left);
	PrePrint(root->right);
	return;
}

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
	printVector(ans);
		return ans;
    }
};	

int main() {
	Solution solution;
	vector<int> ans;
	
	vector<int> date = {1,2,3,null,5,null,4,null,6};
	TreeNode* root = NULL;
	root = CreateTree(date);
	
//	PrePrint(root);	

	ans = solution.rightSideView(root);


	
	return 0;
}



