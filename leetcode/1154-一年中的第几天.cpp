#include <iostream> 
#include <vector> 
#include <string>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}


class Solution {
public:
	bool isRunNian(int year) {
		if((year%4 == 0 && year%100 != 0 ) || year%400 == 0)
			return true;
		return false;
	}
	
    int dayOfYear(string date) {
    	vector<int> nums(date.size()-2);
		for(int i = 0,j = 0;i < date.size();) {
			if(i == 4) {i++;continue;}
			if(i == 7) {i++;continue;}
			nums[j] = date[i] - '0';
			j++;i++;
		}
		PrintVector(nums);
		int year = nums[0]*1000 + nums[1]*100 + nums[2]*10 + nums[3];
		int month = nums[4]*10 + nums[5];
		int day = nums[6]*10 + nums[7];
//		cout << year << " " << month << " " << day << endl;	
//		PrintBool(isRunNian(year));
		int months_feilun[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		int months_shilun[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
		int ans = 0;
		if(isRunNian(year)) {
			for(int i = 1;i <= month;i++) {
				if(i == month) {
					ans += day;
					break;
				}
				ans += months_shilun[i];
			}
		}
		else {
			for(int i = 1;i <= month;i++) {
				if(i == month) {
					ans += day;
					break;
				}
				ans += months_feilun[i];
			}
		}
		return ans;
    }
};


	
int main() {
	Solution solution;
	string 	date = "2003-03-01"; 
	
	auto ans = solution.dayOfYear(date);
	
	cout << ans << endl;
	
	return 0;
}



