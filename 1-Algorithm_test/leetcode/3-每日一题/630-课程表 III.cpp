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

class myclass{
public:
	bool operator() (int i,int j) {
		return i < j;
	}
};

	
//class Solution {
//public:
//
//	
//	
//    int scheduleCourse(vector<vector<int>>& courses) {
//    	sort(courses.begin(), courses.end(), [](const auto& a, const auto& b) { return a[1] < b [1];});
//
////    	sort(courses.begin(),courses.end(),[](const auto&a,const auto&b)
////											{return a[1] < b[1];});
//    	PrintVVector(courses);
//    	
//    	vector<int> class_time(courses.size(),0);
//		for(int i = 0;i < courses.size();i++) {
//			class_time[i] = courses[i][1] - courses[i][0];
//		}
//		PrintVector(class_time);
//		int ans = 0;
//		return ans;
//    }
//};


class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b) { return a[1] < b [1];});

        priority_queue<int> q;
        int day = 0;
        for (auto c: courses) {
            if (day + c[0] <= c[1]) {
                day += c[0];
                q.push(c[0]);
                continue;
            }
            if (!q.empty() && q.top() > c[0]) {
                day -= q.top();
                day += c[0];
                q.pop();
                q.push(c[0]);
            } 
            
        }

        return q.size();
    }
};



	
int main() {
	Solution solution;
	vector<vector<int>> courses  = { 
		{100, 200},
		{200, 1300}, 
		{1000, 1250}, 
		{2000, 3200}};
	
	auto ans = solution.scheduleCourse(courses);
	
	cout << ans << endl;
	
	return 0;
}



