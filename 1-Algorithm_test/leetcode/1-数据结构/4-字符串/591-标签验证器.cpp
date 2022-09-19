#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

void PrintVVector(vector<vector<int>> v){
	for(auto iter = v.begin();iter != v.end();iter++){
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}


class Solution {
public:
    bool isValid(string code) {
		int n = code.size();
		stack<string> tags;
		int i = 0;
		while(i < n){
			if(code[i] == '<'){//遇到左<的情况
				if(i == n-1)// 如果<>的情况，一定是错误的，直接返回
					return false;
				if(code[i+1] == '/'){	// </的情况，一定是结束标签
					int j = code.find('>',i);
//					printf("%d\n",j);
					if(j == string::npos)
						return false;
					string tagname = code.substr(i+2,j-(i+2));
//					cout << tagname << endl;
//					cout << tags.empty() << " " << tags.top()  <<endl;
					if(tags.empty() || tags.top() != tagname)
						return false;
					tags.pop();
					i = j+1;
					if(tags.empty() && i != n)
						return false;
				}else if(code[i+1] == '!'){	// </的情况，一定是cdate标签
					if(tags.empty()) 
						return false;
					string cdata = code.substr(i+2,7);
//					cout << cdata << endl;
					if(cdata != "[CDATA[")
						return false;
					int j = code.find("]]>", i);
//					int j = code.find("]]>",i);
//					printf("%d\n",j);
					if(j == string::npos)
						return false;
					i = j+1;
				}else{	// <字母的情况，一定是开始标签
					int j = code.find('>',i);// 从位置i开始在字符串中寻找匹配的位置
//					printf("%d\n",j);
					if(j == string::npos)// string::npos表示在剩下的位置中没有找到，那么直接返回失败
						return false;
					string tagname = code.substr(i+1,j-(i+1));
//					cout << tagname << endl;
					if(tagname.size() < 1 || tagname.size() > 9)
						return false;
					if(!all_of(tagname.begin(),tagname.end(),[](unsigned char c) {	// all_of检查区间tagname上的所有元素 
						return isupper(c);})) // 检查是否是大写，是的话返回true 
						return false; 
					tags.push(move(tagname));//move告诉编译器：我们有一个左值，但我们希望像一个右值一样处理它
					// 移动以后tagname就是空了
					// cout << tagname << endl;
					i = j+1; // 将起始标签存入后，就移动搜索指针i的位置
				}
			}
			else{
				if(tags.empty())
					return false;
				i++;
			}
//			printf("%d %c\n",i,code[i]); 
		}
		return tags.empty();
    }
};


//"!!!<A>123</A>"
//"<AAAAAAAAAA></AAAAAAAAAA>"
//"<A<></A<>"
//"<A"
//"<A></A><B></B>"
//"<DIV>a</DIV><DIV>b</DIV>" 
	
int main() {
	Solution solution;
//	string code =  "<DIV>This<![CDATA[<div>]]></DIV>";
//	string code =  "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>";
	string code =  "<TRUe><![CDATA[123123]]]]><![CDATA[>123123]]></TRUe>";
	cout <<code.size() << endl;
	
	auto ans = solution.isValid(code);
	
	PrintBool(ans);
	
	return 0;
}



