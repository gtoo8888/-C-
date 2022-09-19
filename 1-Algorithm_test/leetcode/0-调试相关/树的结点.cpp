#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

TreeNode *ConstructBinaryTree(vector<int>& vec, int len, int i){
    if (vec.empty() || len < 1) return nullptr;
    TreeNode *root = NULL;
    if (i < len && vec[i] != 'null'){
        root = new TreeNode(0);
        if (root == nullptr) return nullptr;
        root->val = vec[i];
        root->left = ConstructBinaryTree(vec, len, 2 * i + 1);
        root->right = ConstructBinaryTree(vec, len, 2 * i + 2);
    }
    return root;
}

//LeetCode解答
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if(root!=NULL) que.push(root);
        vector<vector<int>> result;
        while(!que.empty()){
            int size=que.size();//这里一定要用固定大小的size，不要使用que.size(),因为que.size是不断变化的
            vector<int> vec;
            for(int i=0; i<size;i++){
                TreeNode* node=que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};

//测试
int main(){
    TreeNode *root;
    //测试用例
    vector<int> data{3, 9, 20, 'null', 'null',  15, 7};
    root = ConstructBinaryTree(data, data.size(), 0);
    
    //待测试方法
    Solution s;
    vector<vector<int>>result = s.levelOrder(root);
    
    //结果打印
    for(int i=0;i<result.size();i++){
        for(int j=0; j<result[i].size();j++){
            cout<<result[i][j]<< " ";
            if(j==result[i].size()-1)
                cout<<endl;
        }
    }
    return 0;
}

