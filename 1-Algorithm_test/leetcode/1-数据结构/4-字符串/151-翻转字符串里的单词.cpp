#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    void deleteWords(string &s) {//�������ý��иı� 
    	int n = s.size();
        for(int i = s.size()-1;i > 0;i--) {//ɾ���ո�ôӺ���ǰ 
    		if(s[i] == s[i-1] && s[i] == ' ')
    			s.erase(s.begin() + i);
		} 
		if (s.size() > 0 && s[s.size() - 1] == ' ') 
		//ɾ�������ո�,��Ҫ���µ���size����Ϊ���ȸı��� 
        	s.erase(s.begin() + s.size() - 1);
		if (s.size() > 0 && s[0] == ' ') //ɾ����ͷ�ո�
		    s.erase(s.begin());	
    }
    
    string reverseWords(string s) {
    	deleteWords(s);
        cout << s << endl;
    	int start = 0;
    	int end = 0;
		int n = s.size();
		int flag = 0;
		
		reverse(s.begin(),s.begin() + n);
		cout << s << endl;
		for(int i = 0;i < n;i++){
    		
			if(flag == 0){
				start = i;
				flag = 1;
			}
			if(flag == 1 && s[i] == ' '){
				end = i;
				reverse(s.begin() + start,s.begin() + end);
				start = 0;
				end = 0;
				flag = 0;
			}
			if(flag == 1 && i == n-1){
				end = i;
				reverse(s.begin() + start,s.begin() + end);
				start = 0;
				end = 0;
				flag = 0;
			}
			cout << s[i] << " " << i  << " " << start << " " << end << endl;
		}
		return s;
    } 
};

		
int main() {
	Solution solution;
	string str = "     the sky is blue        ";
	string ans;
	
	ans = solution.reverseWords(str);
	
//	cout << "\"" << str << "\"" << endl;
	cout << "\"" << ans << "\"" << endl;
	
	return 0;
}


