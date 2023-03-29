#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVSector(vector<string> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << endl;
	cout << endl; 
}


class Solution {
public:
	static bool cmp(string &log1,string &log2){
		int index1 = log1.find(' ');
		int index2 = log2.find(' ');
		if(log1.substr(index1 + 1) != log2.substr(index2 + 1)){
			// cout << log1.substr(index1 + 1) << endl;
			return log1.substr(index1 + 1) < log2.substr(index2 + 1);
		}
		return log1 < log2;
	}

    vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> numlogs;
		vector<string> zimulogs;
		int n = logs.size();
		for(int i = 0;i < n;i++){
			int index1 = logs[i].find(' ');
			if(logs[i][index1+1] <= '9' && logs[i][index1+1] >= '0')
				numlogs.push_back(logs[i]);
			else
				zimulogs.push_back(logs[i]);
		}
			// PrintVSector(numlogs);	
			// PrintVSector(zimulogs);	
		sort(zimulogs.begin(),zimulogs.end(),cmp);
		// PrintVSector(zimulogs);	
		vector<string> ans = zimulogs;
		ans.insert(ans.end(),numlogs.begin(),numlogs.end());
		return ans;
    }
};



	
int main() {
	Solution solution;
	// vector<string> logs = {	"dig1 8 1 5 1",
	// 						"let1 art can",
	// 						"dig2 3 6",
	// 						"let2 own kit dig",
	// 						"let3 art zero"};
	vector<string> logs = {	"a1 9 2 3 1",
							"g1 act car",
							"zo4 4 7",
							"ab1 off key dog",
							"a8 act zoo"};

	auto ans = solution.reorderLogFiles(logs);
	
	PrintVSector(ans);
	
	return 0;
}



