#include <iostream> 
using namespace std;
#include <vector> 
#include <string>
#include <queue>
#include <algorithm>
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
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> chazhi(n,0);
        for(int i = 0;i < n;i++){
            chazhi[i] = capacity[i] - rocks[i];
        }
        sort(chazhi.begin(),chazhi.end());
		// printVector(chazhi);
        int sum = additionalRocks;
        int i = 0;
        int ans = 0;
        while(sum > 0 && i < n){
			// printf("%d %d\n",sum,i);
            if(chazhi[i] != 0){
                if(sum - chazhi[i] >= 0){
                    sum -= chazhi[i];
                    chazhi[i] = 0;
                }else{
                    sum = 0;
                    break;
                }
            }
			// printVector(chazhi);
            ans++;
            i++;
        }
        return ans;
    }
};

int main() {
	Solution solution;
	int ans;
	vector<int> capacity = {2,3,4,5};
	vector<int> rocks = {1,2,4,4};
	int additionalRocks = 2;

	// vector<int> capacity = {10,2,2};
	// vector<int> rocks = {2,2,0};
	// int additionalRocks = 100;

	ans = solution.maximumBags(capacity,rocks,additionalRocks);
	
	cout << ans << endl;
	
	return 0;
}



