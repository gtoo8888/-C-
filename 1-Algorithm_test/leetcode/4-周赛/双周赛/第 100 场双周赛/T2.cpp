#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
		set<string> s1,s2;
		for(auto it : positive_feedback){
			s1.insert(it);
		}
		for(auto it : negative_feedback){
			s2.insert(it);
		}
		PrintSet(s1);
		PrintSet(s2);
        return {};
    }
};

	
int main() {
	Solution sol;
	vector<string> positive_feedback = {"smart","brilliant","studious"};
	vector<string> negative_feedback = {"not"};
	vector<string> report = {"this student is studious","the student is smart"};
	vector<int> student_id = {1,2};
	int k = 2;

    auto ans = sol.topStudents(positive_feedback,negative_feedback,report,student_id,k);

	PrintVector(ans);
	return 0;
}




