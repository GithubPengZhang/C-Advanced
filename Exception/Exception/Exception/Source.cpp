#include <iostream>
#include <exception>
using namespace std;

//Press Ctrl + F5 to console

void GoWrong() {
	bool bErr1 = true;
	bool bErr2 = false;

	if (bErr1)
	{
		throw bad_alloc();
	}
	if (bErr2)
	{
		throw exception();
	}
}

int main() {
	try
	{
		GoWrong();
	}
	catch (exception &e)
	{
		cout << "Catching exception: " << e.what() << endl; //bad alloc inherit from exception, that is why we hit here
	}
	catch (bad_alloc &e)
	{
		cout << "Catching exception: " << e.what() << endl;
	}

	return 0;
}
