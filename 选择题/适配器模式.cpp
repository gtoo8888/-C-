#include <iostream>
using namespace std;
 
// Targets
class Target
{
public:
	virtual void Request()    // Methods  
	{
		cout << "Target::Request" << endl;
	}
};
 
// Adaptee
class Adaptee
{
public:
	void SpecificRequest()   // Methods 
	{
		cout << "Adaptee::SpecificRequest" << endl;
	}
};
 
// Adapter
class Adapter : public Target, Adaptee
{
public:
	void Request()        // Implements ITarget interface
	{
		// Possibly do some data manipulation  
		// and then call SpecificRequest   
		this->Request();
		this->SpecificRequest();
	}
};
 
// Client
int main(int argc, char *argv[])
{
	Target *targetObj = new Adapter();
	targetObj->Request();
 
	delete targetObj;
	targetObj = NULL;
 
	return 0;
}