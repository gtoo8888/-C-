#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"




void PrintVPector(vector<pair<long long,long long>> v){
	for(auto iter : v){
		// auto it_tmp = iter;
		// for(auto it : it_tmp)
		cout << iter.first << " " << iter.second;
		cout << endl;
	}
	cout << endl;
}

bool mycompare(pair<long long,long long> p1,pair<long long,long long> p2){
	if(p1.first > p2.first)
		return true;
	// else if(p1.second < p2.second)
    else
		return false;
    return true;
}

// 想多了，用pair在保存
// class Solution {
// public:
//     long long kthLargestLevelSum(TreeNode* root, int k) {
//         vector<pair<long long,long long>> cen_sum;
// 		queue<TreeNode*> que;
//         int depth = 0;
		
// 		if(root != nullptr)	
// 			que.push(root);
		
// 		while(!que.empty()){
// 			int size = que.size(); 			
// 			vector<int> temp;
// 			int tmp_sum = 0;
// 			for(int i = 0;i < size;i++){
// 				TreeNode* node_temp = que.front();//将需要的结点读取出来后就pop掉 
// 				que.pop();
// 				tmp_sum += node_temp->val;
// 				if(node_temp->left != nullptr)
// 					que.push(node_temp->left);
// 				if(node_temp->right != nullptr)
// 					que.push(node_temp->right);
// 			}
//             depth++;
//             cen_sum.push_back(pair<long long,long long>(tmp_sum,depth));
// 		}
//         sort(cen_sum.begin(),cen_sum.end(),mycompare);	
//         // PrintVPector(cen_sum);
//         if(k > depth)
//             return -1;
//         return cen_sum[k-1].first;
//         // PrintVVector(ans);
//         // PrintVector(cen_sum);
//         // cout << depth << endl;
// 		// return -1;	
//     }
// };


// 直接用vector存储，然后排序，不知道是不是可以
// class Solution {
// public:
//     long long kthLargestLevelSum(TreeNode* root, int k) {
//         vector<pair<long long,long long>> cen_sum;
//         vector<long long> cen_sum2;
// 		queue<TreeNode*> que;
//         int depth = 0;
		
// 		if(root != nullptr)	
// 			que.push(root);
		
// 		while(!que.empty()){
// 			int size = que.size(); 			
// 			vector<int> temp;
// 			int tmp_sum = 0;
// 			for(int i = 0;i < size;i++){
// 				TreeNode* node_temp = que.front();//将需要的结点读取出来后就pop掉 
// 				que.pop();
// 				tmp_sum += node_temp->val;
// 				if(node_temp->left != nullptr)
// 					que.push(node_temp->left);
// 				if(node_temp->right != nullptr)
// 					que.push(node_temp->right);
// 			}
//             depth++;
//             // cen_sum.push_back(pair<long long,long long>(tmp_sum,depth));
//             cen_sum2.push_back(tmp_sum);
// 		}
//         // sort(cen_sum.begin(),cen_sum.end(),mycompare);	
//         sort(cen_sum2.begin(),cen_sum2.end(),greater<long long>());	
//         // PrintVPector(cen_sum);
//         PrintVector(cen_sum2);
//         if(k > depth)
//             return -1;
//         // return cen_sum[k-1].first;
//         return cen_sum2[k-1];
//         // PrintVector(cen_sum);
//         // cout << depth << endl;
// 		// return -1;	
//     }
// };


void PrintPriQueue_less( priority_queue<int> q){
    while(!q.empty()){
        printf("%d ",q.top());
        q.pop();
    }
	cout << endl; 
}

// 最终使用优先队列存储，存入的时候直接排序
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> q1;         
		queue<TreeNode*> que;
        int depth = 0;
		
		if(root != nullptr)	
			que.push(root);
		
		while(!que.empty()){
			int size = que.size(); 			
			long long tmp_sum = 0;
			for(int i = 0;i < size;i++){
				TreeNode* node_temp = que.front();//将需要的结点读取出来后就pop掉 
				que.pop();
				tmp_sum += node_temp->val;
				if(node_temp->left != nullptr)
					que.push(node_temp->left);
				if(node_temp->right != nullptr)
					que.push(node_temp->right);
			}
            depth++;
            q1.push(tmp_sum);
		}
        // PrintPriQueue_less(q1);
        if(k > depth)
            return -1;

        int tmp_k = k-1;
        while(tmp_k--){
            q1.pop();
        }
        return q1.top();
		// return -1;	
    }
};

int main() {
	Solution solution;

	// vector<int> data = {5,8,9,2,1,3,7,4,6};
    // int k = 2;
	// TreeNode* root = CreateBinaryTree(data);

	vector<int> data = {1,2,null,3,null};
    int k = 4;
	TreeNode* root = CreateBinaryTree(data);

    auto ans = solution.kthLargestLevelSum(root,k);

	cout << ans << endl;
	return 0;
}




