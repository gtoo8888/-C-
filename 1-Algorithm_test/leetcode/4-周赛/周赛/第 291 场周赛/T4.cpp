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
	for(auto it : m)
		printf("%d %d\n",it.first,it.second);
	cout << endl;	
}



class Solution {
public:
    int cout_str(string str){
        unordered_map<char,int> map;
        for(char s : str){
            map[s]++;
        }
        int res = 0;
        for(auto m : map){
            res++;
        }
        return res;
    }

    long long appealSum(string s) {
        int n = s.size();
        vector<string> str;
        for(int i = 1;i <= n;i++){
            string tmp;
            for(int j = 0;j <= n-i;j++){
                tmp = s.substr(j,i);
                // printf("%d %d \n",j,j+i);
                // cout << tmp << endl;
                str.push_back(tmp);
            }
        }
        // PrintVSector(str);
        int ans = 0;
        for(int i = 0;i < str.size();i++){
            ans += cout_str(str[i]);
        }
        return ans;
    }
};


	
int main() {
	Solution solution;

    string s = "abbca";

    auto ans = solution.appealSum(s);

	cout << ans << endl;
	return 0;
}




