////8.2
//#include<iostream> 
//using namespace std;
//
//int main()
//{
//	int rats = 101;
//	int  &rodents = rats;
//	cout << rats << " " << rodents << endl;
//	rodents++;
//	cout << rats << " " << rodents << endl;
//	
//	cout << &rats << endl;	
//	cout << &rodents << endl;
//	return 0;
//}


//8.3
#include<iostream> 
using namespace std;

int main()
{
	int rats = 101;
	int  &rodents = rats;
	cout << rats << " " << rodents << endl;
	
	cout << &rats << endl;	
	cout << &rodents << endl;
	
	int bunnies = 50;
	rodents = bunnies;
	cout << bunnies << endl;
	cout << rats << endl;
	cout << rodents << "\n" << endl;
	
	cout << &bunnies << endl;
	cout << &rodents << endl;
	return 0;
}

