#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include <queue>
#define null 0xffff



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

TreeNode* CreateTree(vector<int> data) {
	vector<string> str_date(data.size());
	for(int i = 0;i < data.size();i++) {
		if(data[i] != null) str_date[i] = to_string(data[i]);
		else str_date[i] = "null";
	}
	
	queue<TreeNode*> que;
	TreeNode* root = new TreeNode(stoi(str_date[0]));
	que.push(root);
	int i = 1;
	while(i < str_date.size()) {
		TreeNode* temp = que.front();que.pop();
		if(str_date[i] != "null") {
			TreeNode* new_node = new TreeNode(stoi(str_date[i]));
			temp->left = new_node;
			que.push(new_node);
		}i++;
		if(str_date[i] != "null") {
			TreeNode* new_node = new TreeNode(stoi(str_date[i]));
			temp->right = new_node;
			que.push(new_node);
		}i++;
	}
	return root;
	
}

void PrePrint(TreeNode* root) {
	if(root == nullptr)	return;
	cout << root->val << " ";
	PrePrint(root->left);
	PrePrint(root->right);
}

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		queue<TreeNode*> que;
		vector<int> ans;

		if(root1 != nullptr)	que.push(root1);
		if(root2 != nullptr)	que.push(root2);

		while(!que.empty()) {
			TreeNode* temp1 =  que.front();que.pop();
			TreeNode* temp2 =  que.front();que.pop();
			temp1->val += temp2->val;
			
			if(temp1->left && temp2->left){
				que1.push(temp1->left);
				que2.push(temp2->left);
			}else if(temp1->left){
				que1.push(temp1->left);
			}
			else if(temp2->left){
				que2.push(temp2->left);
			}

			
		}
		


    }
};


int main() {
	Solution solution;
	vector<int> data1 = {1,3,2,5,null};
	TreeNode* root1 = CreateTree(data1);
	vector<int> data2 = {2,1,3,null,4,null,7};
	TreeNode* root2 = CreateTree(data2);	

	// PrePrint(root2);


	auto ans = solution.mergeTrees(root1,root2);
	
	// printVector(ans);
	
	return 0;
}



