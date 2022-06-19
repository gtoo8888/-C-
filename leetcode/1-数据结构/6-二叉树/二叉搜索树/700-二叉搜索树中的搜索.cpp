#include <iostream> 
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define null 0xfffff 

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printVector(vector<int> &v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl;
}


TreeNode* CreateTree(vector<int> data){
	vector<string> str_data(data.size()," ");
	for(int i = 0;i < data.size();i++){
		if(data[i] != null)
			str_data[i] = to_string(data[i]);
		else
			str_data[i] = "null";
	}
	
	queue<TreeNode*> q;
	TreeNode* root = new TreeNode(stoi(str_data[0]));
	q.push(root);
	int i = 1;
	while(i < str_data.size()){
		TreeNode* temp = q.front();
		q.pop();
		if(str_data[i] != "null"){
			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
			temp->left = new_node;
			q.push(new_node);
		}
		i++;
		if(str_data[i] != "null"){
			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
			temp->right = new_node;
			q.push(new_node);
		}
		i++;
	}
	return root;
}


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL) {
            if(root->val > val) 
                root = root->left;
            else if(root->val < val)
                root = root->right;
            else   
                return root;
        }
        return NULL;
    }
};

void PrePrint(TreeNode* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    PrePrint(root->left);
    PrePrint(root->right);
	return;
}


int main(){
	Solution solution;
	vector<int> data = {4,2,7,1,3};
	TreeNode* root = NULL;
	root = CreateTree(data);
    int val = 2;
			
	TreeNode* ans = solution.searchBST(root,val);
	PrePrint(ans);
	
	return 0;
}



