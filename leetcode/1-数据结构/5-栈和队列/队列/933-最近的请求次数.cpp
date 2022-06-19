#include <iostream> 
#include <vector> 
#include <queue>
using namespace std;

void PrintVector(vector<int> v){
	for(auto it = v.begin();it != v.end();it++)
		cout << *it << " ";
	cout << endl; 
}

void PrintQueue(queue<int> q){
	while(!q.empty()){
		printf("%d ",q.front());
		q.pop();
	}
	cout << endl; 
}

class RecentCounter {
public:
	int count = 0;
	queue<int> q;
    RecentCounter() {
		count = 0;
    }
    
    int ping(int t) {
		q.push(t);
		// cout << q.back() - q.front() << endl;
		while(q.back() - q.front() > 3000)	// ????3000ms????
			q.pop();
		// PrintQueue(q);
		return q.size();
    }
};

int main(){
	RecentCounter rc;
	
	cout << rc.ping(642) << endl;
	cout << rc.ping(1849) << endl;
	cout << rc.ping(4921) << endl;
	cout << rc.ping(5936) << endl;
	cout << rc.ping(5957) << endl;
	return 0;
}



