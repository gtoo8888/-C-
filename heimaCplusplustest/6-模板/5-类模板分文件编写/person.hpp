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






template<class T1,class T2> 
Person<T1,T2>::Person(T1 name,T2 age){
	this -> m_Name = name;
	this -> m_Age = age;
}

template<class T1,class T2> 
void Person<T1,T2>::show(){
	cout << this ->m_Name << " " << this->m_Age << endl;
}




