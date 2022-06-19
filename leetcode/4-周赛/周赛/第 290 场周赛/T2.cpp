#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
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


class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int max_x = INT32_MIN;
        int max_y = INT32_MIN;
        for(int i = 0;i < circles.size();i++) {
            int cir_x = circles[i][0];
            int cir_y = circles[i][1];
            int cir_r = circles[i][2];
            
            if(cir_x + cir_r > max_x)
                max_x = cir_x + cir_r;
            if(cir_y + cir_r > max_y)
                max_y = cir_y + cir_r;
        }
        max_x++;max_y++;
        // printf("%d %d\n",max_x,max_y);
        vector<vector<int>> cir_save(max_x,vector<int>(max_y,0));
        int ans_1 = 0;
        for(int i = 0;i < circles.size();i++) {
            int cir_x = circles[i][0];
            int cir_y = circles[i][1];
            int cir_r = circles[i][2];
            // printf("%d %d %d\n",cir_x,cir_y,cir_r);
            for(int j = cir_x - cir_r;j <= cir_x + cir_r;j++){
                for(int k = cir_y - cir_r;k <= cir_y + cir_r;k++){
                    int liangbian = abs(j-cir_x)*abs(j-cir_x) + abs(k-cir_y)*abs(k-cir_y);
                    float len = sqrt(liangbian);
                    
                    if(len <= cir_r){
                        // printf("j:[%d] k:[%d] %d %f\n",j,k,liangbian,len);
                        cir_save[j][k]++;
                        ans_1++;
                    }
                }
            }
            // cout << endl;
        }
        // PrintVVector(cir_save);
        int ans = 0;
        for(int i = 0;i < cir_save.size();i++) {
            for(int j = 0;j < cir_save[0].size();j++){
                if(cir_save[i][j] != 0)
                    ans++;
            }
        }
        return ans;
    }
};



	
int main() {
	Solution solution;
    vector<vector<int>> circles = {{2,2,2},{3,4,1}};

    auto ans = solution.countLatticePoints(circles);

	cout << ans << endl;
	return 0;
}






