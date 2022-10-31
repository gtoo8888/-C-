#include <iostream> 
#include <vector>
#include <queue>
#include <string>
#include <iomanip> 
#include <algorithm>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

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
	root = CreateBinaryTree(data);
			
	auto ans = solution.isEvenOddTree(root);
//	cout << ans << endl;
	PrintBool(ans);
	
	return 0;
}



