#include <iostream>
#include <vector>
#include <string>
using namespace std;

// O(n2)解法
// 需要多次移动同一个字符
class Solution {
public:
    string replaceSpace(string s) {
        for(int i = 0;i < s.size();i++){
            if(s[i] == ' '){
                s.replace(s.begin()+i,s.begin()+i+1,"%20");
            }
        }
        return s;
    }
};


// O(n)解法
// 从后往前，替换字符
class Solution {
public:
    string replaceSpace(string s) {
    	if(s == "")
    		return "";
    	int len = s.size();
		int num = 0;
		string ans;
		for(int i = 0;i < s.size();i++) 
			if(s[i] == ' ')
				num++;
		s.resize(s.size() + num*2);
		int new_len = s.size();
		int j = len - 1;
		
		for(int i = new_len - 1;i >= 0;i--,j--) {
			if(s[j] == ' ') {
				i -= 2;
				s[i] = '%';
				s[i + 1] = '2';
				s[i + 2] = '0';
			}
			else
				s[i] = s[j];
			cout << s << endl;
		}
		return s;
    }
};




	
int main() {
	Solution sol;
	// test1
	string s = " Wearehappy";
	string s = "Wearehappy ";
	string s = "We arehappy ";
	string s = "We are happy";
	// test2
	string s = "Wearehappy";
	// test3
	string s = nullptr;
	// test4
	string s = "";
	string s = " ";
	string s = "      ";

	auto ans = sol.replaceSpace(s);
	cout << ans << endl;
	return 0;
}



