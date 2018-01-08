#if 0
#include <iostream>
#include "Complex.h"

using namespace std;
using namespace CaveOfComplex;

int main() {

	Complex c1(2, 3);
	Complex c2(3, 4);

	cout << c2 << endl;

	cout << c1+c2 << endl;

	cout << c1 + c2 + c2 << endl;

	Complex c5 = c2 + 1;
	cout << c5 << endl;

	cout << c2 + 1.0 << endl;


	/*Complex c3;
	c3 = c1 + c2;

	cout << c3 << endl;
*/
	return 0;
}
#endif