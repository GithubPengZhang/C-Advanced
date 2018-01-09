#if 0
#include <iostream>

using namespace std;

void test(int val) {
	cout << "hello: " << val << endl;
}

int main() {
	test(7);

	void(*pTest)(int) = test;

	pTest(8);

	return 0;
}
#endif