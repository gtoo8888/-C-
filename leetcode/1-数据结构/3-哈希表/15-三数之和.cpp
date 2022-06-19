#include<iostream>
#include <vector>
#include <algorithm>
#include <iterator> 
using namespace std;

class printVector{
public:
	void operator ()(int val){
		cout << val << " ";
	}
};

//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {//ʱ�临�Ӷ�o(N3) ���ڴ������³�ʱ�� 
//		vector<int> v1;		
//		vector<vector<int>> result_vv;
//		sort(nums.begin(),nums.end());//��Ҫ�������� 
//		//��֤��ֻ�� (a,b,c) ���˳��ᱻö�ٵ����� (b, a, c)(b,a,c)��(c, b, a)(c,b,a) �ȵ���Щ���� 
//		for_each(nums.begin(),nums.end(),printVector());
//		cout << endl;
//		
//		int n = nums.size();
//		if(n < 3) {
//			return {};
//		}
//
//		for(int i = 0;i < n;i++){ 
//			if(i > 0 && nums[i] == nums[i-1])// ֻ�к���һ��ö�ٵ�Ԫ�ز���ͬ�����ǲŻ����ö�� 	
//			//�����ظ�ֵ 
//			//��һ��������֤���ֵ�Ѿ���ö����һ�Σ����ڶ��γ��ֵ�ʱ��ᱻ��ȥ
//			//���Ƚ��ظ�Ԫ�� 
//				continue;
//			for(int j = i+1;j < n;j++){
//			if(j > i+1 && nums[j] == nums[j-1])
//				continue;
//				for(int k = j+1;k < n;k++){
//					if(k > j+1 && nums[k] == nums[k-1])
//						continue;
//					cout <<nums.at(i) <<" " << nums.at(j) <<" " << nums.at(k) << endl;
//					if((nums.at(j) + nums.at(k)) == -nums.at(i)){
//						vector<int> v_temp;
//						v_temp.push_back(nums.at(i));
//						v_temp.push_back(nums.at(j));
//						v_temp.push_back(nums.at(k));
//						
//						result_vv.push_back(v_temp);
//					}
//				}
//			}
//		} 		
//		return result_vv; 
//    }
//};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<int> v1;		
		vector<vector<int>> result_vv;
		sort(nums.begin(),nums.end());
//		for_each(nums.begin(),nums.end(),printVector());
//		cout << endl;
		
		int n = nums.size();

		for(int i = 0;i < n;i++){ 
			if(i > 0 && nums[i] == nums[i-1])
				continue;
			int k = n-1; 
			for(int j = i+1;j < n;j++){
				if(j > i+1 && nums[j] == nums[j-1])
					continue;
//				cout <<i <<" " << j <<" " << k << endl;
//				cout <<nums.at(j) + nums.at(k) <<" " << -nums.at(i) << endl;
				while(j < k && nums[j] + nums[k] > -nums[i])
				//�����С��Ŀ��ֵ��ͷָ������ƣ�ʹ�ú����� 
				//����ʹ���Ŀ��ֵ��βָ����ǰ�ƣ�ʹ�úͼ�С 
					--k;
					
				if(j == k)
					break;
				
				if((nums.at(j) + nums.at(k)) == -nums.at(i)){
					vector<int> v_temp;
					v_temp.push_back(nums.at(i));
					v_temp.push_back(nums.at(j));
					v_temp.push_back(nums.at(k));
					
					result_vv.push_back(v_temp);
				}
			}
		} 		
		return result_vv; 
    }
};

void reverse_index(vector<vector<int>> vec)// vector<vector<int>>���� 
{
//    int i,j;//�±����
//    cout << "Use index : " << endl;
//    for (i = 0; i < vec.size(); i++)
//    {
//        for(j = 0; j < vec[0].size(); j++)
//            cout << vec[i][j] << " ";
//        cout << endl;
//    }

    vector<int>::iterator it;//����������
    vector<vector<int>>::iterator iter;
    vector<int> vec_tmp;
 
    cout << endl;
    for(iter = vec.begin(); iter != vec.end(); iter++)
    {
        vec_tmp = *iter;
        for(it = vec_tmp.begin(); it != vec_tmp.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}


int main() {
	Solution sol;
	int nums[] = {-1,0,1,2,-1,-4};
	vector<int> test_num(nums,nums + sizeof(nums)/sizeof(int));	
	vector<vector<int>> result;
	for_each(test_num.begin(),test_num.end(),printVector());
	cout << endl;
	result = sol.threeSum(test_num);

//	for(unsigned int i = 0; i < v.size(); ++i)//�±���������
//		cout<<v[i]<<" ";
//	cout<<endl;

//	copy(test_num.begin(), test_num.end(), ostream_iterator<int>(cout, " ") );//copy��������
//	cout<<endl;

	reverse_index(result);


	return 0;
}


