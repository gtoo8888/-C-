#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVCector(vector<char> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintVSector(vector<string> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << endl;
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

void PrintMap(unordered_map<int,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

class Solution {
public:
    string greatestLetter(string s) {
        vector<int> save(26*2);
		for(int i = 0;i < s.size();i++){
			if ('a' <= s[i] && s[i] <= 'z')
				save[s[i]-'a'] = 1;
			if('A' <= s[i] && s[i] <= 'Z')
				save[26 + s[i]-'A'] = 1;
		}
		vector<string> daxie;
		for(int i = 0;i < 26;i++){
			if(save[i] != 0)
				if(save[i+26] != 0){
					char tmp = i+'A';
					string str;
					str += tmp;
					daxie.push_back(str);
				}
		}
		PrintVector(save);
		PrintVSector(daxie);
		cout << daxie.size() << endl;
		if(daxie.size() == 1)
			return daxie[0];
		else if(daxie.size() == 0)
			return "";
		else{
			string ans = daxie[0];
			for(int i = 1;i < daxie.size();i++){
				if(daxie[i] > ans)
					ans = daxie[i];
			}
			return ans;
		}
		return "";
    }
};
	
int main() {
	Solution solution;
    string s = "AbCdEfGhIjK";

    auto ans = solution.greatestLetter(s);

	cout << ans << endl;
	return 0;
}




