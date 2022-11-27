#include <iostream>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    int minAddToMakeValid(string s) {
		int l = 0;
		int n = s.size();
		int ans = 0;
		for(int i = 0;i < n;i++){
			if(s[i] == '(')
				l++;
			else if(s[i] == ')'){
				if(l > 0)	//������������ţ����������������
					l--;
				else
					ans++;				
			}
			// printf("%d %d\n",ans,l);
		}
		ans += l;
		return ans;
    }
};

		
int main() {
	Solution solution;
	// string s = "(((";
	// string s = ")))";
	// string s = "(()";
	// string s = "()))";
	// string s = "(()())";	// (()()) �����ǿ��Ե�
	// string s = "()))((";
	// string s = "()))(()()))))";	
	string s = "()))(((()(((()))))))))";
	
	
	auto ans = solution.minAddToMakeValid(s);

	cout << ans << endl;
	
	return 0;
}


