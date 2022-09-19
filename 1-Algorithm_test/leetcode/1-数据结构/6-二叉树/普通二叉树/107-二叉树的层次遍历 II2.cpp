#include <iostream> 
#include <vector> 
#include <iomanip>
#include <queue>
#include <algorithm>
#define null 0xffff
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0),left(nullptr),right(nullptr) {}
	TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode* left,TreeNode* right) : val(x),left(left),right(right) {}	
};

void printVector(vector<string> v){
	for(vector<string>::iterator it = v.begin();it != v.end();it++)
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
			cout << setw(5) << *it << " ";
		cout << endl;
	}
	cout << endl;
}



TreeNode* CreateTree(vector<int> data){
	vector<string> str_data(data.size());
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> q;
		
		if(root != nullptr)
			q.push(root);
		while(!q.empty()){
			int size = q.size();
			vector<int> vec;
			
			for(int i = 0;i < size;i++){
				TreeNode* temp = q.front();
				q.pop();
				vec.push_back(temp->val);
				if(temp->left != nullptr)
					q.push(temp->left);
				if(temp->right != nullptr)
					q.push(temp->right);
			}
			ans.push_back(vec);
		}
		reverse(ans.begin(),ans.end());
//			printVVector(ans);
		return ans;
    }
};

int main(){
	Solution solution;
	vector<vector<int>> ans;
	
		
	vector<int> data = {3,9,20,null,null,15,7};
	TreeNode* root = NULL;
	root = CreateTree(data);
	
	ans = solution.levelOrderBottom(root);
	
	printVVector(ans);
	
	return 0;
}





