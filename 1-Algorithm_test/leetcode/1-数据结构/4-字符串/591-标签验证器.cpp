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
			if(code[i] == '<'){//������<�����
				if(i == n-1)// ���<>�������һ���Ǵ���ģ�ֱ�ӷ���
					return false;
				if(code[i+1] == '/'){	// </�������һ���ǽ�����ǩ
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
				}else if(code[i+1] == '!'){	// </�������һ����cdate��ǩ
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
				}else{	// <��ĸ�������һ���ǿ�ʼ��ǩ
					int j = code.find('>',i);// ��λ��i��ʼ���ַ�����Ѱ��ƥ���λ��
//					printf("%d\n",j);
					if(j == string::npos)// string::npos��ʾ��ʣ�µ�λ����û���ҵ�����ôֱ�ӷ���ʧ��
						return false;
					string tagname = code.substr(i+1,j-(i+1));
//					cout << tagname << endl;
					if(tagname.size() < 1 || tagname.size() > 9)
						return false;
					if(!all_of(tagname.begin(),tagname.end(),[](unsigned char c) {	// all_of�������tagname�ϵ�����Ԫ�� 
						return isupper(c);})) // ����Ƿ��Ǵ�д���ǵĻ�����true 
						return false; 
					tags.push(move(tagname));//move���߱�������������һ����ֵ��������ϣ����һ����ֵһ��������
					// �ƶ��Ժ�tagname���ǿ���
					// cout << tagname << endl;
					i = j+1; // ����ʼ��ǩ����󣬾��ƶ�����ָ��i��λ��
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



