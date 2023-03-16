#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


class Solution {
public:
    bool parseBoolExpr(string expression) {
		int n = expression.size();
		stack<char> sta;
		for(int i = 0;i < n;i++){
			if(expression[i] == ',')
				continue;
			else if(expression[i] == ')'){
				int f_num = 0,t_num = 0;
				while(sta.top() != '('){
					if(sta.top() == 'f')
						f_num++;
					else if(sta.top() == 't')
						t_num++;
					sta.pop();
				}
				sta.pop();
				if(sta.top() == '!'){
                    sta.pop();
					if(f_num > 0)
						sta.push('t');
					else
						sta.push('f');
				}else if(sta.top() == '&'){
                    sta.pop();
					if(f_num == 0)
						sta.push('t');
					else
						sta.push('f');
				}else if(sta.top() == '|'){
                    sta.pop();
					if(t_num > 0)
						sta.push('t');
					else
						sta.push('f');
				}
				
			}else {
				sta.push(expression[i]);
			}
		}
        if(sta.top() == 'f')
            return false;
        else
            return true;
    }
};



int main(void){
	Solution sol;
	// string expression = "&(|(f))";
	// string expression = "|(f,f,f,t)";
	string expression = "!(&(f,t))";

	auto res = sol.parseBoolExpr(expression);
	PrintBool(res);
	return 0;
}
