#include <iostream>
#include <Windows.h>
#include <string>
#include "Header.h"
#include <time.h>
using namespace std;

person::person()
{
	destructorx = new int;
	this->age = 0;
	this->money_value = 0;
}
void person::get(string a, int b, string id, int d)
{
	this->name = name;
	this->age = b;
	this->id = id;
	this->money_value = d;	
}
string person::returnid() { return id; }
int person::returnvalue() { return money_value; }
string person::returnname() {return name;}
void person::destructor() {delete destructorx;}
void person::setvalue(int a) { money_value = a; }