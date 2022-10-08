#include <iostream> 
using namespace std;
#include <vector> 
#include <cmath> 

#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

int str_to_num(string str){
	reverse(str.begin(),str.end());
	// cout << str << endl;
	int num = 0;
	for(int i = 0;i < str.size();i++){	
		// ???????????????????,9*100.00???999
		num += (str[i]-'0')*ceil(pow(10,i));
		// printf("%d %d %f\n",num,i,ceil(pow(10,i));
	}
	return num;
}

string num_to_str(int num){
	string str;
	while(num != 0){
		int tmp = num%10;
		str.push_back('0'+tmp);
		num /= 10;
	}
	reverse(str.begin(),str.end());
	return str;
}

// ???
// class Solution {
// public:
//     vector<string> subdomainVisits(vector<string>& cpdomains) {
// 		// PrintVector(cpdomains);
// 		int n = cpdomains.size();
// 		unordered_map<string,int> map;
// 		for(int i = 0;i < n;i++){
// 			string str_yuming = cpdomains[i];
// 			int pos = str_yuming.find(" ");
// 			string str_num = str_yuming.substr(0,pos);
// 			// printf("%d\n",pos);
// 			// cout << str_num << endl;
// 			int domain_count = str_to_num(str_num);
// 			// cout << domain_count << endl;
// 			int m = str_yuming.size()-1;
// 			for(int j = str_yuming.size()-1;j >= pos;j--){
// 				if(str_yuming[j] == '.' || str_yuming[j] == ' '){
// 					string sub_yuming = str_yuming.substr(j+1,m);
// 					// cout << sub_yuming << endl;
// 					map[sub_yuming] += domain_count;
// 				}
// 			}		
// 			// PrintUnorder_Map(map);
// 		}
// 		vector<string> ans;
// 		for(auto it : map){
// 			string res = num_to_str(it.second);
// 			// cout << num_to_str(it.second) << endl;
// 			res += " " + it.first;
// 			// cout << res << endl;
// 			ans.push_back(res);
// 		}
// 		return ans;
//     }
// };


// ???????
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
		// PrintVector(cpdomains);
		int n = cpdomains.size();
		unordered_map<string,int> map;
		for(auto domain : cpdomains){
			int pos = domain.find(" ");
			string str_num = domain.substr(0,pos);
			int domain_count = str_to_num(str_num);
			int m = domain.size()-1;
			for(int j = m;j >= pos;j--){
				if(domain[j] == '.' || domain[j] == ' '){
					string sub_domain = domain.substr(j+1,m);
					map[sub_domain] += domain_count;
				}
			}		
			// PrintUnorder_Map(map);
		}
		vector<string> ans;
		for(auto it : map){
			string res = num_to_str(it.second) + " " + it.first;
			ans.push_back(res);
		}
		return ans;
    }
};

int main(){
	Solution sol;
	// vector<string> cpdomains = {"9001 discuss.leetcode.com"};
	vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};

	auto ans = sol.subdomainVisits(cpdomains);
	PrintVector(ans);
	return 0;
}



