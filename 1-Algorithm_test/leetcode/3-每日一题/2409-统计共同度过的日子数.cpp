#include <iostream>
#include <vector>
using namespace std;
#include "E:\\Desktop\\languguetest\\Cplusplustest\\algorithm_util.h"


// int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
// class Solution {
// public:
//     int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
//         vector<vector<int>> Alice = {{stoi(arriveAlice.substr(0,2)),stoi(arriveAlice.substr(3,2))},{stoi(leaveAlice.substr(0,2)),stoi(leaveAlice.substr(3,2))}};
//         vector<vector<int>> Bob = {{stoi(arriveBob.substr(0,2)),stoi(arriveBob.substr(3,2))},{stoi(leaveBob.substr(0,2)),stoi(leaveBob.substr(3,2))}};
//         // PrintVVector(Alice);
//         // PrintVVector(Bob);
//         vector<int> AliceTime = {0,0};
//         vector<int> BobTime = {0,0};
//         for(int i = 0;i < 2;i++){
//             for(int j = 1;j < Alice[i][0];j++){
//                 AliceTime[i] += months[j];
//             }
//             AliceTime[i] += Alice[i][1];
//             for(int j = 1;j < Bob[i][0];j++){
//                 BobTime[i] += months[j];
//             }
//             BobTime[i] += Bob[i][1];
//         }
//         // PrintVector(AliceTime);
//         // PrintVector(BobTime);
//         vector<int> all_in(400,0);
//         for(int i = AliceTime[0];i <= AliceTime[1];i++)
//             all_in[i]++;
//         for(int i = BobTime[0];i <= BobTime[1];i++)
//             all_in[i]++;
//         int ans = 0;
//         for(int i = 0;i < 400;i++){
//             if(all_in[i] == 2)
//                 ans++;
//         }
//         return ans;
//     }
// };


int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
class Solution {
public:
    // 转换时间的最好放成一个函数，不用多写
    int str_to_time(string str){
        int month = stoi(str.substr(0,2));
        int day = stoi(str.substr(3,2));
        int time = 0;
        for(int i = 1;i < month;i++){
            time += months[i];
        }
        return time+day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> AliceTime = {str_to_time(arriveAlice),str_to_time(leaveAlice)}; // 直接通过函数实现转化
        vector<int> BobTime = {str_to_time(arriveBob),str_to_time(leaveBob)};
        // PrintVector(AliceTime);PrintVector(BobTime);
        // 求共同在的时间，有了两个时间段，求两个闭区间的交集的整数个数
        // 左端点，两个在的时间取最大值
        // 右端点，两个在的时间取最小值
        int l_node = max(AliceTime[0],BobTime[0]);
        int r_node = min(AliceTime[1],BobTime[1]);
        if(l_node <= r_node)
            return r_node - l_node + 1;
        return 0;
    }
};



		
int main() {
    Solution solution;
	string 	arriveAlice, leaveAlice, arriveBob, leaveBob; 
	arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19";
	cout << solution.countDaysTogether(arriveAlice,leaveAlice,arriveBob,leaveBob) << endl;cout << "-----------------" << endl;

    arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31";
	cout << solution.countDaysTogether(arriveAlice,leaveAlice,arriveBob,leaveBob) << endl;cout << "-----------------" << endl;

    arriveAlice = "09-01", leaveAlice = "10-19", arriveBob = "06-19", leaveBob = "10-20";
	cout << solution.countDaysTogether(arriveAlice,leaveAlice,arriveBob,leaveBob) << endl;cout << "-----------------" << endl;

    arriveAlice = "09-01", leaveAlice = "10-19", arriveBob = "11-01", leaveBob = "12-31";
	cout << solution.countDaysTogether(arriveAlice,leaveAlice,arriveBob,leaveBob) << endl;cout << "-----------------" << endl;
	return 0;
}



