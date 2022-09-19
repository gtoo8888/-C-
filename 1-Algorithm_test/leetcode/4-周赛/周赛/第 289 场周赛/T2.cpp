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

void PrintMap(unordered_map<int,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(auto t : tasks){
            m[t]++;
        }
        PrintMap(m);
        // for(auto m_i : m) {
        //     if(m_i->second < 2)
        //         return -1
        // }
        for(auto it = m.begin();it != m.end();it++){
            if(it->second < 2)
                return -1;
        }
        int ans = 0;
        for(auto it = m.begin();it != m.end();it++){
            if(it->second > 3)
                ans += it->second/3;
        }
        return 0;
    }
};


	
int main() {
	Solution solution;
	vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};

	auto ans = solution.minimumRounds(tasks);
	
	cout << ans << endl;
	
	return 0;
}




