#if 0
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Parent
{
private:
	int nparent;
public:
	Parent() : nparent(0) {
		cout << "Parent: def constructor " << endl;
	}
	Parent(const Parent &other) {
		nparent = other.nparent;
		cout << "Parent: copy constructor " << endl;
	}
	virtual ~Parent() {
		cout << "Parent: destructor " << endl;
	}

	virtual void print() {
		cout << "Parent: print" << endl;
	}

private:

};


class Child : public Parent {
private:
	int nchild;
public:
	Child() : nchild(0) {
		cout << "Child: def constructor " << endl;
	}
	Child(const Child &other) {
		nchild = other.nchild;
		cout << "Child: copy constructor " << endl;
	}
	~Child() {
		cout << "Child: destructor " << endl;
	}

	void print() {
		cout << "Child: print" << endl;
	}
};

int main() {
	Child c1;
	Parent &p1 = c1;
	p1.print();

	cout << "-----------" << endl;

	Parent p2 = Child();
	p2.print();

	return 0;
}
#endif