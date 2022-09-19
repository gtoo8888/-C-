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


// class Solution {
// public:
// 	int ans = 0;
//     vector<int> getaverage(TreeNode* node) {
//         if (node == nullptr) {
// 			vector<int> sum(2);
// 			sum[0] = 0;
// 			sum[1] = 0;
// 			return sum;	
// 		}
//         vector<int> leftsum = getaverage(node->left);       // ×ó
//         vector<int> rightsum = getaverage(node->right);     // ÓÒ
// 		// printVector(leftsum);
// 		// printVector(rightsum);
// 		// printf("%d\n",node->val);
// 		int now_sum = leftsum[0] + rightsum[0] + node->val;
// 		int now_num = leftsum[1] + rightsum[1] + 1;
// 		if(now_sum/now_num == node->val){
// 			ans++;
// 		}
// 		// cout << ans << endl;
// 		vector<int> sum2(2);
// 		sum2[0] = now_sum;
// 		sum2[1] = now_num;
// 		// printVector(sum2);
//         return sum2;
//     }
//     int averageOfSubtree(TreeNode* root) {
// 		getaverage(root);
// 		return ans; 
//     }
// };

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        function<pair<int, int>(TreeNode* root)> DFS = [&](TreeNode* p) {
            int x = p->val, y = 1;
            for (auto s : {p->left, p->right})
                if (s) {
                    auto [sx, sy] = DFS(s);
                    x += sx;
                    y += sy;
                }
            ans += p->val == x / y;
            return make_pair(x, y);
        };
        DFS(root);
        return ans;
    }
};


int main() {
	Solution solution;
	int ans;
	vector<int> data = {1};
	TreeNode* root = CreateTree(data);
	
	PrePrint(root);
	cout << endl;
	ans = solution.averageOfSubtree(root);
	
	cout << ans << endl;
	
	return 0;
}



