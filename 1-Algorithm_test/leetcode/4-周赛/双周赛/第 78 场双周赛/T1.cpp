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

void PrintSMap(unordered_map<string,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

class Solution {
public:
	int string_to_int(string str){
		reverse(str.begin(),str.end());
		int n = str.size();
		int ans = 0;
		for(int i = 0;i < n;i++){
			ans += (str[i] - '0') * pow(10,i);
		}
		return ans;
	}
    int divisorSubstrings(int num, int k) {
        string str;
		int tmp = num;
		while(tmp > 0){
			str.push_back(tmp%10 + '0');
			tmp /= 10;
		}
		reverse(str.begin(),str.end());
		int n = str.size();
		// cout << str << endl;
		int l = 0,r = l + k;
		int ans = 0;
		for(int i = 0;i < n-k+1;i++){
			string sub_str = str.substr(i,k);
			// cout << sub_str << endl;
			int sub_num = string_to_int(sub_str);
			// cout << sub_num << endl;
			if(sub_num == 0)
				continue;
			if(num%sub_num == 0)
				ans++;
		}
		return ans;
    }
};



	
int main() {
	Solution solution;
    int num = 430043;
    int k = 2;

    auto ans = solution.divisorSubstrings(num,k);

	cout << ans << endl;
	return 0;
}




