#ifndef _HEADER_H_
#include <iostream>
using namespace std;

class person {
	string name;
	int age;
	string id;
	int money_value;
	int* destructorx;
public:
	person(); //constructor without any value
	void get (string, int, string, int);


	string returnname();
	string returnid();
	void setvalue(int);
	int returnvalue();
	void destructor();
};












#endif _HEADER_H_
