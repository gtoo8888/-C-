#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
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

void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

class Solution {
public:
	// bool checkstring(string longs, string shorts){
	// 	int n1 = longs.size(),n2 = shorts.size();
	// 	int t1 = 0,t2 = 0;	
	// 	while(t1 <= n1 && t2 <= n2){
	// 		// printf("%c %c %d\n",longs[t1],shorts[t2],t1 - t2);
	// 		if(t1 - t2 > 1)
	// 			return false;
	// 		if(longs[t1] == shorts[t2]){
	// 			t1++;t2++;
	// 		}else{
	// 			t1++;
	// 		}
	// 	}
	// 	return true;
	// }
	// 优化一下
	bool checkstring(string longs, string shorts){
		int n1 = longs.size(),n2 = shorts.size();
		int t1 = 0,t2 = 0;	
		while(t1 < n1 && t2 < n2){
			// printf("%c %c %d\n",longs[t1],shorts[t2],t1 - t2);
			if(longs[t1] == shorts[t2])
				t2++;
			t1++;	// 无论如何都需要加t1，所以直接每次都加
			if(t1 - t2 > 1)
				return false;
		}
		return true;
	}
    bool oneEditAway(string first, string second) {
		int n1 = first.size(),n2 = second.size();
		if(abs(n1-n2) > 1)
			return false;
		if(n1 == n2){
			int ans = 0;
			for(int i = 0;i < n1;i++){
				if(first[i] != second[i]){
					ans++;
					if(ans > 1)
						return false;
				}
			}
		}else if(n1 > n2){
			return checkstring(first,second);
			
		}else if(n1 < n2){
			return checkstring(second,first);
		}
		return true;
    }
};


	
int main() {
	Solution solution;
	// string first =   "afd";
	// string second =  "abcd";

	// string first =   "mart";
	// string second =  "karma";

	string first =   "";
	string second =  "a";

	// string first =   "teacher";
	// string second =  "taches";

	auto ans = solution.oneEditAway(first,second);
	
	PrintBool(ans);
	
	return 0;
}



