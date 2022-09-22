#include <iostream> 
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
#include "C:\\Users\\Yan\\Desktop\\languguetest\\Cplusplustest\algorithm_util.h"

class Solution {
public:
	int result = INT32_MAX;
    int kSimilarity(string s1, string s2) {
		return backtraining(s1,s2,0,0);
    }

	int backtraining(string str1,string str2,int start ,int current){
		if(current >= result)
			return result;
		if(start == str1.size() - 1)
			return result = min(current, result);

		for(int i = start;i < str1.size();i++){
			if(str1[i] != str2[i]){
				for(int j = i+1;j < str2.size();j++){
					if(str2[j] == str1[i] && str2[j] != str1[j]){
						swap(str2,i,j);
						// cout << str2 << endl;
						backtraining(str1,str2,i+1,current+1);
						swap(str2,i,j);
						if(str2[i] == str1[j])
							break;
					}
				}
				return result;
			}
		}
		return result = min(current,result);
	}
	

	void swap(string& str,int i,int j){
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
};



int main(){
	Solution solution;
	string s1 = "abacbc";
	string s2 = "bccaba";

	auto ans = solution.kSimilarity(s1,s2);
	
	cout << ans << endl;
	
	return 0;
}














