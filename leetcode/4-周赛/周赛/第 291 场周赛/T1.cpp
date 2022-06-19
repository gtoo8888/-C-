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
    string removeDigit(string number, char digit) {
        int n = number.size();
        vector<string> vs;
        for(int i = 0;i < n;i++){
            string tmp_number = number;
            string tmp;
            if(number[i] == digit){
                tmp = tmp_number.erase(i, 1);
            }
            if(tmp != "")
                vs.push_back(tmp);
            // cout << tmp << endl;
        }
        PrintVSector(vs);
        string ans;
        string tmp_s = vs[0];
        for(int i = 1;i < vs.size();i++){
            int len = vs[0].size();
            int s = 0;
            if(vs[i] == tmp_s)
                continue;
            while(vs[i][s] == tmp_s[s] && s < len){
                // printf("%c %c\n",vs[i][s],tmp_s[s] );
                s++;
            }
            // cout << endl;
            if(vs[i][s] > tmp_s[s] )
                tmp_s = vs[i];
            else
                tmp_s = tmp_s;
            // cout << tmp_s << endl;
        }
        return tmp_s;
    }
};



	
int main() {
	Solution solution;
    string number = "3619552534";
    char digit = '5';

    auto ans = solution.removeDigit(number,digit);

	cout << ans << endl;
	return 0;
}




