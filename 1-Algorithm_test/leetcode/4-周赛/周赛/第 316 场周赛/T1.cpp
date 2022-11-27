#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"

int string_to_time(string time){
    int hour = 0,min = 0;
    hour = (time[0]-'0')*10+time[1]-'0';
    min = (time[3]-'0')*10+time[4]-'0';
    return hour*60+min;
}

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int event1_start = string_to_time(event1[0]);
        int event1_end = string_to_time(event1[1]);

        int event2_start = string_to_time(event2[0]);
        int event2_end = string_to_time(event2[1]);
        // printf("%d %d\n",event1_start,event1_end);
        // printf("%d %d\n",event2_start,event2_end);
        if((event2_start <= event1_end && event2_start >= event1_start) || 
        (event2_end <= event1_end && event2_end >= event1_start) || 
        (event2_end >= event1_end && event2_start <= event1_start))
            return true;
        else
            return false;
    }
};
	
int main() {
	Solution solution;

    int n = 70;
    // vector<string> event1 = {"01:15","02:00"};    
    // vector<string> event2 = {"02:00","03:00"};    

    vector<string> event1 = {"16:53","19:00"};    
    vector<string> event2 = {"10:33","18:15"};    

    vector<string> event1 = {"15:19","17:56"};    
    vector<string> event2 = {"14:11","20:02"}; 

    auto ans = solution.haveConflict(event1,event2);

	PrintBool(ans);
	return 0;
}




