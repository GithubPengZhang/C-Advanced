#include <iostream>
#include "ring.h"
#include <string>
using namespace std;


int main()
{
	Ring<string> textring(3);

	textring.add("one");
	textring.add("two");
	textring.add("three");

	//c++98 style
	for (Ring<string>::iterator it=textring.begin(); it!=textring.end(); it++)
	{
		cout << (*it) << endl;
	}

	cout << "-------" << endl;

	//c++11 style
	for (auto text: textring)
	{
		cout << text << endl;
	}


	return 0;
}