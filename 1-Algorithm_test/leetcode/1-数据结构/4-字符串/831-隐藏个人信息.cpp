#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string change_str(string str){
        for(auto& c : str){
            if(c >= 'A' && c <= 'Z')
                c = c - ('A'-'a');
        }
        return str;
    }

    string maskPII(string s) {
		int n = s.size();
		int ai = s.find('@');
		if(ai != -1){ // 邮箱地址
            string yuming = s.substr(ai,n-ai);
            yuming = change_str(yuming);
           
            string xingming = s.substr(0,ai);
            string s1 = change_str(xingming.substr(0,1));
            string s2 = change_str(xingming.substr(xingming.size()-1,1));
            string change_xm = s1 + "*****" + s2;
            return change_xm + yuming;
		}else{ // 电话号码
            string haoma = "";
            for(auto c : s){
                if(c >= '0' && c <= '9')
                    haoma.push_back(c);
            }
            int hao_num = haoma.size();
            string mowei = haoma.substr(hao_num-4,4);
            if(hao_num == 10){
                return "***-***-" + mowei;
            }else if(hao_num == 11){
                return "+*-***-***-" + mowei;
            }else if(hao_num == 12){
                return "+**-***-***-" + mowei;
            }else if(hao_num == 13){
                return "+***-***-***-" + mowei;
            }
		}
		return s;
    }
};

	 
int main() {
	Solution solution;
	string queryIP = "";
	queryIP = "LeetCode@LeetCode.com";
	cout << solution.maskPII(queryIP) << endl;cout <<"-------------"<< endl;

	queryIP = "AB@qq.com";
	cout << solution.maskPII(queryIP) << endl;cout <<"-------------"<< endl;

	queryIP = "1(234)567-890";
	cout << solution.maskPII(queryIP) << endl;cout <<"-------------"<< endl;

	return 0;
}


