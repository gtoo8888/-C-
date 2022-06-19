#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void printBool(bool val){
	if(val == true)		cout << "YES" << endl;
	else				cout << "NO" << endl;
	cout << endl;
}

void printlVector(vector<string> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void printMap(unordered_map<string,int> m) {
	for(unordered_map<string,int>::iterator it = m.begin();it != m.end();it++) 
		cout << (*it).first << " " << it->second << endl;
	cout << endl;
}

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string,int> m1;
		unordered_map<string,int> m2;
		int num1 = 0;
		int num2 = 0;
		int min_num = INT32_MAX; 
		for(auto it = list1.begin();it != list1.end();it++) {//可以不使用迭代器遍历
		//可以用数组的方式，减少变量num1和num2 
			num1++;
			m1[*it] = num1;//第一次遍历的时候把字符串和序号都存进去 
		}
		vector<string> ans;
		for(auto it = list2.begin();it != list2.end();it++) {
			if(m1.find(*it) != m1.end()) {//找到了 
				if((m1[*it] + num2) < min_num) {//如果找到的索引和比原来的小 
					min_num = m1[*it] + num2;//更新最小索引和 
					ans.clear();//将原来的答案清空重新填入 
					ans.push_back(*it);
				}
				else if((m1[*it] + num2) == min_num) {//如果最小索引和是一样的，不断插入 
					ans.push_back(*it);
				}	
			}
			//没找到什么都不做，只需要序号加一就好了，就等于略过了 
			num2++;
		}
//		cout << min_num << endl;
		return ans;
    }
};


	
int main() {
	Solution solution;
	vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
	vector<string> ans;
	
	ans = solution.findRestaurant(list1,list2);
	
	printlVector(ans);
	
	return 0;
}



