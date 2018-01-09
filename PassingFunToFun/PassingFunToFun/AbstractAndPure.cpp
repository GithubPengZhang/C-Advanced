#if 0
#include <iostream>
using namespace std;

class Animal
{
public:
	Animal() {
		cout << "New Animal" << endl;
	}
	virtual ~Animal() {}

public:
	virtual void speak() = 0;
	virtual void run() = 0;
};

class Dog : public Animal
{
public:
	Dog() {
		cout << "New dog" << endl;
	}
	~Dog() {}

public:
	virtual void speak() {
		cout << "Woof!" << endl;
	}
};

class Labrador : public Dog
{
public:
	Labrador() {
		cout << "Larador: new" << endl;
	}
	virtual ~Labrador() {}

public:
	virtual void run() {
		cout << "Labrador: run" << endl;
	}

};

void test(Animal &a) {
	a.run();
}

int main() {
	Labrador lab;
	lab.speak();
	lab.run();

	cout << "--------" << endl;

	Animal *animals[3];
	animals[0] = &lab;
	animals[0]->speak();

	cout << "--------" << endl;

	test(lab);

	return 0;
}
#endif // 0
