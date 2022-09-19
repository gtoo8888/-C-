#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <typeinfo>
using namespace std;


int main()
{
	unordered_set<int> us;
	us.insert(9);
	us.insert(6);
	us.insert(8);
	us.insert(10);
	us.insert(7);
	us.insert(3);
	us.insert(6);
	us.insert(7);
	us.insert(4);

	cout << us.empty() << endl;
	cout << us.size() << endl;

	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	
	auto temp = us.insert(4);
	cout << typeid(temp.second).name() << endl;
	

	return 0;
}

