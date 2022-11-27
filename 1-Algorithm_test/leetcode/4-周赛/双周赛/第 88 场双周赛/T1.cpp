#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


void tmpttt(unordered_map<int,int> m) {
	for(auto it : m)
		printf("%d %d\n",it.first,it.second);
	cout << endl;	
}


// class Solution {
// public:
//     bool equalFrequency(string word) {
//         unordered_map<char,int> map;
// 		for(auto c : word){
// 			map[c]++;
// 		}
// 		PrintUnorder_Map(map);
// 		unordered_map<int,int> piinglv;
// 		for(auto it : map){
// 			piinglv[it.second]++;
// 			if(piinglv.size() > 2)
// 				return false;
// 		}
// 		tmpttt(piinglv);
// 		if(piinglv.size() == 1){
// 			for(auto it : piinglv){
// 				if(it.first != 1)
// 					return false;
// 				else
// 					return true;
// 			}
// 		}
// 		vector<int> geshu;
// 		for(auto it : piinglv){
// 			geshu.push_back(it.first);
// 		}
// 		PrintVector(geshu);
// 		if(abs(geshu[0] - geshu[1]) != 1){
// 			return false;
// 		}
// 		return true;
//     }
// };


// class Solution {
// public:
//     bool equalFrequency(string word) {
//         unordered_map<char,int> map;
// 		for(auto c : word){
// 			map[c]++;
// 		}
// 		PrintUnorder_Map(map);
// 		vector<int> pinlv;
// 		for(auto it : map){
// 			pinlv.push_back(it.second);
// 		}
// 		PrintVector(pinlv);
// 		int max_index = 0;
// 		int max_num = INT32_MIN;
// 		for(int i = 0;i < pinlv.size();i++){
// 			if(max_num < pinlv[i]){
// 				max_num = pinlv[i];
// 				max_index = i;
// 			}
// 		}
// 		if(max_num == 1)
// 			return true;
// 		pinlv[max_index]--;
// 		if(pinlv[max_index] == 0)
// 			pinlv.erase(pinlv.begin()+max_index);
// 		PrintVector(pinlv);
// 		for(int i = 0;i < pinlv.size()-1;i++){
// 			if(pinlv[i] != pinlv[i+1]){
// 				return false;
// 			}
// 		}
// 		return true;
//     }
// };



class Solution {
public:
    bool equalFrequency(string word) {
		for(int i = 0;i < word.size();i++){	
			string tmp = word;
			tmp.erase(tmp.begin()+i);
			// cout << tmp << endl;
			unordered_map<char,int> map;
			for(auto c : tmp){
				map[c]++;
			}
			vector<int> pinlv;
			for(auto it : map){
				pinlv.push_back(it.second);
			}
			// PrintVector(pinlv);
			int biaozhun = pinlv[0];
			bool flag = false;
			for(int i = 0;i < pinlv.size();i++){
				if(pinlv[i] != biaozhun){
					flag = true;
					break;
				}
			}
			if(flag == true)
				continue;
			else
				return true;
		}
		return false;
    }
};

	
int main() {
	Solution solution;
	// string word = "abcc";
	string word = "aazz";
	// string word = "aabbccccddee";
	// string word = "aabbcccddee";
	// string word = "abc";
	// string word = "aabbcc";
	// string word = "ddaccb";
	// string word = "bbcca";
    vector<int> num = {10,4,-8,7};
    int k = 2;

    auto ans = solution.equalFrequency(word);

	PrintBool(ans);
	return 0;
}




