#pragma once 
#include <iostream> 
using namespace std;
#include <string>



template<class NameType,class AgeType> 
class Person{
public:
	Person(NameType name,AgeType age);
	void show();
	NameType m_Name;
	AgeType m_Age;
}; 


