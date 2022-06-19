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

void PrintVector(vector<int> v){
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
	void InPrint(TreeNode* root,vector<int> & n) {
		if(root == nullptr) return;
		InPrint(root->left,n);
		n.push_back(root->val);
		InPrint(root->right,n);
		return;
	}	
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> nums1,nums2;

		InPrint(root1,nums1);
		InPrint(root2,nums2);

		if(nums1.empty())
			return nums2;
		if(nums2.empty())
			return nums1;
		// PrintVector(nums1);
		// PrintVector(nums2);
		int n1 = nums1.size();
		int n2 = nums2.size();
		printf("%d %d\n",n1,n2);
		vector<int> ans(n1+n2);
		int i=0,j=0;
		int ansi=0;
		while(i < n1 && j < n2){
			if(nums1[i] > nums2[j])
				ans[ansi++] = nums2[j++];
			else
				ans[ansi++] = nums1[i++];
		}
		printf("%d %d\n",i,j);
		while(i < n1)
			ans[ansi++] = nums1[i++];
		while(j < n2)
			ans[ansi++] = nums2[j++];
		return ans;
    }
};

void inorPrint(TreeNode* root) {
	if(root == nullptr) return;
	inorPrint(root->left);
	cout << root->val << " ";
	inorPrint(root->right);
	return;
}

int main(){
	Solution solution;

	vector<int> data1 = {0,null,59,57,90};
	TreeNode* root1 = NULL;
	root1 = CreateTree(data1);

	vector<int> data2 = {60,17,74,6,20,63,97,null,null,null,null,null,null,95,null};
	TreeNode* root2 = NULL;
	root2 = CreateTree(data2);
	// inorPrint(root1);
	// inorPrint(root2);
	
	auto ans = solution.getAllElements(root1,root2);
	
	PrintVector(ans);
	
	return 0;
}














