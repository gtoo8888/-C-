#include <iostream> 
#include <cstring> 
using namespace std;

int main()
{
	const char* state1 = "Florida";
	const char* state2 = "Kansas";
	const char* state3 = "Euphoria";
	int len = std::strlen(state2);

	int i;
	for(i = 1;i < len;i++){
		cout.write(state2,i);
		cout << endl;
	}

	// for(i = len;i > 0;i--){
	// 	cout.write(state2,i) << endl;
	// }

	// cout.write(state2,len+5) << endl;
	return 0;
}

