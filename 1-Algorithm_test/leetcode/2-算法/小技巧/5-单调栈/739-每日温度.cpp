#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}


// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         PrintVector(temperatures);
//         stack<int> st;
//         vector<int> ans(temperatures.size(),0);
//         st.push(0);
//         for(int i = 0;i < temperatures.size();i++) {
//             if(temperatures[i] < temperatures[st.top()])
//                 st.push(i);
//             else if(temperatures[i] == temperatures[st.top()])
//                 st.push(i);
//             else{
//                 while(!st.empty() && temperatures[i] > temperatures[st.top()]){
//                     ans[st.top()] = i - st.top();
//                     st.pop();
//                 }
//                 st.push(i);
//             }
//             PrintVector(ans);
//         }

//         return ans;
//     }
// };

//�����ߣ��ҳ���һ�����Լ����Ԫ��
//����˳��Ϊ���ҿ�ʼ
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         PrintVector(temperatures);
//         stack<int> st;
//         vector<int> ans(temperatures.size(),0);
//         for(int i = temperatures.size()-1;i >= 0;i--){
//             //!st.empty() && ����ջ����ֵ������
//             //ջ����ֵ && st.top()ջ��Ԫ��=�ոձ�ѹ��ջ��Ҳ�����ұ�һ��Ԫ�أ��ȵ�ǰԪ��С
//             //�յĽ�����ѭ��
//             while(!st.empty() && st.top() <= temperatures[i])   //��Ҫ�Բ�������������е���
//                 st.pop();
//             ans[i] = st.empty() ? -1 : st.top();
//             st.push(temperatures[i]);
//             // PrintVector(ans);
//         }
//         return ans;
//     }
// };

//�����ߣ��ҳ���һ�����Լ����Ԫ�ص��±�
//����˳��Ϊ���ҿ�ʼ
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         PrintVector(temperatures);
//         stack<int> st;
//         vector<int> ans(temperatures.size(),0);
//         for(int i = temperatures.size()-1;i >= 0;i--){
//             //!st.empty() && ����ջ����ֵ������
//             //ջ����ֵ && st.top()ջ��Ԫ��=�ոձ�ѹ��ջ��Ҳ�����ұ�һ��Ԫ�أ��ȵ�ǰԪ��С
//             while(!st.empty() && temperatures[st.top()] <= temperatures[i]){   //��Ҫ�Բ�������������е���
//                 st.pop();
//             }
//             ans[i] = st.empty() ? -1 : st.top() - i;
//             st.push(i);
//             // PrintVector(ans);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        PrintVector(temperatures);
        stack<int> st;
        vector<int> ans(temperatures.size(),0);
        for(int i = 0;i < temperatures.size();i++) {//����߿�ʼ�Ļ���������ʱ�����Ҫ��¼������
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){   //��Ҫ�Բ�������������е���
                //��while�ѻ�ѹ�Ķ����������
                ans[st.top()] = i - st.top();// �����ֵ���̣�������ȸ�ֵ�˺��漸��
                //�ҵ���ǰ��ı��Լ����ֵ���ٸ�ֵ�����
                st.pop();//�Ѿ��ҵ��˱ȵ�ǰ��ģ�����ֱ�ӵ�����
            }
            st.push(i);//���û�ҵ��ȵ�ǰֵ��ģ����ջ��һֱ�ۼӱȵ�ǰֵС��
            // ͬʱ���ջ��������һ���ǵݼ���
            PrintVector(ans);
        }
        return ans;
    }
};
	
int main() {
	Solution solution;
    vector<int> temperatures = {30,40,50,60};
	
	auto ans = solution.dailyTemperatures(temperatures);
	
	PrintVector(ans);
	
	return 0;
}



