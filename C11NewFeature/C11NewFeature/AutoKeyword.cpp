#include <iostream>
using namespace std;

template <class T>
auto test(T value1 ) -> T {
	return value1;
}

auto retInt() -> double {
	return 11.2;
}

int main() {

	auto value = 7;
	auto text = "hello";

	cout << value << endl;
	cout << text << endl;

	cout << "---------" << endl;
	
	cout << retInt() << endl;

	cout << "---------" << endl;

	//cout << test(5, 6) << endl;

	//cout << test(5, 11.2) << endl;

	//cout << test("2", "3") << endl;

	cout << test("hello") << endl;
	cout << test(2.3) << endl;

	return 0;
}