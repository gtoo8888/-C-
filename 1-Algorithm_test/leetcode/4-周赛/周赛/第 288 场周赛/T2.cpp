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

void PrintVB(vector<bool> v){
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
    int add_sum(vector<int> temp){
        if(temp.empty())
            return 0;
        int ans_sum = 0;
        int ten_i = 0;
        for(int i = temp.size()-1;i >= 0;i--){
            ans_sum += temp[i]*pow(10,ten_i);
            // printf("%d %d\n",ans[i],pow(10,ten_i));
            ten_i++;
        }
        return ans_sum;
    }
    string minimizeResult(string expression) {
        vector<int> num_left,num_right;
        bool add_flag = false;
        for(char s : expression){
            if(s == '+'){
                add_flag = true;
                continue;
            }
            if(add_flag == false)
                num_left.push_back(s-'0'); 
            else    
                num_right.push_back(s-'0');
        }
        // PrintVector(num_left);
        // PrintVector(num_right);
        vector<int> ans_l1;
        vector<int> ans_l2;
        vector<int> ans_r1;
        vector<int> ans_r2;

        int temp_min = INT32_MAX;
        for(int i = 0;i < num_left.size();i++){
            for(int j = 1;j <= num_right.size();j++){
                vector<int> temp_l1(num_left.begin(),num_left.begin() + i);
                vector<int> temp_l2(num_left.begin() + i,num_left.end());
                vector<int> temp_r1(num_right.begin(),num_right.begin() + j);
                vector<int> temp_r2(num_right.begin() + j,num_right.end()); 
                int l1 = add_sum(temp_l1);
                int l2 = add_sum(temp_l2);
                int r1 = add_sum(temp_r1);
                int r2 = add_sum(temp_r2);
                if(l1 == 0) l1 = 1;
                if(r2 == 0) r2 = 1;
                // printf("%d %d %d %d\n",add_sum(temp_l1),add_sum(temp_l2),
                //                         add_sum(temp_r1),add_sum(temp_r2)) ; 
                // printf("%d %d %d %d\n",l1,l2,r1,r2) ;     
                int temp_sum = l1 * (l2 + r1) * r2;      
                // temp_min =  temp_sum < temp_min ? temp_sum : temp_min;
                if(temp_sum < temp_min) {
                    temp_min = temp_sum;
                    ans_l1 = temp_l1;
                    ans_l2 = temp_l2;
                    ans_r1 = temp_r1;
                    ans_r2 = temp_r2;
                }
                // printf("%d %d\n",temp_sum,temp_min);  

            }
        }
        // PrintVector(ans_l1);
        // PrintVector(ans_l2);
        // PrintVector(ans_r1);
        // PrintVector(ans_r2); 
        string ans(expression.size()+2,'0');

        vector<int> vec3;
        if(!ans_l1.empty())
            vec3.insert(vec3.end(),ans_l1.begin(),ans_l1.end());
        vec3.push_back(99);
        vec3.insert(vec3.end(),ans_l2.begin(),ans_l2.end());
        vec3.push_back(100);
        vec3.insert(vec3.end(),ans_r1.begin(),ans_r1.end());
        vec3.push_back(101);
        if(!ans_r2.empty())
            vec3.insert(vec3.end(),ans_r2.begin(),ans_r2.end());

        for(int i = 0;i < vec3.size();i++) {
            if(vec3[i] == 99){
                ans[i] = '(';
                continue;
            }
            if(vec3[i] == 100){
                ans[i] = '+';
                continue;
            }
            if(vec3[i] == 101){
                ans[i] = ')';
                continue;
            }
            ans[i] = '0' + vec3[i];
        }
        // PrintVector(vec3); 

        return ans;
    }
};


	
int main() {
	Solution solution;
	string expression = "12+34";
	
	auto ans = solution.minimizeResult(expression);
	
	cout << ans << endl;
	
	return 0;
}




