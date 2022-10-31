#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include <queue>
#define null 0xffff
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



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

void PrePrint_chongjian(TreeNode* root,vector<int>& v) {
	if(root == nullptr) return;
	v.push_back(root->val);
	PrePrint_chongjian(root->left,v);
	PrePrint_chongjian(root->right,v);
	return;
}


void PrePrint_jiandan(TreeNode* root) {
	if(root == nullptr) return;
	cout << root->val << " ";
	PrePrint_jiandan(root->left);
	PrePrint_jiandan(root->right);
	return;
}

void PrePrint(TreeNode* root,int val) {
	if(root == nullptr)	return;
	// cout << root->val << " ";
    // if(root->val == val){
    //     root->left = nullptr;
    //     root->right = nullptr;
    //     return;
    // }
	if(root->left == nullptr)
		return;
    if(root->left->val == val){
        root->left = nullptr;
        return;
    }else
    	PrePrint(root->left,val);

	if(root->right == nullptr)
		return;
    if(root->right->val == val){
        root->right = nullptr;
        return;
    }else
	    PrePrint(root->right,val);
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
		queue<TreeNode*> que;
		int depth = -1;
		if(root != nullptr)	que.push(root);
		while(!que.empty()) {
			int size = que.size();
			depth++;
			for(int i = 0;i < size;i++) {
				TreeNode* temp = que.front();que.pop();
				if(temp->left) que.push(temp->left);
				if(temp->right) que.push(temp->right);
			}
		}
		return depth;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
		vector<int> chongjianshu;
		PrePrint_chongjian(root,chongjianshu);
		PrintVector(chongjianshu);
        vector<int> ans;
        for(int i = 0;i < n;i++){
			TreeNode* tmp = CreateTree(chongjianshu);
            PrePrint(tmp,queries[i]);
            PrePrint_jiandan(tmp);
			int height = maxDepth(tmp);
			ans.push_back(height);
			cout << endl;
        }
		cout << endl;

        return ans;
    }
};


int main() {
	Solution solution;
    // vector<int> data = {1,3,4,2,null,6,5,null,null,null,null,null,7};
	// TreeNode* root = CreateTree(data);
    // vector<int> queries = {4};
	
    vector<int> data = {5,8,9,2,1,3,7,4,6};
	TreeNode* root = CreateTree(data);
    vector<int> queries = {3,2,4,8};


	// PrePrint(root);
	// ans = solution.maxDepth(root);
    auto ans = solution.treeQueries(root,queries);
	
	// cout << ans << endl;
    PrintVector(ans);
	
	return 0;
}



