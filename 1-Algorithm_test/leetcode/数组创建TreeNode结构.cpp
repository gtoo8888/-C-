#include <iostream> 
using namespace std;
#include <vector> 
#include <typeinfo> 
#include <queue>
#include <iomanip>
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

//通过数组创建TreeNode 
TreeNode* CreateTree(vector<int>Data) {
	vector<string>str_data(Data.size(), "");//先都作为字符串
	 
	for (int i = 0; i < Data.size(); i++) {//读取每一个值，变成字符串 
		if (Data[i] != null)
			str_data[i] = to_string(Data[i]);
		else
			str_data[i] = "null";
	}
	queue<TreeNode*>q;
	TreeNode* root = new TreeNode(stoi(str_data[0]));//定义头结点，字符串转换成数字 
	q.push(root);
	int i = 1;//从第二个开始，因为一号已经进去了
	//通过栈将挂上去的孩子保存下来，先挂上去的先出来，达到左右叶子的切换
	//一遍挂，边放入栈中，作为接下来挂节点的条件 
	while (i < str_data.size()) {
		TreeNode* tmp = q.front();//队列是先进先出，读取front每次都是读取到左儿子，符合输入的储存规则 
		q.pop();//读取后需要弹出，这一轮循环是先把左孩子给挂上去，弹出后下一轮就可以挂右孩子了 
		if (str_data[i] != "null") {
			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
			tmp->left = new_node;
			q.push(new_node);
		}
		i++;
		if (str_data[i] != "null") {
			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
			tmp->right = new_node;
			q.push(new_node);
		}
		//无论是否添加节点，i都会自加
		//通过i++的操作，完成了对null节点的屏蔽
		i++;//每次需要添加左右节点，所以每次加两个 
	}
	//结束以后队列中还有数据 
	return root;
}

void prePrint(TreeNode* Root) {//先序遍历
	if (Root == NULL) return;
	cout << Root->val << ',';
	prePrint(Root->left);
	prePrint(Root->right);
	return;
}

void postPrint(TreeNode* Root) {//后序遍历
	if (Root == NULL) return;
	postPrint(Root->left);
	postPrint(Root->right);
	cout << Root->val << ',';
	return;
}

void inPrint(TreeNode* Root) {//中序遍历
	if (Root == NULL) return;
	inPrint(Root->left);
	cout << Root->val << ',';
	inPrint(Root->right);
	return;
}


int main(){
	vector<int>data = { 1,null,2,3,null };
	TreeNode* root = NULL;//创建根节点 
	root = CreateTree(data);//把节点都挂上去 
//	TreeNode* root = CreateTree(data);
		
	cout << "PreOrder:" << endl;
	prePrint(root);
	cout << endl << "InOrder:" << endl;
	inPrint(root);
	cout << endl << "PostOrder:" << endl;
	postPrint(root);
	
	return 0;
}



