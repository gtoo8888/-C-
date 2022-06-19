#include <iostream>
#include <vector>
using namespace std;

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

void PrintVector(vector<string> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << endl;
	cout << endl;
}






class Solution {
public:
	bool vaild_IP(string s,int start,int end) {
		if(start > end)						return false;
//		if(end > s.size())					return false;
		if(s[start] == '0' && start != end)	return false;
			
		int num = 0;
		for(int i = start;i <= end;i++) {
			if(s[i] > '9' || s[i] < '0')
				return false;
			num = num*10 + (s[i] - '0');
//			cout << num << endl;
			if(num > 255)
				return false;
		}	
		return true;
	}
		
	vector<string> ans;
	void backtracking(string s,int StartIndex,int path_num)  {
		if(path_num == 3) {
			if(vaild_IP(s,StartIndex,s.size()-1))
				ans.push_back(s);
			return;
		}
		
		for(int i = StartIndex;i < s.size();i++) {
//			cout << StartIndex << " " << i << endl;
//			PrintBool(vaild_IP(s,StartIndex,i));
			if(vaild_IP(s,StartIndex,i)) {
				s.insert(s.begin() + i + 1,'.');
				path_num++;
//				cout << s << endl;
				backtracking(s,i+2,path_num);
				path_num--;
				s.erase(s.begin() + i + 1);
			}
			else
				break;
		}
	}
	 
	
    vector<string> restoreIpAddresses(string s) {
    	ans.clear();
    	backtracking(s,0,0);
    	
//    	bool temp = vaild_IP("2552",0,3);
//    	PrintBool(temp);	
    	return ans;
    }
};

	
int main() {
	Solution solution;
	string s = "25525511135"; 

	
	auto ans = solution.restoreIpAddresses(s);
	
	
	PrintVector(ans);
	
	return 0;
}



