#include <iostream> 
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;
#define null 0xfffff 
#define test_cout  cout << "!!!" << endl 

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printVector(vector<int> &v){
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl;
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

TreeNode* CreateTree(vector<int> data){
	vector<string> str_data(data.size()," ");
	for(int i = 0;i < data.size();i++){
		if(data[i] != null)
			str_data[i] = to_string(data[i]);
		else
			str_data[i] = "null";
	}
	
	queue<TreeNode*> q;
	TreeNode* root = new TreeNode(stoi(str_data[0]));
	q.push(root);
	int i = 1;
	while(i < str_data.size()){
		TreeNode* temp = q.front();
		q.pop();
		if(str_data[i] != "null"){
			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
			temp->left = new_node;
			q.push(new_node);
		}
		i++;
		if(str_data[i] != "null"){
			TreeNode* new_node = new TreeNode(stoi(str_data[i]));
			temp->right = new_node;
			q.push(new_node);
		}
		i++;
	}
	return root;
}


class Codec {
public:
	
    void PrePrint(TreeNode* root,vector<int>& v_all){
 		if(root == NULL)
			return;
		v_all.emplace_back(root->val);
		PrePrint(root->left,v_all);
		PrePrint(root->right,v_all);
		return;
	}
	string vector_to_string(vector<int> v){
		string ans;
		if(v.empty())
			return ans;
		for(int i = 0;i < v.size() - 1;i++){
			ans += to_string(v[i]) + ',';
		}
		ans += to_string(v[v.size() - 1]);
		return ans;
	}
    string serialize(TreeNode* root) {
		vector<int> v_all;
		PrePrint(root,v_all);
		return vector_to_string(v_all);
    }

    vector<int> split(string& data){
		vector<int> ans;
		std::string token;
		size_t pos = 0;
		while( (pos = data.find(",")) != std::string::npos){
			token = data.substr(0,pos);
			// cout << token << endl;
			// cout << token << " " << pos << " " << stoi(token) << endl;
			ans.push_back(stoi(token));
			data.erase(0,pos+1);
		}
		ans.push_back(stoi(data));
		return ans;
	}

    TreeNode* deserialize(string data) {
		if (data.empty()) return nullptr;	// 如果字符串是空，就一定要返回掉，不然后面转换会出错
        vector<int> vals = split(data);
		// printVector(vals);
		TreeNode* root = new TreeNode(vals[0]);
		vector<int> leftVal;
		vector<int> rightVal;
		
		for(auto val : vals){
			if(val < vals[0])
				leftVal.emplace_back(val);
			else if(val > vals[0])
				rightVal.emplace_back(val);
		}
		// printVector(leftVal);printVector(rightVal);
		root->left = deserialize(vector_to_string(leftVal));
		root->right = deserialize(vector_to_string(rightVal));
		return root;
    }

};

void PrePrint(TreeNode* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    PrePrint(root->left);
    PrePrint(root->right);
	return;
}

// 这个构造还有一点毛病
TreeNode* CreateTree2(vector<int> vals) {
	if (vals.empty()) return nullptr;
	// printVector(vals);
	TreeNode* root = new TreeNode(vals[0]);
	vector<int> leftVal;
	vector<int> rightVal;
	for(auto val : vals){
		if(val < vals[0])
			leftVal.emplace_back(val);
		else if(val > vals[0])
			rightVal.emplace_back(val);
	}
	// printVector(leftVal);printVector(rightVal);
	root->left = CreateTree2(leftVal);
	root->right = CreateTree2(rightVal);
	return root;
}


int main(){
	// vector<int> data = {2,1,3};
	// vector<int> data = {41,37,44,24,39,42,48,1,35,38,40};
	vector<int> data = {41,37,44,24,39,42,48,1,35,38,40,null,43,46,49,0,2,30,36,null,null,null,null,null,null,45,47,null,null,null,null,null,4,29,32,null,null,null,null,null,null,3,9,26,null,31,34,null,null,7,11,25,27,null,null,33,null,6,8,10,16,null,null,null,28,null,null,5,null,null,null,null,null,15,19,null,null,null,null,12,null,18,20,null,13,17,null,null,22,null,14,null,null,21,23};
	TreeNode* root = NULL;
	root = CreateTree(data);
	// root = CreateTree2(data);
	// PrePrint(root);

	Codec* ser = new Codec();
	Codec* deser = new Codec();
	string tree = ser->serialize(root);
	cout << tree << endl;
	TreeNode* ans = deser->deserialize(tree);
	PrePrint(ans);

	return 0;
}








