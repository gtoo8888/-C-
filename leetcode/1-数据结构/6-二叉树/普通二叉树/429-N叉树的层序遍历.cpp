#include <iostream> 
#include <vector>
#include <queue>
#include <string>
#include <iomanip> 
#include <algorithm>
using namespace std;
#define null 0xfffff 

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};





class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> que;

        if(root != nullptr)
            que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> vec;

            for(int i = 0;i < size;i++) {
                Node* temp = que.front();que.pop();
                vec.push_back(temp->val);
                for(int j = 0;j < temp->children.size();j++) {
                    if(temp->children[j])
                        que.push(temp->children[j]);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};




int main(){
	Solution solution;
	vector<vector<int>> ans;

	vector<int> data = {6,4,7,1,3,5,8};
	TreeNode* root = NULL;
	root = CreateTree(data);
			
	ans = solution.levelOrderBottom(root);
	printVVector(ans);
	
	return 0;
}



