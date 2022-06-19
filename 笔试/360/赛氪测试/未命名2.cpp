#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_slip(int n1) {
	int temp = n1;
	int sum = 0;
	while(temp != 0) {
		int a = temp%10;
		sum += a*a*a;
		temp /= 10;
	}
//	cout << sum << endl;
	if(sum == n1)
		return true;
	else
		return false;
}



int main() {

	int n1,n2;
	vector<int> ans;
	while(~scanf("%d %d",&n1,&n2)) {
		for(int i = n1;i <= n2;i++) {
			if(is_slip(i))
				ans.push_back(i);
		}
		if(!ans.empty()){
			for(int i = 0;i < ans.size();i++)
				cout << ans[i] << " ";
			cout << endl;
		}
		else
			cout << "no\n";
	}
	return 0;
}
