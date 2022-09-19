#include <iostream> 
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define null 0xfffff 

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

void printVector(vector<int> &v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl;
}


class Solution {
public:
    // void PrintVVector(vector<vector<int>> v){
    //     for(auto iter : v){
    //         auto it_tmp = iter;
    //         for(auto it : it_tmp)
    //             cout << it << " ";
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    Node* dfs(int xLU,int yLU,int xRD,int yRD,vector<vector<int>>& grid) {
        for(int i = xLU;i < xRD;i++){
            for(int j = yLU;j < yRD;j++){
                if(grid[i][j] != grid[xLU][yLU])
                    return new Node(1,0,
                    dfs(xLU,yLU,(xLU+xRD)/2,(yLU+yRD)/2,grid),
                    dfs(xLU,(yLU+yRD)/2,(xLU+xRD)/2,yRD,grid),
                    dfs((xLU+xRD)/2,yLU,xRD,(yLU+yRD)/2,grid),
                    dfs((xLU+xRD)/2,(yLU+yRD)/2,xRD,yRD,grid));
            }
        }
        return new Node(grid[xLU][yLU],1);
    }

    Node* construct(vector<vector<int>>& grid) {
        // PrintVVector(grid);
        int n = grid.size();
        return dfs(0,0,n,n,grid);
    }
};

int main(){
	Solution solution;
	vector<int> ans;

	vector<int> data = {3,9,20,null,null,15,7};
	TreeNode* root = NULL;
	root = CreateTree(data);
			
	ans = solution.inorderTraversal(root);
	printVector(ans);
	
	return 0;
}



