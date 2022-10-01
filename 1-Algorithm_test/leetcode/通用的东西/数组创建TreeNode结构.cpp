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

//���vector 
void printVector(vector<int> &v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl;
}

//ͨ�����鴴��TreeNode 
TreeNode* CreateTree(vector<int>Data) {
	vector<string>str_data(Data.size(), "");//�ȶ���Ϊ�ַ���
	 
	for (int i = 0; i < Data.size(); i++) {//��ȡÿһ��ֵ������ַ��� 
		if (Data[i] != null)
			str_data[i] = to_string(Data[i]);
		else
			str_data[i] = "null";
	}
	queue<TreeNode*>q;
	TreeNode* root = new TreeNode(stoi(str_data[0]));//����ͷ��㣬�ַ���ת�������� 
	q.push(root);
	int i = 1;//�ӵڶ�����ʼ����Ϊһ���Ѿ���ȥ��
	//ͨ��ջ������ȥ�ĺ��ӱ����������ȹ���ȥ���ȳ������ﵽ����Ҷ�ӵ��л�
	//һ��ң��߷���ջ�У���Ϊ�������ҽڵ������ 
	while (i < str_data.size()) {
		TreeNode* tmp = q.front();//�������Ƚ��ȳ�����ȡfrontÿ�ζ��Ƕ�ȡ������ӣ���������Ĵ������ 
		q.pop();//��ȡ����Ҫ��������һ��ѭ�����Ȱ����Ӹ�����ȥ����������һ�־Ϳ��Թ��Һ����� 
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
		//�����Ƿ���ӽڵ㣬i�����Լ�
		//ͨ��i++�Ĳ���������˶�null�ڵ������
		i++;//ÿ����Ҫ������ҽڵ㣬����ÿ�μ����� 
	}
	//�����Ժ�����л������� 
	return root;
}

void prePrint(TreeNode* Root) {//�������
	if (Root == NULL) return;
	cout << Root->val << ',';
	prePrint(Root->left);
	prePrint(Root->right);
	return;
}

void postPrint(TreeNode* Root) {//�������
	if (Root == NULL) return;
	postPrint(Root->left);
	postPrint(Root->right);
	cout << Root->val << ',';
	return;
}

void inPrint(TreeNode* Root) {//�������
	if (Root == NULL) return;
	inPrint(Root->left);
	cout << Root->val << ',';
	inPrint(Root->right);
	return;
}


int main(){
	vector<int>data = { 1,null,2,3,null };
	TreeNode* root = NULL;//�������ڵ� 
	root = CreateTree(data);//�ѽڵ㶼����ȥ 
//	TreeNode* root = CreateTree(data);
		
	cout << "PreOrder:" << endl;
	prePrint(root);
	cout << endl << "InOrder:" << endl;
	inPrint(root);
	cout << endl << "PostOrder:" << endl;
	postPrint(root);
	
	return 0;
}



