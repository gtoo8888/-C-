#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

void printVector(vector<string> v){
	for(vector<string>::iterator it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	stack<int> sta; 
		for(int i = 0;i < tokens.size();i++) {
			cout << sta.top() << endl;
			if(tokens[i] == "+"){
				int temp1 = sta.top();sta.pop();
				int temp2 = sta.top();sta.pop();
				sta.push(temp1 + temp2);
			}
			else if(tokens[i] == "-"){
				int temp1 = sta.top();sta.pop();
				int temp2 = sta.top();sta.pop();
				sta.push(temp1 - temp2);
			}				
			else if(tokens[i] == "*"){
				int temp1 = sta.top();sta.pop();
				int temp2 = sta.top();sta.pop();
				sta.push(temp1 * temp2);
			}
			else if(tokens[i] == "/"){
				int temp1 = sta.top();sta.pop();
				int temp2 = sta.top();sta.pop();
//				    cout << temp1 << " " << temp2 << endl;
				sta.push(temp2 / temp1);//弹出顺序问题，这个要反一下 
			}	
			else
				sta.push(stoi(tokens[i]));
		}
		return sta.top();
    }
};

		
int main() {
	Solution solution;
	int ans = 0;
	string tokens_nums[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	vector<string> tokens(tokens_nums,tokens_nums + sizeof(tokens_nums) / sizeof(string));
	printVector(tokens);
	
	ans = solution.evalRPN(tokens);
	
	cout << ans << endl;
	return 0;
}


