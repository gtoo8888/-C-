#include <iostream> 
using namespace std;
#include <vector> 
#include <typeinfo> 
#include <queue>
#include <iomanip>
#define null 0xfffff


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printDVector(vector<double> v){
	for(vector<double>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void printVector(vector<int> v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}
void printVVector(vector<vector<int>> v){
	vector<vector<int>>::iterator iter;
	vector<int>::iterator it;
	vector<int> it_temp;
	
	for(iter = v.begin();iter != v.end();iter++){
		it_temp = *iter;
		for(it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

TreeNode* CreateTree(vector<int> date) {
	vector<string> str_date(date.size());
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
	if(root == nullptr) return;
	cout << root->val << " ";
	PrePrint(root->left);
	PrePrint(root->right);
	return;
}


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
	root = CreateTree(date);
	
//	PrePrint(root);	

	ans = solution.averageOfLevels(root);

	printDVector(ans);
	
	return 0;
}



