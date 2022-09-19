#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<long long> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


void PrintBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

//class Solution {//±©Á¦ 
//public:
//    vector<long long> getDistances(vector<int>& arr) {
//        vector<long long> ans(arr.size(),0);
//        
//        for(int i = 0;i < arr.size();i++) {
//        	long long sum = 0;
//        	for(int j = 0;j < arr.size();j++) {
//        		if(arr[j] == arr[i])
//        			sum += abs(j - i);
//			}
//			ans[i] = sum;
//		}
//		return ans;
//    }
//};

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector<long long> ans(arr.size(),0);
        
        for(int i = 0;i < arr.size();i++) {
        	long long sum = 0;
        	cout << "-----------" << endl;
        	int k = arr.size()-1;
        	for(int j = 0;j < k;j++) {
        		if(j != i && arr[j] == arr[i]){
        			cout << arr[j] << " " << arr[i] << endl;
        			cout << j << " " << i << endl;
					sum += abs(j - i);
				}
        		if(k != i && arr[k] == arr[i]){
        			cout << arr[k] << " " << arr[i] << endl;
        			cout << k << " " << i << endl;
					sum += abs(k - i);
				}
				if(arr[k] == arr[j]){
					sum += abs(k - j);
				}
				cout << arr[j] << " " << arr[k] << " " << arr[i] << endl;
//        		cout << sum << endl;
				if(arr.size()%2 == 1 && j == arr.size()/2){}					
				else
					k--;
			}
			ans[i] = sum;
		}
		return ans;
    }
};

	
int main() {
	Solution solution;
	vector<int> arr = {2,1,3,1,2,3,3};

	
	auto ans = solution.getDistances(arr);
	
	PrintVector(ans);
	
	return 0;
}



