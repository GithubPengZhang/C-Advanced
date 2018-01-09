#include <string>
#include <iostream>
using namespace std;

void testGreat(void(*great)(string)) {
	great("Bob");
}

void runDivide(double(*divide)(double a, double b)) {
	auto rval = divide(9, 3);
	cout << rval << endl;
}


int main() {
	auto pGreat = [](string name) { cout << "Hello: " << name << endl; };

	pGreat("Mike");

	testGreat(pGreat);

	auto pDivide = [](double a, double b) -> double {
		if (b == 0.0)
			return 0;
		return (a / b);
	};

	cout << pDivide(2, 5) << endl;

	runDivide(pDivide);


	return 0;
}