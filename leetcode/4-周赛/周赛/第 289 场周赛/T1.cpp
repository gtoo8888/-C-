#include <iostream>
#include <vector>
#include <algorithm>
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

// class Solution {
// public:
//     int hebing(string s){
//         if(s.size() == 3)
//             return (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
//         if(s.size() == 2)
//             return (s[0] - '0') + (s[1] - '0');
//         if(s.size() == 1)
//             return (s[0] - '0');
//     }
//     string digitSum(string s, int k) {
//         int num_1 = s.size()/k;
//         vector<int> tmp1(num_1+1,0);
//         while(tmp1.size() < k){
//             int tmp_i = 0;
//             for(int i = 0;i < s.size();i += 3){
//                 string s_tmp;
//                 if(i+3 < s.size()){
//                     string s_tmp1(s.begin()+i,s.begin()+i+3);
//                     s_tmp = s_tmp1;
//                 }
//                 else{
//                     string s_tmp1(s.begin()+i,s.end());
//                     s_tmp = s_tmp1;
//                 }
//                 // cout << s_tmp << endl;
//                 printf("%d\n",hebing(s_tmp));
//                 tmp1[tmp_i] = hebing(s_tmp);
//                 tmp_i++;
//             }
//             PrintVector(tmp1);
//         }
        
//         string ans = "h";
//         return ans;
//     }
// };

class Solution {
public:
    int hebing(vector<int> s){
        if(s.size() == 3)
            return s[0] + s[1] + s[2];
        if(s.size() == 2)
            return s[0] + s[1];
        if(s.size() == 1)
            return s[0];
    }

    string digitSum(string s, int k) {
        int num_1 = s.size()/k;

        vector<int> int_s(s.size(),0);
        for(int i = 0;i < s.size();i++){
            int_s[i] = s[i] - '0';
        }

        while(int_s.size() >= k){
            int tmp_i = 0;
//            PrintVector(int_s);
            for(int i = 0;i < int_s.size();i += 3){
                vector<int> s_tmp;
                if(i+3 < int_s.size()){
                    vector<int> s_tmp1(int_s.begin()+i,int_s.begin()+i+3);
                    PrintVector(s_tmp1);
                    s_tmp = s_tmp1;
                }
                else{
                    vector<int> s_tmp1(int_s.begin()+i,int_s.end());
                    PrintVector(s_tmp1);
                    s_tmp = s_tmp1;
                }
//                PrintVector(s_tmp);
                int_s[tmp_i] = hebing(s_tmp);
                tmp_i++;
                printf("%d %d\n",hebing(s_tmp),tmp_i);
            }
            int_s.resize(tmp_i);
             cout << endl;
            PrintVector(int_s);
        }

        string ans = "h";
        return ans;
    }
};


	
int main() {
	Solution solution;
    string s = "11111222223";
	int k = 3;
	
	auto ans = solution.digitSum(s,k);
	
	cout << ans << endl;
	
	return 0;
}




