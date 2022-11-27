#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"



int min_swap(vector<int> &nums){
    map<int, int>mp;    
    vector<int> tmp_num(nums);
    sort(tmp_num.begin(), tmp_num.end());
    for(int i = 0; i < tmp_num.size(); i++)
        mp[tmp_num[i]] = i;
 
    int cnt = 0;
    for (int i = 0; i < nums.size();i++){
        if (nums[i] == tmp_num[i])
            continue;
        swap(nums[i], nums[mp[nums[i]]]);
        cnt++;
    }
    return cnt;
}

int selectSort(vector<int> &nums){
    int num = 0;
 	int minIndex;
    int n = nums.size();
 	for(int i=0;i<n-1;i++){
 		minIndex=i;
 		for(int j=i+1;j<n;j++){
 			if(nums[j]<nums[minIndex]){
 				minIndex=j;
			}
		}
		if(i!=minIndex){
			swap(nums[i],nums[minIndex]);
			num++;
		}
	}	
    return num;
 }


class Solution {
public:
    int minimumOperations(TreeNode* root) {
		queue<TreeNode*> que;
		
		if(root != nullptr)	
			que.push(root);
		int ans = 0;
		while(!que.empty()){
			int size = que.size(); 
			vector<int> temp;
			
			for(int i = 0;i < size;i++){
				TreeNode* node_temp = que.front();
				que.pop();
				temp.push_back(node_temp->val);
				
				if(node_temp->left != nullptr)
					que.push(node_temp->left);
				if(node_temp->right != nullptr)
					que.push(node_temp->right);
			}
			ans += selectSort(temp);
            PrintVector(temp);
		}
        return ans;
    }
};

int main() {
	Solution solution;

	// vector<int> data = {1,4,3,7,6,8,5,null,null,null,null,9,null,10,null};
	// TreeNode* root = CreateBinaryTree(data);

	vector<int> data = {332,463,103,417,150,409,41,135,129,117,474,263,null,328,456,347,167,383,null,null,422,493,489,275,72,null,null,425,89,null,null,162,18,null,null,null,null,363,290,106,260,468,null,null,null,432,null,323,null,null,null,null,null,null,36,null,null,302,190,null,280,null,null,null,null,488,null,null,null,null,446,null,null,null,null,null,75};
	TreeNode* root = CreateBinaryTree(data);

    auto ans = solution.minimumOperations(root);

	cout << ans << endl;
	return 0;
}




