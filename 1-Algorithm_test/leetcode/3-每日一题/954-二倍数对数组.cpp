#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <array>
using namespace std;


void printVector(vector<int> str)  {
	for(auto it = str.begin();it !=  str.end();it++)
		cout << *it << " ";
	cout << endl;
}

void printBool(bool val){
	if(val == true)		cout << "true" << endl;
	else				cout << "false" << endl;
	cout << endl;
}

void PrintMap(unordered_map<int,int> m) {
	for(auto it = m.begin();it != m.end();it++)
		cout << (*it).first << " " << it->second << endl;
	cout << endl;	
}

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
		sort(arr.begin(),arr.end());

		unordered_map<int,int> cnt; 
		for(auto n : arr) {//��ÿ����ȡ����
			if(n%2 == 0 && n > 0 && cnt[n/2] ) {	//�������0,����3�Ǽ���6���Ͱ�6����
				// cout << cnt[n/2] << endl;
				cnt[n/2]--;
			}else if(n < 0 && cnt[n*2] ) {	//���С��0�����ҵǼǹ��ˣ��ǾͰѵǼǵĻ���
				// cout << cnt[n*2] << endl;
				cnt[n*2]--;
			}else{		//���ʲô��û�еǼǹ����Ǿ͵Ǽ�һ��
				cnt[n]++;
			}
			cout << n << endl;
			PrintMap(cnt);
		}
		for(unordered_map<int,int>::iterator it = cnt.begin();it != cnt.end();it++) {
			if(it->first == 0) {
				if(it->second%2 == 0)
					continue;
				return false;
			}
			if(it->second != 0)
				return false;
		}
		return true;
    }
};


	
int main() {
	Solution solution;
	vector<int> arr = {3,1,3,6};
	
	auto ans = solution.canReorderDoubled(arr);
	
	printBool(ans);
	
	return 0;
}



