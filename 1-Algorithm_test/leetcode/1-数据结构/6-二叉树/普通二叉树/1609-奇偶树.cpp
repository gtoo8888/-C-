#include <iostream> 
#include <vector>
#include <queue>
#include <string>
#include <iomanip> 
#include <algorithm>
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

//输出vector 
void printVector(vector<int> &v){
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
			cout << setw(5) << *it << " ";
		cout << endl;
	}
	cout << endl;
}



void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
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
    bool isEvenOddTree(TreeNode* root) {
		queue<TreeNode*> que;
		que.push(root);
		int i = 1;
		int level = 0;
		
		while(!que.empty()) {
			int len = que.size();
			int last = 0;
			for(int i = 0;i < len;i++) {
				TreeNode* temp = que.front();que.pop();
				cout << level << " " << last << " " << temp->val << endl;
				if(level%2 == 0){//偶数下标
					if(i != 0 && last >= temp->val)
						return false;
					if(temp->val%2 == 0){
						return false; 
					}
				}
				else{//奇数下标
					if(i != 0 && last <= temp->val)
//						cout << "!!!" << endl;
						 return false;
					if(temp->val%2 != 0){
						return false;
					}
				}
				last = temp->val;
				if(temp->left)	que.push(temp->left);
				if(temp->right)	que.push(temp->right); 
			}
			level++;
		}
		return true;
    }
};



int main(){
	Solution solution;
	
	vector<int> data = {5,9,1,3,5,7,null};
	TreeNode* root = NULL;
	root = CreateTree(data);
			
	auto ans = solution.isEvenOddTree(root);
//	cout << ans << endl;
	PrintBool(ans);
	
	return 0;
}



