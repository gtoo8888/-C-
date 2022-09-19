#include <iostream> 
#include <vector>
#include <queue>
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

void PrintVVector(vector<vector<int>> v){
	
	for(auto iter = v.begin();iter != v.end();iter++){		
		auto it_temp = *iter;
		for(auto it = it_temp.begin();it != it_temp.end();it++)
			cout << *it << " ";
		cout << endl;
	}
	cout << endl;
}

//class Solution {
//public:
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//    	int num = prerequisites.size();
//		vector<vector<int>> edge(numCourses);
//		vector<int> rudubiao(num,0);
//		
////		cout << prerequisites[1][1] << endl;
////		for(int i = 0;i < num;i++) {
////		int i = 0;
////		for(auto iter = prerequisites.begin();
////								iter != prerequisites.end();iter++) {
////			cout << (*iter)[1] << " ";
////			edge[i][(*iter)[1]] = ((*iter)[0]);
////			rudubiao[(*iter)[1]]++;
////			i++;
////		}
//		for( auto &p : prerequisites )
//		{
//			cout << p[0] << endl;
//			edge[ p[ 1 ] ].emplace_back( p[ 0 ] );
//			++rudubiao[ p[ 0 ] ];
//		}
//
//		PrintVector(rudubiao);
////		PrintVVector(edge);
//		return true;
//    }
//};


class Solution {
public:
	bool canFinish( int numCourses, const vector< vector< int > > &prerequisites )
	{
		vector< vector< int > > edges( numCourses );	// �ߣ���¼�Կγ�iΪ���޿εĿγ�
		vector< int > indegree( numCourses );	// ��ȣ����γ�i�м������޿�
		for( auto &p : prerequisites )
		{
			edges[ p[ 1 ] ].emplace_back( p[ 0 ] );
			++indegree[ p[ 0 ] ];
		}

		queue< int > q;	// ��¼���Ϊ0�Ŀγ�
		for( int i{}; i < numCourses; ++i )
			if( !indegree[ i ] )
				q.emplace( i );

		int vCount{};	// ����������������Ķ��㣨�γ̣���
		while( q.size() )
		{
			auto v = q.front();	// ȡ������v������Ľ������һ����ȡ���Ķ���
			q.pop();
			++vCount;

			auto &edge = edges[ v ];
			for( auto i : edge )
				if( --indegree[ i ] == 0 )	// ������vΪ���޵���ȶ���1
					q.emplace( i );
		}

		return vCount == numCourses;
	}
};


int main(){
	Solution solution;
	int numCourses = 5;
	vector<vector<int>> prerequisites = {{1,2},{1,4},{2,4},{2,3},{3,5},{4,5}};

	auto ans = solution.canFinish(numCourses,prerequisites);
	
	PrintBool(ans);
	
	return 0;
}














