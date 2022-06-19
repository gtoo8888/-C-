#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printVVector(vector<vector<int>> v){
	vector<vector<int>>::iterator iter;
	vector<int>::iterator it;
	vector<int> it_temp;
	
	for(iter = v.begin();iter != v.end();iter++){
		it_temp = *iter;
		for(it = it_temp.begin();it != it_temp.end();it++)
			cout << setw(5) << *it << " ";
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    	vector<vector<int>> ans(n,vector<int>(n,0));
    	int loop = n*n;
    	int len = n - 1;
    	int i = 0;
    	int j = 0;
    	int start_x = i,start_y = j;
    	int num = 1;
    	while(loop){
    		i = start_x;
    		j = start_y;
    		for(i = start_x;i < start_x + len;i++) {
    			if(!loop) break;
    			ans[start_y][i] = num;
    			num++;
    			loop--;
    		}
//    		printVVector(ans);
//    		cout << loop << endl;
    		
    		for(j = start_y;j < start_y + len;j++) {
    			if(!loop) break;
    			ans[j][i] = num;
    			num++;
    			loop--;
			}
//			printVVector(ans);
//			cout << loop << endl;
			
			for(;i > start_x;i--) {
				if(!loop) break;
				ans[j][i] = num;
    			num++;
    			loop--;
			}
//			printVVector(ans);
//			cout << loop << endl;
			
			for(;j > start_y;j--) {
				if(!loop) break;
				ans[j][i] = num;
    			num++;
    			loop--;
			}
//			printVVector(ans);
//			cout << loop << endl;
			
			len -= 2;
			start_x++;
			start_y++;
			
			if(loop == 1 && n%2){
				ans[n/2][n/2] = n*n;
				loop--;
			}
		}
		return ans;
    }
};
		
int main() {
	Solution solution;
	int num = 9;
	vector<vector<int>> v;
	
	v = solution.generateMatrix(num);
	
	printVVector(v);
	
	return 0;
}



