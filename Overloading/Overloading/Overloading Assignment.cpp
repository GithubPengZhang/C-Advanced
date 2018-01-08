#if 0
#include <iostream>
#include <string>
using namespace std;

// rule of three: destructor, copy constructor, copy assignment operator
class Test
{
private:
	int id;
	string name;
public:
	Test() : id(0), name("") {
	}

	Test(int id, string name) : id(id), name(name) {
	}

	//copy constructor
	Test(const Test &other) {
		this->clone(other);
	}

	//copy assignment operator
	const Test &operator=(const Test &other) {
		this->clone(other);
		return *this;
	}

	void clone(const Test &other) {
		cout << "Clone" << endl;
		id = other.id;
		name = other.name;
	}

	void print() {
		cout << id << ": " << name << endl;
	}
};


int main() {
	Test test1(10, "Mike");
	test1.print();

	Test test2(20, "Bob:");
	test2.print();

	test2 = test1;
	test2.print();

	return 0;
}
#endif