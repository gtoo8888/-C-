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

// class Solution {
// public:
//     bool check(string& tmp){
//         if(tmp[0] == tmp[1] && tmp[1] == tmp[2] && tmp[0] == tmp[2])
//             return true;
//         else
//             return false;
//     }
//     string largestGoodInteger(string num) {
//         if(num.size() < 3)
//             return "";
//         string ans = "000";
//         int n = num.size();
//         bool flag = false;
//         for(int i = 0;i+3 <= n;i++){
//             string tmp = num.substr(i,3);
//             // cout << tmp << endl;
//             if(check(tmp)){
//                 flag = true;
//                 // cout << tmp << endl;
//                 if(tmp[0] >= ans[0])
//                     ans = tmp;
//             }
//         }
//         if(!flag)
//             return "";
//         return ans;
//     }
// };

// Ëõ¶Ì´úÂëºó
class Solution {
public:
    string largestGoodInteger(string num) {
        if(num.size() < 3)
            return "";
        string ans = "";
        for(int i = 0;i+3 <= num.size();i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                ans = max(ans,num.substr(i,3));
            }
        }
        return ans;
    }
};
	
int main() {
	Solution solution;
    string num = "2300019";

    auto ans = solution.largestGoodInteger(num);

	cout << ans << endl;
	return 0;
}




